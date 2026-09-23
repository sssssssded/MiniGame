// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Input/Input.h"
//#include "../Animation/MyPlayerAnimInstance.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class MINIPORJECT_20260923_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent>	mArm;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent>	mCamera;

	UPROPERTY()
	TObjectPtr<class UMyPlayerAnimInstance>	mAnimInst;

	virtual void Move(const FInputActionValue& Value);
	virtual void Attack(const FInputActionValue& Value);
	virtual void PlayerJump(const FInputActionValue& Value);

};
