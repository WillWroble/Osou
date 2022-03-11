// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include "Particles/ParticleSystemComponent.h"
#include "ParticleEmitterInstances.h"
#include "../Plugins/WWise/Source/AkAudio/Classes/AkAmbientSound.h"
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
	void AddRythm(std::vector<float> beat, std::vector<float> tone, int in);
	void SetTransitions(std::vector<float> ts);
	void ResetEverything();
	std::vector<std::vector<float>> beats;
	std::vector<std::vector<float>> tones;
	std::vector<float>* currentBeat;
	std::vector<float>* currentTones;
	std::vector<float> transitionTimes;
	int index;
	int transitionIndex;
	float baseSpeed;
	float speed;
	float clockTime;
	float beatTime;
	int beatIndex;
	UFUNCTION(BlueprintImplementableEvent)
	void OnSlightlyEarly();
	UFUNCTION(BlueprintImplementableEvent)
	void OnBeatChange();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int PopupType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float currentTone;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float error;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float metronomeSpeed;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		UParticleSystem* templateEmitter;
	//UPROPERTY(EditDefaultsOnly, Category = "WidgetParam")
		//UUserWidget* widget;
};
