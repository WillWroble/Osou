// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
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

	std::vector<int> mappedLevels;
	int level;
	int order_;
	//float timer;
	float timer2;
	float timer3;
	FVector pos1;
	bool isSelected_;
	bool isActive;
	bool isCategory;
	FVector startPosition;
	int adjustedOrder();
	UFUNCTION(BlueprintImplementableEvent)
		void ManualTick();
	UFUNCTION(BlueprintImplementableEvent)
		void ManualBegin();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float dTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float interpTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isCursorHovering;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float timer;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float deltaPosition;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString levelScore;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText levelGrade;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText levelName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FColor levelColor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int levelDifficulty;
	


};
