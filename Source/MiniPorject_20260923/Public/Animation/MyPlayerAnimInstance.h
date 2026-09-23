// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../GameInfo.h"
#include "Animation/AnimInstance.h"
#include "MyPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MINIPORJECT_20260923_API UMyPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UMyPlayerAnimInstance();
	
public:
	virtual void NativeInitializeAnimation();
	virtual void NativeBeginPlay();
	virtual void NativeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float	mGroundSpeed = 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool	mAccelerating = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool	mAir = false;
};
