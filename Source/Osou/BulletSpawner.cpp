// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletSpawner.h"


BulletSpawner::BulletSpawner()
{
}
BulletSpawner::~BulletSpawner()
{
}
bool FrameCompare(TimeFrame a, TimeFrame b) {
	return a.time < b.time;
}

void BulletSpawner::AddRythm(std::vector<float> beat, int quanity, float offset)
{
	float timeStamp = offset;
	for (int i = 0; i < quanity; i++) {
		
		for (int j = 0; j < beat.size(); j++) {
			timeStamp += beat[j];
			//spawnTimes.push_back(timeStamp);
			TimeFrame timeframe = TimeFrame();
			timeframe.time = timeStamp;
			//add empty vector
			//std::vector<SpawnPoint> spawns;
			spawnTable.push_back(timeframe);
		}
	}
}

void BulletSpawner::SortSpawnTimes()
{
	std::sort(spawnTable.begin(), spawnTable.end(), FrameCompare);
}

void BulletSpawner::AddSpawnPoint(float x, float y, std::vector<float> angles, int index, BulletType bType, std::vector<float> bCoeff)
{
	if (index >= spawnTable.size()) {
		//index out of range
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (index));
		if(index < 64)
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, *(FString::FromInt(index)));
		
		return;
	}
	SpawnPoint p(x, y, angles, bType, bCoeff);
	spawnTable[index].spawnMap.push_back(p);
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
void BulletSpawner::AddSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = offset; i < spawnTable.size(); i+= timeSignature) {
		AddSpawnPoint(x, y, angles, i, bType, bCoeff);
	}
}

void BulletSpawner::AddTargetingSpawnPoint(float x, float y, std::vector<float> angles, int index, BulletType bType, std::vector<float> bCoeff)
{
	if (index >= spawnTable.size()) {
		//index out of range
		return;
	}
	SpawnPoint p(x, y, angles, bType, bCoeff);
	p.isAngleRelative = true;
	spawnTable[index].spawnMap.push_back(p);
}

void BulletSpawner::AddTargetingSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = offset; i < spawnTable.size(); i += timeSignature) {
		AddTargetingSpawnPoint(x, y, angles, i, bType, bCoeff);
	}
}

void BulletSpawner::AddDynamicSpawnPoint(float x, float y, std::vector<float> angles, int index, int timeSignature, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = 0; i < angles.size(); i++) {
		AddSpawnPoint(x, y, { angles[i] }, index + timeSignature*i, bType, bCoeff);
	}
}

void BulletSpawner::AddDynamicSpawnPoints(float x, float y, std::vector<float> angles, int timeSignature, int offset, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = offset; i*angles.size()*timeSignature < spawnTable.size(); i += timeSignature) {
		AddDynamicSpawnPoint(x, y, angles, i*angles.size()*timeSignature, timeSignature, bType, bCoeff);
	}
}

void BulletSpawner::AddCorners(std::vector<float> angles, int timeSignature, int offset, BulletType bType, std::vector<float> bCoeff)
{
	int angleMap[4] = { 0, 90, -90, 180 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::vector<float> newAngles;
			for (int k = 0; k < angles.size(); k++) {
				newAngles.push_back((180*j) + (1 - (2*j))*angles[k] + (180*i));
			}
			std::vector<float> t = std::vector<float>(bCoeff);
			if (bType == BulletType::CurvedBullet && bCoeff.size() >= 4 && j) {
				t[3] *= -1;
			}
			AddSpawnPoints(4500 * (1 - 2*i) * (j - 0.5), 2530 * (i - 0.5), newAngles, timeSignature, offset, bType, t);
		}
	}
}

void BulletSpawner::AddMultipleSpawnPoints(std::vector<float> xs, std::vector<float> ys, std::vector<float> angles, int index, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = 0; i < xs.size(); i++) {
		AddSpawnPoint(xs[i], ys[i], angles, index, bType, bCoeff);
	}
}

void BulletSpawner::AddMultipleLayersOfSpawnPoints(std::vector<float> xs, std::vector<float> ys, std::vector<float> angles, int timeSignature, int offset, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = offset; i < spawnTable.size(); i += timeSignature) {
		AddMultipleSpawnPoints(xs, ys, angles, i, bType, bCoeff);
	}
}

void BulletSpawner::AddHorizontalWallOfSpawnPoints(int width, int x, int y, std::vector<float> angles, int spacing, int index, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = x; i < width + x; i += spacing) {
		AddSpawnPoint(i, y, angles, index, bType, bCoeff);
	}
}

void BulletSpawner::AddVerticalWallOfSpawnPoints(int height, int x, int y, std::vector<float> angles, int spacing, int index, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = y; i < height + y; i += spacing) {
		AddSpawnPoint(x, i, angles, index, bType, bCoeff);
	}
}

void BulletSpawner::AddLayersOfHorizontalSpawnPoints(int width, int x, int y, std::vector<float> angles, int spacing, int timeSignature, int offset, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = offset; i < spawnTable.size(); i += timeSignature) {
		AddHorizontalWallOfSpawnPoints(width, x, y, angles, spacing, i, bType, bCoeff);
	}
}

void BulletSpawner::AddLayersOfVerticalSpawnPoints(int height, int x, int y, std::vector<float> angles, int spacing, int timeSignature, int offset, BulletType bType, std::vector<float> bCoeff)
{
	for (int i = offset; i < spawnTable.size(); i += timeSignature) {
		AddVerticalWallOfSpawnPoints(height, x, y, angles, spacing, i, bType, bCoeff);
	}
}

void BulletSpawner::SpawnBetweenTwoPoints(FVector2D p1, FVector2D p2, int spacing, int index, BulletType bType, std::vector<float> bCoeff)
{
	FVector2D delta = p2 - p1;
	float z = delta.SizeSquared();
	//float d1 = sqrtf(y - (powf((z + y - x), 2) / (4 * z)));
	for (int i = 0; i < spacing; i++) {
		float scale = ((float)i) / ((float)spacing);
		FVector2D sD = delta * scale; //scaled delta
		FVector2D spawn = p1 + sD;
		float a = atan2f(delta.Y, delta.X) * (180 / PI);
		a -= 90;
		//float s = bCoeff[0] * ray.Size() / d1;
		//std::vector<float> tempCoeff = std::vector<float>(bCoeff);
		//tempCoeff[0] = s;
		AddSpawnPoint(spawn.X, spawn.Y, { a }, index, bType, bCoeff);
	}
}

void BulletSpawner::AddProjectionFromPoint(FVector2D p, FVector2D l1, FVector2D l2, int spacing, int index, BulletType bType, std::vector<float> bCoeff)
{
	FVector2D delta = l2 - l1;
	float x = (l1 - p).SizeSquared();
	float y = (l2 - p).SizeSquared();
	float z = delta.SizeSquared();
	float d1 = sqrtf(y - (powf((z + y - x), 2) / (4 * z)));
	for (int i = 0; i < spacing; i++) {
		float scale = ((float)i) / ((float)spacing);
		FVector2D sD = delta * scale; //scaled delta
		FVector2D p2 = l1 + sD;
		FVector2D ray = p2 - p;
		float a = atan2f(ray.Y, ray.X) * (180/PI);
		float s = bCoeff[0]*ray.Size()/d1;
		std::vector<float> tempCoeff = std::vector<float>(bCoeff);
		tempCoeff[0] = s;
		AddSpawnPoint(p.X, p.Y, { a }, index, bType, tempCoeff);
	}
}

void BulletSpawner::AddMovingSpawnPointByEquation(int spacing, int index, int timeSignature, float(*xfunc)(float), float(*yfunc)(float), float(*afunc)(float), BulletType bType, std::vector<float> bCoeff)
{
	for (int i = 0; i < spacing; i++) {
		float progress = (float)i / (float)spacing;
		AddSpawnPoint(xfunc(progress), yfunc(progress), { afunc(progress) }, index + (i*timeSignature), bType, bCoeff);
	}
}

void BulletSpawner::AddSpawnPointByEquation(int spacing, int index, float(*xfunc)(float), float(*yfunc)(float), float(*afunc)(float), BulletType bType, std::vector<float> bCoeff)
{
	for (int i = 0; i < spacing; i++) {
		float progress = (float)i / (float)spacing;
		AddSpawnPoint(xfunc(progress), yfunc(progress), { afunc(progress) }, index, bType, bCoeff);
	}
}

