// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestLib.h"

FVector UMyTestLib::Slerp(FVector start, FVector end, float alpha)
{
	float dot = FVector::DotProduct(start, end);

	dot = FMath::Clamp<float>(dot, -1.0f, 1.0f);

	float theta = FMath::Acos(dot) * alpha;
	FVector relativeVec = end - start * dot;
	relativeVec.Normalize(1.0f);

	return ((start * FMath::Cos(theta)) + (relativeVec * FMath::Sin(theta)));
}

FVector UMyTestLib::RotateAroundTarget(FVector target, FVector axis, float angle, float radius, float speed)
{
	FVector dimensions = FVector(radius, 0.0f, 0.0f);
	float theta = FMath::Clamp<float>(angle, 0.0f, 360.0f);
	FVector axisVector = axis;
	if (axisVector.Size() != 1.0f)
		axisVector.Normalize();

	FVector RotatedVec = dimensions.RotateAngleAxis(theta, axisVector);

	return target + RotatedVec;
}
