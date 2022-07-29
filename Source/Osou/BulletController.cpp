// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletController.h"
#include "EngineUtils.h"

ABasicBullet* myBullet;
AKillMe* player;
BulletSpawner testSpawner;
//std::vector<BulletSpawner> LevelLibrary::allLevels[levelIndex];
int ABulletController::levelIndex = 0;
float ABulletController::audioCoeff = 1.0f;

// Sets default values
ABulletController::ABulletController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	clockTime = 0;
	index = 0;
	transitionIndex = 0;
	isDisplayMessage = false;
	messageCounter = 0;
	messageTime = 0;
	messageClockTime = 0;
	messageIndex = 0;
	tutorialTime = 0;
	adjustedDeltaTime = 0;
	tutFirstTime = true;
	isTimeFrozen = false;

}

// Called when the game starts or when spawned
void ABulletController::BeginPlay()
{
	Super::BeginPlay();

	TActorIterator<AKillMe> It(GetWorld());
	player = *It;
	TActorIterator<AMovingBorder> It1(GetWorld());
	border = *It1;
	if (player == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "didnt find player");
	}
	if (LevelLibrary::allLevels.empty()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "BUILDING LEVELS");
		LevelLibrary::BuildLevels();
		
	
	} else {
		//do more things
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(ABulletController::audioCoeff));

	//add player beats
	//IMPORTANT 0.08 DELAY CONSTANT
	if (levelIndex == 0) {
		//VEE PART ONE
		//player->rhythmDelayConstants = { .46, 0.19, 0};
		//player->SetTransitions({ 0, 9998, 9999 }); //105
		//player->setSpeedMultis({ 1.2, 1.2, 1.2 });
		//player->AddRythm({ 0.46154 }, 0); //0.2
		//player->AddRythm({ 0.23077 }, 1);
		//player->AddRythm({ 0.46154 }, 2);
		//player->AddTextInstruction(0, 1, 3, FString("welcome to osou :D"));
		//player->AddTextInstruction(0, 4.5, 3, FString("Osou is a rhythm game, so try to click to the 130 bpm rhythm"));
		//player->AddTextInstruction(1, 10, 0.5, FString("X2 Tempo in"), 1, 3);
		player->rhythmDelayConstants = { 0, 0, 0 };
		player->SetTransitions({ 0, 9998, 9999 }); //105
		player->setSpeedMultis({ 1.2, 1.2, 1.2 });
		player->AddRythm({ 0.46 }, 0); //0.2
		player->AddRythm({ 0.23 }, 1);
		player->AddRythm({ 0.46 }, 2);
		player->AddTextInstruction(0, 1, 3, FString("welcome to osou :D"));
		player->AddTextInstruction(0, 4.5, 3, FString("Osou is a rhythm game, so try to click to the 130 bpm rhythm"));
	}
	else if(levelIndex == 1){
		//UN OWEN WAS HER
		//player->rhythmDelayConstants = { 0, 0.287, 0, 0 };
		//player->SetTransitions({ 0, 15.5, 105 }); //({ 0, 15.5, 11.9, 90 }); //{0, 15.5, 105}
		//player->setSpeedMultis({ 1, 1, 1});
		//player->AddRythm({ 0.27666666 }, 0); //0.28
		//player->AddRythm({ 0.387 }, 1);
		////player->AddRythm({ 0.387, 0.387, 0.387, 0.387, 0.387, 0.387/2, 0.387/2, 0.387, 0.387, 0.387, 0.387/2, 0.387/2, 0.387/2, 
		////	 0.387/4, 0.387/4,0.387 / 2,  0.387 / 2, 0.387 / 2, 0.387/2, 0.387/2, 0.387/2, 2*0.387 }, 2);
		//player->AddRythm({ 0.69 }, 2);
		player->rhythmDelayConstants = { 0, 0, 0 };
		player->SetTransitions({ 0, 15.5, 105 }); //105
		player->setSpeedMultis({ 1, 1, 1 });
		player->AddRythm({ 0.28 }, 0); //0.2
		player->AddRythm({ 0.38 }, 1);
		player->AddRythm({ 0.69 }, 2);
		player->AddTextInstruction(1, 7.5, 1, FString("Beat Change in"), 1.0, 3);
	}
	else if(levelIndex == 2) {
		//VEE PART TWO
		//player->rhythmDelayConstant = 0.36;
		//player->rhythmDelayConstants = { 0.33, 0.438, 0.222, 0.23, 0.06, 0 };//0.1
		//player->SetTransitions({ 0, 45, 72.8-45, 86 - 72.8, 104 -86, 58}); //72.8
		//player->setSpeedMultis({ 1.2/0.46, 1.2/0.46, 1.2/0.23, 1.2 / 0.23, 1.2/0.46, 1.2/0.46 });
		//player->AddRythm({ 0.46154}, 0); //0.2
		//player->AddRythm({ 0.46154 }, 1);
		//player->AddRythm({ 0.23077 }, 2);
		//player->AddRythm({ 0.23077 }, 3);
		//player->AddRythm({ 0.46154 }, 4);
		//player->AddRythm({ 0.46154 }, 5);
		//player->AddTextInstruction(1, 72-1.2, 0.4, FString("X2 in"), 1.0, 3);
		//player->AddTextInstruction(1, 104 - 1.2-2, 0.4, FString("X0.5 in"), 1.0, 3);
		player->rhythmDelayConstants = { 0, 0, 0 , 0 };
		player->SetTransitions({ 0, 72.8,104 - 72.8, 58 }); //72.8
		player->setSpeedMultis({ 1.2, 1.2, 1.2, 1.2 });
		player->AddRythm({ 0.46 }, 0); //0.2
		player->AddRythm({ 0.23 }, 1);
		player->AddRythm({ 0.46 }, 2);
		player->AddRythm({ 0.46 }, 3);
		player->AddTextInstruction(1, 72 - 1.2, 0.4, FString("X2 in"), 1.0, 3);
		player->AddTextInstruction(1, 104 - 1.2 - 2, 0.4, FString("X0.5 in"), 1.0, 3);
	}
	else if(levelIndex == 3){
		//SIMPLE RHYTHM
		player->rhythmDelayConstant = 0;
		player->rhythmDelayConstants = { 0.0, 0.0 };
		player->SetTransitions({0, 32 });
		player->setSpeedMultis({ 3, 2.5 });
		player->AddRythm({ 1.82, 2, 2, 1, 1, 1, 1, 0.5, 1.5, 0.5, 1.5, 0.5, 1, 0.25, 0.25, 0.5, 1, 0.25, 0.25, 0.5, 0.5, 0.5, 0.25, 0.25, 0.5, 0.5, 0.5, 0.25, 
			0.25, 0.5, 0.5, 0.25, 0.25, 0.25, 
			0.25, 0.5, 0.5, 0.25, 0.25, 0.25, 0.25,
			0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25,
			0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
			0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 
			0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
			0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.16667, 0.16667, 0.16667,
			0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.16667, 0.16667, 0.16667, 
			0.25, 0.25, 0.125, 0.125, 0.125, 0.125, 0.25, 0.25, 0.16667, 0.16667, 0.16667, 
			0.25, 0.25, 0.125, 0.125, 0.125, 0.125, 0.25, 0.25, 0.16667, 0.16667, 0.16667, 
			0.25, 0.25, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.16667, 0.16667, 0.16667, 
			}, 0);
		player->AddRythm({ 1 }, 1);
	}
	else {
		//EVERY BATTLE
		player->rhythmDelayConstant = 0;
		player->rhythmDelayConstants = { 0.0, 0.0 };
		player->SetTransitions({ 0, 32 });
		player->setSpeedMultis({ 3, 2.5 });
		player->AddRythm({ 1 }, 0);
		player->AddRythm({ 1 }, 1);
	}
	spawner = &(LevelLibrary::allLevels[levelIndex][0]);
	player->speed = player->baseSpeed;// / player->beats[0][0];
	player->currentMulti = player->speedMultis[0];
	player->rhythmDelayConstant = player->rhythmDelayConstants[0];
	border->instructions = spawner->borderInstructions;
	border->InitializeFromOutside();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, *(FString::FromInt(LevelLibrary::allLevels.size())));
	if (levelIndex == 0) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "WHAT THE FUCK");
	}
}

// Called every frame
void ABulletController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	clockTime += (DeltaTime*ABulletController::audioCoeff);
	messageClockTime += (DeltaTime*ABulletController::audioCoeff);
	//adjustedDeltaTime = DeltaTime;
	std::list<ABasicBullet*>::iterator itr = activeBullets.begin();
	while (itr != activeBullets.end()) {

		(*itr)->UpdateMovement(DeltaTime*ABulletController::audioCoeff);
		if ((((abs((*itr)->GetActorLocation().X) > 2250 || abs((*itr)->GetActorLocation().Z) > 1265) && (*itr)->time > 5) || (*itr)->flaggedForRemoval)) {
			if (!(*itr)->Destroy()) {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "COULDNT DESTROY BULLET");
			}
			itr = activeBullets.erase(itr);
		}
		else {
			++itr;
		}
	}
	if (isTimeFrozen) {
		return;
	}
	//check spawning routines
	if (spawner->spawnTable[index].time < clockTime) {
		//time to spawn shit!
		adjustedDeltaTime = clockTime - spawner->spawnTable[index].time;
		for (int i = 0; i < spawner->spawnTable[index].spawnMap.size(); i++) {
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "SPAWNING STUFF");
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(spawner->spawnAngles[index][i]));
			FVector pos(spawner->spawnTable[index].spawnMap[i].X, 2, spawner->spawnTable[index].spawnMap[i].Y);
			float angle = 0;
			if (spawner->spawnTable[index].spawnMap[i].isAngleRelative) {
				FVector playerPos = player->GetActorLocation();
				float dX = playerPos.X - pos.X;
				float dY = playerPos.Z - pos.Z;
				angle = atan2f(dY, dX) * 180/PI;
			}
			for (int j = 0; j < spawner->spawnTable[index].spawnMap[i].angles.size(); j++) {
				TSubclassOf<AActor> tempClass;
				BulletType tempBType = spawner->spawnTable[index].spawnMap[i].bulletType;
				if (tempBType == BulletType::BasicBullet) {
					tempClass = BulletClass;
				} else if (tempBType == BulletType::ExplodingBullet) {
					tempClass = ExplodingBullet;
				}
				else if (tempBType == BulletType::CurvedBullet) {
					tempClass = CurvedBullet;
				}
				else if (tempBType == BulletType::HexagonBullet) {
					tempClass = HexBullet;
				}
				else if (tempBType == BulletType::CurvedBulletReg) {
					tempClass = CurvedBulletReg;
				}
				activeBullets.push_back(GetWorld()->SpawnActor<ABasicBullet>(tempClass,
					pos,
					FRotator(angle + spawner->spawnTable[index].spawnMap[i].angles[j], 0, 0)));
				activeBullets.back()->Start(spawner->spawnTable[index].spawnMap[i].coeffecients);
				activeBullets.back()->UpdateMovement(adjustedDeltaTime);
				//activeBullets.back()->coeffecient = spawner->spawnTable[index].spawnMap[i].bCoeffecient;
			}
		}
		index++;
		//0.66 3 count intervals
		if (index == spawner->spawnTable.size()) {
			
			
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "TRANSITIONING");
			if (levelIndex != 0) {
				transitionIndex++;
				if (transitionIndex == LevelLibrary::allLevels[levelIndex].size()) {
					//just reset for now
					transitionIndex = 0;
				}
				spawner = &(LevelLibrary::allLevels[levelIndex][transitionIndex]);
			}
			index = 0;
			clockTime = 0;
			
		}
		if (levelIndex == 0) {
			if (tutorialTime < 18) {
				//wait
				//tutorialTime = 197;
			}
			else if (tutorialTime < 19) {
				player->sound->SetWaveParameter(FName("wave"), player->song0);
				player->sound->Play();
				player->Health = 1;
				//DisplayMessage(FString("Osou is a rhythm game, so try to click to the 130 bpm tempo"));
				//player->FinishedLevel();
			}
			else if (tutorialTime < 66) {
				if (player->Health < 0.1) {
					tutorialTime = 0;
					player->sound->Stop();
					//player->sound->Play();
					index = 0;
					clockTime = 0;
					player->Health = 1;
					player->hScore = 0;
					player->rhythmDelayConstant = 0.21;
					DisplayMessage(FString("Try again, stay on 130 bpm tempo"));
				}
			}
			else if (tutorialTime < 67) {
				
				on_screen_message temp;
				temp.type = 0;
				temp.duration = 2;
				temp.startTime = 0;
				temp.message = FString("good job! lets add some music and obstacles, stay at the same tempo");
				currentMessage = temp;
				isDisplayMessage = true;
				player->sound->Stop();
				player->sound->SetWaveParameter(FName("wave"), player->song1_1);
				player->rhythmDelayConstant = 0.35;
				
			}
			else if (tutorialTime <87) {
				//wait
			}
			else if (tutorialTime < 88) {
				spawner = &(LevelLibrary::allLevels[levelIndex][1]);
				//player->rhythmDelayConstant = player->rhythmDelayConstants[0];
				index = 0;
				clockTime = 0;
				player->sound->Play();

			}
			else if (tutorialTime < 133) {
				if (player->Health < 0.1 || player->hScore > 1) {
					if (player->hScore > 1) {
						DisplayMessage(FString("Try not to get hit too many times"));
					}
					else {
						DisplayMessage(FString("Stay on 130bpm tempo, try again"));
					}
					tutorialTime = 77;
					player->sound->Stop();
					//player->sound->Play();
					spawner = &(LevelLibrary::allLevels[levelIndex][0]);
					index = 0;
					clockTime = 0;
					player->Health = 1;
					player->hScore = 0;
					player->CloseWidget();
					player->rhythmDelayConstant = 0.415;
				}
			}
			else if (tutorialTime < 134) {
				on_screen_message temp;
				temp.type = 0;
				temp.duration = 2;
				temp.startTime = 0;
				temp.message = FString("well done, now let's make this a little harder");
				player->CloseWidget();
				player->hScore = 0;
				currentMessage = temp;
				isDisplayMessage = true;
				player->rhythmDelayConstant = 0.1;
			}
			else if (tutorialTime < 149) {
				//wait
			}
			else if (tutorialTime < 155) {
				if (index % 6 == 0) {
					spawner = &(LevelLibrary::allLevels[levelIndex][2]);
					index = 0;
					clockTime = 0;
					if (!tutFirstTime) {
						player->sound->Play();
					}
				}
			}
			else if (tutorialTime < 197) {
				if (player->Health < 0.1 || player->hScore > 1) {
					if (player->hScore > 1) {
						DisplayMessage(FString("Try not to get hit too many times"));
					}
					else {
						DisplayMessage(FString("Stay at 130bpm tempo, try again"));
					}
					tutorialTime = 140; //134
					player->sound->Stop();
					player->sound->SetWaveParameter(FName("wave"), player->song1_2);
					//player->sound->Play();
					spawner = &(LevelLibrary::allLevels[levelIndex][0]);
					index = 0;
					clockTime = 0;
					player->Health = 1;
					player->hScore = 0;
					player->rhythmDelayConstant = 0.1;
					player->CloseWidget();
					tutFirstTime = false;
				}
			}
			else if (tutorialTime < 198) {

				on_screen_message temp;
				temp.type = 0;
				temp.duration = 1;
				temp.startTime = 0;
				temp.message = FString("great job, now let's double the tempo");
				currentMessage = temp;
				isDisplayMessage = true;
				tutFirstTime = true;
		
				spawner = &(LevelLibrary::allLevels[levelIndex][0]);
				index = 0;
				clockTime = 0;
			}
			else if (tutorialTime < 202) { //215
				//wait
			}
			else if (tutorialTime < 203) {
				on_screen_message temp;
				temp.type = 1;
				temp.duration = 0.33;
				temp.startTime = 0;
				temp.count = 3;
				temp.message = FString("X2 in");
				currentMessage = temp;
				isDisplayMessage = true;
			}
			else if (tutorialTime < 215) {
				//wait
			}
			else if (tutorialTime < 216) {
				spawner = &(LevelLibrary::allLevels[levelIndex][3]);
				index = 0;
				clockTime = 0;

				player->currentBeat = &(player->beats[1]);
				player->currentMulti = player->speedMultis[1];
				player->index = 0;
				player->clockTime = 0;
				player->Health += 1;

				if (!tutFirstTime) {
					player->sound->Play();
				}
				else {
					player->rhythmDelayConstant = player->rhythmDelayConstants[1];
				}

			}
			else if (tutorialTime < 456-34+27*(tutFirstTime)) {
				if (player->Health < 0.1 || player->hScore > 3) {
					if (player->hScore > 3) {
						DisplayMessage(FString("Try not to get hit too many times"));
					}
					else {
						DisplayMessage(FString("You need to double your tempo, try again"));
					}
					tutorialTime = 203; //198
					player->sound->Stop();
					player->sound->SetWaveParameter(FName("wave"), player->song1_3);
					//player->sound->Play();
					spawner = &(LevelLibrary::allLevels[levelIndex][0]);
					index = 0;
					clockTime = 0;
					player->Health = 1;
					player->hScore = 0;
					player->rhythmDelayConstant = 0.18;
					player->CloseWidget();
					tutFirstTime = false;

				}
			}
			else if(tutorialTime < 457-34+27*(tutFirstTime)) {
				
				on_screen_message temp;
				temp.type = 0;
				temp.duration = 2;
				temp.startTime = 0;
				temp.message = FString("Fantastic job!, lets go back down to normal tempo");
				currentMessage = temp;
				isDisplayMessage = true;
				//player->FinishedLevel();
			}
			else if (tutorialTime < 465-34+27*(tutFirstTime)) {
				//wait
			}
			else if (tutorialTime < 466-34+27*(tutFirstTime)) {
				on_screen_message temp;
				temp.type = 1;
				temp.duration = 0.33;
				temp.startTime = 0;
				temp.count = 3;
				temp.message = FString("X0.5 in");
				currentMessage = temp;
				isDisplayMessage = true;
			}
			else if (tutorialTime < 490-34+27*(tutFirstTime)) {
				//wait
			}
			else if (tutorialTime < 491 - 34+27*(tutFirstTime)) {

				player->messages.clear();
				//player->rhythmDelayConstant = 0.39;
				//player->rhythmDelayConstants = { 0.37, 0.458, 0.252, 0, 0 };//0.1
				//player->SetTransitions({ 0, 45, 72.8 - 45,104 - 72.8, 58 }); //72.8
				//player->setSpeedMultis({ 1.2 , 1.2 , 1.2 , 1.2 / 0.46, 1.2 / 0.46 });
				//player->AddRythm({ 0.46154 }, 0); //0.2
				//player->AddRythm({ 0.46154 }, 1);
				//player->AddRythm({ 0.23077 }, 2);
				//player->AddRythm({ 0.46154 }, 3);
				//player->AddRythm({ 0.46 }, 4);
				//player->AddTextInstruction(1, 72 - 1.2, 0.4, FString("X2 in"), 1.0, 3);
				//player->AddTextInstruction(1, 104 - 1.2 - 2, 0.4, FString("X0.5 in"), 1.0, 3);
				player->rhythmDelayConstants = { 0, 0, 0 , 0 };
				player->SetTransitions({ 0, 72.8,104 - 72.8, 58 }); //72.8
				player->setSpeedMultis({ 1.2, 1.2, 1.2, 1.2 });
				player->AddRythm({ 0.46 }, 0); //0.2
				player->AddRythm({ 0.23 }, 1);
				player->AddRythm({ 0.46 }, 2);
				player->AddRythm({ 0.46 }, 3);
				player->AddTextInstruction(1, 72 - 1.2, 0.4, FString("X2 in"), 1.0, 3);
				player->AddTextInstruction(1, 104 - 1.2 - 2, 0.4, FString("X0.5 in"), 1.0, 3);

				spawner = &(LevelLibrary::allLevels[2][0]);
				levelIndex = 2;
				index = 0;
				messageIndex = 0;
				transitionIndex = 0;
				clockTime = 0;
				messageClockTime = 0;
				//player->sound->SetWaveParameter(FName("wave"), player->song1_4);
				player->currentBeat = &(player->beats[0]);
				player->rhythmBuffer = 3;
				player->currentMulti = player->speedMultis[0];
				player->rScore = (((float)player->perfects) / ((float)player->total))*100.0f;
				//save data
				float score = powf((player->rScore / 100), 0.25) * (100 - (player->tutHScore * 10));
				int grade = 0;
				//score = 75;
				if (score >= 93.669998) {
					grade = 1;
				}
				else if (score >= 84.306999) {
					grade = 2;
				}
				else if (score >= 67.797997) {
					grade = 3;
				}
				else if (score >= 46.837399) {
					grade = 4;
				}
				else {
					grade = 5;
				}
				if (UMySaveGame* LoadedGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(FString("osou_save"), 0)))
				{
					// The operation was successful, so LoadedGame now contains the data we saved earlier.
					//UE_LOG(LogTemp, Warning, TEXT("LOADED: %s"), *LoadedGame->PlayerName);
					if (score > LoadedGame->scores[8]) {
						LoadedGame->scores[8] = score;
						LoadedGame->grades[8] = grade;
						UGameplayStatics::SaveGameToSlot(LoadedGame, FString("osou_save"), 0);
					}

				}
				else {
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "DIDNT FIND SAVE");
					UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
					SaveGameInstance->scores.Init(0, 72);
					SaveGameInstance->grades.Init(0, 72);
					SaveGameInstance->scores[8] = score;
					SaveGameInstance->grades[8] = grade;
					UGameplayStatics::SaveGameToSlot(SaveGameInstance, FString("osou_save"), 0);
				}
				player->clockTime = 0;
				player->hScore = 0;
				player->total = 0;
				player->perfects = 0;
			}
			tutorialTime++;
		}
	}
	if (player->messages.size() > messageIndex && messageClockTime > player->messages[messageIndex].startTime) {
		currentMessage = player->messages[messageIndex];
		isDisplayMessage = true;
		messageIndex++;
	}
	if (isDisplayMessage) {
		if (currentMessage.type == 0) {
			if (messageTime == 0) {
				player->content = currentMessage.message;
				player->FadeInText();
			}
			messageTime += (DeltaTime*ABulletController::audioCoeff);
			if (messageTime > currentMessage.duration) {
				player->FadeOutText();
				messageTime = 0;
				isDisplayMessage = false;
			}
		}
		else {
			if (messageTime == 0) {
				player->content = currentMessage.message;
				player->FadeInText();
				messageCounter = 1;
			}
			else if (messageTime > currentMessage.duration) {
				if (messageCounter % 2 == 0) {
					//start next number
					if (messageCounter == currentMessage.count * 2 + 2) {
						player->content = FString("now!");
					}
					else {
						player->content = FString::FromInt(currentMessage.count + 1 - (messageCounter / 2));
					}
					player->FadeInText();
				}
				else {
					//start fading out
					player->FadeOutText();
				}
				messageCounter++;
				messageTime = 0.001;
				
			}
			messageTime += (DeltaTime*ABulletController::audioCoeff);
			if (messageCounter == currentMessage.count * 2 + 4) {
				isDisplayMessage = false;
				messageTime = 0;
				messageCounter = 0;
			}
		}
	}
	border->UpdateMovement(DeltaTime*ABulletController::audioCoeff);
	if (border->CheckForCollision(player->GetActorLocation())) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OUTSIDE OF RANGE");
		player->ResetEverything();
	}
}
void ABulletController::ResetBullets()
{
	std::list<ABasicBullet*>::iterator itr = activeBullets.begin();
	while (itr != activeBullets.end()) {
		(*itr)->flaggedForRemoval = true;
		++itr;
	}
	transitionIndex = 0;
	index = 0;
	clockTime = 0;
	messageClockTime = 0;
	spawner = &(LevelLibrary::allLevels[levelIndex][0]);

}
void ABulletController::DisplayMessage(FString message, int type, float duration, float start)
{
	
	on_screen_message temp;
	temp.type = type;
	temp.duration = duration;
	temp.startTime = start;
	temp.message = message;
	currentMessage = temp;
	isDisplayMessage = true;
}
void ABulletController::SetCalibration()
{
	audioCoeff = audioCoeff_BP;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(ABulletController::audioCoeff));
}
void ABulletController::SetLevelToTrueRhythm()
{
	levelIndex = 3;
}
/*
testSpawner.AddTimes(UNtimes1);
		std::vector<float> zero8 = { 0,0,0,0,0,0,0,0 };
		std::vector<float> zero4 = { 0,0,0,0 };
		std::vector<float> extcardinals = { 0, 90, 180, -90, 45, 135, -45, -135 };
		std::vector<float> cardinals = { 0, 90, 180, -90};
		std::vector<float> cocardinals = { 45, 135, -45, -135 };

		std::vector<float> corners16x = { -2250, -2250, -2250, -2250, -2250, -2250, -2250, -2250,  2250,  2250,  2250,  2250, 2250, 2250, 2250, 2250 }; //2250
		std::vector<float> corners16y = { -1265, -1265, -1265, -1265,  1265,  1265,  1265,  1265, -1265, -1265, -1265, -1265, 1265, 1265, 1265, 1265 }; //1265
		std::vector<float> corners12x;
		std::vector<float> corners12y;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 3; k++) {
					corners12x.push_back(4500 * (i - 0.5));
					corners12y.push_back(2530 * (j - 0.5));
				}
			}
		}
		std::vector<float> corners14x = corners12x; corners14x.push_back(0); corners14x.push_back(0);
		std::vector<float> corners14y = corners12y; corners14y.push_back(-1265); corners14y.push_back(1265);

		std::vector<float> corners8x = { -2250, -2250, -2250, -2250, 2250, 2250, 2250, 2250 };
		std::vector<float> corners8y = { -1265, -1265, 1265, 1265, -1265, -1265, 1265, 1265 };

		std::vector<float> corners12flatx = corners8x; corners12flatx.push_back(0); corners12flatx.push_back(0); corners12flatx.push_back(0); corners12flatx.push_back(0);
		std::vector<float> corners12flaty = corners8y; corners12flaty.push_back(-1265); corners12flaty.push_back(-1265); corners12flaty.push_back(1265); corners12flaty.push_back(1265);


		std::vector<float> cornerAngles16 = { 18, 36, 54, 72, -18, -36, -54, -72, 108, 126, 144, 162, -108, -126, -144, -162 };
		std::vector<float> cornerAngles12 = { 22.5, 45, 67.5, -22.5, -45, -67.5, 112.5, 135, 157.5, -112.5, -135, -157.5 };
		std::vector<float> cornerAngles8 = { 30, 60, -30, -60, 120, 150, -120, -150 };
		for (int i = 0; i < 10; i++) {
			testSpawner.AddAngles(cornerAngles8);
			testSpawner.AddPosition(corners8x, corners8y);


			testSpawner.AddAngles(cornerAngles12);
			testSpawner.AddPosition(corners12x, corners12y);

		}
		testSpawner.AddAngles(cornerAngles8);
		testSpawner.AddPosition(corners8x, corners8y);
*/
