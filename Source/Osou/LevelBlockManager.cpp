// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelBlockManager.h"

#define LOCTEXT_NAMESPACE "LevelNames"
// Sets default values
ALevelBlockManager::ALevelBlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	timer = 0;
	timer2 = 0;
	levelDatas.push_back({ 1,0, LOCTEXT("levelName1", "Flowering Night (Tutorial) (WIP)") });
	levelDatas.push_back({ 2,0, LOCTEXT("levelName2", "UN Owen Was Her") });
	levelDatas.push_back({ 3,0, LOCTEXT("levelName3", "Beloved Tomboyish Girl (WIP)") });
	levelDatas.push_back({ 4,0, LOCTEXT("levelName4", "Lullaby of a Deserted Hell (WIP)") });
	levelDatas.push_back({ 5,0, LOCTEXT("levelName5", "Radiant Radiant Symphany (WIP)") });
	levelDatas.push_back({ 6,0, LOCTEXT("levelName6", "Reach for the Moon (WIP)") });
	levelDatas.push_back({ 7,0, LOCTEXT("levelName7", "Necrofantasia (WIP)") });
	levelDatas.push_back({ 8,0, LOCTEXT("levelName8", "Flight of the Bamboo Cutter (WIP)") });
	positionDeltas = std::vector<float>(8, 0);

}

// Called when the game starts or when spawned
void ALevelBlockManager::BeginPlay()
{
	Super::BeginPlay();
	rightClick = FKey("RightMouseButton");
	leftClick = FKey("LeftMouseButton");
	pController = GetWorld()->GetFirstPlayerController();
	audio1 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag1"))[0];
	audio2 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag2"))[0];
	audio3 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag3"))[0];
	audio4 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag4"))[0];
	audio5 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag5"))[0];
	audio6 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag6"))[0];
	audio7 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag7"))[0];
	audio8 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag8"))[0];

	pController->bShowMouseCursor = true;
	pController->bEnableMouseOverEvents = true;
	forwardPolarity = false;
	lastTex = 0;

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
	if (timer2 > 0) {
		if (timer2 < DeltaTime) {
			timer2 = 0;
			//lastTex = i;
		}
		else {
			timer2 -= DeltaTime;
		}
		dMat->SetScalarParameterValue(FName("blend"), timer2);
	}
	for (int i = 0; i < boxInstances.size(); i++) {
		if (boxInstances[i]->isCursorHovering) {
			if (pController->WasInputKeyJustPressed(leftClick)) {
				if (boxInstances[i]->isSelected_) {
					if (i == 1) {
						ABulletController::levelIndex = i;
						UGameplayStatics::OpenLevel(this, FName("Minimal_Default"));
					}
					else {
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LEVEL NOT RDY");
					}
				}
				else {
					timer2 = 1;
					//back1->GetStaticMeshComponent()->GetMaterial()->
					dMat->SetTextureParameterValue(FName("tex_1"), getBackround(lastTex));
					dMat->SetTextureParameterValue(FName("tex_2"), getBackround(i));
					getSound(lastTex)->FadeOut(1, 0);
					getSound(i)->FadeIn(1);
					lastTex = i;
				}
				UnselectAllBoxes();
				boxInstances[i]->isSelected_ = true;
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
			else if (boxInstances[i]->timer2 < 0.5 && boxInstances[i]->isSelected_) {
				if (DeltaTime > 0.5 - boxInstances[i]->timer2) {
					UpdateDeltas(i, 100 * (0.5 - boxInstances[i]->timer2));
					boxInstances[i]->AddActorLocalOffset(FVector(-350 * (0.5 - boxInstances[i]->timer2), 0, 0));
					boxInstances[i]->timer2 = 0.5;
				}
				else {
					UpdateDeltas(i, 100 * DeltaTime);
					boxInstances[i]->AddActorLocalOffset(FVector(-350 * DeltaTime, 0, 0));
					boxInstances[i]->timer2 += 5 * DeltaTime;
				}
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
		if (boxInstances[i]->timer2 != 0 && !boxInstances[i]->isSelected_) {
			if (DeltaTime > boxInstances[i]->timer2) {
				UpdateDeltas(i, -100 * (boxInstances[i]->timer2));
				boxInstances[i]->AddActorLocalOffset(FVector(350 * (boxInstances[i]->timer2), 0, 0));
				boxInstances[i]->timer2 = 0;
			}
			else {
				UpdateDeltas(i, -100 * DeltaTime);
				boxInstances[i]->AddActorLocalOffset(FVector(350 * DeltaTime, 0, 0));
				boxInstances[i]->timer2 -= 5 * DeltaTime;
			}
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
void ALevelBlockManager::UnselectAllBoxes()
{
	for (int i = 0; i < boxInstances.size(); i++) {
		boxInstances[i]->isSelected_ = false;
	}
}
UTexture* ALevelBlockManager::getBackround(int i)
{
	if (i == 0) {
		return tex1;
	}
	else if (i == 1) {
		return tex2;
	}
	else if (i == 2) {
		return tex3;
	}
	else if (i == 3) {
		return tex4;
	}
	else if (i == 4) {
		return tex5;
	}
	else if (i == 5) {
		return tex6;
	}
	else if (i == 6) {
		return tex7;
	}
	else if (i == 7) {
		return tex8;
	}
	else if (i == 8) {

	}
	else {

	}
	return tex1;
}
UAudioComponent* ALevelBlockManager::getSound(int i)
{
	if (i == 0) {
		return audio1;
	}
	else if (i == 1) {
		return audio2;
	}
	else if (i == 2) {
		return audio3;
	}
	else if (i == 3) {
		return audio4;
	}
	else if (i == 4) {
		return audio5;
	}
	else if (i == 5) {
		return audio6;
	}
	else if (i == 6) {
		return audio7;
	}
	else if (i == 7) {
		return audio8;
	}
	else if (i == 8) {

	}
	else {

	}
	return audio1;
}
#undef LOCTEXT_NAMESPACE

