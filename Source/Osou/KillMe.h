// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include "Particles/ParticleSystemComponent.h"
#include "ParticleEmitterInstances.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/EditableTextBox.h"
#include "Components/EditableText.h"
#include "KillMe.generated.h"

UCLASS()
class OSOU_API AKillMe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKillMe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddRythm(std::vector<float> beat, int in);
	void SetTransitions(std::vector<float> ts);
	//void ResetEverything();
	void FinishedLevel();
	std::vector<std::vector<float>> beats;
	std::vector<float>* currentBeat;
	std::vector<float> transitionTimes;
	int index;
	int transitionIndex;
	float baseSpeed;
	float speed;
	float clockTime;
	float beatTime;
	float invunerableTime;
	int iCounter;
	int beatIndex;
	int perfects;
	int total;
	UFUNCTION(BlueprintImplementableEvent)
	void OnSlightlyEarly();
	UFUNCTION(BlueprintImplementableEvent)
	void OnBeatChange();
	UFUNCTION(BlueprintImplementableEvent)
	void OnFinishLevel();
	UFUNCTION(BlueprintImplementableEvent)
	void CloseWidget();
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHealthBar();
	UFUNCTION(BlueprintCallable)
	void ResetEverything();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int PopupType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float metronomeSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UUserWidget* widget;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float rScore;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int hScore;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isInvunerable;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		UParticleSystem* templateEmitter;
	//UPROPERTY(EditDefaultsOnly, Category = "WidgetParam")
	//	UUserWidget* widget;
};
