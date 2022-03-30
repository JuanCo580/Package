// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterTest.h"

#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values
ACharacterTest::ACharacterTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterTest::BeginPlay()
{
	Super::BeginPlay();

	initialRotation = GetActorRotation();
	
}

// Called every frame
void ACharacterTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (fuel <= 0)
	{
		Destroy();
	}

	if (upPressed)
	{
		fuel -= 0.2;

		//float deltaTime = GetWorld()->GetDeltaSeconds();
		AddActorLocalOffset(FVector(0, 0, velocity += 0.3));


	}


}

// Called to bind functionality to input
void ACharacterTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Up", IE_Pressed, this, &ACharacterTest::UpPressed);
	InputComponent->BindAction("Up", IE_Released, this, &ACharacterTest::UpReleased);
	//InputComponent->BindAxis("Vertical", this, &AMyPlayer::VerticalAxis);
	InputComponent->BindAxis("Horizontal", this, &ACharacterTest::HorizontalAxis);

}

/*void AMyPlayer::Up()
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(FVector(0, 0, velocity*deltaTime));
}*/

void ACharacterTest::UpPressed()
{
	upPressed = true;

}

void ACharacterTest::UpReleased()
{
	upPressed = false;
}

/*void AMyPlayer::VerticalAxis(float value)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(FRotator(value * rotationVelocity * deltaTime, 0, 0));
}*/

void ACharacterTest::HorizontalAxis(float value)
{
	//float deltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(FRotator(0, 0, value * rotationVelocity));
}

