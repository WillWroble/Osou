// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameBackround.h"

// Sets default values
AInGameBackround::AInGameBackround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInGameBackround::BeginPlay()
{
	Super::BeginPlay();
	levelIndex_BP = ABulletController::levelIndex;
	InitMat();
}

// Called every frame
void AInGameBackround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

