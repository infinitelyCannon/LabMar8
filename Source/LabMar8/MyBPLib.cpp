// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBPLib.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

FString UMyBPLib::MakeIntense(FString myWords, int32 &length, FVector &scale, FRotator rotation)
{
	return myWords.ToUpper();
}

void UMyBPLib::Shotz(
	TSubclassOf<AActor> Projectile,
	FVector Location,
	FRotator Rotation,
	UObject *RefObj)
{
	UWorld *myWorld = GEngine->GetWorldFromContextObject(RefObj);
	AActor *MyShot = myWorld->SpawnActor<AActor>(Projectile, Location, Rotation);
}
