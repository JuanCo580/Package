// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTest.generated.h"

UCLASS()
class DEVTEST_API ACharacterTest : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY()
		bool upPressed;						//Creacion de la variable buleana upPressed.

	UPROPERTY()
		float velocity = 5;					//Creacion de la variable flotante velocity con un valor de 5, esta tiene la intencion de ser la variable medible de nuestro desplazamiento.

	UPROPERTY()
		float rotationVelocity = 50;		//Creacion de la variable flotante rotationVelocity con un valor de 50, esta tiene la intencion de ser la variable medible de nuestra rotacion.

	UPROPERTY(EditAnywhere)
		float fuel = 100;					//Creacion de la variable flotante fuel con un valor de 100, esta tiene la intencion de ser la variable medible de nuestro combustible.

	UPROPERTY()
		FRotator initialRotation;			//Creacion de la variable de rotacion initialRotation.


	//void Up();
	void UpPressed();
	void UpReleased();
	//void VerticalAxis(float value);
	void HorizontalAxis(float value);


};
