// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyTestLib.generated.h"

/**
 * 
 */
UCLASS()
class LABMAR8_API UMyTestLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static float getTravelTime(float initial, float velocity, float destination);
	
	UFUNCTION(BlueprintPure)
	static FVector Slerp(FVector start, FVector end, FVector axis, float speed, float alpha);

	UFUNCTION(BlueprintPure)
	static FVector RotateAroundTarget(
		FVector target,
		FVector axis,
		float time,
		float radius,
		float speed,
		float perpendicularOffset,
		float radialOffset,
		float minRadius,
		float maxRadius,
		bool clampMovement);
};
