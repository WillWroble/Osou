// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelBlockManager.h"

#define LOCTEXT_NAMESPACE "LevelNames"
std::vector<LevelData> ALevelBlockManager::levelDatas = std::vector <LevelData>(73);
// Sets default values
ALevelBlockManager::ALevelBlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	timer = 0;
	timer2 = 0;
	scrollTarget = FVector(0, 0, 0);
	//levelDatas = std::vector <LevelData>(73);
	for (int i = 0; i < 73; i++) {
		//set default values
		levelDatas[i] = { -1,0, LOCTEXT("DefaultLevelName", "LEVEL NOT CREATED YET"), {}};
	}
	levelDatas[0] = { 0,0, LOCTEXT("levelName0.1", "EnV Pack"), LOCTEXT("artistName0.1", "     Artwork by Le Juicer abc"), {8, 23,  9, 10}};
	levelDatas[1] = { 0,0, LOCTEXT("levelName0.2", "Touhou Pack"), LOCTEXT("artistName0.2", "     Artwork by My Juicer 123"), {11, 12, 13, 14, 15, 16, 17, 18} };
	levelDatas[7] = { 0,0, LOCTEXT("levelName0.8", "True Rhythm (Experimental)"), LOCTEXT("artistName0.8", "     Artwork by XQCL abc123"), {19, 20, 21, 22} };
	levelDatas[8] =	{ 1,1, LOCTEXT("levelName1.1", "Vee (Tutorial)"), LOCTEXT("artistName1.1", "     Artwork by EL GOBLINO ZZZXX"), {} };
	levelDatas[9] = { 1,2, LOCTEXT("levelName1.2", "Streetlights (WIP)"), LOCTEXT("artistName1.2", "     lol"), {} };
	levelDatas[10] = { 2,4, LOCTEXT("levelName1.3", "Enn (WIP)"), LOCTEXT("artistName1.3", "     Artwork by Pei (Sumurai)"), {} };
	levelDatas[11] = { 3,2, LOCTEXT("levelName2.1", "Flowering Night (WIP)"), LOCTEXT("artistName2.1", "     lol"), {} };
	levelDatas[12] = { 4,2, LOCTEXT("levelName2.2", "UN Owen Was Her"), LOCTEXT("artistName2.2", "     lol"), {} };
	levelDatas[13] = { 5,2, LOCTEXT("levelName2.3", "Beloved Tomboyish Girl (WIP)"), LOCTEXT("artistName2.3", "     lol"), {} };
	levelDatas[14] = { 6,3, LOCTEXT("levelName2.4", "Lullaby of a Deserted Hell (WIP)"), LOCTEXT("artistName2.4", "     lol"), {} };
	levelDatas[15] = { 7,3, LOCTEXT("levelName2.5", "Radiant Radiant Symphany (WIP)"), LOCTEXT("artistName2.5", "     lol"), {} };
	levelDatas[16] = { 8,4, LOCTEXT("levelName2.6", "Reach for the Moon (WIP)"), LOCTEXT("artistName2.6", "     lol"), {} };
	levelDatas[17] = { 9,4, LOCTEXT("levelName2.7", "Necrofantasia (WIP)"), LOCTEXT("artistName2.7", "     lol"), {} };
	levelDatas[18] = { 10,4, LOCTEXT("levelName2.8", "Flight of the Bamboo Cutter (WIP)"), LOCTEXT("artistName2.8", "     lol"), {} };
	levelDatas[23] = { 10, 2, LOCTEXT("levelName1.4", "Vee (full level)"), LOCTEXT("artistName1.4", "     Artwork by Unknown Artist"), {} };
	levelDatas[19] = { 10, 2, LOCTEXT("levelName8.1", "Simple Rhythm"), LOCTEXT("artistName8.1", "     Artwork by Unknown Artist"), {} };
	levelDatas[20] = { 10, 2, LOCTEXT("levelName8.2", "Every Battle (PREVIEW)"), LOCTEXT("artistName8.2", "     Artwork by Unknown Artist"), {} };


	positionDeltas = std::vector<float>(73, 0);

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
	audio1->SetWaveParameter(FName("wavefile"), sound0);

	pController->bShowMouseCursor = true;
	pController->bEnableMouseOverEvents = true;
	forwardPolarity = false;
	isFadeToTwo = true;
	wtf = true;
	normalUp = true;
	normalDown = true;
	lastTex = 0;
	scrollForce = 0;
	orderShift = 0;
	upShift = 0;
	downShift = 0;
	activeBoxes = 8;
	wormhole = -1270;
	isCollapsing = false;
	gradeConversionLetter = { FString(""), FString("S"), FString("A"), FString("B"), FString("C"), FString("D") };
	gradeConversionColor = {FColor::Transparent, FColor::Purple, FColor::Green, FColor::Yellow, FColor::Orange, FColor::Red };


	BindToInput();
	FAsyncLoadGameFromSlotDelegate LoadedDelegate;
	LoadedDelegate.BindUObject(this, &ALevelBlockManager::FinishedLoadingLevels);
	UGameplayStatics::AsyncLoadGameFromSlot(FString("osou_save"), 0, LoadedDelegate);
	
	levelMap = { -1, -1, -1, -1, -1, -1, -1, -1,
	0, -1, -1, 2, 1, -1, 4, 5, 6, 7, 8};
	for (int i = 0; i < 70; i++) {
		levelMap.push_back(-1);
	}
	levelMap[23] = 2;
	levelMap[19] = 3;
	levelMap[20] = 4;
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
		if (scrollForce < -360) {
			scrollForce = -360;//-0.8334/(DeltaTime);
		}
		else if (scrollForce > 360){
			scrollForce = 360;//0.8334/(DeltaTime);
		}
		AddDeltaToAll(30 * (scrollForce) * DeltaTime*1.70666666667);
		//AddDeltaToAll(30 * (scrollForce)*(1.0f/60.0f) * 1.70666666667);
		//levelBoxHub->AddActorLocalOffset(FVector(0, 0, 1) * 30 * (scrollForce)*DeltaTime);
		if (scrollForce < 0) {
			scrollForce -= DeltaTime * (2*scrollForce-60); //1.667
			if (scrollForce > 0) {
				scrollForce = 0;
			}
		}
		else {
			scrollForce -= DeltaTime * (2*scrollForce+60);//360 * DeltaTime;
			if (scrollForce < 0) {
				scrollForce = 0;
			}
		}
	}
	if (timer2 > 0) {
		if (timer2 < DeltaTime) {
			timer2 = 0;
			if (isFadeToTwo) {
				dMat->SetScalarParameterValue(FName("blend"), timer2);
			}
			else {
				dMat->SetScalarParameterValue(FName("blend"), 1 - timer2);
			}
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
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "UVVGVGVYTYT");
				if (boxInstances[i]->isSelected_) {
					//already selected (clicking again)
					if (!boxInstances[i]->isCategory) {
						int n = levelMap[i];
						if (n == 2|| n == 1 || n == 0 || n == 3 || n == 4) {
							ABulletController::levelIndex = n;
							if (n == 3 || n == 4) {
								CheckForCalibration();
								if (hasCalibrated) {
									AKillMe::is4HealthStatic = true;
									UGameplayStatics::OpenLevel(this, FName("TrueRhythm"));
								}
							}
							else {
								AKillMe::is4HealthStatic = false;
								UGameplayStatics::OpenLevel(this, FName("Classic"));
							}
							
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
								boxInstances[j]->AddActorLocalOffset(FVector(0, 0, boxInstances[i]->mappedLevels.size() * 360.0 * ((boxInstances[i]->timer3) / 0.2)));
								//positionDeltas[j] += boxInstances[i]->mappedLevels.size() * -360.0;
							}
						}
						if (boxInstances[i]->timer3 == 0) {
							for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
								int boxIndex = boxInstances[i]->mappedLevels[j];
								boxInstances[boxIndex]->AddActorLocalOffset(FVector(0, -0.5, 0));
								boxInstances[boxIndex]->isPreExpanded = false;
								//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LTT IS COLL");
								//boxInstances[boxIndex]->timer = 1;
							}
						}
						for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
							int boxIndex = boxInstances[i]->mappedLevels[j];
							boxInstances[boxIndex]->isPreExpanded = false;
						}
						
						UnselectAllBoxes();
						boxInstances[i]->timer3 -= 0.2;
						boxInstances[i]->isSelected_ = false;
						
					}
				}
				else if(boxInstances[i]->GetActorLocation().X <= 3020){
					UnselectAllBoxes();
					//selecting now (clicking for the first time)
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "SELECTING");
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
					textOut = levelDatas[i].artistCredit;
					SetUIProperties();
					//getSound(lastTex)->FadeOut(1, 0);
					//getSound(i)->FadeIn(1);
					
					lastTex = i;
					
					if(boxInstances[i]->isCategory) {
						//expand levels
						isCollapsing = true;
						for (int j = 0; j < boxInstances.size(); j++) {
							if (boxInstances[j]->isActive && Shifted(boxInstances[j]->order_) > Shifted(boxInstances[i]->adjustedOrder())) {
								boxInstances[j]->AddActorLocalOffset(FVector(0, 0, boxInstances[i]->mappedLevels.size() * -360.0 * ((0.2 + boxInstances[i]->timer3)/0.2)));
								if (boxInstances[j]->GetActorLocation().Z < -2890) {
									boxInstances[j]->splitDistance = true;
								}
								//positionDeltas[j] += boxInstances[i]->mappedLevels.size() * -360.0;
							}
						}
						if (boxInstances[i]->timer3 == 0) {
							activeBoxes += boxInstances[i]->mappedLevels.size();
							for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
								int boxIndex = boxInstances[i]->mappedLevels[j];
								boxInstances[boxIndex]->SetActorLocation(FVector(6000, 0.5, boxInstances[i]->GetActorLocation().Z - (360 * (j + 1)) - 200 * (boxInstances[i]->timer))); //-20
								boxInstances[boxIndex]->isActive = true;
								boxInstances[boxIndex]->SetHidden(false);
								//boxInstances[boxIndex]->timer = 1;
								//boxInstances[boxIndex]->interpTime = -1;//FVector::Dist(boxInstances[boxIndex]->GetActorLocation(), FVector(6500, 0, 0));
								if (boxInstances[boxIndex]->GetActorLocation().Z < -2890) {
									boxInstances[boxIndex]->SetActorLocation(FVector(3000, 1, boxInstances[i]->GetActorLocation().Z - (360 * (j + 1)) - 200 * (boxInstances[i]->timer)));
									boxInstances[boxIndex]->splitDistance = true;
									boxInstances[boxIndex]->isPreExpanded = true;
									GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "PRE EXPANDING");
								}
								else {
									boxInstances[boxIndex]->interpTime = -1;
								}
							}
						}
						boxInstances[i]->timer3 += 0.2;
					}
				}
			}
			if (boxInstances[i]->timer != 0.2 && boxInstances[i]->GetActorLocation().X <= 3020) {
				if (DeltaTime > 0.2 - boxInstances[i]->timer) {
					UpdateDeltas(i, 200 * (0.2 - boxInstances[i]->timer));
					boxInstances[i]->timer = 0.2;
				}
				else {
					UpdateDeltas(i, 200 * DeltaTime);
					boxInstances[i]->timer += DeltaTime;
				}
				//boxInstances[i]->SetActorRelativeScale3D(FVector(boxInstances[i]->timer * 1 + 1));
			}
		}
		else if (boxInstances[i]->timer != 0) {
			if (DeltaTime > boxInstances[i]->timer) {
				UpdateDeltas(i, -200 * (boxInstances[i]->timer));
				boxInstances[i]->timer = 0;
			} else {
				UpdateDeltas(i, -200 * DeltaTime);
				boxInstances[i]->timer -= DeltaTime;
			}
			//boxInstances[i]->SetActorRelativeScale3D(FVector(boxInstances[i]->timer* 1  + 1));
		}
		if (boxInstances[i]->timer2 != 0.2 && boxInstances[i]->isSelected_) {
			if (DeltaTime > 0.2 - boxInstances[i]->timer2) {
				UpdateDeltas(i, 200 * (0.2 - boxInstances[i]->timer2));
				boxInstances[i]->AddActorLocalOffset(FVector(-700 * (0.2 - boxInstances[i]->timer2), 0, 0));
				boxInstances[i]->timer2 = 0.2;
			}
			else {
				UpdateDeltas(i, 200 * DeltaTime);
				boxInstances[i]->AddActorLocalOffset(FVector(-700 * DeltaTime, 0, 0));
				boxInstances[i]->timer2 += 1 * DeltaTime;
			}
		}
		if (boxInstances[i]->timer2 != 0 && !boxInstances[i]->isSelected_) {
			if (DeltaTime > boxInstances[i]->timer2) {
				UpdateDeltas(i, -200 * (boxInstances[i]->timer2));
				boxInstances[i]->AddActorLocalOffset(FVector(700 * (boxInstances[i]->timer2), 0, 0));
				boxInstances[i]->timer2 = 0;
			}
			else {
				UpdateDeltas(i, -200 * DeltaTime);
				boxInstances[i]->AddActorLocalOffset(FVector(700 * DeltaTime, 0, 0));
				boxInstances[i]->timer2 -= 1 * DeltaTime;
			}
		}
		if (boxInstances[i]->timer3 != 0) {
			if (DeltaTime + curveCoeff * (DeltaTime * (0.2 * (boxInstances[i]->timer3 > 0) - boxInstances[i]->timer3)) >= fabs(boxInstances[i]->timer3) || (false  && boxInstances[i]->timer3 < 0)) {
				isCollapsing = false;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "SNAPPING");
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(fabs(boxInstances[i]->timer3)));
				if (boxInstances[i]->timer3 > 0) {
					//coming forward
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						int boxIndex = boxInstances[i]->mappedLevels[j];
						if (!boxInstances[boxIndex]->isPreExpanded) {
							boxInstances[boxIndex]->AddActorLocalOffset(FVector(-15000 * (boxInstances[i]->timer3), 0.5, 0));
						}
						boxInstances[boxIndex]->isPreExpanded = false;
						boxInstances[boxIndex]->isActive = true;
						boxInstances[boxIndex]->interpTime = -1;
					}
					boxInstances[i]->timer3 = 0;
				}
				else {
					//going back
					activeBoxes -= boxInstances[i]->mappedLevels.size();
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						int boxIndex = boxInstances[i]->mappedLevels[j];
						//boxInstances[boxIndex]->AddActorLocalOffset(FVector(-15000 * (boxInstances[i]->timer3), 0, 0));
						//boxInstances[boxIndex]->isActive = false;
						//boxInstances[boxIndex]->isSelected_ = false;
						if (boxInstances[boxIndex]->timer2 != 0) {
							UpdateDeltas(boxIndex, -200 * (boxInstances[boxIndex]->timer2));
							boxInstances[boxIndex]->AddActorLocalOffset(FVector(700 * (boxInstances[boxIndex]->timer2), 0, 0));
							boxInstances[boxIndex]->timer2 = 0;
							boxInstances[boxIndex]->isSelected_ = false;
						}
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(-15000 * (boxInstances[i]->timer3), 0, 0));
						boxInstances[boxIndex]->isActive = false;
						boxInstances[boxIndex]->isPreExpanded = false;
						boxInstances[boxIndex]->SetHidden(true);
						//boxInstances[boxIndex]->timer2 = 0;
					}
					/*
					for (int j = 0; j < boxInstances.size(); j++) {
						//snaps bottom back
						if (boxInstances[j]->isActive && boxInstances[j]->GetActorLocation().Z < boxInstances[i]->GetActorLocation().Z) {
							boxInstances[j]->AddActorLocalOffset(FVector(0, 0, (boxInstances[i]->mappedLevels.size() * 360.0)));
						}
					}
					*/
					for (int j = 0; j < boxInstances.size(); j++) {
						//snaps bottom back
						if (boxInstances[j]->isActive && Shifted(boxInstances[j]->order_) > Shifted(boxInstances[i]->adjustedOrder())) {
							boxInstances[j]->AddActorLocalOffset(FVector(0, 0, (boxInstances[i]->mappedLevels.size() * -360.0 * (boxInstances[i]->timer3)/0.2)));
							boxInstances[j]->interpTime = -1;
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
						//if (boxInstances[boxIndex]->isPreExpanded) continue;
						if (!boxInstances[boxIndex]->isPreExpanded) {
							boxInstances[boxIndex]->AddActorLocalOffset(FVector(-15000 * (DeltaTime + curveCoeff * (DeltaTime * (0.2 - boxInstances[i]->timer3))), 0, 0));
						}
						boxInstances[boxIndex]->interpTime = -1;//FVector::Dist(boxInstances[boxIndex]->GetActorLocation(), FVector(6500, 0, 0));
					}
					boxInstances[i]->timer3 -= 1 * DeltaTime + curveCoeff * (DeltaTime * (0.2 - boxInstances[i]->timer3));
				}
				else {
					for (int j = 0; j < boxInstances[i]->mappedLevels.size(); j++) {
						//going back
						int boxIndex = boxInstances[i]->mappedLevels[j];
						boxInstances[boxIndex]->AddActorLocalOffset(FVector(15000 * (DeltaTime + curveCoeff * (DeltaTime * (-1* boxInstances[i]->timer3))), 0, 0));
						boxInstances[boxIndex]->isPreExpanded = false;
					}
					for (int j = 0; j < boxInstances.size(); j++) {
						//moves bottom back
						if (boxInstances[j]->isActive && Shifted(boxInstances[j]->order_) > Shifted(boxInstances[i]->adjustedOrder())) {
							boxInstances[j]->AddActorLocalOffset(FVector(0, 0, (boxInstances[i]->mappedLevels.size() * 360.0 * ((DeltaTime + curveCoeff * (DeltaTime * (-1 * boxInstances[i]->timer3))) / 0.2))));
							boxInstances[j]->interpTime = -1;
						}
					}
					boxInstances[i]->timer3 += (1 * DeltaTime + curveCoeff*(DeltaTime*(-1*(boxInstances[i]->timer3))));
				}
			}
		}
		//boxInstances[i]->dTime = DeltaTime;
		//boxInstances[i]->ManualTick();
	}
	
	if (pController->IsInputKeyDown(rightClick) || pController->IsInputKeyDown(leftClick)) {
		//enable scrolling
		
		float dx; float dy;
		pController->GetInputMouseDelta(dx, dy);

		scrollForce += 30*dy;
			
		
	}
	
	for (int i = 0; i < positionDeltas.size(); i++) {

		if (!boxInstances[i]->isActive) {
			positionDeltas[i] = 0;
			continue;
		}
		//if (boxInstances[i]->isActive && !isCollapsing && false) {
		//	float posX = boxInstances[i]->GetActorLocation().X;
		//	float deltaZ = boxInstances[i]->GetActorLocation().Z + 2380+ (360 * (activeBoxes - 8));
		//	if (deltaZ <= 0) {
		//		//bottom to top
		//		//boxInstances[i]->SetActorLocation(FVector(posX, 1, 2690));
		//		if (boxInstances[i] == bottomBox) {
		//			boxInstances[i]->AddActorLocalOffset(FVector(0, 0, 2380 * 2 + (360 * (activeBoxes - 8))));
		//			boxInstances[i]->startPosition.Z += 2380 * 2 + (360 * (activeBoxes - 8));
		//			tempTop = boxInstances[i];


		//		}
		//		else {
		//			boxInstances[i]->SetActorLocation(tempTop->GetActorLocation() + FVector(0, 0, 360));
		//			boxInstances[i]->startPosition = tempTop->startPosition + FVector(0, 0, 360);
		//			tempTop = boxInstances[i];
		//			
		//		}
		//		//tempBottom = findByOrder(70);
		//		orderShift = 73 - boxInstances[i]->order_;
		//		tempBottom = findLowest();
		//		//boxInstances[i]->startPosition.Z += 2380* 2 + (360 * (activeBoxes - 8));
		//	}
		//	deltaZ = boxInstances[i]->GetActorLocation().Z - 2380 ;
		//	if (deltaZ >= 0) {
		//		//top to bottom
		//		//boxInstances[i]->SetActorLocation(FVector(posX, 1, -2690 - (360 * (activeBoxes - 8))));
		//		if (boxInstances[i] == topBox) {
		//			boxInstances[i]->AddActorLocalOffset(FVector(0, 0, -2380 * 2) - (360 * (activeBoxes - 8)));
		//			boxInstances[i]->startPosition.Z -= 2380 * 2 + (360 * (activeBoxes - 8));
		//			tempBottom = boxInstances[i];
		//		}
		//		else {
		//			boxInstances[i]->SetActorLocation(tempBottom->GetActorLocation() - FVector(0, 0, 360));
		//			boxInstances[i]->startPosition = tempBottom->startPosition - FVector(0, 0, 360);
		//			tempBottom = boxInstances[i];
		//			
		//		}
		//		//tempTop = findByOrder(1);
		//		orderShift = 72 - boxInstances[i]->order_;
		//		tempTop = findByOrder(0);
		//		//boxInstances[i]->startPosition.Z -= 2380* 2 + (360 * (activeBoxes - 8));
		//	}
		//}
		//int temp = floor(GetActorLocation().Z / 360);
		//int multiplier = (abs(2 * (((int)floor(boxInstances[i]->GetActorLocation().Z / 360)) % 2)) - 1);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, *(FString::FromInt(temp)));
		//boxInstances[i]->AddActorLocalOffset(FVector(0, 0,2* roundf(positionDeltas[i]/2)));
		//hello this aa comm
		boxInstances[i]->AddActorLocalOffset(FVector(0, 0, positionDeltas[i]));
		//positionDeltas[i] * 0.125 * multiplier
		//UKismetSystemLibrary::MoveComponentTo(this->RootComponent, (boxInstances[i]->startPosition + scrollTarget), FRotator(0), true, true, 1, true, EMoveComponentAction::Move, LatentInfo);
		//scrollTarget += FVector(0, 0, 1) * 2 * roundf(positionDeltas[i] / 2);
		/*FVector v = FMath::VInterpTo(GetActorLocation(), 
			FVector(15000, 10, (fmod((boxInstances[i]->startPosition.Z + scrollTarget.Z)+2690, 2690*2)-2690) * 10), 
			DeltaTime, 6);*/
		//FVector v = FMath::VInterpTo(GetActorLocation(),(boxInstances[i]->startPosition + scrollTarget) * 10, DeltaTime, 6);
		//boxInstances[i]->SetActorLocation(FVector(2*roundf(v.X/2), 1, 2*roundf(v.Z/2)));
		//v.Z = fmod(v.Z+2690, 2 * 2690)-2690;
		//boxInstances[i]->SetActorLocation(v);
		//boxInstances[i]->SetActorLocation(boxInstances[i]->startPosition);
		positionDeltas[i] = 0;

		boxInstances[i]->deltaPosition = FVector::Dist(boxInstances[i]->pos1, boxInstances[i]->GetActorLocation());
		boxInstances[i]->pos1 = boxInstances[i]->GetActorLocation();

		if (boxInstances[i]->isActive && !isCollapsing) {
			float posX = boxInstances[i]->GetActorLocation().X;
			float deltaZ = boxInstances[i]->GetActorLocation().Z + 2690 + (360 * (activeBoxes - 8));
			if (deltaZ <= 0) {
				//boxInstances[i]->SetActorLocation(FVector(posX, 1, 2690+ deltaZ));
				boxInstances[i]->AddActorLocalOffset(FVector(0, 0, 2690 * 2+ (360 * (activeBoxes - 8))));
				//upShift = 73-boxInstances[i]->order_;
				//orderShift = upShift - downShift;
				if (!normalDown && false) {
					
					//normalUp = false;
					orderShift = 0 + boxInstances[i]->order_;
					boxInstances[i]->hasGoneThroughPortal = false;
					downShift--;
				}
				else {
					normalUp = false;
					orderShift = 73 - boxInstances[i]->order_;
					boxInstances[i]->hasGoneThroughPortal = true;
					upShift++;
					if (upShift == activeBoxes) {
						upShift = 0;
					}
				}
				if (orderShift % 73 == 0) {
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "RESET");
					normalDown = true;
					normalUp = true;
				}
				//boxInstances[i]->splitDistance = true;
				//boxInstances[i]->interpTime = -1;//FVector::Dist(boxInstances[i]->GetActorLocation()+FVector(0, 0, 2690 * 2 + (360 * (activeBoxes - 8))), FVector(6500, 0, 0));
				//boxInstances[i]->startPosition.Z += 2690*2 + (360 * (activeBoxes - 8));
			}
			deltaZ = boxInstances[i]->GetActorLocation().Z - 2690;
			if (deltaZ >= 0) {
				//boxInstances[i]->SetActorLocation(FVector(posX, 1, -2690 - (360 * (activeBoxes - 8)) + deltaZ));
				boxInstances[i]->AddActorLocalOffset(FVector(0, 0, -2690 * 2-(360 * (activeBoxes - 8))));
				//orderShift = 72-boxInstances[i]->order_;
				if (!normalUp && false) {

					//normalDown = false;
					orderShift = 1 + boxInstances[i]->order_;
					boxInstances[i]->hasGoneThroughPortal = false;
					upShift--;
				}
				else {
					normalDown = false;
					orderShift = 72 - boxInstances[i]->order_;
					boxInstances[i]->hasGoneThroughPortal = true;
					downShift++;
					if (downShift == activeBoxes) {
						downShift = 0;
					}
				}
				if (orderShift % 73 == 0) {
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "RESET");
					normalDown = true;
					normalUp = true;
				}
				//orderShift = (upShift - downShift) + 73;
				
				//boxInstances[i]->splitDistance = true;
				//boxInstances[i]->interpTime = -1;//FVector::Dist(boxInstances[i]->GetActorLocation()+ FVector(0, 0, -2690 * 2 - (360 * (activeBoxes - 8))), FVector(6500, 0, 0));
				//boxInstances[i]->startPosition.Z -= 2690*2 + (360 * (activeBoxes - 8));
			}
		}
		boxInstances[i]->dTime = DeltaTime;
		boxInstances[i]->ManualTick();
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
	scrollTarget += FVector(0, 0, 1) * delta*1.5;
	for (int i = 0; i < positionDeltas.size(); i++) {
		//if (boxInstances[i]->isActive) {
			positionDeltas[i] += delta;
		//}
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
		UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
		SaveGameInstance->scores.Init(0, 72);
		SaveGameInstance->grades.Init(0, 72);
		SaveGameInstance->autoStartTutorial = false;
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, FString("osou_save"), 0);
		//ABulletController::levelIndex = levelMap[8];
		//UGameplayStatics::OpenLevel(this, FName("Minimal_Default"));

	}
	float posX = 3000;
	float posY = 800;
	boxInstances = std::vector<ALevelBox*>(73);
	for (int i = 0; i < levelDatas.size(); i++) {
		if (i < 8 || i == 72) {
			ALevelBox* tempBox = GetWorld()->SpawnActor<ALevelBox>(LevelBlockClass,
				FVector(posX, 1, posY), //- (12.5*((2*(((int)abs(posY/360))%2))-1)
				FRotator(0));
			boxInstances[i] = (tempBox);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelName")[0]))->SetText(levelDatas[i].levelName);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelScore")[0]))->SetText(gradeConversionLetter[levelDatas[i].grade]);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelScore")[0]))->SetTextRenderColor(gradeConversionColor[levelDatas[i].grade]);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "ScoreNum")[0]))->SetText(FString::Printf(TEXT("%.1f"), levelDatas[i].score));
			if (levelDatas[i].score == 0) {
				((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "ScoreNum")[0]))->SetText(FString(""));
			}
			tempBox->levelName = levelDatas[i].levelName;
			tempBox->mappedLevels = levelDatas[i].subLevels;
			tempBox->isActive = true;
			tempBox->isCategory = true;
			tempBox->startPosition = FVector(posX, 1, posY);
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, tempBox->startPosition.ToString());
			//tempBox->AttachToActor(levelBoxHub, FAttachmentTransformRules::KeepRelativeTransform);
			posY -= 360;//360*1.70666666667;//360
			//tempBox->SetActorScale3D(FVector(0.7*1.70666666667, 0.7*1.70666666667, 0.7*1.70666666667));
			tempBox->SetActorScale3D(FVector(1, 1, 1));
			tempBox->ManualBegin();
			if (i == 72) {
				tempBox->SetHidden(true);
				tempBox->SetActorEnableCollision(false);
			}
		}
		else {
			ALevelBox* tempBox = GetWorld()->SpawnActor<ALevelBox>(LevelBlockClass,
				FVector(0, 1, 6000), //- (12.5*((2*(((int)abs(posY/360))%2))-1)
				FRotator(0));
			boxInstances[i] = (tempBox);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelName")[0]))->SetText(levelDatas[i].levelName);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelScore")[0]))->SetText(gradeConversionLetter[levelDatas[i].grade]);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "LevelScore")[0]))->SetTextRenderColor(gradeConversionColor[levelDatas[i].grade]);
			((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "ScoreNum")[0]))->SetText(FString::Printf(TEXT("%.1f"), levelDatas[i].score));
			
			TArray<UActorComponent*> starSprites = tempBox->GetComponentsByTag(UPaperSpriteComponent::StaticClass(), "Star");
			/*if (levelDatas[i].levelDifficulty > 0) {
				((UPaperSpriteComponent*)starSprites[0])->SetVisibility(true);
			}
			if (levelDatas[i].levelDifficulty > 1) {
				((UPaperSpriteComponent*)starSprites[1])->SetVisibility(true);
			}
			if (levelDatas[i].levelDifficulty > 2) {
				((UPaperSpriteComponent*)starSprites[2])->SetVisibility(true);
			}
			if (levelDatas[i].levelDifficulty > 3) {
				((UPaperSpriteComponent*)starSprites[3])->SetVisibility(true);
			}
			if (levelDatas[i].levelDifficulty > 4) {
				((UPaperSpriteComponent*)starSprites[4])->SetVisibility(true);
			}*/
			if (levelDatas[i].score == 0) {
				//((UTextRenderComponent*)(tempBox->GetComponentsByTag(UTextRenderComponent::StaticClass(), "ScoreNum")[0]))->SetText(FString(""));
				tempBox->levelScore = FString("");
			}
			else {
				tempBox->levelScore = FString::Printf(TEXT("%.1f"), levelDatas[i].score);
			}
			tempBox->SetHidden(true);
			tempBox->levelName = levelDatas[i].levelName;
			tempBox->levelColor = gradeConversionColor[levelDatas[i].grade];
			tempBox->mappedLevels = levelDatas[i].subLevels;
			tempBox->levelDifficulty = levelDatas[i].levelDifficulty;
			tempBox->isActive = false;
			tempBox->isCategory = false;
			tempBox->startPosition = FVector(0, 0, 0);
			tempBox->ManualBegin();

			//tempBox->AttachToActor(levelBoxHub, FAttachmentTransformRules::KeepRelativeTransform);
		}
		topBox = boxInstances[0];
		bottomBox = boxInstances[7];
		tempTop = topBox;
		tempBottom = bottomBox;
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
	boxInstances[72]->order_ = 72;
}
void ALevelBlockManager::ScrollDown()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "SCROLLING DOWN");
	scrollForce += 20;
	//float newScrollForce = scrollForce - 50;
	/*
	if (newScrollForce < -200) {
		scrollForce = -200;
	}
	else {
		scrollForce = newScrollForce;
	}
	//scrollForce = -200;
	*/
}
void ALevelBlockManager::ScrollUp()
{
	scrollForce -= 20;
	//float newScrollForce = scrollForce + 50;
	/*
	if (newScrollForce > 200) {
		scrollForce = 200;
	}
	else {
		scrollForce = newScrollForce;
	}
	*/
	//scrollForce = 200;
}
int ALevelBlockManager::Shifted(int n)
{
	return (n + orderShift) % 73;
}
ALevelBox* ALevelBlockManager::findByOrder(int n)
{
	if (boxInstances.empty()) {
		return nullptr;
	}
	for (int i = 0; i < 73; i++) {
		if (Shifted(boxInstances[i]->order_) == n) {
			return boxInstances[i];
		}
	}
	return nullptr;
}
ALevelBox* ALevelBlockManager::findLowest()
{
	int largest = 0;
	int index = 0;
	if (boxInstances.empty()) {
		return nullptr;
	}
	for (int i = 0; i < 73; i++) {
		if (Shifted(boxInstances[i]->order_) > largest && boxInstances[i]->isActive) {
			largest = Shifted(boxInstances[i]->order_);
			index = i;
		}
	}
	return boxInstances[index];

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
	else if (i == 23) {
		return tex14;
	}
	else if (i == 20) {
		return tex15;
	}
	else {

	}
	return tex0;
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
	else if (i == 23) {
		return sound14;
	}
	else if (i == 20) {
		return sound17;
	}
	else {

	}
	return sound0;
}

#undef LOCTEXT_NAMESPACE

