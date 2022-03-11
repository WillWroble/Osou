// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletController.h"
#include "EngineUtils.h"

ABasicBullet* myBullet;
AKillMe* player;
BulletSpawner testSpawner;
std::vector<BulletSpawner> testSpawners;

// Sets default values
ABulletController::ABulletController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	clockTime = 0;
	levelIndex = 0;
	index = 0;
	transitionIndex = 0;

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
	if (levelIndex == 0 && testSpawners.empty()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "BUILDING LEVELS");
		//build test level
		testSpawners.push_back(BulletSpawner());
		testSpawners[0].AddRythm({ 1.33,0.3,0.3 }, 7, 0);
		testSpawners[0].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
		testSpawners[0].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
		testSpawners[0].AddCorners({ 60, 30 }, 1, 0);
		testSpawners[0].AddInstruction(2, 0 , -1000, 1); //5
		testSpawners[0].AddInstruction(1, 1, 0, 4);
		testSpawners[0].AddInstruction(0, 1000, -1000, 2);
		testSpawners[0].AddInstruction(3, 0, 0, 2);
		testSpawners[0].AddInstruction(4, 0, 0, 9999);
		//testSpawner.AddSpawnPoints(0, 0, { 0, 45, 90, 135, 180, 225, 270, 315 }, 4, 0);
		testSpawners.push_back(BulletSpawner());
		testSpawners[1].AddRythm({ 0.5 }, 27, 0);
		testSpawners[1].AddLayersOfHorizontalSpawnPoints(2250, -2250, 1200, { -90 }, 100, 2, 0);
		testSpawners[1].AddLayersOfHorizontalSpawnPoints(2250, 0, 1200, { -90 }, 100, 2, 1);
		//testSpawners[1].AddRythm({ 1.33,0.3,0.3 }, 21, 0);
		//testSpawners[1].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
		//testSpawners[1].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);

		
	} else {
		//do more things
	}
	//add player beats
	player->SetTransitions({ 0, 15.5 }); //15.5
	player->AddRythm({ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 }, {50, 50, 50, 50, 50, 50}, 0); //0.2
	player->AddRythm({ 0.3, 0.3 }, {50, 50}, 1);
	spawner = &(testSpawners[0]);
	player->speed = player->baseSpeed / player->beats[0][0];
	border->instructions = spawner->borderInstructions;
	border->InitializeFromOutside();
}

// Called every frame
void ABulletController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	clockTime += DeltaTime;

	//check spawning routines
	if (spawner->spawnTimes[index] < clockTime) {
		//time to spawn shit!
		for (int i = 0; i < spawner->spawnTable[index].size(); i++) {
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "SPAWNING STUFF");
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(spawner->spawnAngles[index][i]));
			FVector pos(spawner->spawnTable[index][i].X, 2, spawner->spawnTable[index][i].Y);
			float angle = 0;
			if (spawner->spawnTable[index][i].isAngleRelative) {
				FVector playerPos = player->GetActorLocation();
				float dX = playerPos.X - pos.X;
				float dY = playerPos.Z - pos.Z;
				angle = atan2f(dY, dX) * 180/PI;
			}
			for (int j = 0; j < spawner->spawnTable[index][i].angles.size(); j++) {
				activeBullets.push_back(GetWorld()->SpawnActor<ABasicBullet>(BulletClass,
					pos,
					FRotator(angle + spawner->spawnTable[index][i].angles[j], 0, 0)));
			}
		}
		index++;
		if (index == spawner->spawnTimes.size()) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "TRANSITIONING");
			transitionIndex++;
			if (transitionIndex == testSpawners.size()) {
				//just reset for now
				transitionIndex = 0;
			}
			spawner = &(testSpawners[transitionIndex]);
			index = 0;
			clockTime = 0;
		}
	}
	std::list<ABasicBullet*>::iterator itr = activeBullets.begin();
	while (itr != activeBullets.end()) {

		(*itr)->UpdateMovement(DeltaTime);
		if (abs((*itr)->GetActorLocation().X) > 2250 || abs((*itr)->GetActorLocation().Z) > 1265 || (*itr)->flaggedForRemoval) {
			(*itr)->Destroy();
			itr = activeBullets.erase(itr);
		}
		else {
			++itr;
		}
	}
	border->UpdateMovement(DeltaTime);
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
	spawner = &(testSpawners[0]);

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
