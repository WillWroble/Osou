// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleLogic.h"

// Sets default values
ATitleLogic::ATitleLogic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATitleLogic::BeginPlay()
{
	Super::BeginPlay();
	pController = GetWorld()->GetFirstPlayerController();
	pController->bShowMouseCursor = true;
	pController->bEnableMouseOverEvents = true;
	ABulletController::levelIndex = 0;

	APawn* evilPawn = pController->GetPawn();
	if (evilPawn != nullptr) {
		evilPawn->Destroy();
	}
	
}

// Called every frame
void ATitleLogic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

