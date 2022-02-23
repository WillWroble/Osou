// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Vector>
#include "BasicBullet.generated.h"

UCLASS()
class OSOU_API ABasicBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void UpdateMovement(float DeltaTime);
	virtual void Start(std::vector<float> coeff);
	bool flaggedForRemoval;
	float speed;
	float coeffecient;
	float time;
	FVector scale;
	std::vector<float> coeffeceints;

};
