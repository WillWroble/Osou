// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class OSOU_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int> grades;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<float> scores;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float soundCoeff = 1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool autoStartTutorial = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool hasCalibratedSound = false;
	
};
