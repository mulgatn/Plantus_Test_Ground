// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class MYPROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Player Control")
	float walk_speed_;

	UPROPERTY(EditAnywhere, Category = "Player Control")
	float run_speed_;

	UPROPERTY(EditAnywhere, Category = "Player Control")
	float speed_multiplier_;

	UPROPERTY(EditAnywhere, Category = "Player Control")
	bool b_can_run_;

	UPROPERTY(EditAnywhere, Category = "Player Control")
	float mouse_sensitivity_;

	UPROPERTY(EditAnywhere, Category = "Player Control")
	float fall_gravity_;

	UPROPERTY(EditAnywhere, Category = "Player Control")
	float default_gravity_;

	UPROPERTY(EditAnywhere, Category = "Player Control")
	float reach_range_;

	UPROPERTY(EditAnywhere, Category = "Player Control")
	FVector2D camera_rotation_Y_limit_;

	UPROPERTY()
	UCameraComponent* camera_component_ = nullptr;

	UPROPERTY()
	UCharacterMovementComponent* movement_component_ = nullptr;

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void MoveForward(float value);
	UFUNCTION()
	void MoveRight(float value);
	UFUNCTION()
	void AddYawInput(float value);
	UFUNCTION()
	void AddPitchInput(float value);
	UFUNCTION()
	void StartRun();
	UFUNCTION()
	void StopRun();
	UFUNCTION()
	void SetGravity();
	UFUNCTION()
	AActor* Raycast();
};
