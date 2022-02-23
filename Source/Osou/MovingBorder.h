// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include <math.h>
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "MovingBorder.generated.h"
struct BorderInstruction {
	float x;
	float y;
	float duration;
	int type; //0 = move instruction, 1 = size instruction, 2 = spawn instruction, 3 = despawn instruction, 4 = wait instruction
};

UCLASS()
class OSOU_API AMovingBorder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingBorder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	bool isActive;
	int instructionIndex;
	float timer;
	float radius;
	FVector delta;
	FVector scale;
	std::vector<BorderInstruction> instructions;
	UNiagaraComponent* particleEffect;
	virtual void Tick(float DeltaTime) override;
	void InitializeFromOutside();
	void UpdateMovement(float DeltaTime);
	void ResetBorder();
	bool CheckForCollision(FVector playerPosition);
};
