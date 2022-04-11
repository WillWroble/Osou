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
	levelDatas = std::vector <LevelData>(72);
	for (int i = 0; i < 72; i++) {
		//set default values
		levelDatas[i] = { -1,0, LOCTEXT("DefaultLevelName", "LEVEL NOT CREATED YET"), {} };
	}
	levelDatas[0] = { 0,0, LOCTEXT("levelName0.1", "EnV Pack"), {8, 9, 10} };
	levelDatas[1] = { 0,0, LOCTEXT("levelName0.2", "Touhou Pack"), {11, 12, 13, 14, 15, 16, 17, 18} };
	levelDatas[8] =	 { 1,0, LOCTEXT("levelName1.1", "Vee (Tutorial) (WIP)"), {} };
	levelDatas[11] = { 1,0, LOCTEXT("levelName2.1", "Flowering Night (WIP)"), {} };
	levelDatas[12] = { 4,0, LOCTEXT("levelName2.2", "UN Owen Was Her"), {} };
	levelDatas[13] = { 5,0, LOCTEXT("levelName2.3", "Beloved Tomboyish Girl (WIP)"), {} };
	levelDatas[14] = { 6,0, LOCTEXT("levelName2.4", "Lullaby of a Deserted Hell (WIP)"), {} };
	levelDatas[15] = { 7,0, LOCTEXT("levelName2.5", "Radiant Radiant Symphany (WIP)"), {} };
	levelDatas[16] = { 8,0, LOCTEXT("levelName2.6", "Reach for the Moon (WIP)"), {} };
	levelDatas[17] = { 9,0, LOCTEXT("levelName2.7", "Necrofantasia (WIP)"), {} };
	levelDatas[18] = { 10,0, LOCTEXT("levelName2.8", "Flight of the Bamboo Cutter (WIP)"), {} };
	positionDeltas = std::vector<float>(72, 0);

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
	isFadeToTwo = true;
	lastTex = 0;

	float posX = 1500;
	float posY = 800;
	boxInstances = std::vector<ALevelBox*>(72);
	for (int i = 0; i < levelDatas.size(); i++) {
		if (i < 8) {
			ALevelBox* tempBox = GetWorld()->SpawnActor<ALevelBox>(LevelBlockClass,
				FVector(posX, 1, posY), //- (12.5*((2*(((int)abs(posY/200))%2))-1)
				FRotator(0));
			boxInstances[i] = (tempBox);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelName")[0]))->SetText(levelDatas[i].levelName);
			tempBox->mappedLevels = levelDatas[i].subLevels;
			tempBox->isActive = true;
			tempBox->isCategory = true;
			posY -= 200;
		}
		else {
			ALevelBox* tempBox = GetWorld()->SpawnActor<ALevelBox>(LevelBlockClass,
				FVector(9999, 1, 9999), //- (12.5*((2*(((int)abs(posY/200))%2))-1)
				FRotator(0));
			boxInstances[i] = (tempBox);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelName")[0]))->SetText(levelDatas[i].levelName);
			tempBox->mappedLevels = levelDatas[i].subLevels;
			tempBox->isActive = false;
			tempBox->isCategory = false;
		}
	}
}
// Called every frame
void ALevelBlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (timer2 > 0) {
		if (timer2 < DeltaTime) {
			timer2 = 0;
			isFadeToTwo = !isFadeToTwo;
			//lastTex = i;
		}
		else {
			timer2 -= DeltaTime;
			if (isFadeToTwo) {
				dMat->SetScalarParameterValue(FName("blend"), timer2);
			}
			else {
				dMat->SetScalarParameterValue(FName("blend"), 1 - timer2);
			}
		}
		
	}
	for (int i = 0; i < boxInstances.size(); i++) {
		if (!boxInstances[i]->isActive) {
			continue;
		}
		if (boxInstances[i]->isCursorHovering) {
			if (pController->WasInputKeyJustPressed(leftClick)) {

				//UnselectAllBoxes();

				if (boxInstances[i]->isSelected_) {
					//already selected (clicking again)
					if (!boxInstances[i]->isCategory) {
						if (i == 1 || i == 0) {
							ABulletController::levelIndex = i;
							UGameplayStatics::OpenLevel(this, FName("Minimal_Default"));
						}
						else {
							GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LEVEL NOT RDY");
						}
					}
					else {
						//collapse levels
						for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
							int boxIndex = boxInstances[i]->mappedLevels[j];
							if (boxInstances[boxIndex]->isSelected_) {
								//quickly deselects sublevels
								UpdateDeltas(boxIndex, -100 * boxInstances[boxIndex]->timer2);
								boxInstances[boxIndex]->AddActorLocalOffset(FVector(350 * (boxInstances[i]->timer2), 0, 0));
								boxInstances[boxIndex]->timer2 = 0;
							}
							boxInstances[boxIndex]->isActive = false;
							//boxInstances[boxIndex]->timer = 1;
						}
						for (int j = 0; j < boxInstances.size(); j++) {
							if (boxInstances[j]->isActive && boxInstances[j]->GetActorLocation().Z < boxInstances[i]->GetActorLocation().Z) {
								boxInstances[j]->AddActorLocalOffset(FVector(0, 0, boxInstances[i]->mappedLevels.size() * 200.0 * ((boxInstances[i]->timer3) / 0.2)));
								//positionDeltas[j] += boxInstances[i]->mappedLevels.size() * -200.0;
							}
						}
						
						UnselectAllBoxes();
						boxInstances[i]->timer3 -= 0.2;
						boxInstances[i]->isSelected_ = false;
						
					}
				}
				else {
					UnselectAllBoxes();
					//selecting now (clicking for the first time)
					boxInstances[i]->isSelected_ = true;
					timer2 = 1;
					//back1->GetStaticMeshComponent()->GetMaterial()->
					//dMat->SetTextureParameterValue(FName("tex_1"), getBackround(lastTex));
					if (isFadeToTwo) {
						dMat->SetTextureParameterValue(FName("tex_2"), getBackround(i));
					}
					else {
						dMat->SetTextureParameterValue(FName("tex_1"), getBackround(i));
					}

					getSound(lastTex)->FadeOut(1, 0);
					getSound(i)->FadeIn(1);
					lastTex = i;
					
					if(boxInstances[i]->isCategory) {
						//expand levels
						for (int j = 0; j < boxInstances.size(); j++) {
							if (boxInstances[j]->isActive && boxInstances[j]->GetActorLocation().Z < boxInstances[i]->GetActorLocation().Z) {
								boxInstances[j]->AddActorLocalOffset(FVector(0, 0, boxInstances[i]->mappedLevels.size() * -200.0 * ((0.2 + boxInstances[i]->timer3)/0.2)));
								//positionDeltas[j] += boxInstances[i]->mappedLevels.size() * -200.0;
							}
						}
						if (boxInstances[i]->timer3 == 0) {
							for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
								int boxIndex = boxInstances[i]->mappedLevels[j];
								boxInstances[boxIndex]->SetActorLocation(FVector(3000, 1, boxInstances[i]->GetActorLocation().Z - (200 * (j + 1)) - 100 * (boxInstances[i]->timer))); //-20
								boxInstances[boxIndex]->isActive = true;
								//boxInstances[boxIndex]->timer = 1;
							}
						}
						boxInstances[i]->timer3 += 0.2;
					}
				}
			}
			if (boxInstances[i]->timer != 0.2) {
				if (DeltaTime > 0.2 - boxInstances[i]->timer) {
					UpdateDeltas(i, 100 * (0.2 - boxInstances[i]->timer));
					boxInstances[i]->timer = 0.2;
				}
				else {
					UpdateDeltas(i, 100 * DeltaTime);
					boxInstances[i]->timer += DeltaTime;
				}
				boxInstances[i]->SetActorRelativeScale3D(FVector(boxInstances[i]->timer * 0.5 + 0.7));
			}
		}
		else if (boxInstances[i]->timer != 0) {
			if (DeltaTime > boxInstances[i]->timer) {
				UpdateDeltas(i, -100 * (boxInstances[i]->timer));
				boxInstances[i]->timer = 0;
			} else {
				UpdateDeltas(i, -100 * DeltaTime);
				boxInstances[i]->timer -= DeltaTime;
			}
			boxInstances[i]->SetActorRelativeScale3D(FVector(boxInstances[i]->timer*0.5  + 0.7));
		}
		if (boxInstances[i]->timer2 != 0.2 && boxInstances[i]->isSelected_) {
			if (DeltaTime > 0.2 - boxInstances[i]->timer2) {
				UpdateDeltas(i, 100 * (0.2 - boxInstances[i]->timer2));
				boxInstances[i]->AddActorLocalOffset(FVector(-350 * (0.2 - boxInstances[i]->timer2), 0, 0));
				boxInstances[i]->timer2 = 0.2;
			}
			else {
				UpdateDeltas(i, 100 * DeltaTime);
				boxInstances[i]->AddActorLocalOffset(FVector(-350 * DeltaTime, 0, 0));
				boxInstances[i]->timer2 += 1 * DeltaTime;
			}
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
				boxInstances[i]->timer2 -= 1 * DeltaTime;
			}
		}
		if (boxInstances[i]->timer3 != 0) {
			if (DeltaTime > fabs(boxInstances[i]->timer3)) {
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(fabs(boxInstances[i]->timer3)));
				if (boxInstances[i]->timer3 > 0) {
					//coming forward
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						int boxIndex = boxInstances[i]->mappedLevels[j];
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(-7500 * (boxInstances[i]->timer3), 0, 0));
						boxInstances[boxIndex]->isActive = true;
					}
					boxInstances[i]->timer3 = 0;
				}
				else {
					//going back
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						int boxIndex = boxInstances[i]->mappedLevels[j];
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(-7500 * (boxInstances[i]->timer3), 0, 0));
						//boxInstances[boxIndex]->isActive = false;
						
					}
					/*
					for (int j = 0; j < boxInstances.size(); j++) {
						//snaps bottom back
						if (boxInstances[j]->isActive && boxInstances[j]->GetActorLocation().Z < boxInstances[i]->GetActorLocation().Z) {
							boxInstances[j]->AddActorLocalOffset(FVector(0, 0, (boxInstances[i]->mappedLevels.size() * 200.0)));
						}
					}
					*/
					for (int j = 0; j < boxInstances.size(); j++) {
						//snaps bottom back
						if (boxInstances[j]->isActive && boxInstances[j]->GetActorLocation().Z < boxInstances[i]->GetActorLocation().Z) {
							boxInstances[j]->AddActorLocalOffset(FVector(0, 0, (boxInstances[i]->mappedLevels.size() * -200.0 * (boxInstances[i]->timer3)/0.2)));
						}
					}
					boxInstances[i]->timer3 = 0;
				}

			}
			else {
				if (boxInstances[i]->timer3 > 0) {
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						//coming forward
						int boxIndex = boxInstances[i]->mappedLevels[j];
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(-7500 * DeltaTime, 0, 0));
					}
					boxInstances[i]->timer3 -= 1 * DeltaTime;
				}
				else {
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						//going back
						int boxIndex = boxInstances[i]->mappedLevels[j];
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(7500 * DeltaTime, 0, 0));
					}
					for (int j = 0; j < boxInstances.size(); j++) {
						//moves bottom back
						if (boxInstances[j]->isActive && boxInstances[j]->GetActorLocation().Z < boxInstances[i]->GetActorLocation().Z) {
							boxInstances[j]->AddActorLocalOffset(FVector(0, 0, (boxInstances[i]->mappedLevels.size() * 200.0 * (DeltaTime / 0.2))));
						}
					}
					boxInstances[i]->timer3 += 1 * DeltaTime;
				}
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
	for (int i = 0; i < positionDeltas.size(); i++) {
		if (boxInstances[index]->isActive) {
			if (boxInstances[i]->GetActorLocation().Z > boxInstances[index]->GetActorLocation().Z) {
				positionDeltas[i] += delta;
			}
			else if (boxInstances[i]->GetActorLocation().Z < boxInstances[index]->GetActorLocation().Z){
				positionDeltas[i] -= delta;
			}
		}
	}
	/*
	for (int i = 0; i < index; i++) {
		positionDeltas[i] += delta;
	}
	for (int i = index + 1; i < positionDeltas.size(); i++) {
		positionDeltas[i] -= delta;
	}
	*/
}
void ALevelBlockManager::UnselectAllBoxes()
{
	for (int i = 0; i < boxInstances.size(); i++) {
		if (!boxInstances[i]->isCategory) {
			boxInstances[i]->isSelected_ = false;
		}
	}
}
UTexture* ALevelBlockManager::getBackround(int i)
{
	if (i == 11) {
		return tex1;
	}
	else if (i == 12) {
		return tex2;
	}
	else if (i == 13) {
		return tex3;
	}
	else if (i == 14) {
		return tex4;
	}
	else if (i == 15) {
		return tex5;
	}
	else if (i == 16) {
		return tex6;
	}
	else if (i == 17) {
		return tex7;
	}
	else if (i == 18) {
		return tex8;
	}
	else if (i == 19) {

	}
	else {

	}
	return tex1;
}
UAudioComponent* ALevelBlockManager::getSound(int i)
{
	if (i == 11) {
		return audio1;
	}
	else if (i == 12) {
		return audio2;
	}
	else if (i == 13) {
		return audio3;
	}
	else if (i == 14) {
		return audio4;
	}
	else if (i == 15) {
		return audio5;
	}
	else if (i == 16) {
		return audio6;
	}
	else if (i == 17) {
		return audio7;
	}
	else if (i == 18) {
		return audio8;
	}
	else if (i == 19) {

	}
	else {

	}
	return audio1;
}
#undef LOCTEXT_NAMESPACE

