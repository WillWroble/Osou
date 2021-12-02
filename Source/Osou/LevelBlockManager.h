// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "LevelBox.h"
#include <vector>
#include "Kismet/GameplayStatics.h"
#include "Components/TextRenderComponent.h"
#include "LevelBlockManager.generated.h"

struct LevelData {

	int levelNumber;
	int levelDifficulty;
	FText levelName;
};
UCLASS()
class OSOU_API ALevelBlockManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelBlockManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateDeltas(int index, float delta);
	APlayerController* pController;
	FKey rightClick;
	FKey leftClick;
	std::vector<LevelData> levelDatas;
	std::vector<ALevelBox*> boxInstances;
	std::vector<float> positionDeltas;
	float timer;

	UPROPERTY(EditDefaultsOnly, Category = "LevelBlockBlueprint")
		TSubclassOf<AActor> LevelBlockClass;

};
