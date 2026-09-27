#include "GameInfo.h"

// 로그 정의
DEFINE_LOG_CATEGORY(ShimDebug);

FRotator GetTargetRotation(const FVector& Target,
	const FVector& Self)
{
	return UKismetMathLibrary::FindLookAtRotation(Self, Target);
}