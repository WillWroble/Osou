// Fill out your copyright notice in the Description page of Project Settings.


#include "CreditsLogic.h"

// Sets default values
ACreditsLogic::ACreditsLogic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACreditsLogic::BeginPlay()
{
	Super::BeginPlay();
	pController = GetWorld()->GetFirstPlayerController();
	pController->bShowMouseCursor = true;
	pController->bEnableMouseOverEvents = true;

	APawn* evilPawn = pController->GetPawn();
	if (evilPawn != nullptr) {
		evilPawn->Destroy();
	}
}

// Called every frame
void ACreditsLogic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

