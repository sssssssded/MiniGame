// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "Components/WidgetComponent.h"
#include "MyWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class MINIPORJECT_20260923_API UMyWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	UMyWidgetComponent(const FObjectInitializer& PCIP);

public:
	virtual void TickComponent(float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

};
