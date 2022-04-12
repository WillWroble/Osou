// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "LevelBox.h"
#include "BulletController.h"
#include "Engine/StaticMeshActor.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWave.h"
#include <vector>
#include <Engine/Texture.h>
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextRenderComponent.h"
#include "LevelBlockManager.generated.h"

struct LevelData {

	int levelNumber;
	int levelDifficulty;
	FText levelName;
	std::vector<int> subLevels;
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
	void UnselectAllBoxes();
	UTexture* getBackround(int i);
	USoundWave* getSound(int i);
	UAudioComponent* audio1;
	UAudioComponent* audio2;
	UAudioComponent* audio3;
	UAudioComponent* audio4;
	UAudioComponent* audio5;
	UAudioComponent* audio6;
	UAudioComponent* audio7;
	UAudioComponent* audio8;
	APlayerController* pController;
	FKey rightClick;
	FKey leftClick;
	std::vector<LevelData> levelDatas;
	std::vector<ALevelBox*> boxInstances;
	std::vector<float> positionDeltas;
	int lastTex;
	int audioPtr1;
	int audioPtr2;
	bool forwardPolarity;
	bool isFadeToTwo;

	float timer;
	float timer2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UMaterialInstanceDynamic* dMat;


	UPROPERTY(EditDefaultsOnly, Category = "LevelBlockBlueprint")
		TSubclassOf<AActor> LevelBlockClass;
	UPROPERTY(EditDefaultsOnly, Category = "tex1")
		UTexture* tex1;
	UPROPERTY(EditDefaultsOnly, Category = "tex2")
		UTexture* tex2;
	UPROPERTY(EditDefaultsOnly, Category = "tex3")
		UTexture* tex3;
	UPROPERTY(EditDefaultsOnly, Category = "tex4")
		UTexture* tex4;
	UPROPERTY(EditDefaultsOnly, Category = "tex5")
		UTexture* tex5;
	UPROPERTY(EditDefaultsOnly, Category = "tex6")
		UTexture* tex6;
	UPROPERTY(EditDefaultsOnly, Category = "tex7")
		UTexture* tex7;
	UPROPERTY(EditDefaultsOnly, Category = "tex8")
		UTexture* tex8;
	UPROPERTY(EditDefaultsOnly, Category = "tex9")
		UTexture* tex9;
	UPROPERTY(EditDefaultsOnly, Category = "sound1")
		USoundWave* sound1;
	UPROPERTY(EditDefaultsOnly, Category = "sound2")
		USoundWave* sound2;
	UPROPERTY(EditDefaultsOnly, Category = "sound3")
		USoundWave* sound3;
	UPROPERTY(EditDefaultsOnly, Category = "sound4")
		USoundWave* sound4;
	UPROPERTY(EditDefaultsOnly, Category = "sound5")
		USoundWave* sound5;
	UPROPERTY(EditDefaultsOnly, Category = "sound6")
		USoundWave* sound6;
	UPROPERTY(EditDefaultsOnly, Category = "sound7")
		USoundWave* sound7;
	UPROPERTY(EditDefaultsOnly, Category = "sound8")
		USoundWave* sound8;
	UPROPERTY(EditDefaultsOnly, Category = "sound9")
		USoundWave* sound9;
};
