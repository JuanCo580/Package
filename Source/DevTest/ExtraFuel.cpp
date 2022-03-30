// Fill out your copyright notice in the Description page of Project Settings.


#include "ExtraFuel.h"
// Includes added for the correct operation of the functions
#include "MyPlayer.h"

// Sets default values
AExtraFuel::AExtraFuel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExtraFuel::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AExtraFuel::OnOverlap);						//At the start of the game, the dynamics of the overlap begins
	
}

// Called every frame
void AExtraFuel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExtraFuel::OnOverlap(AActor* me, AActor* other)									//The overlap function is started
{
	AMyPlayer* pb = Cast<AMyPlayer>(other);												//Casting the player
	if (pb != nullptr)
	{
		pb->fuel += 20;																	//The player recovers 20 fuel
		Destroy();																		//The actor is destroyed
	}
}

