// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPoint.h"


SpawnPoint::SpawnPoint(float x, float y, std::vector<float>& a, BulletType bType, std::vector<float> coeff)
{
	X = x; Y = y;
	angles = a;
	isAngleRelative = false;
	bulletType = bType;
	coeffecients = coeff;

}

SpawnPoint::~SpawnPoint()
{
}
