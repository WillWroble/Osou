// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelBlockManager.h"

#define LOCTEXT_NAMESPACE "LevelNames"
std::vector<LevelData> ALevelBlockManager::levelDatas = std::vector <LevelData>(72);
// Sets default values
ALevelBlockManager::ALevelBlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	timer = 0;
	timer2 = 0;
	//levelDatas = std::vector <LevelData>(72);
	for (int i = 0; i < 72; i++) {
		//set default values
		levelDatas[i] = { -1,0, LOCTEXT("DefaultLevelName", "LEVEL NOT CREATED YET"), {}};
	}
	levelDatas[0] = { 0,0, LOCTEXT("levelName0.1", "EnV Pack"), {8, 9, 10} };
	levelDatas[1] = { 0,0, LOCTEXT("levelName0.2", "Touhou Pack"), {11, 12, 13, 14, 15, 16, 17, 18} };
	levelDatas[7] = { 0,0, LOCTEXT("levelName0.8", "Avicii Pack"), {19, 20, 21, 22} };
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
	/*
	APawn* evilPawn = pController->GetPawn();
	if (evilPawn != nullptr) {
		evilPawn->Destroy();
	}
	*/
	rightClick = FKey("RightMouseButton");
	leftClick = FKey("LeftMouseButton");
	pController = GetWorld()->GetFirstPlayerController();
	world = GetWorld();
	audio1 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag1"))[0];
	audio2 = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag2"))[0];
	audio1->SetWaveParameter(FName("wavefile"), sound1);

	pController->bShowMouseCursor = true;
	pController->bEnableMouseOverEvents = true;
	forwardPolarity = false;
	isFadeToTwo = true;
	lastTex = 0;
	scrollForce = 0;
	orderShift = 0;
	activeBoxes = 8;
	wormhole = -1270;
	isCollapsing = false;
	gradeConversionLetter = { FString(""), FString("S"), FString("A"), FString("B"), FString("C"), FString("D") };
	gradeConversionColor = {FColor::Transparent, FColor(0x8437DDFF), FColor(0x29A329FF), FColor(0x86A326FF), FColor(0xE9DB08FF), FColor(0xE90908FF) };

	BindToInput();
	FAsyncLoadGameFromSlotDelegate LoadedDelegate;
	LoadedDelegate.BindUObject(this, &ALevelBlockManager::FinishedLoadingLevels);
	UGameplayStatics::AsyncLoadGameFromSlot(FString("osou_save"), 0, LoadedDelegate);
	
	levelMap = { -1, -1, -1, -1, -1, -1, -1, -1,
	0, -1, -1, 2, 1, 3, 4, 5, 6, 7, 8};
	for (int i = 0; i < 70; i++) {
		levelMap.push_back(-1);
	}
	APawn* evilPawn = pController->GetPawn();
	if (evilPawn != nullptr) {
		evilPawn->Destroy();
	}
	
}
// Called every frame
void ALevelBlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (boxInstances.empty()) {
		return;
	}
	
	if (scrollForce != 0) {
		if (scrollForce < -100) {
			scrollForce = -100;//-0.8334/(DeltaTime);
		}
		else if (scrollForce > 100){
			scrollForce = 100;//0.8334/(DeltaTime);
		}
		AddDeltaToAll(30 * (scrollForce) * DeltaTime);
		if (scrollForce < 0) {
			scrollForce += 200 * DeltaTime; //1.667
			if (scrollForce > 0) {
				scrollForce = 0;
			}
		}
		else {
			scrollForce -= 200 * DeltaTime;//200 * DeltaTime;
			if (scrollForce < 0) {
				scrollForce = 0;
			}
		}
	}
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
						int n = levelMap[i];
						if (n == 1 || n == 0) {
							ABulletController::levelIndex = n;
							UGameplayStatics::OpenLevel(this, FName("Minimal_Default"));
						}
						else {
							GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LEVEL NOT RDY");
						}
					}
					else {
						//collapse levels
						isCollapsing = true;
						for (int j = 0; j < boxInstances.size(); j++) {
							//bump
							if (boxInstances[j]->isActive && Shifted(boxInstances[j]->order_) > Shifted(boxInstances[i]->adjustedOrder())) {
								boxInstances[j]->AddActorLocalOffset(FVector(0, 0, boxInstances[i]->mappedLevels.size() * 200.0 * ((boxInstances[i]->timer3) / 0.2)));
								//positionDeltas[j] += boxInstances[i]->mappedLevels.size() * -200.0;
							}
						}
						if (boxInstances[i]->timer3 == 0) {
							for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
								int boxIndex = boxInstances[i]->mappedLevels[j];
								boxInstances[boxIndex]->AddActorLocalOffset(FVector(0, -0.5, 0));
								//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LTT IS COLL");
								//boxInstances[boxIndex]->timer = 1;
							}
						}
						
						UnselectAllBoxes();
						boxInstances[i]->timer3 -= 0.2;
						boxInstances[i]->isSelected_ = false;
						
					}
				}
				else if(boxInstances[i]->GetActorLocation().X <= 1510){
					UnselectAllBoxes();
					//selecting now (clicking for the first time)
					boxInstances[i]->isSelected_ = true;
					timer2 = 1;
					//back1->GetStaticMeshComponent()->GetMaterial()->
					//dMat->SetTextureParameterValue(FName("tex_1"), getBackround(lastTex));
					if (isFadeToTwo) {
						dMat->SetTextureParameterValue(FName("tex_2"), getBackround(i));
						audio2->SetWaveParameter(FName("wavefile"), getSound(i));
						audio1->FadeOut(1, 0);
						audio2->FadeIn(1);
					}
					else {
						dMat->SetTextureParameterValue(FName("tex_1"), getBackround(i));
						audio1->SetWaveParameter(FName("wavefile"), getSound(i));
						audio2->FadeOut(1, 0);
						audio1->FadeIn(1);
					}

					//getSound(lastTex)->FadeOut(1, 0);
					//getSound(i)->FadeIn(1);
					
					lastTex = i;
					
					if(boxInstances[i]->isCategory) {
						//expand levels
						isCollapsing = true;
						activeBoxes += boxInstances[i]->mappedLevels.size();
						for (int j = 0; j < boxInstances.size(); j++) {
							if (boxInstances[j]->isActive && Shifted(boxInstances[j]->order_) > Shifted(boxInstances[i]->adjustedOrder())) {
								boxInstances[j]->AddActorLocalOffset(FVector(0, 0, boxInstances[i]->mappedLevels.size() * -200.0 * ((0.2 + boxInstances[i]->timer3)/0.2)));
								//positionDeltas[j] += boxInstances[i]->mappedLevels.size() * -200.0;
							}
						}
						if (boxInstances[i]->timer3 == 0) {
							for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
								int boxIndex = boxInstances[i]->mappedLevels[j];
								boxInstances[boxIndex]->SetActorLocation(FVector(3000, 0.5, boxInstances[i]->GetActorLocation().Z - (200 * (j + 1)) - 100 * (boxInstances[i]->timer))); //-20
								boxInstances[boxIndex]->isActive = true;
								//boxInstances[boxIndex]->timer = 1;
							}
						}
						boxInstances[i]->timer3 += 0.2;
					}
				}
			}
			if (boxInstances[i]->timer != 0.2 && boxInstances[i]->GetActorLocation().X <= 1510) {
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
			if (DeltaTime + curveCoeff * (DeltaTime * (0.2 * (boxInstances[i]->timer3 > 0) - boxInstances[i]->timer3)) > fabs(boxInstances[i]->timer3) || (false  && boxInstances[i]->timer3 < 0)) {
				isCollapsing = false;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "SNAPPING");
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(fabs(boxInstances[i]->timer3)));
				if (boxInstances[i]->timer3 > 0) {
					//coming forward
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						int boxIndex = boxInstances[i]->mappedLevels[j];
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(-7500 * (boxInstances[i]->timer3), 0.5, 0));
						boxInstances[boxIndex]->isActive = true;
					}
					boxInstances[i]->timer3 = 0;
				}
				else {
					//going back
					activeBoxes -= boxInstances[i]->mappedLevels.size();
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						int boxIndex = boxInstances[i]->mappedLevels[j];
						//boxInstances[boxIndex]->AddActorLocalOffset(FVector(-7500 * (boxInstances[i]->timer3), 0, 0));
						//boxInstances[boxIndex]->isActive = false;
						//boxInstances[boxIndex]->isSelected_ = false;
						if (boxInstances[boxIndex]->timer2 != 0) {
							UpdateDeltas(boxIndex, -100 * (boxInstances[boxIndex]->timer2));
							boxInstances[boxIndex]->AddActorLocalOffset(FVector(350 * (boxInstances[boxIndex]->timer2), 0, 0));
							boxInstances[boxIndex]->timer2 = 0;
							boxInstances[boxIndex]->isSelected_ = false;
						}
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(-7500 * (boxInstances[i]->timer3), 0, 0));
						boxInstances[boxIndex]->isActive = false;
						//boxInstances[boxIndex]->timer2 = 0;
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
						if (boxInstances[j]->isActive && Shifted(boxInstances[j]->order_) > Shifted(boxInstances[i]->adjustedOrder())) {
							boxInstances[j]->AddActorLocalOffset(FVector(0, 0, (boxInstances[i]->mappedLevels.size() * -200.0 * (boxInstances[i]->timer3)/0.2)));
						}
					}
					boxInstances[i]->timer3 = 0;
				}

			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "MOVING");
				if (boxInstances[i]->timer3 > 0) {
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						//coming forward
						int boxIndex = boxInstances[i]->mappedLevels[j];
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(-7500 * (DeltaTime + curveCoeff * (DeltaTime * (0.2 - boxInstances[i]->timer3))), 0, 0));
					}
					boxInstances[i]->timer3 -= 1 * DeltaTime + curveCoeff * (DeltaTime * (0.2 - boxInstances[i]->timer3));
				}
				else {
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						//going back
						int boxIndex = boxInstances[i]->mappedLevels[j];
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(7500 * (DeltaTime + curveCoeff * (DeltaTime * (-1* boxInstances[i]->timer3))), 0, 0));
					}
					for (int j = 0; j < boxInstances.size(); j++) {
						//moves bottom back
						if (boxInstances[j]->isActive && Shifted(boxInstances[j]->order_) > Shifted(boxInstances[i]->adjustedOrder())) {
							boxInstances[j]->AddActorLocalOffset(FVector(0, 0, (boxInstances[i]->mappedLevels.size() * 200.0 * ((DeltaTime + curveCoeff * (DeltaTime * (-1 * boxInstances[i]->timer3))) / 0.2))));
						}
					}
					boxInstances[i]->timer3 += (1 * DeltaTime + curveCoeff*(DeltaTime*(-1*(boxInstances[i]->timer3))));
				}
			}
		}
	}
	
	if (pController->IsInputKeyDown(rightClick) || pController->IsInputKeyDown(leftClick)) {
		//enable scrolling
		
		float dx; float dy;
		pController->GetInputMouseDelta(dx, dy);

		scrollForce += 50*dy;
			
		
	}
	
	for (int i = 0; i < positionDeltas.size(); i++) {
		//int temp = floor(GetActorLocation().Z / 200);
		//int multiplier = (abs(2 * (((int)floor(boxInstances[i]->GetActorLocation().Z / 200)) % 2)) - 1);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, *(FString::FromInt(temp)));
		boxInstances[i]->AddActorLocalOffset(FVector(0, 0, positionDeltas[i])); //positionDeltas[i] * 0.125 * multiplier
		positionDeltas[i] = 0;
		if (boxInstances[i]->isActive && !isCollapsing) {
			float posX = boxInstances[i]->GetActorLocation().X;
			float deltaZ = boxInstances[i]->GetActorLocation().Z + 1400 + (200 * (activeBoxes-8));
			if (deltaZ < 0) {
				boxInstances[i]->SetActorLocation(FVector(posX, 1, 1400 + deltaZ));
				orderShift = 72-boxInstances[i]->order_;
			}
			deltaZ = boxInstances[i]->GetActorLocation().Z - 1400;
			if (deltaZ > 0) {
				boxInstances[i]->SetActorLocation(FVector(posX, 1, -1400 - (200 * (activeBoxes-8)) + deltaZ));
				orderShift = 71-boxInstances[i]->order_;
			}
		}
	}
}
void ALevelBlockManager::UpdateDeltas(int index, float delta)
{
	for (int i = 0; i < positionDeltas.size(); i++) {
		if (boxInstances[i]->isActive) {
			if (boxInstances[i]->order_ < boxInstances[index]->order_) {
				positionDeltas[i] += delta;
			}
			else if (boxInstances[i]->order_ > boxInstances[index]->order_){
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
void ALevelBlockManager::AddDeltaToAll(float delta)
{
	for (int i = 0; i < positionDeltas.size(); i++) {
		if (boxInstances[i]->isActive) {
			positionDeltas[i] += delta;
		}
	}
}
void ALevelBlockManager::UnselectAllBoxes()
{
	for (int i = 0; i < boxInstances.size(); i++) {
		if (!boxInstances[i]->isCategory) {
			boxInstances[i]->isSelected_ = false;
		}
	}
}
void ALevelBlockManager::BindToInput()
{
	// Initialize our component
	InputComponent = NewObject<UInputComponent>(this);
	InputComponent->RegisterComponent();
	if (InputComponent)
	{
		// Bind inputs here
		// InputComponent->BindAction("Jump", IE_Pressed, this, &AUnrealisticPawn::Jump);
		// etc...
		InputComponent->BindAction("ScrollDown", IE_Pressed, this, &ALevelBlockManager::ScrollDown);
		InputComponent->BindAction("ScrollUp", IE_Pressed, this, &ALevelBlockManager::ScrollUp);

		// Now hook up our InputComponent to one in a Player
		// Controller, so that input flows down to us
		EnableInput(pController);
	}
}
void ALevelBlockManager::FinishedLoadingLevels(const FString& SlotName, const int32 UserINdex, USaveGame* LoadedGameData)
{
	UMySaveGame* currentSave = (UMySaveGame*)LoadedGameData;
	if (currentSave) {
		for (int i = 0; i < 72; i++) {
			levelDatas[i].grade = currentSave->grades[i];
			levelDatas[i].score = currentSave->scores[i];
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "NO SAVE FILE FOUND");
		for (int i = 0; i < 72; i++) {
			levelDatas[i].grade = 0;
			levelDatas[i].score = 0;
		}
	}
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
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelScore")[0]))->SetText(gradeConversionLetter[levelDatas[i].grade]);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelScore")[0]))->SetTextRenderColor(gradeConversionColor[levelDatas[i].grade]);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "ScoreNum")[0]))->SetText(FString::Printf(TEXT("%.1f"), levelDatas[i].score));
			if (levelDatas[i].score == 0) {
				((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "ScoreNum")[0]))->SetText(FString(""));
			}
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
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelScore")[0]))->SetText(gradeConversionLetter[levelDatas[i].grade]);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelScore")[0]))->SetTextRenderColor(gradeConversionColor[levelDatas[i].grade]);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "ScoreNum")[0]))->SetText(FString::Printf(TEXT("%.1f"), levelDatas[i].score));

			if (levelDatas[i].score == 0) {
				((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "ScoreNum")[0]))->SetText(FString(""));
			}

			tempBox->mappedLevels = levelDatas[i].subLevels;
			tempBox->isActive = false;
			tempBox->isCategory = false;
		}
	}

	int orderCount = 0;
	for (int i = 0; i < 8; i++) {
		boxInstances[i]->order_ = orderCount;
		orderCount++;
		for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
			boxInstances[boxInstances[i]->mappedLevels[j]]->order_ = orderCount;
			orderCount++;
		}
	}
}
void ALevelBlockManager::ScrollDown()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "SCROLLING DOWN");
	scrollForce += 50;
	//float newScrollForce = scrollForce - 50;
	/*
	if (newScrollForce < -100) {
		scrollForce = -100;
	}
	else {
		scrollForce = newScrollForce;
	}
	//scrollForce = -100;
	*/
}
void ALevelBlockManager::ScrollUp()
{
	scrollForce -= 50;
	//float newScrollForce = scrollForce + 50;
	/*
	if (newScrollForce > 100) {
		scrollForce = 100;
	}
	else {
		scrollForce = newScrollForce;
	}
	*/
	//scrollForce = 100;
}
int ALevelBlockManager::Shifted(int n)
{
	return (n + orderShift) % 72;
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
	else if (i == 1) {
		return tex9;
	}
	else if (i == 0) {
		return tex10;
	}
	else if (i == 8) {
		return tex11;
	}
	else if (i == 9) {
		return tex12;
	}
	else if (i == 10) {
		return tex13;
	}
	else {

	}
	return tex1;
}
USoundWave* ALevelBlockManager::getSound(int i)
{
	if (i == 11) {
		return sound1;
	}
	else if (i == 12) {
		return sound2;
	}
	else if (i == 13) {
		return sound3;
	}
	else if (i == 14) {
		return sound4;
	}
	else if (i == 15) {
		return sound5;
	}
	else if (i == 16) {
		return sound6;
	}
	else if (i == 17) {
		return sound7;
	}
	else if (i == 18) {
		return sound8;
	}
	else if (i == 1) {
		return sound9;
	}
	else if (i == 0) {
		return sound10;
	}
	else if (i == 8) {
		return sound11;
	}
	else if (i == 9) {
		return sound12;
	}
	else if (i == 10) {
		return sound13;
	}
	else {

	}
	return sound1;
}
#undef LOCTEXT_NAMESPACE

