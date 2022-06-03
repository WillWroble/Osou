// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicBullet.h"

// Sets default values
ABasicBullet::ABasicBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	flaggedForRemoval = false;
	speed = 0;

}

// Called when the game starts or when spawned
void ABasicBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicBullet::UpdateMovement(float DeltaTime)
{
	//float angle = GetActorRotation().Pitch * (PI) * (1/180);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(angle));
	time += DeltaTime;
	AddActorLocalOffset(FVector(1,0,0) * coeffeceints[0] * DeltaTime); //500
	//AddActorLocalOffset(FVector(1, 0, 0) * coeffeceints[0] * (1.0f/60.0f));
	
}

void ABasicBullet::Start(std::vector<float> coeff)
{
	coeffeceints = coeff;
	scale = GetActorScale() * coeffeceints[1];
	SetActorScale3D(scale);
	
}

