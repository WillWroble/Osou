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
	std::vector<float> C1 = { 0, 45, 90, 135, 180, 225, 270, 315};
	std::vector<float> C2 = { -10, 35, 80, 125, 170, 215, 260, 305 };
	std::vector<float> C3 = { 10, 55, 100, 145, 190, 235, 280, 325 };
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
	levelZero[3].AddRythm({ 0.23, 0.05, 0.05 }, 120, 0);
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

	levelZero[3].AddSpawnPoint(2000, 1000, C1, 120);
	levelZero[3].AddSpawnPoint(-2000, -1000, C1, 120+36);
	levelZero[3].AddSpawnPoint(-2000, 1000, C1, 120+(36*2));
	levelZero[3].AddSpawnPoint(2000, -1000, C1, 120+(36*3));

	levelZero[3].AddSpawnPoint(2000, 1000, C2, 120);
	levelZero[3].AddSpawnPoint(-2000, -1000, C2, 120 + 36);
	levelZero[3].AddSpawnPoint(-2000, 1000, C2, 120 + (36 * 2));
	levelZero[3].AddSpawnPoint(2000, 1000, C2, 120);

	levelZero[3].AddSpawnPoint(-2000, -1000, C3, 120 + 36);
	levelZero[3].AddSpawnPoint(-2000, 1000, C3, 120 + (36 * 2));
	levelZero[3].AddSpawnPoint(2000, -1000, C3, 120 + (36 * 3));
	levelZero[3].AddSpawnPoint(2000, -1000, C3, 120 + (36 * 3));


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
	//VEE FULL LEVEL
	std::vector<BulletSpawner> levelTwo = std::vector<BulletSpawner>();
	levelTwo.push_back(BulletSpawner());
	levelTwo[0].AddRythm({ 0.46, 0.1, 0.1 }, 68, 0);//68
	
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0);

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1);
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1);
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1);

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2);
	

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3);

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4);
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4);
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4);

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5);

	levelTwo[0].AddSpawnPoint(-2250, -1200, B1, 0+30, BulletType::BasicBullet, { 400, 1 });
	levelTwo[0].AddSpawnPoint(-2250, 1200, B4, 9+30, BulletType::BasicBullet, { 400, 1 });
	levelTwo[0].AddSpawnPoint(2250, -1200, B2, 18+30, BulletType::BasicBullet, { 400, 1 });
	levelTwo[0].AddSpawnPoint(2250, 1200, B3, 27+30, BulletType::BasicBullet, { 400, 1 });
	//hexagon
	
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1000, 1732), FVector2D(2000, 0), 3, 69);
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(2000, 0), FVector2D(1000, -1732), 3, 69);
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1000, -1732), FVector2D(-1000, -1732), 3, 69);
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1000, -1732), FVector2D(-2000, 0), 3, 69);
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-2000, 0), FVector2D(-1000, 1732), 3, 69);
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1000, 1732), FVector2D(1000, 1732), 3, 69);
	

	//triangle blob

	//angled lines 
	levelTwo[0].SpawnBetweenTwoPoints(FVector2D(1000, 3500), FVector2D(3500, 1000), 5, 85, BulletType::HexagonBullet);
	levelTwo[0].SpawnBetweenTwoPoints(FVector2D(3500, -1000), FVector2D(1000, -3500), 5, 85, BulletType::HexagonBullet);
	levelTwo[0].SpawnBetweenTwoPoints(FVector2D(-1000, -3500), FVector2D(-3500, -1000), 5, 85, BulletType::HexagonBullet);
	levelTwo[0].SpawnBetweenTwoPoints(FVector2D(-3500, 1000), FVector2D(-1000, 3500), 5, 85, BulletType::HexagonBullet);

	std::vector<FVector2D> vecs = { FVector2D(-2000, -1000), FVector2D(-2000, 1000), FVector2D(2000, 1000), FVector2D(2000, -1000)};
	//std::vector<float> ys = { -1000, 1000, 1000, -1000 };

	for (int i = 0; i < 4; i++) {
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(1000, 1732)+vecs[i], FVector2D(2000, 0)+vecs[i], 3, 102+18*i);
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(2000, 0)+vecs[i], FVector2D(1000, -1732)+vecs[i], 3, 102+18*i);
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(1000, -1732)+vecs[i], FVector2D(-1000, -1732)+vecs[i], 3, 102+18*i);
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(-1000, -1732)+vecs[i], FVector2D(-2000, 0)+vecs[i], 3, 102+18*i);
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(-2000, 0)+vecs[i], FVector2D(-1000, 1732)+vecs[i], 3, 102+18*i);
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(-1000, 1732)+vecs[i], FVector2D(1000, 1732)+vecs[i], 3, 102+18*i);

		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(1000, 1732) -vecs[i], FVector2D(2000, 0) -vecs[i], 3, 102 + 18 * i);
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(2000, 0) -vecs[i], FVector2D(1000, -1732) -vecs[i], 3, 102 + 18 * i);
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(1000, -1732) -vecs[i], FVector2D(-1000, -1732) -vecs[i], 3, 102 + 18 * i);
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(-1000, -1732) -vecs[i], FVector2D(-2000, 0) -vecs[i], 3, 102 + 18 * i);
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(-2000, 0) -vecs[i], FVector2D(-1000, 1732) -vecs[i], 3, 102 + 18 * i);
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(-1000, 1732) -vecs[i], FVector2D(1000, 1732) -vecs[i], 3, 102 + 18 * i);

		if (i == 3) {
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(1000, 1732) + vecs[i-1], FVector2D(2000, 0) + vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(2000, 0) + vecs[i-1], FVector2D(1000, -1732) + vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(1000, -1732) + vecs[i-1], FVector2D(-1000, -1732) + vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(-1000, -1732) + vecs[i-1], FVector2D(-2000, 0) + vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(-2000, 0) + vecs[i-1], FVector2D(-1000, 1732) + vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(-1000, 1732) + vecs[i-1], FVector2D(1000, 1732) + vecs[i-1], 3, 102 + 18 * i);

			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(1000, 1732) - vecs[i-1], FVector2D(2000, 0) - vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(2000, 0) - vecs[i-1], FVector2D(1000, -1732) - vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(1000, -1732) - vecs[i-1], FVector2D(-1000, -1732) - vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(-1000, -1732) - vecs[i-1], FVector2D(-2000, 0) - vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(-2000, 0) - vecs[i-1], FVector2D(-1000, 1732) - vecs[i-1], 3, 102 + 18 * i);
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(-1000, 1732) - vecs[i-1], FVector2D(1000, 1732) - vecs[i-1], 3, 102 + 18 * i);
		}
	}

	levelTwo.push_back(BulletSpawner());
	levelTwo[1].AddRythm({ 0.46, 0.1, 0.1 }, 37, 0);
	//vert one
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266, { -180 }, 500, 12, 0);

	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1216, { -180 }, 500, 12, 1);
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266, { -180 }, 500, 12, 1);
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1316, { -180 }, 500, 12, 1);

	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266, { -180 }, 500, 12, 2);
	//horiz one
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 12, 3);

	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 12, 4);
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 12, 4);
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 12, 4);

	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 12, 5);
	//vert two
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266-250, { -180 }, 500, 12, 6);

	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1216-250, { -180 }, 500, 12, 7);
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266-250, { -180 }, 500, 12, 7);
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1316-250, { -180 }, 500, 12, 7);

	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266-250, { -180 }, 500, 12, 8);
	//horiz two
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 12, 9);

	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 12, 10);
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 12, 10);
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 12, 10);

	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 12, 11);

	levelTwo[1].AddRythm({ 0.92 }, 15, 15.46);//was 15
	//levelTwo[1].AddSpawnPoints(0, 0, A1, 1, 900);
	//levelTwo[1].AddCorners({30, 60}, 1, 900);
	levelTwo[1].AddSpawnPoints(2250, 1000, A1, 4, 111);
	levelTwo[1].AddSpawnPoints(-2250, -1000, A1, 4, 112);
	levelTwo[1].AddSpawnPoints(-2250, 1000, A1, 4, 113);
	levelTwo[1].AddSpawnPoints(2250, -1000, A1, 4, 114);

	levelTwo[1].SortSpawnTimes();

	levelTwo.push_back(BulletSpawner());
	levelTwo[2].AddRythm({ 0.23, 0.05, 0.05 }, 91, 0);//91
	//levelTwo[2].AddRythm({ 0.46, 0.05, 0.05 }, 42, 15.84);
	//beat 1
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2, BulletType::BasicBullet, { 1400, 1 });

	//beat 2
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5, BulletType::BasicBullet, { 1400, 1 });



	//levelTwo[2].AddRythm({ 0.46, 0.05, 0.05 }, 23, 15.18);
	//
	////beat 1 spaced
	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 6, 0+138, BulletType::BasicBullet, { 1400, 1 });

	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 6, 139, BulletType::BasicBullet, { 1400, 1 });
	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 1000, 6, 139, BulletType::BasicBullet, { 1400, 1 });
	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 1000, 6, 139, BulletType::BasicBullet, { 1400, 1 });

	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 6, 140, BulletType::BasicBullet, { 1400, 1 });

	////beat 2 spaced
	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -1750, 1200, { -90 }, 1000, 6, 141, BulletType::BasicBullet, { 1400, 1 });

	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -1750, 1200, { -90 }, 1000, 6, 142, BulletType::BasicBullet, { 1400, 1 });
	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -1800, 1200, { -90 }, 1000, 6, 142, BulletType::BasicBullet, { 1400, 1 });
	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -1700, 1200, { -90 }, 1000, 6, 142, BulletType::BasicBullet, { 1400, 1 });

	//levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -1750, 1200, { -90 }, 1000, 6, 143, BulletType::BasicBullet, { 1400, 1 });
	
	//filling layer 1
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 27, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 28, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2300, 1200, { -90 }, 1000, 28, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2200, 1200, { -90 }, 1000, 28, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 29, BulletType::BasicBullet, { 1400, 1 });

	//filling layer 2
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 42, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 43, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2050, 1200, { -90 }, 1000, 43, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -1950, 1200, { -90 }, 1000, 43, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 44, BulletType::BasicBullet, { 1400, 1 });

	//filling layer 3
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1500, 54, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1500, 55, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2050, 1200, { -90 }, 1500, 55, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -1950, 1200, { -90 }, 1500, 55, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1500, 56, BulletType::BasicBullet, { 1400, 1 });

	//filling layer 4
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1500, 69, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1500, 70, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2300, 1200, { -90 }, 1500, 70, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2200, 1200, { -90 }, 1500, 70, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1500, 71, BulletType::BasicBullet, { 1400, 1 });

	//filling layer 5
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 93, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 94, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2300, 1200, { -90 }, 1000, 94, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2200, 1200, { -90 }, 1000, 94, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 95, BulletType::BasicBullet, { 1400, 1 });

	//filling layer 6
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 120, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 121, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2050, 1200, { -90 }, 1000, 121, BulletType::BasicBullet, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -1950, 1200, { -90 }, 1000, 121, BulletType::BasicBullet, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 122, BulletType::BasicBullet, { 1400, 1 });

	//shifting layer 1
	levelTwo[2].ClearSlots(21,138, 6);
	levelTwo[2].ClearSlots(21,139, 6);
	levelTwo[2].ClearSlots(21,140, 6);

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250, 1200, { -90 }, 500, 138, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5});

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250+35, 1200, { -90 }, 500, 139, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3300+35, 1200, { -90 }, 500, 139, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3200+35, 1200, { -90 }, 500, 139, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250+70, 1200, { -90 }, 500, 140, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	//shifting layer 2
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000, 1200, { -90 }, 500, 159, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000 - 35, 1200, { -90 }, 500, 160, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2050 - 35, 1200, { -90 }, 500, 160, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -1950 - 35, 1200, { -90 }, 500, 160, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000 - 70, 1200, { -90 }, 500, 161, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	//shifting layer 3 
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250, 1200, { -90 }, 500, 180, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250 - 35, 1200, { -90 }, 500, 181, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2300 - 35, 1200, { -90 }, 500, 181, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2200 - 35, 1200, { -90 }, 500, 181, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250 - 70, 1200, { -90 }, 500, 182, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	//shifting layer 4
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000, 1200, { -90 }, 500, 201, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000 + 35, 1200, { -90 }, 500, 202, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3050 + 35, 1200, { -90 }, 500, 202, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2950 + 35, 1200, { -90 }, 500, 202, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000 + 70, 1200, { -90 }, 500, 203, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	//shifting layer 5
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250, 1200, { -90 }, 500, 222, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250 + 35, 1200, { -90 }, 500, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3300 + 35, 1200, { -90 }, 500, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3200 + 35, 1200, { -90 }, 500, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250 + 70, 1200, { -90 }, 500, 224, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	//filling layer 5
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000, 1200, { -90 }, 1000, 222, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000 + 35, 1200, { -90 }, 1000, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3050 + 35, 1200, { -90 }, 1000, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2950 + 35, 1200, { -90 }, 1000, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000 + 70, 1200, { -90 }, 1000, 224, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.5 });
	//shifting layer 6
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000, 1200, { -90 }, 500, 243, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000 - 35, 1200, { -90 }, 500, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2050 - 35, 1200, { -90 }, 500, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -1950 - 35, 1200, { -90 }, 500, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000 - 70, 1200, { -90 }, 500, 245, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	//filling layer 6
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250, 1200, { -90 }, 1000, 243, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250 - 35, 1200, { -90 }, 1000, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2300 - 35, 1200, { -90 }, 1000, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2200 - 35, 1200, { -90 }, 1000, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250 - 70, 1200, { -90 }, 1000, 245, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.5 });


	//regular layer refill


	//cross hex pattern
	/*for (int i = 0; i < 4; i++) {
		levelTwo[2].AddProjectionFromPoint(vecs[i], FVector2D(1000, 1732) + vecs[i], FVector2D(2000, 0) + vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(vecs[i], FVector2D(2000, 0) + vecs[i], FVector2D(1000, -1732) + vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(vecs[i], FVector2D(1000, -1732) + vecs[i], FVector2D(-1000, -1732) + vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(vecs[i], FVector2D(-1000, -1732) + vecs[i], FVector2D(-2000, 0) + vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(vecs[i], FVector2D(-2000, 0) + vecs[i], FVector2D(-1000, 1732) + vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(vecs[i], FVector2D(-1000, 1732) + vecs[i], FVector2D(1000, 1732) + vecs[i], 3, 152 + 36 * i);

		levelTwo[2].AddProjectionFromPoint(-vecs[i], FVector2D(1000, 1732) - vecs[i], FVector2D(2000, 0) - vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(-vecs[i], FVector2D(2000, 0) - vecs[i], FVector2D(1000, -1732) - vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(-vecs[i], FVector2D(1000, -1732) - vecs[i], FVector2D(-1000, -1732) - vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(-vecs[i], FVector2D(-1000, -1732) - vecs[i], FVector2D(-2000, 0) - vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(-vecs[i], FVector2D(-2000, 0) - vecs[i], FVector2D(-1000, 1732) - vecs[i], 3, 152 + 36 * i);
		levelTwo[2].AddProjectionFromPoint(-vecs[i], FVector2D(-1000, 1732) - vecs[i], FVector2D(1000, 1732) - vecs[i], 3, 152 + 36 * i);
	}*/
	/*
	levelTwo[2].SpawnTriangleBlob(2500, 1410, 30-180, 600, 3, 143, BulletType::HexagonBullet);
	levelTwo[2].SpawnTriangleBlob(-2500, -1410, 30, 600, 3, 143, BulletType::HexagonBullet);
	levelTwo[2].SpawnTriangleBlob(-2500, 1410, -30, 600, 3, 143, BulletType::HexagonBullet);
	levelTwo[2].SpawnTriangleBlob(2500, -1410, 60+90, 600, 3, 143, BulletType::HexagonBullet);
	*/
	
	/*levelTwo[2].SpawnTriangleBlob(2500, 1410, 30 - 180, 600, 5, 158-18, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[2].SpawnTriangleBlob(2500, -1410, 60 + 90, 600, 5, 173-18, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[2].SpawnTriangleBlob(-2500, -1410, 30, 600, 5, 188-18, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[2].SpawnTriangleBlob(-2500, 1410, -30, 600, 5, 202-18, BulletType::HexagonBullet, {700, 1});
	*/
	
	/*levelTwo[2].AddSpawnPoint(-2250, -1200, A1, 176 + 30-36, BulletType::BasicBullet, { 400, 1 });
	levelTwo[2].AddSpawnPoint(-2250, 1200, A1, 176 + 9 + 30-36, BulletType::BasicBullet, { 400, 1 });
	levelTwo[2].AddSpawnPoint(2250, -1200, A1, 176 + 18 + 30-36, BulletType::BasicBullet, { 400, 1 });
	levelTwo[2].AddSpawnPoint(2250, 1200, A1, 176 + 27 + 30-36, BulletType::BasicBullet, { 400, 1 });*/

	//levelTwo[2].AddRythm({ 0.46 }, 28, 16.2-0.4); //17.2
	//levelTwo[2].AddTargetingSpawnPoints(0, 0, { -60, 0, 60 }, 4, 195, BulletType::HexagonBullet);
	//levelTwo[2].AddTargetingSpawnPoints(0, 0, { -30, 30 }, 4, 197, BulletType::HexagonBullet);
	levelTwo[2].SortSpawnTimes();




	levelTwo.push_back(BulletSpawner());
	levelTwo[3].AddRythm({ 0.46, 0.1, 0.1 }, 100, 0);

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0);

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1);
	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1);
	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1);

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2);


	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3);

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4);
	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4);
	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4);

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5);

	////angled spawn lines
	//levelTwo[3].SpawnBetweenTwoPoints(FVector2D(1000, 3500), FVector2D(3500, 1000), 5, 0, BulletType::HexagonBullet);
	//levelTwo[3].SpawnBetweenTwoPoints(FVector2D(3500, -1000), FVector2D(1000, -3500), 5, 0, BulletType::HexagonBullet);
	//levelTwo[3].SpawnBetweenTwoPoints(FVector2D(-1000, -3500), FVector2D(-3500, -1000), 5, 0, BulletType::HexagonBullet);
	//levelTwo[3].SpawnBetweenTwoPoints(FVector2D(-3500, 1000), FVector2D(-1000, 3500), 5, 0, BulletType::HexagonBullet);

	////straight spawn lines
	//levelTwo[3].SpawnBetweenTwoPoints(FVector2D(3182, 1750), FVector2D(3182, -1750), 5, 0, BulletType::HexagonBullet);
	//levelTwo[3].SpawnBetweenTwoPoints(FVector2D(1750, -3182), FVector2D(-1750, -3182), 5, 0, BulletType::HexagonBullet);
	//levelTwo[3].SpawnBetweenTwoPoints(FVector2D(-3182, -1750), FVector2D(-3182, 1750), 5, 0, BulletType::HexagonBullet);
	//levelTwo[3].SpawnBetweenTwoPoints(FVector2D(-1750, 3182), FVector2D(1750, 3182), 5, 0, BulletType::HexagonBullet);

	/*levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1000, 1000), FVector2D(1000, 1000), 5, 0);
	levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1000, 1000), FVector2D(1000, -1000), 5, 0);
	levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1000, -1000), FVector2D(-1000, -1000), 5, 0);
	levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1000, -1000), FVector2D(-1000, 1000), 5, 0);*/

	for (int i = 0; i < 2; i++) {
		levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0)+vecs[i], FVector2D(-1000, 1000) + vecs[i], FVector2D(1000, 1000) + vecs[i], 5, 0+18*i);
		levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0) + vecs[i], FVector2D(1000, 1000) + vecs[i], FVector2D(1000, -1000) + vecs[i], 5, 0 + 18 * i);
		levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0) + vecs[i], FVector2D(1000, -1000) + vecs[i], FVector2D(-1000, -1000) + vecs[i], 5, 0 + 18 * i);
		levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0) + vecs[i], FVector2D(-1000, -1000) + vecs[i], FVector2D(-1000, 1000) + vecs[i], 5, 0 + 18 * i);
	}
	levelTwo[3].SpawnTriangleBlob(2500, 1410, 30 - 180, 600, 5, 158 - 18-110, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[3].SpawnTriangleBlob(2500, -1410, 60 + 90, 600, 5, 173 - 18-110, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[3].SpawnTriangleBlob(-2500, -1410, 30, 600, 5, 188 - 18-110, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[3].SpawnTriangleBlob(-2500, 1410, -30, 600, 5, 202 - 18-110, BulletType::HexagonBullet, { 700, 1 });


	levelTwo[3].AddRythm({ 0.46 }, 40, 29.54);
	//levelTwo[3].AddCorners({ 18, 36, 54, 72 }, 2, 300);
	levelTwo[3].AddSpawnPoints(-2250, -1265, { 18, 36, 54, 72 }, 8, 300);
	levelTwo[3].AddSpawnPoints(-2250, 1265, { 18-90, 36-90, 54-90, 72-90 }, 8, 302);
	levelTwo[3].AddSpawnPoints(2250, 1265, { 18-180, 36-180, 54-180, 72-180 }, 8, 304);
	levelTwo[3].AddSpawnPoints(2250, -1265, { 18+90, 36+90, 54+90, 72+90 }, 8, 306);

	levelTwo[3].SortSpawnTimes();



	//levelTwo[0] = levelTwo[3];
	

	levelTwo[0].AddInstruction(4, 0, 0, 9999);
	allLevels.push_back(levelTwo);
}

LevelLibrary::LevelLibrary()
{

}

LevelLibrary::~LevelLibrary()
{
}
