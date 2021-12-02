// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletSpawner.h"


BulletSpawner::BulletSpawner()
{
}
BulletSpawner::~BulletSpawner()
{
}

void BulletSpawner::AddRythm(std::vector<float> beat, int quanity, float offset)
{
	float timeStamp = offset;
	for (int i = 0; i < quanity; i++) {
		
		for (int j = 0; j < beat.size(); j++) {
			timeStamp += beat[j];
			spawnTimes.push_back(timeStamp);
			//add empty vector
			std::vector<SpawnPoint> spawns;
			spawnTable.push_back(spawns);
		}
	}
}

void BulletSpawner::AddSpawnPoint(float x, float y, std::vector<float> angles, int index)
{
	if (index >= spawnTable.size()) {
		//index out of range
		return;
	}
	SpawnPoint p(x, y, angles);
	spawnTable[index].push_back(p);
}

void BulletSpawner::AddInstruction(int type, float x, float y, float duration)
{
	BorderInstruction newInstruction;
	newInstruction.duration = duration;
	newInstruction.x = x;
	newInstruction.y = y;
	newInstruction.type = type;
	borderInstructions.push_back(newInstruction);
}
void BulletSpawner::AddSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset)
{
	for (int i = offset; i < spawnTable.size(); i+= timeSignature) {
		AddSpawnPoint(x, y, angles, i);
	}
}

void BulletSpawner::AddTargetingSpawnPoint(float x, float y, std::vector<float> angles, int index)
{
	if (index >= spawnTable.size()) {
		//index out of range
		return;
	}
	SpawnPoint p(x, y, angles);
	p.isAngleRelative = true;
	spawnTable[index].push_back(p);
}

void BulletSpawner::AddTargetingSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset)
{
	for (int i = offset; i < spawnTable.size(); i += timeSignature) {
		AddTargetingSpawnPoint(x, y, angles, i);
	}
}

void BulletSpawner::AddCorners(std::vector<float> angles, int timeSignature, int offset)
{
	int angleMap[4] = { 0, 90, -90, 180 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::vector<float> newAngles;
			for (int k = 0; k < angles.size(); k++) {
				newAngles.push_back(angles[k] + angleMap[2*i +j]);
			}
			AddSpawnPoints(4500 * (j - 0.5), 2530 * (i - 0.5), newAngles, timeSignature, offset);
		}
	}
}

void BulletSpawner::AddMultipleSpawnPoints(std::vector<float> xs, std::vector<float> ys, std::vector<float> angles, int index)
{
	for (int i = 0; i < xs.size(); i++) {
		AddSpawnPoint(xs[i], ys[i], angles, index);
	}
}

void BulletSpawner::AddMultipleLayersOfSpawnPoints(std::vector<float> xs, std::vector<float> ys, std::vector<float> angles, int timeSignature, int offset)
{
	for (int i = offset; i < spawnTable.size(); i += timeSignature) {
		AddMultipleSpawnPoints(xs, ys, angles, i);
	}
}

void BulletSpawner::AddHorizontalWallOfSpawnPoints(int width, int x, int y, std::vector<float> angles, int spacing, int index)
{
	for (int i = x; i < width + x; i += spacing) {
		AddSpawnPoint(i, y, angles, index);
	}
}

void BulletSpawner::AddLayersOfHorizontalSpawnPoints(int width, int x, int y, std::vector<float> angles, int spacing, int timeSignature, int offset)
{
	for (int i = offset; i < spawnTable.size(); i += timeSignature) {
		AddHorizontalWallOfSpawnPoints(width, x, y, angles, spacing, i);
	}
}
