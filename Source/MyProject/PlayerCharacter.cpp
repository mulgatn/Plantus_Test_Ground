// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

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
	camera_rotation_Y_limit_ = FVector2D(70.0f, -85.0f);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	camera_component_ = FindComponentByClass<UCameraComponent>();
	if (camera_component_ != nullptr) {

	}
	movement_component_ = GetCharacterMovement();
	movement_component_->MaxWalkSpeed = walk_speed_ * speed_multiplier_;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &APlayerCharacter::StartRun);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &APlayerCharacter::StopRun);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseX", this, &APlayerCharacter::AddYawInput);
	PlayerInputComponent->BindAxis("MouseY", this, &APlayerCharacter::AddPitchInput);
}

