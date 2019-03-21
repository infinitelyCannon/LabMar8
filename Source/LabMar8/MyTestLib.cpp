// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestLib.h"

FVector UMyTestLib::Slerp(FVector start, FVector end, float alpha)
{
	float dot = FVector::DotProduct(start, end);

	FMath::Clamp<float>(dot, -1.0f, 1.0f);

	float theta = FMath::Acos(dot) * alpha;
	FVector relativeVec = end - start * dot;
	relativeVec.Normalize();

	return ((start * FMath::Cos(theta)) + (relativeVec * FMath::Sin(theta)));
}
