// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include "KillMe.h"
#include "Kismet/GameplayStatics.h"
#include "BulletController.h"
#include "Components/AudioComponent.h"
#include "RhythmTest.generated.h"

UCLASS()
class OSOU_API ARhythmTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARhythmTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LeftClick();
	void BindToInput();
	void AddTextInstruction(int type, float start, float duration, FString textContent, float interval = 1, int count = 0);
	void DisplayMessage(FString message, int type = 0, float duration = 2, float start = 0);
	float mean(std::vector<float> items);
	float stddev(std::vector<float> items);

	APlayerController* pController;
	UAudioComponent* sound;
	std::vector<float> clickTimes;
	std::vector<float> allClickTimes;
	on_screen_message currentMessage;
	std::vector<on_screen_message> messages;
	float prevTime;
	bool collectionMode;
	bool isDisplayMessage;
	int messageIndex;
	int messageCounter;
	float messageTime;
	float messageClockTime;
	//float testClockTime;
	UFUNCTION(BlueprintCallable)
		void SetLevelToTrueRhythm();

	UFUNCTION(BlueprintImplementableEvent)
		void FadeInText();
	UFUNCTION(BlueprintImplementableEvent)
		void FadeOutText();
	UFUNCTION(BlueprintImplementableEvent)
		void AddUI();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString content;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float testClockTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float audioCoeff_BP;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool testCompleted;

};
