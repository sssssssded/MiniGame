// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/Input.h"

///Script/EnhancedInput.InputMappingContext'/Game/Input/NMC_Player.NMC_Player'
///Script/EnhancedInput.InputAction'/Game/Input/IA_Move.IA_Move'
///Script/EnhancedInput.InputAction'/Game/Input/IA_Jump.IA_Jump'
///Script/EnhancedInput.InputAction'/Game/Input/IA_CameraZoom.IA_CameraZoom'
///Script/EnhancedInput.InputAction'/Game/Input/IA_CameraRotation.IA_CameraRotation'
/// 

UInput::UInput()
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext>
		IMC(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/NMC_Player.NMC_Player'"));

	if (IMC.Succeeded())
		mContext = IMC.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction>
		MoveAction(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Move.IA_Move'"));

	if (MoveAction.Succeeded())
		mActions.Add(TEXT("Move"), MoveAction.Object);


	static ConstructorHelpers::FObjectFinder<UInputAction>
		JumpAction(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Jump.IA_Jump'"));

	if (JumpAction.Succeeded())
		mActions.Add(TEXT("Jump"), JumpAction.Object);

}

TObjectPtr<UInputAction> UInput::FindAction(const FString& Name) const
{
	return mActions.FindRef(Name);
}
