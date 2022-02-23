// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelBox.generated.h"

UCLASS()
class OSOU_API ALevelBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float timer;
	float timer2;
	bool isSelected_;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isCursorHovering;
};
