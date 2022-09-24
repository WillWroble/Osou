// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicBullet.h"
#include "KillMe.h"
#include "TrackingBullet.generated.h"

/**
 * 
 */
UCLASS()
class OSOU_API ATrackingBullet : public ABasicBullet
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	public:
		static AKillMe* player;
		void UpdateMovement(float DeltaTime);
		float inversion = 1;

	
};
