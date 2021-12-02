// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPoint.h"


SpawnPoint::SpawnPoint(float x, float y, std::vector<float>& a)
{
	X = x; Y = y;
	angles = a;
	isAngleRelative = false;
}

SpawnPoint::~SpawnPoint()
{
}
