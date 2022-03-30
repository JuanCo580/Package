// Fill out your copyright notice in the Description page of Project Settings.


#include "Planet.h"
// Includes added for the correct operation of the functions
#include "MyPlayer.h"
#include "Engine/World.h"


// Sets default values
APlanet::APlanet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &APlanet::OnHit);									//At the start of the game, the dynamics of the overlap begins
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlanet::OnHit(AActor* me, AActor* other)												//The overlap function is started
{
	if (AMyPlayer* pb = Cast<AMyPlayer>(other))												//Casting the player
	{
			other->SetActorRotation(FRotator(0, 0, 270));									//The player's rotation is located in the starting vector
	}
}

