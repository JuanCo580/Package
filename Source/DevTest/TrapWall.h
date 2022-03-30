// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrapWall.generated.h"

UCLASS()
class DEVTEST_API ATrapWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrapWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle timerHandle;
	void ChangeDirection();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	UPROPERTY()
		float velocity = -60;													//The floating variable "velocity" is created with a value of -60

	UPROPERTY()
		float changeTime = 1;													//The floating variable "changeTime" is created with the value of 1

	UPROPERTY(EditAnywhere)
		float damage = 100;														//The floating variable "damage" is created with a value of 100

	UFUNCTION()
		void OnOverlap(AActor* me, AActor* other);								//Creates an overlap function which detects the player

};
