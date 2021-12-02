// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>

/**
 * 
 */
class OSOU_API SpawnPoint
{
public:
	SpawnPoint(float x, float y, std::vector<float>& a);
	~SpawnPoint();
	bool isAngleRelative;
	float X;
	float Y;
	std::vector<float> angles;
};
