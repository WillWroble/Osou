// Fill out your copyright notice in the Description page of Project Settings.


#include "EquationLibrary.h"

EquationLibrary::EquationLibrary()
{
}

EquationLibrary::~EquationLibrary()
{
}

float EquationLibrary::xDelta(float i, float t)
{
	if (i == 0) {
		return bxcurve1(t);
	}
	else if (i == 1) {
		return bxcurve2(t);
	}
	else if (i == 2) {
		return bxcurve3(t);
	}
	else if (i == 3) {
		return bxcurve4(t);
	}
	return 0;
}

float EquationLibrary::yDelta(float i, float t)
{
	if (i == 0) {
		return bycurve1(t);
	}
	else if (i == 1) {
		return bycurve2(t);
	}
	else if (i == 2) {
		return bycurve3(t);
	}
	else if (i == 3) {
		return bycurve4(t);
	}
	return 0;
}

float EquationLibrary::aDelta(float i, float t)
{
	if (i == 0) {
		return bacurve1(t);
	}
	else if (i == 1) {
		return bacurve2(t);
	}
	else if (i == 2) {
		return bacurve3(t);
	}
	else if (i == 3) {
		return bacurve4(t);
	}
	return 0;
}

float EquationLibrary::getFixedCoordinate(float a, float b)
{
	
	return sqrtf(powf(a, 2) + pow(b, 2));
		
}

float EquationLibrary::bxcurve1(float t)
{
	return 1;
}

float EquationLibrary::bycurve1(float t)
{
	return 0;
}

float EquationLibrary::bacurve1(float t)
{
	return 0.03;
}

float EquationLibrary::xcircle(float t)
{
	return cosf(t * 2 * PI) * 2200;
}

float EquationLibrary::ycircle(float t)
{
	return sinf(t * 2 * PI) * 2200;
}

float EquationLibrary::acircle(float t)
{
	return (t * 360) + 180;
}
