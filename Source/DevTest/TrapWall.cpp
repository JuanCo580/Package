// Fill out your copyright notice in the Description page of Project Settings.


#include "TrapWall.h"
// Includes added for the correct operation of the functions
#include "TimerManager.h"
#include "MyPlayer.h"

// Sets default values
ATrapWall::ATrapWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrapWall::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(timerHandle, this, &ATrapWall::ChangeDirection, changeTime, true);

	OnActorBeginOverlap.AddDynamic(this, &ATrapWall::OnOverlap);
}

void ATrapWall::ChangeDirection()
{
	velocity *= -1;																								//The speed at which the motion loop changes from one side to the other
}

// Called every frame
void ATrapWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector movement(0, 0, 0);																					//The vector variable "movement" is created with the intervals (0,0,0), this variable only works internally
	movement.Z = velocity * DeltaTime;																			//The vector "Z" is used and given a value of movement
	AddActorLocalOffset(movement, true);																		//Modifies the displacement of the "Z" axis and with the "true" it executes it in a loop

}

void ATrapWall::OnOverlap(AActor* me, AActor* other)															//The overlap function is started
{
	AMyPlayer* pb = Cast<AMyPlayer>(other);																		//Casting the player
	if (pb != nullptr)	
	{
		pb->life-= damage;																						//When contact is made with the player, the number of the variable "damage" is subtracted from the variable "life".
	}
}

