// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalActor.h"
// Includes added for the correct operation of the functions
#include "MyPlayer.h"

// Sets default values
APortalActor::APortalActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APortalActor::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &APortalActor::OnOverlap);								//At the start of the game, the dynamics of the overlap begins
	
}

// Called every frame
void APortalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortalActor::OnOverlap(AActor* me, AActor* other)											//The overlap function is started
{
	AMyPlayer* pb = Cast<AMyPlayer>(other);														//Casting the player
	if (pb != nullptr)
	{
		other->SetActorRotation(FRotator(0, 0, 180));											//The player's rotation is located in the vector (0,0,108)
		other->SetActorLocation(FVector(30, 4770, 240));										//The player's location is located in the vector (30,4770,240)
		
	}

}

