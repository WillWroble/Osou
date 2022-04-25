// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletController.h"
#include "EngineUtils.h"

ABasicBullet* myBullet;
AKillMe* player;
BulletSpawner testSpawner;
//std::vector<BulletSpawner> LevelLibrary::allLevels[levelIndex];
int ABulletController::levelIndex = 0;

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
	messageIndex = 0;
	tutorialTime = 0;
	tutFirstTime = true;

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
	//add player beats
	//IMPORTANT 0.08 DELAY CONSTANT
	if (levelIndex == 0) {
		player->SetTransitions({ 0, 30, 90 }); //105
		player->setSpeedMultis({ 1, 1, 1 });
		player->AddRythm({ 0.38 }, 0); //0.2
		player->AddRythm({ 0.19 }, 1);
		player->AddRythm({ 0.38 }, 2);
		player->AddTextInstruction(0, 1, 3, FString("welcome to osou :D"));
		//player->AddTextInstruction(1, 10, 0.5, FString("X2 Tempo in"), 1, 3);
	}
	else {
		player->SetTransitions({ 0, 15.5, 105 }); //105
		player->setSpeedMultis({ 1, 1, 1 });
		player->AddRythm({ 0.2 }, 0); //0.2
		player->AddRythm({ 0.3 }, 1);
		player->AddRythm({ 0.69 }, 2);
	}
	spawner = &(LevelLibrary::allLevels[levelIndex][0]);
	player->speed = player->baseSpeed / player->beats[0][0];
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
	clockTime += DeltaTime;

	//check spawning routines
	if (spawner->spawnTable[index].time < clockTime) {
		//time to spawn shit!
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
				activeBullets.push_back(GetWorld()->SpawnActor<ABasicBullet>(tempClass,
					pos,
					FRotator(angle + spawner->spawnTable[index].spawnMap[i].angles[j], 0, 0)));
				activeBullets.back()->Start(spawner->spawnTable[index].spawnMap[i].coeffecients);
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
			}
			else if (tutorialTime < 19) {
				player->sound->SetWaveParameter(FName("wave"), player->song0);
				player->sound->Play();
				player->FinishedLevel();
			}
			else if (tutorialTime < 66) {
				if (player->Health < 0.5) {
					tutorialTime = 0;
					player->sound->Stop();
					//player->sound->Play();
					index = 0;
					clockTime = 0;
					player->Health = 1;
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
				
			}
			else if (tutorialTime <87) {
				//wait
			}
			else if (tutorialTime < 88) {
				spawner = &(LevelLibrary::allLevels[levelIndex][1]);
				index = 0;
				clockTime = 0;
				player->sound->Play();

			}
			else if (tutorialTime < 133) {
				if (player->Health < 0.5) {
					tutorialTime = 77;
					player->sound->Stop();
					//player->sound->Play();
					spawner = &(LevelLibrary::allLevels[levelIndex][0]);
					index = 0;
					clockTime = 0;
					player->Health = 1;
				}
			}
			else if (tutorialTime < 134) {
				on_screen_message temp;
				temp.type = 0;
				temp.duration = 2;
				temp.startTime = 0;
				temp.message = FString("well done, now let's make this a little harder");
				currentMessage = temp;
				isDisplayMessage = true;
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
				if (player->Health < 0.5) {
					tutorialTime = 140; //134
					player->sound->Stop();
					player->sound->SetWaveParameter(FName("wave"), player->song1_2);
					//player->sound->Play();
					spawner = &(LevelLibrary::allLevels[levelIndex][0]);
					index = 0;
					clockTime = 0;
					player->Health = 1;
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

			}
			else if (tutorialTime < 264) {
				if (player->Health < 0.5) {
					tutorialTime = 203;
					player->sound->Stop();
					player->sound->SetWaveParameter(FName("wave"), player->song1_3);
					//player->sound->Play();
					spawner = &(LevelLibrary::allLevels[levelIndex][0]);
					index = 0;
					clockTime = 0;
					player->Health = 1;
					tutFirstTime = false;
				}
			}
			else {
				
				on_screen_message temp;
				temp.type = 0;
				temp.duration = 2;
				temp.startTime = 0;
				temp.message = FString("Fantastic job!");
				currentMessage = temp;
				isDisplayMessage = true;
				//player->FinishedLevel();
			}
			tutorialTime++;
		}
	}
	if (player->messages.size() > messageIndex && clockTime > player->messages[messageIndex].startTime) {
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
			messageTime += DeltaTime;
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
			messageTime += DeltaTime;
			if (messageCounter == currentMessage.count * 2 + 4) {
				isDisplayMessage = false;
				messageTime = 0;
				messageCounter = 0;
			}
		}
	}
	std::list<ABasicBullet*>::iterator itr = activeBullets.begin();
	while (itr != activeBullets.end()) {

		(*itr)->UpdateMovement(DeltaTime);
		if ((abs((*itr)->GetActorLocation().X) > 2250 || abs((*itr)->GetActorLocation().Z) > 1265 || (*itr)->flaggedForRemoval) && (*itr)->time > 5) {
			if (!(*itr)->Destroy()) {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "COULDNT DESTROY BULLET");
			}
			itr = activeBullets.erase(itr);
		}
		else {
			++itr;
		}
	}
	border->UpdateMovement(DeltaTime);
	if (border->CheckForCollision(player->GetActorLocation())) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OUTSIDE OF RANGE");
		//player->ResetEverything();
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
	spawner = &(LevelLibrary::allLevels[levelIndex][0]);

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
