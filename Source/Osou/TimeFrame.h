// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnPoint.h"
#include <vector>

/**
 * 
 */
class OSOU_API TimeFrame
{
public:
	TimeFrame();
	~TimeFrame();
	float time;
	std::vector<SpawnPoint> spawnMap;
};
