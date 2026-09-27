// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/pointWidget.h"

UpointWidget::UpointWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UpointWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//mName = "시작점";

}

void UpointWidget::SetInfoName(const FString& Name)
{
	mName->SetText(FText::FromString(Name));
}
