// Fill out your copyright notice in the Description page of Project Settings.


#include "P1.h"

// Sets default values
AP1::AP1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AP1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AP1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AP1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

