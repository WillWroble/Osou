// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>

/**
 * 
 */
/*
UENUM(BlueprintType)
enum class BulletType : unit8 {
	NormalBullet UMETA(DisplayName="NormalBullet"),
	ExplodingBullet UMETA(DisplayName="ExplodingBullet"),

};
*/

enum BulletType {BasicBullet, ExplodingBullet, CurvedBullet, HexagonBullet, CurvedBulletReg, CurvedGrowingBullet, KnifeBullet, CurvedBulletKnife, KnifeBulletRed, CurvedKnifeRed, BasicFireball, TrackingBullet, GhostBullet, FractureBullet};

class OSOU_API SpawnPoint
{
public:
	SpawnPoint(float x, float y, std::vector<float>& a, BulletType bType, std::vector<float> coeff);
	~SpawnPoint();
	bool isAngleRelative;
	float X;
	float Y;
	float speed;
	float bCoeffecient;
	std::vector<float> coeffecients;
	std::vector<float> angles;
	BulletType bulletType;
};
