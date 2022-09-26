// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicBullet.h"
#include "Components/ChildActorComponent.h"
#include "FractureBullet.generated.h"

/**
 * 
 */
UCLASS()
class OSOU_API AFractureBullet : public ABasicBullet
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	void UpdateMovement(float DeltaTime);

	/*UActorComponent* child1;
	UActorComponent* child2;
	UActorComponent* child3;
	UActorComponent* child4;
	UActorComponent* child5;
	UActorComponent* child6;*/

	TArray<UChildActorComponent*> myChildren;



	
};
