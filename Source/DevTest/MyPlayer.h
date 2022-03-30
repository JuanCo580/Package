// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"

UCLASS()
class DEVTEST_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite)
		bool upPressed;								//Creation of the bulean variable "upPressed"

	UPROPERTY()
		float velocity = 3;							//Creation of the floating variable "velocity" with a value of 3, this is intended to be the measurable variable of our displacement
	
	UPROPERTY()
		float rotationVelocity = 30;				//Creation of the floating variable "rotationVelocity" with a value of 30, this is intended to be the measurable variable of our rotation

	UPROPERTY()
		FRotator initialRotation;					//Creation of the rotation variable "initialRotation"

	UPROPERTY()
		FVector initialPosition;					//Creation of the vector variable "initialPosition"

	UPROPERTY(	EditAnywhere, BlueprintReadOnly)
		float life = 100;							//The floating variable "life" is created with a value of 100

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float lifeCount = 3;						//The floating variable "lifeCount" is created with a value of 3

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float fuel = 100;							//Creation of the floating variable "fuel" with a value of 100, this is intended to be the measurable variable of our fuel


	void UpPressed();								//Creation of the definition "UpPressed()", to detect that the space bar was pressed
	void UpReleased();								//Creation of the definition "UpReleased()", to detect that the space bar was released
	void HorizontalAxis(float value);				//Creation of the definition "HorizontalAxis(float value)", to detect the movement of the camera in the "X" axis and thus give direction to the ship
	void RestartPlayer();							//Creation of the "RestartPlayer" definition, this will have the variables that the player must have when respawning
};
