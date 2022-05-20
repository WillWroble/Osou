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
	//level selector
	static int levelIndex;
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
	virtual void Tick(float DeltaTime) override;
	void ResetBullets();
	void DisplayMessage(FString message, int type = 0, float duration = 2, float start = 0);
	int spawnerCount;
	BulletSpawner* spawner;
	std::list<ABasicBullet*> activeBullets;
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

};
