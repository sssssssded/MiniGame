// Fill out your copyright notice in the Description page of Project Settings.


#include "Point/MyPoint.h"
#include "UI/pointWidget.h"
#include "WidgetComponent/MyWidgetComponent.h"

// Sets default values
AMyPoint::AMyPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	SpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	pointWidgetComponent = CreateDefaultSubobject<UMyWidgetComponent>(TEXT("Widget"));

	SpawnPoint->SetupAttachment(RootComponent);


	static ConstructorHelpers::FClassFinder<UUserWidget>
		nameWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Point/WBP_Point.WBP_Point_C'"));

	if (nameWidgetClass.Succeeded())
	{
		pointWidgetComponent->SetWidgetClass(nameWidgetClass.Class);
	}

	pointWidgetComponent->SetWidgetSpace(EWidgetSpace::World);
	pointWidgetComponent->SetDrawSize(FVector2D(200.0, 80.0));
	pointWidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	pointWidgetComponent->SetTwoSided(true);
}

// Called when the game starts or when spawned
void AMyPoint::BeginPlay()
{
	Super::BeginPlay();
	
	pointWidget = Cast<UpointWidget>(pointWidgetComponent->GetWidget());

	pointWidget->SetInfoName("시작점");

}

// Called every frame
void AMyPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

