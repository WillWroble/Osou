// Fill out your copyright notice in the Description page of Project Settings.


#include "Ihatemyself.h"

bool test;

// Sets default values
AIhatemyself::AIhatemyself()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	test = false;

}

// Called when the game starts or when spawned
void AIhatemyself::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "hello?");
	
}


// Called every frame
void AIhatemyself::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//FVector delta(DeltaTime*100, 0, 0);
	//AddActorLocalOffset(delta);
	APlayerController* controller;
	controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	float x = 0; float y = 0; 
	int h = 0; int w = 0;
	FVector pos(0,0,0); FVector dir(0,0,0);
	controller->GetMousePosition(x, y);
	controller->DeprojectMousePositionToWorld(pos, dir);
	controller->GetViewportSize(w, h);
	y = h - y;
	y = y - (h/2);
	x = x - (w/2);
	x = x * 4500 / w;
	y = y * 4500 / w;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *(FString::SanitizeFloat(x)));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *(FString::SanitizeFloat(pos.X)));

}

// Called to bind functionality to input
void AIhatemyself::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	test = true;
	check(InputComponent);
	InputComponent->BindAxis("MouseMovement", this, &AIhatemyself::TestFunction);

}

void AIhatemyself::TestFunction(float Value)
{
	//do thing lol
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *(FString::SanitizeFloat(Value)));
	FVector delta(Value, 0, 0);
	AddActorLocalOffset(delta);
}

