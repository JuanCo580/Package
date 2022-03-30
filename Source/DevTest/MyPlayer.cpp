// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
// Includes added for the correct operation of the functions
#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	initialRotation = GetActorRotation();											//The previously created variable gets the player's initial rotation
	initialPosition = GetActorLocation();											//The previously created variable gets the initial position of the player
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (fuel <= 0)																	//An "if" is created to detect if the ship's fuel is equal or less than 0, so the player will restart and a main life will be deducted.
	{
		RestartPlayer();															//Call the function "RestartPlayer()"
	}

	if (upPressed==true)															//An "if" is created that is activated when the space bar is pressed
	{
		fuel-=0.3;																	//When pressurized, the fuel is reduced by -0.2 of its initial value constantly until it is no longer pressurized
		AddActorLocalOffset(FVector(0, 0, velocity+=0.3));							//When pressurized, the initial velocity increases by 0.3 of its initial value
	}

	if (life <= 0)																	//An "if" is created to detect if the ship's fuel is equal or less than 0, so the player will restart and a main life will be deducted.
	{
		RestartPlayer();															//Call the function "RestartPlayer()"
	}
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Up", IE_Pressed, this, &AMyPlayer::UpPressed);		//Detects when the space bar is pressed
	InputComponent->BindAction("Up", IE_Released, this, &AMyPlayer::UpReleased);	//Detects when the space bar is released
	InputComponent->BindAxis("Horizontal", this, &AMyPlayer::HorizontalAxis);		//Detects the horizontal movement that is exerted when the mouse is moved
}


void AMyPlayer::UpPressed()															//"UpPressed()" event is called
{
	upPressed = true;																//When the space bar is pressed, the variable becomes "true"
}


void AMyPlayer::UpReleased()														//"UpReleased()" event is called
{
	upPressed = false;																// When the space bar is released, the variable becomes "false"
}


void AMyPlayer::HorizontalAxis(float value)											//Directional function with respect to the player's address
{
	AddActorLocalRotation(FRotator(0,0, value * rotationVelocity));				//When the player moves the mouse, it rotates on the required axis.
}


void AMyPlayer::RestartPlayer()														//The function "RestartPlayer()" is called, it contains the base data for the player	
{
	SetActorRotation(initialRotation);
	SetActorLocation(initialPosition);
	lifeCount -= 1;
	life = 100;
	fuel = 100;
}



