// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingBorder.h"

// Sets default values
AMovingBorder::AMovingBorder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMovingBorder::BeginPlay()
{
	Super::BeginPlay();
	
	particleEffect = (UNiagaraComponent*)(this->GetComponentsByTag(UNiagaraComponent::StaticClass(), "tag1"))[0];

}

// Called every frame
void AMovingBorder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMovingBorder::InitializeFromOutside()
{
	instructionIndex = 0;
	timer = 0;
	radius = pow(600, 2);
}

void AMovingBorder::UpdateMovement(float DeltaTime)
{
	if (timer > instructions[instructionIndex].duration) {
		timer = 0;
		if (instructions[instructionIndex].type == 2) {
			//spawn in
			isActive = true;
			particleEffect->SetVisibility(true);
			delta = FVector(instructions[instructionIndex].x, 1, instructions[instructionIndex].y);
			SetActorLocation(delta);
		}
		else if (instructions[instructionIndex].type == 3) {
			//spawn out
			isActive = false;
			particleEffect->SetVisibility(false);
			//AddActorLocalOffset(FVector(0, -2, 0));
		}

		instructionIndex++;

		if (instructions[instructionIndex].type == 0) {
			delta = FVector(instructions[instructionIndex].x - GetActorLocation().X, 0, instructions[instructionIndex].y - GetActorLocation().Z);
		} else if (instructions[instructionIndex].type == 1) {
			delta = FVector(instructions[instructionIndex].x - GetActorScale().X);
			scale = GetActorScale();
		}
	}
	if (instructions[instructionIndex].type == 0) {
		AddActorLocalOffset(delta * DeltaTime / instructions[instructionIndex].duration);
	} else if (instructions[instructionIndex].type == 1) {
		scale += FVector(delta * DeltaTime / instructions[instructionIndex].duration);
		SetActorRelativeScale3D(scale);
	}
	timer += DeltaTime;
}

void AMovingBorder::ResetBorder()
{
	instructionIndex = 0;
	timer = 0;
	SetActorLocation(FVector(0, -1, 0));
	SetActorScale3D(FVector(5, 5, 5));
	particleEffect->SetVisibility(false);
	isActive = false;
}

bool AMovingBorder::CheckForCollision(FVector playerPosition)
{
	if (isActive == false) {
		return false;
	}
	if (pow(playerPosition.X - GetActorLocation().X, 2) + pow(playerPosition.Z - GetActorLocation().Z, 2) < radius * pow(GetActorScale3D().Z,2)) {
		return false;
	} else {
		return true;
	}

}


