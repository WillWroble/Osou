// Fill out your copyright notice in the Description page of Project Settings.


#include "CurvedGrowingBullet.h"
void ACurvedGrowingBullet::BeginPlay()
{
	Super::BeginPlay();
}

void ACurvedGrowingBullet::Start(std::vector<float> coeff)
{
	Super::Start(coeff);
	int d = 6 - coeffeceints.size();
	for (int i = 0; i < d; i++) {
		coeffeceints.push_back(1);
	}
}

void ACurvedGrowingBullet::UpdateMovement(float DeltaTime)
{
	time += DeltaTime;
	FVector direction = FVector(EquationLibrary::xDelta(coeffeceints[2], time * coeffeceints[0] / 1000) * coeffeceints[4], 0, EquationLibrary::yDelta(coeffeceints[2], time * coeffeceints[0] / 1000) * coeffeceints[5]);
	AddActorLocalRotation(FRotator(EquationLibrary::aDelta(coeffeceints[2], time * coeffeceints[0] / 10000) * coeffeceints[3] * coeffeceints[0] * DeltaTime, 0, 0));
	AddActorLocalOffset(direction * coeffeceints[0] * DeltaTime);
	//AddActorLocalOffset(FVector(0, 0, 1) * coeffeceints[0] * DeltaTime * EquationLibrary::yDelta(coeffeceints[2], time) * coeffeceints[4]);
	scale += FVector(DeltaTime * (time/8));
	SetActorScale3D(scale);

}
