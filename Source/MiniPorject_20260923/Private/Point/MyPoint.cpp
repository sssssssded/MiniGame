// Fill out your copyright notice in the Description page of Project Settings.


#include "Point/MyPoint.h"

// Sets default values
AMyPoint::AMyPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

