// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBPLib.generated.h"

/**
 * 
 */
UCLASS()
class LABMAR8_API UMyBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintPure)
		static FString MakeIntense(FString myWords, int32 &length, FVector &scale, FRotator rotation);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "RefObj"))
		static void Shotz(
			TSubclassOf<AActor> Projectile,
			FVector Location,
			FRotator Rotation,
			UObject *RefObj);
};
