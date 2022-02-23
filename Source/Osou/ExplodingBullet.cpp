// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplodingBullet.h"

void AExplodingBullet::BeginPlay()
{
	Super::BeginPlay();
	//scale = GetActorScale();

}

void AExplodingBullet::Start(std::vector<float> coeff)
{
	Super::Start(coeff);
	int d = 3 - coeffeceints.size();
	for (int i = 0; i < d; i++) {
		coeffeceints.push_back(1);
	}
}

void AExplodingBullet::UpdateMovement(float DeltaTime)
{
	time += DeltaTime;
	AddActorLocalOffset(FVector(1, 0, 0) * coeffeceints[0] * DeltaTime);
	scale += FVector(DeltaTime * 3 * coeffeceints[2]);
	SetActorScale3D(scale);

}
