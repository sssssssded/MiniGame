// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "UIInfo.h"
#include "Blueprint/UserWidget.h"
#include "pointWidget.generated.h"

/**
 * 
 */
UCLASS()
class MINIPORJECT_20260923_API UpointWidget : public UBaseWidget
{
	GENERATED_BODY()

public:
	UpointWidget(const FObjectInitializer& ObjectInitializer);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock>	mName;

protected:
	virtual void NativeOnInitialized();

public:
	void SetInfoName(const FString& Name);
};
