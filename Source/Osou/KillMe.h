// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include <utility>
#include "Particles/ParticleSystemComponent.h"
#include "ParticleEmitterInstances.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/EditableTextBox.h"
#include "Components/EditableText.h"

#include "Kismet/GameplayStatics.h"
//#include "InputCoreTypes.h"
#include "PaperSpriteComponent.h"
#include "Components/AudioComponent.h"
//#include "BulletController.h"
#include "EngineUtils.h"

#include "KillMe.generated.h"
struct on_screen_message
{
	FString message;
	float startTime;
	float duration;
	float interval;
	int type;
	int count;
};

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
	static bool is4HealthStatic;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void AddRythm(std::vector<float> beat, int in);
	virtual void SetTransitions(std::vector<float> ts);
	virtual void setSpeedMultis(std::vector<float> s);

	virtual void AddTextInstruction(int type, float start, float duration, FString textContent, float interval = 1, int count = 0);
	//void ResetEverything();
	virtual void FinishedLevel();
	std::vector<std::vector<float>> beats;
	std::vector<float>* currentBeat;
	std::vector<float> transitionTimes;
	std::vector<float> speedMultis;
	std::vector<on_screen_message> messages;
	std::vector<int> levelConversion;
	UAudioComponent* sound;

	UWidget* childWidget;
	UPaperSpriteComponent* sprite;
	UPaperSpriteComponent* circleSprite;
	//UAudioComponent* sound;
	UAudioComponent* drumBeat;
	UParticleSystemComponent* trail;
	FParticleEmitterInstance* emitter;
	APlayerController* pController;
	//ABulletController* bulletController;
	FKey leftClick;
	FKey space;
	FVector direction;
	FVector baseScale;
	FVector scale;
	FVector baseLocation;

	bool isLevelFinsihedd;
	bool wasClicked;
	bool isMoving;
	int screenW;
	int screenH;
	int skipCount;
	int successivePerfects;
	float travelTime;
	float timeout;
	float relativeTimeout;
	float travelTimeout;
	bool hasStarted;
	bool clicked;

	
	float currentMulti;
	int index;
	int relativeIndex;
	int transitionIndex;
	float baseSpeed;
	float speed;
	float clockTime;
	float beatTime;
	float invunerableTime;
	bool isTimeFrozen;
	//float absoluteTimer;
	float rhythmBuffer;
	float rhythmDelayConstant;
	std::vector<float> rhythmDelayConstants;
	int iCounter;
	int beatIndex;
	int perfects;
	//int messageIndex;
	int total;
	int tutHScore;
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
	UFUNCTION(BlueprintImplementableEvent)
	void FadeInText();
	UFUNCTION(BlueprintImplementableEvent)
	void FadeOutText();
	UFUNCTION(BlueprintCallable)
	virtual void ResetEverything();
	UFUNCTION(BlueprintCallable)
	void StopEverything();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int PopupType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool is4Health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float metronomeSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UUserWidget* widget;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float rScore;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int hScore;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int currentLevel;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isInvunerable;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString content;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		UParticleSystem* templateEmitter;
	UPROPERTY(EditDefaultsOnly, Category = "song0")
		USoundWave* song0;
	UPROPERTY(EditDefaultsOnly, Category = "song1.1")
		USoundWave* song1_1;
	UPROPERTY(EditDefaultsOnly, Category = "song1.2")
		USoundWave* song1_2;
	UPROPERTY(EditDefaultsOnly, Category = "song1.3")
		USoundWave* song1_3;
	UPROPERTY(EditDefaultsOnly, Category = "song1.4")
		USoundWave* song1_4;
	UPROPERTY(EditDefaultsOnly, Category = "song2")
		USoundWave* song2;
	UPROPERTY(EditDefaultsOnly, Category = "song3")
		USoundWave* song3;
	UPROPERTY(EditDefaultsOnly, Category = "song4")
		USoundWave* song4;
	UPROPERTY(EditDefaultsOnly, Category = "song5")
		USoundWave* song5;
	UPROPERTY(EditDefaultsOnly, Category = "song6")
		USoundWave* song6;
	UPROPERTY(EditDefaultsOnly, Category = "song7")
		USoundWave* song7;
	UPROPERTY(EditDefaultsOnly, Category = "song8")
		USoundWave* song8;
	UPROPERTY(EditDefaultsOnly, Category = "song9")
		USoundWave* song9;


	//UPROPERTY(EditDefaultsOnly, Category = "WidgetParam")
	//	UUserWidget* widget;
};
