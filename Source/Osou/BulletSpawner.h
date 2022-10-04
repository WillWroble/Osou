// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include <algorithm>
#include "SpawnPoint.h"
#include "MovingBorder.h"
#include "TimeFrame.h"
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
	std::vector<TimeFrame> spawnTable;
	std::vector<BorderInstruction> borderInstructions;

	//spawn time data
	//std::vector<float> spawnTimes;
	std::vector<float> spawnTimesBorders;

	//building functions
	void AddRythm(std::vector<float> beat, int quanity, float offset);
	void SortSpawnTimes();
	void ClearSlot(int index);
	void ClearSlots(int timeSignature, int offSet, int count = 9999);
	void AddSpawnPoint(float x, float y, std::vector<float> angles, int index, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddSpawnPointByTime(float x, float y, std::vector<float> angles, float time, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void AddInstruction(int type, float x, float y, float duration);
	void AddSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddTargetingSpawnPoint(float x, float y, std::vector<float> angles, int index, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddTargetingSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddDynamicSpawnPoint(float x, float y, std::vector<float> angles, int index, int timeSignature, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddDynamicSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddTargetingDynamicSpawnPoint(float x, float y, std::vector<float> angles, int index, int timeSignature, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void AddTargetingDynamicSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void AddCorners(std::vector<float> angles, int timeSignature, int offset, BulletType Btype = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddCorner(std::vector<float> angles, int offset, BulletType Btype = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void AddMultipleSpawnPoints(std::vector<float> xs, std::vector<float> ys, std::vector<float> angles, int index, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddMultipleLayersOfSpawnPoints(std::vector<float> xs, std::vector<float> ys, std::vector<float> angles, int timeSignature, int offset, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddHorizontalWallOfSpawnPoints(int width, int x, int y, std::vector<float> angles, int spacing, int index, BulletType Btype = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddHorizontalWallOfSpawnPointsByTime(int width, int x, int y, std::vector<float> angles, int spacing, float time, BulletType Btype = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void AddVerticalWallOfSpawnPoints(int height, int x, int y, std::vector<float> angles, int spacing, int index, BulletType Btype = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void AddLayersOfHorizontalSpawnPoints(int width, int x, int y, std::vector<float> angles, int spacing, int timeSignature, int offset, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void AddLayersOfVerticalSpawnPoints(int height, int x, int y, std::vector<float> angles, int spacing, int timeSignature, int offset, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void SpawnBetweenTwoPoints(FVector2D p1, FVector2D p2, int spacing, int index, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void SpawnTriangleBlob(int x, int y, float angle, float spacing, int count, int index, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = { 700, 1 });
	void AddProjectionFromPoint(FVector2D p, FVector2D l1, FVector2D l2, int spacing, int index, BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddMovingSpawnPointByEquation(int spacing, int index, int timeSignature, float (*xfunc)(float), float (*yfunc)(float), float (*afunc)(float), BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	void AddSpawnPointByEquation(int spacing, int index, float (*xfunc)(float), float (*yfunc)(float), float (*afunc)(float), BulletType bType = BulletType::BasicBullet, std::vector<float> bCoeff = {700, 1});
	

};
