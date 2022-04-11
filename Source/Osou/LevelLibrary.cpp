// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelLibrary.h"

std::vector<std::vector<BulletSpawner>> LevelLibrary::allLevels = std::vector<std::vector<BulletSpawner>>();
void LevelLibrary::BuildLevels()
{
	//ANGEL SETS
	std::vector<float> A1 = { 0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5 };
	std::vector<float> B1 = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	std::vector<float> B2 = std::vector<float>(10);
	std::vector<float> B3 = std::vector<float>(10);
	std::vector<float> B4 = std::vector<float>(10);
	for (int i = 0; i < 10; i++) {
		B2[i] = B1[i] + 90;
		B3[i] = B1[i] + 180;
		B4[i] = B1[i] + 270;
		//B2[i] = B1[i] + 90;

	}
	//LEVEL ZERO
	std::vector<BulletSpawner> levelZero = std::vector<BulletSpawner>();
	levelZero.push_back(BulletSpawner());
	levelZero[0].AddRythm({ 0.46, 0.1, 0.1 }, 80, 0);
	levelZero[0].AddInstruction(4, 0, 0, 9999);

	levelZero.push_back(BulletSpawner());
	levelZero[1].AddRythm({ 0.46, 0.1, 0.1 }, 20, 0);
	levelZero[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0);

	levelZero[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1);
	levelZero[1].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1);
	levelZero[1].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1);

	levelZero[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2);


	levelZero[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3);

	levelZero[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4);
	levelZero[1].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4);
	levelZero[1].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4);

	levelZero[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5);

	levelZero.push_back(BulletSpawner());
	levelZero[2].AddRythm({ 0.46, 0.1, 0.1 }, 20, 0);
	levelZero[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0);

	levelZero[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1);
	levelZero[2].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1);
	levelZero[2].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1);

	levelZero[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2);


	levelZero[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3);

	levelZero[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4);
	levelZero[2].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4);
	levelZero[2].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4);

	levelZero[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5);
	levelZero[2].AddSpawnPoint(-2250, -1200, B1, 0, BulletType::BasicBullet, { 400, 1 });
	levelZero[2].AddSpawnPoint(-2250, 1200, B4, 9, BulletType::BasicBullet, { 400, 1 });
	levelZero[2].AddSpawnPoint(2250, -1200, B2, 18, BulletType::BasicBullet, { 400, 1 });
	levelZero[2].AddSpawnPoint(2250, 1200, B3, 27, BulletType::BasicBullet, { 400, 1 });
	//levelZero[1].AddSpawnPoint(800, 0, A1, 45, BulletType::BasicBullet, { 400, 1 });
	//levelZero[1].AddSpawnPoint(-800, 0, A1, 54, BulletType::BasicBullet, { 400, 1 });

	levelZero.push_back(BulletSpawner());
	levelZero[3].AddRythm({ 0.23, 0.05, 0.05 }, 20, 0);
	levelZero[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0, BulletType::BasicBullet, { 1400, 1 });

	levelZero[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1, BulletType::BasicBullet, { 1400, 1 });
	levelZero[3].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1, BulletType::BasicBullet, { 1400, 1 });
	levelZero[3].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1, BulletType::BasicBullet, { 1400, 1 });

	levelZero[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2, BulletType::BasicBullet, { 1400, 1 });


	levelZero[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3, BulletType::BasicBullet, { 1400, 1 });

	levelZero[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4, BulletType::BasicBullet, { 1400, 1 });
	levelZero[3].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4, BulletType::BasicBullet, { 1400, 1 });
	levelZero[3].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4, BulletType::BasicBullet, { 1400, 1 });

	levelZero[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5, BulletType::BasicBullet, { 1400, 1 });

	allLevels.push_back(levelZero);
	
	//LEVEL ONE
	std::vector<BulletSpawner> levelOne;
	levelOne.clear();
	levelOne.push_back(BulletSpawner());

	levelOne[0].AddRythm({ 1.33,0.3,0.3 }, 7, 0);
	levelOne[0].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
	levelOne[0].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
	levelOne[0].AddCorners({ 60, 30 }, 1, 0, BulletType::BasicBullet);
	//levelOne[0].AddCorners({ 0 }, 1, 0, BulletType::CurvedBullet, { 700, 2, 0, 1, 1, 1 });
	//levelOne[0].AddCorners({ 70 }, 1, 0, BulletType::CurvedBullet, { 700, 2, 0, -1, 1, 1 });


	levelOne[0].AddInstruction(2, 0, -1000, 1); //5
	levelOne[0].AddInstruction(1, 1, 0, 4);
	levelOne[0].AddInstruction(0, 1000, -1000, 2);
	levelOne[0].AddInstruction(3, 0, 0, 2);

	levelOne[0].AddInstruction(4, 0, 0, 15);

	levelOne[0].AddInstruction(1, 5, 0, 1);
	levelOne[0].AddInstruction(2, 0, 1000, 1);
	levelOne[0].AddInstruction(1, 1.5, 0, 4);
	levelOne[0].AddInstruction(0, 1000, 1000, 2);
	levelOne[0].AddInstruction(0, 1000, -1000, 4);
	levelOne[0].AddInstruction(0, 0, -1000, 2);
	levelOne[0].AddInstruction(3, 0, 0, 2);

	levelOne[0].AddInstruction(4, 0, 0, 71.5);

	levelOne[0].AddInstruction(1, 5, 0, 1);
	levelOne[0].AddInstruction(2, 0, 0, 1);
	levelOne[0].AddInstruction(1, 0.75, 0, 8.5);

	levelOne[0].AddInstruction(4, 0, 0, 9999);



	//testSpawner.AddSpawnPoints(0, 0, { 0, 45, 90, 135, 180, 225, 270, 315 }, 4, 0);
	levelOne.push_back(BulletSpawner());
	levelOne[1].AddRythm({ 0.5 }, 27, 0); //27
	levelOne[1].AddLayersOfHorizontalSpawnPoints(2250, -2250, 1200, { -90 }, 100, 2, 0);
	levelOne[1].AddLayersOfHorizontalSpawnPoints(2250, 0, 1200, { -90 }, 100, 2, 1);
	//levelOne[1].AddRythm({ 1.33,0.3,0.3 }, 21, 0);
	//levelOne[1].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
	//levelOne[1].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
	levelOne.push_back(BulletSpawner());
	levelOne[2].AddRythm({ 1.33,0.3,0.3 }, 12, 0);
	levelOne[2].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
	levelOne[2].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
	levelOne[2].AddCorners({ 60, 30 }, 1, 0);

	levelOne[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 10, 17, BulletType::BasicBullet, { 300, 1 });
	levelOne[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 10, 17, BulletType::BasicBullet, { 300, 1 });
	levelOne[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 10, 17, BulletType::BasicBullet, { 300, 1 });
	levelOne[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 10, 17, BulletType::BasicBullet, { 300, 1 });
	levelOne[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 10, 17, BulletType::BasicBullet, { 300, 1 });

	levelOne.push_back(BulletSpawner());
	//levelOne[3] = &(levelOne[3]);
	levelOne[3].AddRythm({ 0.3 }, 64, 0);
	std::vector<float> A2 = std::vector<float>(16);
	std::vector<float> A3 = std::vector<float>(16);
	std::vector<float> A4 = std::vector<float>(16);

	for (int i = 0; i < 16; i++) {
		A2[i] = A1[i] + 90;
		A3[i] = A1[i] + 180;
		A4[i] = A1[i] + 270;
	}
	levelOne[3].AddDynamicSpawnPoints(0, 0, { 0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5 }, 1, 0);
	levelOne[3].AddDynamicSpawnPoints(0, 0, A2, 1, 0);
	levelOne[3].AddDynamicSpawnPoints(0, 0, A3, 1, 0);
	levelOne[3].AddDynamicSpawnPoints(0, 0, A4, 1, 0);

	levelOne[3].AddTargetingSpawnPoints(0, 0, { 0 }, 4, 0, BulletType::ExplodingBullet);

	levelOne[3].AddRythm({ 0.61 }, 5, 14.3);
	levelOne[3].AddSpawnPoints(0, 0, A1, 1, 64);


	levelOne[3].SortSpawnTimes();

	levelOne.push_back(BulletSpawner());
	levelOne[4].AddRythm({ 0.5 }, 54, 0); //27
	levelOne[4].AddLayersOfHorizontalSpawnPoints(2250, -2250, 1200, { -90 }, 100, 2, 0);
	levelOne[4].AddLayersOfHorizontalSpawnPoints(2250, 0, 1200, { -90 }, 100, 2, 1);

	levelOne[4].AddRythm({ 2 }, 6, 13.5);
	levelOne[4].AddSpawnPoint(800, 400, A1, 54, BulletType::BasicBullet, { 400, 1 });
	levelOne[4].AddSpawnPoint(-800, -400, A1, 55, BulletType::BasicBullet, { 400, 1 });
	levelOne[4].AddSpawnPoint(-800, 400, A1, 56, BulletType::BasicBullet, { 400, 1 });
	levelOne[4].AddSpawnPoint(800, -400, A1, 57, BulletType::BasicBullet, { 400, 1 });
	levelOne[4].AddSpawnPoint(800, 0, A1, 58, BulletType::BasicBullet, { 400, 1 });
	levelOne[4].AddSpawnPoint(-800, 0, A1, 59, BulletType::BasicBullet, { 400, 1 });

	levelOne[4].SortSpawnTimes();

	levelOne.push_back(BulletSpawner());

	levelOne[5].AddRythm({ 1.33,0.3,0.3 }, 11, 0);
	levelOne[5].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
	levelOne[5].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
	levelOne[5].AddCorners({ 60, 30 }, 1, 21, BulletType::BasicBullet);

	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 10, 0, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 10, 0, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 10, 0, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 10, 0, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 10, 0, BulletType::BasicBullet, { 300, 1 });

	levelOne[5].AddSpawnPointByEquation(12, 10, &(EquationLibrary::xcircle), &(EquationLibrary::ycircle), &(EquationLibrary::acircle), BulletType::ExplodingBullet, { 450, 2, 0 });
	levelOne[5].AddRythm({ 2 }, 6, 4);
	levelOne[5].AddCorners({ 0 }, 1, 33, BulletType::CurvedBullet, { 700, 2, 0, 1, 1, 1 });
	levelOne[5].AddCorners({ 70 }, 1, 33, BulletType::CurvedBullet, { 700, 2, 0, -1, 1, 1 });
	levelOne[5].AddCorners({ 18, 36, 54, 72 }, 2, 33);

	levelOne[5].SortSpawnTimes();

	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 10, 29, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 10, 29, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 10, 29, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 10, 29, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 10, 29, BulletType::BasicBullet, { 300, 1 });

	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 5, 38, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 5, 38, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 5, 38, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 5, 38, BulletType::BasicBullet, { 300, 1 });
	levelOne[5].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 5, 38, BulletType::BasicBullet, { 300, 1 });

	allLevels.push_back(levelOne);
	//allLevels[1] = levelZero;
	//allLevels[0] = levelOne;
	//LEVEL TWO
}

LevelLibrary::LevelLibrary()
{

}

LevelLibrary::~LevelLibrary()
{
}
