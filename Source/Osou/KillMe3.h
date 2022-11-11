// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KillMe.h"
#include "PaperFlipbookComponent.h"
#include "KillMe3.generated.h"

/**
 * 
 */
UCLASS()
class OSOU_API AKillMe3 : public AKillMe
{
	GENERATED_BODY()

	public:
		// Sets default values for this actor's properties
		AKillMe3();
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:
		UPaperFlipbookComponent* flipBook;

		virtual void Tick(float DeltaTime) override;
		virtual void AddRythm(std::vector<float> beat, int in) override;
		virtual void SetTransitions(std::vector<float> ts) override;
		virtual void setSpeedMultis(std::vector<float> s) override;

		virtual void AddTextInstruction(int type, float start, float duration, FString textContent, float interval = 1, int count = 0) override;
		//void ResetEverything();
		//UFUNCTION(BlueprintCallable)
		virtual void ResetEverything() override;

		UFUNCTION(BlueprintImplementableEvent)
			void StartGlide();
		UFUNCTION(BlueprintImplementableEvent)
			void EndGlide();
};
