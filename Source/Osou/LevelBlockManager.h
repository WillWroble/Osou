// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "LevelBox.h"
#include "BulletController.h"
#include "KillMe.h"
#include "Engine/StaticMeshActor.h"
#include "Components/AudioComponent.h"
#include "PaperSpriteComponent.h"
#include "Sound/SoundWave.h"
#include <vector>
#include <Engine/Texture.h>
#include <stdlib.h>
#include "Materials/MaterialInstanceDynamic.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextRenderComponent.h"
#include "LevelBlockManager.generated.h"

enum grade {S_, A_, B_, C_, D_};
struct LevelData {

	int levelNumber;
	int levelDifficulty;
	FText levelName;
	FText artistCredit;
	std::vector<int> subLevels;
	int grade;
	float score;
	
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
	void AddDeltaToAll(float delta);
	void UnselectAllBoxes();
	void BindToInput();
	void FinishedLoadingLevels(const FString& SlotName, const int32 UserINdex, USaveGame* LoadedGameData);
	void ScrollDown();
	void ScrollUp();
	int Shifted(int n);
	ALevelBox* findByOrder(int n);
	ALevelBox* findLowest();
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
	UWorld* world;
	FKey rightClick;
	FKey leftClick;
	FVector scrollTarget;
	ALevelBox* topBox;
	ALevelBox* bottomBox;
	ALevelBox* tempTop;
	ALevelBox* tempBottom;
	static std::vector<LevelData> levelDatas;
	std::vector<ALevelBox*> boxInstances;
	std::vector<FString> gradeConversionLetter;
	std::vector<FColor> gradeConversionColor;
	std::vector<float> positionDeltas;
	std::vector<int> levelMap;
	int lastTex;
	int audioPtr1;
	int audioPtr2;
	int activeBoxes;
	int orderShift;
	int upShift;
	int downShift;
	bool forwardPolarity;
	bool isFadeToTwo;
	bool isCollapsing;
	bool wtf;
	bool normalUp;
	bool normalDown;

	float timer;
	float timer2;
	float wormhole;


	float scrollForce;

	const float curveCoeff = 0;
	//UPROPERTY(EditDefaultsOnly, Category = "SaveDataObject")
	//	TSubclassOf<UMySaveGame> MySaveGameClass;
	UFUNCTION(BlueprintImplementableEvent)
	void SetUIProperties();
	UFUNCTION(BlueprintImplementableEvent)
		void CheckForCalibration();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText textOut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool hasCalibrated;
	

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UMaterialInstanceDynamic* dMat;


	UPROPERTY(EditDefaultsOnly, Category = "LevelBlockBlueprint")
		TSubclassOf<AActor> LevelBlockClass;
	UPROPERTY(EditDefaultsOnly, Category = "tex0")
		UTexture* tex0;
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
	UPROPERTY(EditDefaultsOnly, Category = "tex10")
		UTexture* tex10;
	UPROPERTY(EditDefaultsOnly, Category = "tex11")
		UTexture* tex11;
	UPROPERTY(EditDefaultsOnly, Category = "tex12")
		UTexture* tex12;
	UPROPERTY(EditDefaultsOnly, Category = "tex13")
		UTexture* tex13;
	UPROPERTY(EditDefaultsOnly, Category = "tex14")
		UTexture* tex14;
	UPROPERTY(EditDefaultsOnly, Category = "tex15")
		UTexture* tex15;




	UPROPERTY(EditDefaultsOnly, Category = "sound0")
		USoundWave* sound0;
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
	UPROPERTY(EditDefaultsOnly, Category = "sound10")
		USoundWave* sound10;
	UPROPERTY(EditDefaultsOnly, Category = "sound11")
		USoundWave* sound11;
	UPROPERTY(EditDefaultsOnly, Category = "sound12")
		USoundWave* sound12;
	UPROPERTY(EditDefaultsOnly, Category = "sound13")
		USoundWave* sound13;
	UPROPERTY(EditDefaultsOnly, Category = "sound14")
		USoundWave* sound14;
	UPROPERTY(EditDefaultsOnly, Category = "sound15")
		USoundWave* sound15;
	UPROPERTY(EditDefaultsOnly, Category = "sound16")
		USoundWave* sound16;
	UPROPERTY(EditDefaultsOnly, Category = "sound17")
		USoundWave* sound17;
};
