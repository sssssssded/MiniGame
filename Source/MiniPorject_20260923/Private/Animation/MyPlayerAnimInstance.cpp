// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/MyPlayerAnimInstance.h"
#include "Character/MyCharacter.h"

UMyPlayerAnimInstance::UMyPlayerAnimInstance()
{

}

void UMyPlayerAnimInstance::NativeInitializeAnimation()
{
}

void UMyPlayerAnimInstance::NativeBeginPlay()
{
}

void UMyPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{

	AMyCharacter* PlayerChar =
		Cast<AMyCharacter>(TryGetPawnOwner());

	if (IsValid(PlayerChar))
	{
		UCharacterMovementComponent* Movement =
			PlayerChar->GetCharacterMovement();

		// Velocity는 속도벡터이다. 이동속도가 있을 경우 0이 아니게 된다.
		mGroundSpeed = Movement->Velocity.Length();

		// 가속도가 있는지 체크한다.
		float	Acceleration = Movement->GetCurrentAcceleration().Length();

		mAccelerating = Acceleration > 0.f;

		mAir = Movement->IsFalling();
	}
}
