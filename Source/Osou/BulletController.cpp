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
		//BulletSpawner* tempSpawner;
		//build test level
		/*
		LevelLibrary::allLevels[levelIndex].clear();
		LevelLibrary::allLevels[levelIndex].push_back(BulletSpawner());
		
		testSpawners[0].AddRythm({ 1.33,0.3,0.3 }, 7, 0);
		testSpawners[0].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
		testSpawners[0].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
		testSpawners[0].AddCorners({ 60, 30 }, 1, 0, BulletType::BasicBullet);
		//testSpawners[0].AddCorners({ 0 }, 1, 0, BulletType::CurvedBullet, { 700, 2, 0, 1, 1, 1 });
		//testSpawners[0].AddCorners({ 70 }, 1, 0, BulletType::CurvedBullet, { 700, 2, 0, -1, 1, 1 });
		
		
		testSpawners[0].AddInstruction(2, 0 , -1000, 1); //5
		testSpawners[0].AddInstruction(1, 1, 0, 4);
		testSpawners[0].AddInstruction(0, 1000, -1000, 2);
		testSpawners[0].AddInstruction(3, 0, 0, 2);

		testSpawners[0].AddInstruction(4, 0, 0, 15);

		testSpawners[0].AddInstruction(1, 5, 0, 1);
		testSpawners[0].AddInstruction(2, 0, 1000, 1);
		testSpawners[0].AddInstruction(1, 1.5, 0, 4);
		testSpawners[0].AddInstruction(0, 1000, 1000, 2);
		testSpawners[0].AddInstruction(0, 1000, -1000, 4);
		testSpawners[0].AddInstruction(0, 0, -1000, 2);
		testSpawners[0].AddInstruction(3, 0, 0, 2);

		testSpawners[0].AddInstruction(4, 0, 0, 71.5);

		testSpawners[0].AddInstruction(1, 5, 0, 1);
		testSpawners[0].AddInstruction(2, 0, 0, 1);
		testSpawners[0].AddInstruction(1, 0.75, 0, 8.5);

		testSpawners[0].AddInstruction(4, 0, 0, 9999);

		

		//testSpawner.AddSpawnPoints(0, 0, { 0, 45, 90, 135, 180, 225, 270, 315 }, 4, 0);
		testSpawners.push_back(BulletSpawner());
		testSpawners[1].AddRythm({ 0.5 }, 27, 0); //27
		testSpawners[1].AddLayersOfHorizontalSpawnPoints(2250, -2250, 1200, { -90 }, 100, 2, 0);
		testSpawners[1].AddLayersOfHorizontalSpawnPoints(2250, 0, 1200, { -90 }, 100, 2, 1);
		//testSpawners[1].AddRythm({ 1.33,0.3,0.3 }, 21, 0);
		//testSpawners[1].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
		//testSpawners[1].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
		testSpawners.push_back(BulletSpawner());
		testSpawners[2].AddRythm({ 1.33,0.3,0.3 }, 12, 0);
		testSpawners[2].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
		testSpawners[2].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
		testSpawners[2].AddCorners({ 60, 30 }, 1, 0);

		testSpawners[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 10, 17, BulletType::BasicBullet, { 300, 1 });
		testSpawners[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 10, 17, BulletType::BasicBullet, { 300, 1 });
		testSpawners[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 10, 17, BulletType::BasicBullet, { 300, 1 });
		testSpawners[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 10, 17, BulletType::BasicBullet, { 300, 1 });
		testSpawners[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 10, 17, BulletType::BasicBullet, { 300, 1 });

		testSpawners.push_back(BulletSpawner());
		tempSpawner = &(testSpawners[3]);
		tempSpawner->AddRythm({ 0.3 }, 64, 0);
		std::vector<float> A1 = { 0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5 };
		std::vector<float> A2 = std::vector<float>(16);
		std::vector<float> A3 = std::vector<float>(16);
		std::vector<float> A4 = std::vector<float>(16);
		
		for (int i = 0; i < 16; i++) {
			A2[i] = A1[i] + 90;
			A3[i] = A1[i] + 180;
			A4[i] = A1[i] + 270;
		}
		tempSpawner->AddDynamicSpawnPoints(0, 0, { 0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5 }, 1, 0);
		tempSpawner->AddDynamicSpawnPoints(0, 0, A2, 1, 0);
		tempSpawner->AddDynamicSpawnPoints(0, 0, A3, 1, 0);
		tempSpawner->AddDynamicSpawnPoints(0, 0, A4, 1, 0);

		tempSpawner->AddTargetingSpawnPoints(0, 0, { 0 }, 4, 0, BulletType::ExplodingBullet);

		tempSpawner->AddRythm({ 0.61 }, 5, 14.3);
		tempSpawner->AddSpawnPoints(0, 0, A1, 1, 64);

		
		tempSpawner->SortSpawnTimes();

		testSpawners.push_back(BulletSpawner());
		testSpawners[4].AddRythm({ 0.5 }, 54, 0); //27
		testSpawners[4].AddLayersOfHorizontalSpawnPoints(2250, -2250, 1200, { -90 }, 100, 2, 0);
		testSpawners[4].AddLayersOfHorizontalSpawnPoints(2250, 0, 1200, { -90 }, 100, 2, 1);
		
		testSpawners[4].AddRythm({ 2 }, 6, 13.5);	
		testSpawners[4].AddSpawnPoint(800, 400, A1, 54, BulletType::BasicBullet, {400, 1});
		testSpawners[4].AddSpawnPoint(-800, -400, A1, 55, BulletType::BasicBullet, { 400, 1 });
		testSpawners[4].AddSpawnPoint(-800, 400, A1, 56, BulletType::BasicBullet, { 400, 1 });
		testSpawners[4].AddSpawnPoint(800, -400, A1, 57, BulletType::BasicBullet, { 400, 1 });
		testSpawners[4].AddSpawnPoint(800, 0, A1, 58, BulletType::BasicBullet, { 400, 1 });
		testSpawners[4].AddSpawnPoint(-800, 0, A1, 59, BulletType::BasicBullet, { 400, 1 });
		
		testSpawners[4].SortSpawnTimes();

		testSpawners.push_back(BulletSpawner());

		testSpawners[5].AddRythm({ 1.33,0.3,0.3 }, 11, 0);
		testSpawners[5].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
		testSpawners[5].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
		testSpawners[5].AddCorners({ 60, 30 }, 1, 21, BulletType::BasicBullet);
		
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 10, 0, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 10, 0, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 10, 0, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 10, 0, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 10, 0, BulletType::BasicBullet, { 300, 1 });
		
		testSpawners[5].AddSpawnPointByEquation(12, 10, &(EquationLibrary::xcircle), &(EquationLibrary::ycircle), &(EquationLibrary::acircle), BulletType::ExplodingBullet, {450, 2, 0});
		testSpawners[5].AddRythm({ 2 }, 6, 4);
		testSpawners[5].AddCorners({ 0 }, 1, 33, BulletType::CurvedBullet, { 700, 2, 0, 1, 1, 1 });
		testSpawners[5].AddCorners({ 70 }, 1, 33, BulletType::CurvedBullet, { 700, 2, 0, -1, 1, 1 });
		testSpawners[5].AddCorners({18, 36, 54, 72}, 2, 33);

		testSpawners[5].SortSpawnTimes();

		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 10, 29, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 10, 29, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 10, 29, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 10, 29, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 10, 29, BulletType::BasicBullet, { 300, 1 });

		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 5, 38, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 5, 38, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 5, 38, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 5, 38, BulletType::BasicBullet, { 300, 1 });
		testSpawners[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 5, 38, BulletType::BasicBullet, { 300, 1 });
		*/
		


		
		


		


		
	} else {
		//do more things
	}
	//add player beats
	//IMPORTANT 0.08 DELAY CONSTANT
	if (levelIndex == 0) {
		player->SetTransitions({ 0, 30, 90 }); //105
		player->setSpeedMultis({ 1.4, 1, 1 });
		player->AddRythm({ 0.42 }, 0); //0.2
		player->AddRythm({ 0.42 }, 1);
		player->AddRythm({ 0.42 }, 2);
		player->AddTextInstruction(0, 5, 3, FString("welcome to osou :D"));
		player->AddTextInstruction(1, 10, 0.5, FString("X2 Tempo in"), 1, 3);
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
		if (index == spawner->spawnTable.size()) {
			if (levelIndex == 0) {
				if (transitionIndex == 0) {
					//first transition
					if (true) {
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "TRANSITIONING");
						transitionIndex++;
					}
				}
				else {
					//second transition
					if (true) {
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "TRANSITIONING");
						transitionIndex++;
					}
				}
				if (transitionIndex == LevelLibrary::allLevels[levelIndex].size()) {
					//just reset for now
					transitionIndex = 0;
				}
				spawner = &(LevelLibrary::allLevels[levelIndex][transitionIndex]);
				index = 0;
				clockTime = 0;
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "TRANSITIONING");
				transitionIndex++;
				if (transitionIndex == LevelLibrary::allLevels[levelIndex].size()) {
					//just reset for now
					transitionIndex = 0;
				}
				spawner = &(LevelLibrary::allLevels[levelIndex][transitionIndex]);
				index = 0;
				clockTime = 0;
			}
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
