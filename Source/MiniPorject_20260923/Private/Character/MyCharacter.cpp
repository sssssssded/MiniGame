// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MyCharacter.h"
#include "Animation/MyPlayerAnimInstance.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	mArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	mArm->SetupAttachment(GetMesh());
	mCamera->SetupAttachment(mArm);
	mArm->TargetArmLength = 500.f;

	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	

	static ConstructorHelpers::FClassFinder<UAnimInstance>
		PlayerAnim(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/Character/Player/Animation/ABP_Player.ABP_Player_C'"));

	if (PlayerAnim.Succeeded())
		GetMesh()->SetAnimInstanceClass(PlayerAnim.Class);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	TObjectPtr<APlayerController> PlayerController =
		Cast<APlayerController>(GetController());
	if (IsValid(PlayerController))
	{
		// PlayerController가 가지고 있는 InputSystem을 얻어온다.
		TObjectPtr<UEnhancedInputLocalPlayerSubsystem>	InputSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

		// InputMappingContext를 가지고 있는 CDO를 얻어온다.
		const UInput* InputCDO = GetDefault<UInput>();

		// InputMappingContext를 InputSystem에 등록한다.
		InputSystem->AddMappingContext(InputCDO->mContext, 0);
	}

	mAnimInst = Cast<UMyPlayerAnimInstance>(GetMesh()->GetAnimInstance());

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	TObjectPtr<UEnhancedInputComponent>	Input =
		Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (IsValid(Input))
	{
		const UInput* InputCDO = GetDefault<UInput>();

		Input->BindAction(InputCDO->FindAction(TEXT("Move")),
			ETriggerEvent::Triggered, this, &AMyCharacter::Move);

		Input->BindAction(InputCDO->FindAction(TEXT("Jump")),
			ETriggerEvent::Completed, this, &AMyCharacter::PlayerJump);
	}

}

void AMyCharacter::Move(const FInputActionValue& Value)
{
	FVector2D	MoveVec = Value.Get<FVector2D>();

	UE_LOG(ShimDebug, Warning, TEXT("엑스축 %f"), MoveVec.X);
	UE_LOG(ShimDebug, Warning, TEXT("와이축 %f"), MoveVec.Y);

	if (MoveVec.X != 0)
	{
		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		AddMovementInput(Direction, MoveVec.X); // 입력에 따른 방향만 설정
	}

	if (MoveVec.Y != 0)
	{
		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetRightVector(FRotator(0, Rotator.Yaw, 0));
		AddMovementInput(Direction, MoveVec.Y); // 입력에 따른 방향만 설정
	}
}

void AMyCharacter::Attack(const FInputActionValue& Value)
{
}

void AMyCharacter::PlayerJump(const FInputActionValue& Value)
{
	// 점프가 가능한 상태일 경우 점프한다.
	if (CanJump())
		Jump();
}

