// Fill out your copyright notice in the Description page of Project Settings.


#include "BeatCircle.h"

// Sets default values
ABeatCircle::ABeatCircle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABeatCircle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABeatCircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

