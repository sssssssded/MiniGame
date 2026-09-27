#pragma once

#include "EngineMinimal.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"


#include "Components/WidgetComponent.h"

// 로그 카테고리 선언.
DECLARE_LOG_CATEGORY_EXTERN(ShimDebug, Warning, All);

FRotator GetTargetRotation(const FVector& Target, const FVector& Self);