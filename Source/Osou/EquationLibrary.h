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
	//shifting
	static float bxcurve2(float t) { return 1; }
	static float bycurve2(float t) { return 1; }
	static float bacurve2(float t) { return 0; }
	//slowing
	static float bxcurve3(float t) { return powf(1.0f/(t+1), 1); }
	static float bycurve3(float t) { return 0; }
	static float bacurve3(float t) { return 0; }
	//dampended slowing
	static float bxcurve4(float t) { return powf(1.0f / (t + 1), 0.5); }
	static float bycurve4(float t) { return 0; }
	static float bacurve4(float t) { return 0; }
	//swirling
	static float bxcurve5(float t) { return 1; }
	static float bycurve5(float t) { return 0; }
	static float bacurve5(float t) { return 1; }




	static float xDelta(float i, float t);
	static float yDelta(float i, float t);
	static float aDelta(float i, float t);


	static float xcircle(float t);
	static float ycircle(float t);
	static float acircle(float t);
};
