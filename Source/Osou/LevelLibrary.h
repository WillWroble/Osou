// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BulletSpawner.h"
#include "EquationLibrary.h"
#include <vector>
#include "CoreMinimal.h"

/**
 * 
 */
class OSOU_API LevelLibrary
{
public:
	static std::vector<std::vector<BulletSpawner>> allLevels;
	static void BuildLevels();
	LevelLibrary();
	~LevelLibrary();
};
