// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelBlockManager.h"

#define LOCTEXT_NAMESPACE "LevelNames"
// Sets default values
ALevelBlockManager::ALevelBlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	timer = 0;
	levelDatas.push_back({ 1,0, LOCTEXT("levelName1", "UN Owen Was Her") });
	levelDatas.push_back({ 2,0, LOCTEXT("levelName2", "WIP") });
	levelDatas.push_back({ 3,0, LOCTEXT("levelName3", "WIP") });
	levelDatas.push_back({ 4,0, LOCTEXT("levelName4", "WIP") });
	levelDatas.push_back({ 5,0, LOCTEXT("levelName5", "WIP") });
	levelDatas.push_back({ 6,0, LOCTEXT("levelName6", "WIP") });
	levelDatas.push_back({ 7,0, LOCTEXT("levelName7", "WIP") });
	levelDatas.push_back({ 8,0, LOCTEXT("levelName8", "WIP") });
	positionDeltas = std::vector<float>(8, 0);

}

// Called when the game starts or when spawned
void ALevelBlockManager::BeginPlay()
{
	Super::BeginPlay();
	rightClick = FKey("RightMouseButton");
	leftClick = FKey("LeftMouseButton");
	pController = GetWorld()->GetFirstPlayerController();
	pController->bShowMouseCursor = true;
	pController->bEnableMouseOverEvents = true;

	float posX = 1500;
	float posY = 800;
	for (int i = 0; i < levelDatas.size(); i++) {
		ALevelBox* tempBox = GetWorld()->SpawnActor<ALevelBox>(LevelBlockClass,
			FVector(posX, 1, posY), //- (12.5*((2*(((int)abs(posY/200))%2))-1)
			FRotator(0));
		boxInstances.push_back(tempBox);
		((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelName")[0]))->SetText(levelDatas[i].levelName);
		posY -= 200;
	}
}

// Called every frame
void ALevelBlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (int i = 0; i < boxInstances.size(); i++) {
		if (boxInstances[i]->isCursorHovering) {
			if (pController->WasInputKeyJustPressed(leftClick)) {
				if (i == 0) {
					UGameplayStatics::OpenLevel(this, FName("Minimal_Default"));
				}
				else {
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LEVEL NOT RDY");
				}
			}
			if (boxInstances[i]->timer < 1) {
				if (DeltaTime > 1 - boxInstances[i]->timer) {
					UpdateDeltas(i, 100 * (1 - boxInstances[i]->timer));
					boxInstances[i]->timer = 1;
				}
				else {
					UpdateDeltas(i, 100 * DeltaTime);
					boxInstances[i]->timer += 5*DeltaTime;
				}
				boxInstances[i]->SetActorRelativeScale3D(FVector(boxInstances[i]->timer * 0.1 + 0.7));
			}
		}
		else if (boxInstances[i]->timer != 0) {
			if (DeltaTime > boxInstances[i]->timer) {
				UpdateDeltas(i, -100 * (boxInstances[i]->timer));
				boxInstances[i]->timer = 0;
			} else {
				UpdateDeltas(i, -100 * DeltaTime);
				boxInstances[i]->timer -= 5*DeltaTime;
			}
			boxInstances[i]->SetActorRelativeScale3D(FVector(boxInstances[i]->timer*0.1  + 0.7));
		}
	}
	/*
	if (pController->IsInputKeyDown(rightClick)) {
		//enable scrolling
		for (int i = 0; i < positionDeltas.size(); i++) {
			float dx; float dy;
			pController->GetInputMouseDelta(dx, dy);
			positionDeltas[i] += dy*15;
		}
	}
	*/
	for (int i = 0; i < positionDeltas.size(); i++) {
		//int temp = floor(GetActorLocation().Z / 200);
		//int multiplier = (abs(2 * (((int)floor(boxInstances[i]->GetActorLocation().Z / 200)) % 2)) - 1);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, *(FString::FromInt(temp)));
		boxInstances[i]->AddActorLocalOffset(FVector(0, 0, positionDeltas[i])); //positionDeltas[i] * 0.125 * multiplier
		positionDeltas[i] = 0;
	}
}
void ALevelBlockManager::UpdateDeltas(int index, float delta)
{
	for (int i = 0; i < index; i++) {
		positionDeltas[i] += delta;
	}
	for (int i = index + 1; i < positionDeltas.size(); i++) {
		positionDeltas[i] -= delta;
	}
}
#undef LOCTEXT_NAMESPACE

