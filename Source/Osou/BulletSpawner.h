// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "SpawnPoint.h"
#include "MovingBorder.h"
#include "CoreMinimal.h"

/**
 * 
 */
class OSOU_API BulletSpawner
{
public:
	BulletSpawner();
	~BulletSpawner();

	//spawn transform data
	std::vector<std::vector<SpawnPoint>> spawnTable;
	std::vector<BorderInstruction> borderInstructions;

	//spawn time data
	std::vector<float> spawnTimes;
	std::vector<float> spawnTimesBorders;

	//building functions
	void AddRythm(std::vector<float> beat, int quanity, float offset);
	void AddSpawnPoint(float x, float y, std::vector<float> angles, int index);
	void AddInstruction(int type, float x, float y, float duration);
	void AddSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset);
	void AddTargetingSpawnPoint(float x, float y, std::vector<float> angles, int index);
	void AddTargetingSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset);
	void AddCorners(std::vector<float> angles, int timeSignature, int offset);
	void AddMultipleSpawnPoints(std::vector<float> xs, std::vector<float> ys, std::vector<float> angles, int index);
	void AddMultipleLayersOfSpawnPoints(std::vector<float> xs, std::vector<float> ys, std::vector<float> angles, int timeSignature, int offset);
	void AddHorizontalWallOfSpawnPoints(int width, int x, int y, std::vector<float> angles, int spacing, int index);
	void AddLayersOfHorizontalSpawnPoints(int width, int x, int y, std::vector<float> angles, int spacing, int timeSignature, int offset);
	

};
