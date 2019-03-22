// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestLib.h"

FVector UMyTestLib::RotateAroundTarget(FVector target, FVector axis, float angle, float radius, float speed)
{
	FVector dimensions = FVector(radius, 0.0f, 0.0f);
	//float theta = angle;
	//theta = FMath::Clamp<float>(theta, 0.0f, 360.f);
	FVector axisVector = axis;
	if (axisVector.Size() != 1.0f)
		axisVector.Normalize();

	FVector RotatedVec = dimensions.RotateAngleAxis(angle * speed, axisVector);

	return target + RotatedVec;
}

FVector UMyTestLib::Slerp(FVector start, FVector end, FVector axis, float speed, float alpha)
{
	/*
	a: 0
	b: 1
	c: 0
	d: 180
	float dot = FVector::DotProduct(start, end);

	dot = FMath::Clamp<float>(dot, -1.0f, 1.0f);

	float theta = FMath::Acos(dot) * alpha;
	FVector relativeVec = end - start * dot;
	relativeVec.Normalize(1.0f);

	return ((start * FMath::Cos(theta)) + (relativeVec * FMath::Sin(theta)));
	*/
	//y = (x - a) * ((d - c) / (b - a)) + c
	float angle = alpha * 180.0f;
	float distance = FVector::Dist(start, end) * 0.5f;
	FVector midPoint = (start + end) * 0.5f;


	return RotateAroundTarget(midPoint, axis, angle, distance, speed);
}
