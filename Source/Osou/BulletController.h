// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <list>
#include <vector>
#include "BulletSpawner.h"
#include "KillMe.h"
#include "BasicBullet.h"
#include "MovingBorder.h"
#include "Components/AudioComponent.h"
#include "CoreMinimal.h"
#include "EquationLibrary.h"
#include "LevelLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MySaveGame.h"
#include "TrackingBullet.h"
#include "InGameCharacter.h"
#include "GameFramework/Actor.h"
#include "BulletController.generated.h"


UCLASS()
class OSOU_API ABulletController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//references
	AMovingBorder* border;
	AInGameCharacter* character;
	//level selector
	static int levelIndex;
	static float audioCoeff;
	int transitionIndex;
	int index;    
	int messageIndex;
	bool isDisplayMessage;
	on_screen_message currentMessage;
	// Called every frame
	float clockTime;
	float messageTime;
	float messageClockTime;
	float adjustedDeltaTime;
	int tutorialTime;
	int messageCounter;
	bool tutFirstTime;
	bool isTimeFrozen;
	virtual void Tick(float DeltaTime) override;
	void ResetBullets();
	void DisplayMessage(FString message, int type = 0, float duration = 2, float start = 0);
	int spawnerCount;
	BulletSpawner* spawner;
	std::list<ABasicBullet*> activeBullets;
	UFUNCTION(BlueprintCallable)
		void SetCalibration();
	UFUNCTION(BlueprintCallable)
		void SetLevelToTrueRhythm();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float audioCoeff_BP;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		TSubclassOf<AActor> BulletClass;
	UPROPERTY(EditDefaultsOnly, Category = "ExplodingBullet")
		TSubclassOf<AActor> ExplodingBullet;
	UPROPERTY(EditDefaultsOnly, Category = "CurvedBullet")
		TSubclassOf<AActor> CurvedBullet;
	UPROPERTY(EditDefaultsOnly, Category = "HexBullet")
		TSubclassOf<AActor> HexBullet;
	UPROPERTY(EditDefaultsOnly, Category = "CurvedBullet_Reg")
		TSubclassOf<AActor> CurvedBulletReg;
	UPROPERTY(EditDefaultsOnly, Category = "CurvedGrowingBullet")
		TSubclassOf<AActor> CurvedGrowingBullet;
	UPROPERTY(EditDefaultsOnly, Category = "KnifeBullet")
		TSubclassOf<AActor> KnifeBullet;
	UPROPERTY(EditDefaultsOnly, Category = "CurvedKnifeBullet")
		TSubclassOf<AActor> CurvedKnifeBullet;
	UPROPERTY(EditDefaultsOnly, Category = "RedKnifeBullet")
		TSubclassOf<AActor> RedKnifeBullet;
	UPROPERTY(EditDefaultsOnly, Category = "CurvedKnifeRed")
		TSubclassOf<AActor> RedCurvedKnifeBullet;
	UPROPERTY(EditDefaultsOnly, Category = "BasicFireball")
		TSubclassOf<AActor> BasicFireball;
	UPROPERTY(EditDefaultsOnly, Category = "TrackingBullet")
		TSubclassOf<AActor> TrackingBullet;
	UPROPERTY(EditDefaultsOnly, Category = "GhostBullet")
		TSubclassOf<AActor> GhostBullet;
	UPROPERTY(EditDefaultsOnly, Category = "FractureBullet")
		TSubclassOf<AActor> FractureBullet;
	UPROPERTY(EditDefaultsOnly, Category = "CirnoBullet")
		TSubclassOf<AActor> CirnoBullet;
	UPROPERTY(EditDefaultsOnly, Category = "BasicBulletBlue")
		TSubclassOf<AActor> BasicBulletBlue;


};
