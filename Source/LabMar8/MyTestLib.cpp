// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestLib.h"

FVector UMyTestLib::RotateAroundTarget(
	FVector target,
	FVector axis,
	float time,
	float radius,
	float speed,
	float perpendicularOffset,
	float radialOffset,
	float minRadius,
	float maxRadius,
	bool clampMovement)
{
	float rVelocity = radialOffset * time;
	FVector dVelocity = axis;
	dVelocity.Normalize();

	if (((radius + rVelocity) <= minRadius || (radius + rVelocity) >= maxRadius) && clampMovement)
		dVelocity = dVelocity * perpendicularOffset * getTravelTime(radius, radialOffset, (radialOffset < 0.0f ? minRadius : maxRadius));
	else
		dVelocity = dVelocity * perpendicularOffset * time;

	FVector dimensions = FVector(clampMovement ? FMath::Clamp(radius + rVelocity, minRadius, maxRadius) : (radius + rVelocity), 0.0f, 0.0f);

	FVector axisVector = axis;
	if (axisVector.Size() != 1.0f)
		axisVector.Normalize();

	FVector RotatedVec = dimensions.RotateAngleAxis(time * speed, axisVector);

	return target + RotatedVec + dVelocity;
}

float UMyTestLib::getTravelTime(float initial, float velocity, float destination)
{
	return FMath::Abs((destination - initial) / velocity);
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


	return FVector(0, 0, 0);//RotateAroundTarget(midPoint, axis, angle, distance, speed);
}
