// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelBox.h"

// Sets default values
ALevelBox::ALevelBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isCursorHovering = false;
	isSelected_ = false;
	isPreExpanded = false;
	hasGoneThroughBottomPortal = false;
	hasGoneThroughTopPortal = false;
	hasGoneThroughPortal = false;
	timer = 0;
	timer2 = 0;
	timer3 = 0;
	order_ = 0;

}

// Called when the game starts or when spawned
void ALevelBox::BeginPlay()
{
	Super::BeginPlay();
	pos1 = GetActorLocation();
	
}

// Called every frame
void ALevelBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ALevelBox::adjustedOrder()
{
	return order_ + mappedLevels.size();
}



