// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
// Includes added for the correct operation of the functions
#include "MyPlayer.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AWall::OnOverlap);				//At the start of the game, the dynamics of the overlap begins
	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWall::OnOverlap(AActor* me, AActor* other)							//The overlap function is started
{
	if (AMyPlayer* pb = Cast<AMyPlayer>(other))								//Casting the player
	{
		other->SetActorRotation(FRotator(0, 0,90));							//The player's rotation is located in the starting vector
	}
}

