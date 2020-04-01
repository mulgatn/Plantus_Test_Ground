// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	walk_speed_ = 5.0f;
	run_speed_ = 10.0;
	speed_multiplier_ = 100.0f;
	b_can_run_ = true;
	mouse_sensitivity_ = 3.0f;
	fall_gravity_ = 1.0f;
	default_gravity_ = 1.0f;
	reach_range_ = 100.0f;
	camera_rotation_Y_limit_ = FVector2D(70.0f, -85.0f);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	camera_component_ = FindComponentByClass<UCameraComponent>();
	movement_component_ = GetCharacterMovement();
	movement_component_->MaxWalkSpeed = walk_speed_ * speed_multiplier_;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetGravity();
	interactable_object_ = Raycast();
	
	/*if (interactable_object_) {
		UE_LOG(LogTemp, Warning, TEXT("HIT %s"), *interactable_object_->GetName());
	}*/
}

void APlayerCharacter::MoveForward(float value) {

	if (Controller && value != 0.0f) {
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void APlayerCharacter::MoveRight(float value) {

	if (Controller && value != 0.0f) {
		AddMovementInput(GetActorRightVector(), value);
	}
}

void APlayerCharacter::AddYawInput(float value) {

	if (value != 0.0f) {
		float new_rotation_yaw = GetActorRotation().Yaw + value * mouse_sensitivity_;
		FRotator rotator = FRotator(0.0f, new_rotation_yaw, 0.0f);
		UGameplayStatics::GetPlayerController(this, 0)->SetControlRotation(rotator);
	}
}

void APlayerCharacter::AddPitchInput(float value) {
	if (camera_component_ && value != 0.0f) {
		float current_pitch = camera_component_->GetComponentRotation().Pitch;
		float rotation_magnitude = value * mouse_sensitivity_;

		float new_rotation_pitch = camera_component_->GetComponentRotation().Pitch + rotation_magnitude;
		if (new_rotation_pitch > camera_rotation_Y_limit_.X) {
			new_rotation_pitch = camera_rotation_Y_limit_.X;
		}
		else if (new_rotation_pitch < camera_rotation_Y_limit_.Y) {
			new_rotation_pitch = camera_rotation_Y_limit_.Y;
		}

		FRotator new_rotation = FRotator(new_rotation_pitch, camera_component_->GetComponentRotation().Yaw, camera_component_->GetComponentRotation().Roll);
		camera_component_->SetWorldRotation(new_rotation);
	}
}

void APlayerCharacter::StartRun() {
	if (movement_component_) {
		movement_component_->MaxWalkSpeed = run_speed_ * speed_multiplier_;
	}
}

void APlayerCharacter::StopRun() {
	if (movement_component_) {
		movement_component_->MaxWalkSpeed = walk_speed_ * speed_multiplier_;
	}
}

void APlayerCharacter::SetGravity() {
	if (movement_component_->Velocity.Z < 0) {
		movement_component_->GravityScale = fall_gravity_;
	}
	else {
		movement_component_->GravityScale = default_gravity_;
	}
}

AActor* APlayerCharacter::Raycast() {
	FMinimalViewInfo camera_view_info;
	camera_component_->GetCameraView(1.0f, camera_view_info);
	FVector camera_location = camera_view_info.Location;
	FRotator camera_rotation = camera_view_info.Rotation;

	FVector start = camera_location;
	FVector end = (camera_rotation.Vector() * reach_range_) + start;
	FHitResult Hit;
	DrawDebugLine(GetWorld(), start, end, FColor(255, 0, 0, 0), false, 0.1f, 0, 2.0f);
	
	GetWorld()->LineTraceSingleByChannel(Hit, start, end, ECollisionChannel::ECC_GameTraceChannel1);
	return Hit.GetActor();
}

void APlayerCharacter::InteractWithObject()
{
	if (interactable_object_)
	{
		PickUpObject();
	}
}

void APlayerCharacter::PickUpObject()
{
	if (!held_item_)
	{
		held_item_ = interactable_object_;
		held_item_->SetActorLocation(held_item_pos_->GetComponentLocation());
	}
}

void APlayerCharacter::ActivateObject()
{
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &APlayerCharacter::StartRun);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &APlayerCharacter::StopRun);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::InteractWithObject);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseX", this, &APlayerCharacter::AddYawInput);
	PlayerInputComponent->BindAxis("MouseY", this, &APlayerCharacter::AddPitchInput);
}

