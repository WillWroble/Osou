// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <list>
#include <vector>
#include "BulletSpawner.h"
#include "KillMe.h"
#include "BasicBullet.h"
#include "MovingBorder.h"
#include "CoreMinimal.h"
#include "EquationLibrary.h"
#include "LevelLibrary.h"
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
	int messageCounter;
	virtual void Tick(float DeltaTime) override;
	void ResetBullets();
	int spawnerCount;
	BulletSpawner* spawner;
	std::list<ABasicBullet*> activeBullets;
	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
		TSubclassOf<AActor> BulletClass;
	UPROPERTY(EditDefaultsOnly, Category = "ExplodingBullet")
		TSubclassOf<AActor> ExplodingBullet;
	UPROPERTY(EditDefaultsOnly, Category = "CurvedBullet")
		TSubclassOf<AActor> CurvedBullet;

};
