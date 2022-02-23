// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "CoreMinimal.h"

/**
 * 
 */
class OSOU_API EquationLibrary
{
public:
	EquationLibrary();
	~EquationLibrary();
	static float getFixedCoordinate(float a, float b);
	static float bxcurve1(float t);
	static float bycurve1(float t);
	static float bacurve1(float t);

	static float xDelta(float i, float t);
	static float yDelta(float i, float t);
	static float aDelta(float i, float t);


	static float xcircle(float t);
	static float ycircle(float t);
	static float acircle(float t);
};
