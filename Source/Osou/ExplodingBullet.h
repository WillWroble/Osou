// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicBullet.h"
#include "ExplodingBullet.generated.h"

/**
 * 
 */
UCLASS()
class OSOU_API AExplodingBullet : public ABasicBullet
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
		virtual void Start(std::vector<float> coeff);
		void UpdateMovement(float DeltaTime);

	
};
