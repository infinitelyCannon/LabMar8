// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestLib.h"

FVector UMyTestLib::Slerp(
	FVector target,
	FVector axis,
	float initialAngle,
	float time,
	float radius,
	float speed,
	float perpendicularOffset,
	float radialOffset,
	float minRadius,
	float maxRadius,
	bool clampMovement,
	float &angle)
{
	float rVelocity = radialOffset * time;
	float startAngle = FMath::Fmod(initialAngle, 360.0f);
	FVector dVelocity = axis;
	dVelocity.Normalize();

	if (((radius + rVelocity) <= minRadius || (radius + rVelocity) >= maxRadius) && clampMovement)
		dVelocity = dVelocity * perpendicularOffset * getTravelTime(radius, radialOffset, (radialOffset < 0.0f ? minRadius : maxRadius));
	else
		dVelocity = dVelocity * perpendicularOffset * time;

	FVector dimensions = FVector(0.0f, clampMovement ? FMath::Clamp(radius + rVelocity, minRadius, maxRadius) : (radius + rVelocity), 0.0f).RotateAngleAxis(startAngle, axis);

	FVector axisVector = axis;
	if (axisVector.Size() != 1.0f)
		axisVector.Normalize();

	FVector RotatedVec = dimensions.RotateAngleAxis(time * speed, axisVector);
	angle = FMath::Fmod(speed * time, 360.0f);

	return target + RotatedVec + dVelocity;
}

float UMyTestLib::getTravelTime(float initial, float velocity, float destination)
{
	return FMath::Abs((destination - initial) / velocity);
}
