// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelLibrary.h"

std::vector<std::vector<BulletSpawner>> LevelLibrary::allLevels = std::vector<std::vector<BulletSpawner>>();
void LevelLibrary::BuildLevels()
{
	//ANGEL SETS
	std::vector<float> A1 = { 0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5 };
	std::vector<float> A1_2 = std::vector<float>(16);
	std::vector<float> A1_3 = std::vector<float>(16);
	std::vector<float> A1_4 = std::vector<float>(16);
	std::vector<float> A1plus180 = std::vector<float>(16);


	std::vector<float> B1 = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	std::vector<float> B2 = std::vector<float>(10);
	std::vector<float> B3 = std::vector<float>(10);
	std::vector<float> B4 = std::vector<float>(10);
	std::vector<float> C1 = { 0, 45, 90, 135, 180, 225, 270, 315};
	std::vector<float> C2 = { -10, 35, 80, 125, 170, 215, 260, 305 };
	std::vector<float> C3 = { 10, 55, 100, 145, 190, 235, 280, 325 };
	std::vector<float> D1 = { 0, 10, 20, 30 ,40, 50, 60, 70, 80, 90,100, 110,120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350 };
	std::vector<float> D2 = std::vector<float>(36);
	std::vector<float> E1 = { 0, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 144, 156, 168, 180, 192, 204, 216, 228, 240, 252, 264, 276, 288, 300, 312, 324, 336, 348 };
	std::vector<float> E2 = std::vector<float>(30);
	std::vector<float> F1 = std::vector<float>(24);
	std::vector<float> F2 = std::vector<float>(24);
	std::vector<float> G1 = std::vector<float>(20);
	std::vector<float> G2 = std::vector<float>(20);

	float fCount = 0;
	for (int i = 0; i < 24; i++) {
		F1[i] = fCount;
		F2[i] = fCount + 7.5;
		fCount += 15;
	}
	fCount = 0;
	for (int i = 0; i < 20; i++) {
		G1[i] = fCount;
		G2[i] = fCount + 9;
		fCount += 18;
	}
	for (int i = 0; i < 30; i++) {
		E2[i] = E1[i] + 6;
	}
	for (int i = 0; i < 36; i++) {
		D2[i] = D1[i] + 5;
	}
	for (int i = 0; i < 16; i++) {
		A1_2[i] = A1[i] + 11.25;
		A1_3[i] = A1[i] + 7.5;
		A1_4[i] = A1[i] + 15;
		A1plus180[i] = A1[i] + 180;
	}
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
	
	//LEVEL ONE: UN OWEN WAS HER
	std::vector<BulletSpawner> levelOne;
	levelOne.clear();
	levelOne.push_back(BulletSpawner());

	levelOne[0].AddRythm({ 1.33,0.3,0.3 }, 7, 0);
	levelOne[0].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
	levelOne[0].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
	levelOne[0].AddCorners({ 60, 30 }, 1, 0, BulletType::BasicBullet);
	//levelOne[0].AddCorners({ 0 }, 1, 0, BulletType::CurvedBullet, { 700, 2, 0, 1, 1, 1 });
	//levelOne[0].AddCorners({ 70 }, 1, 0, BulletType::CurvedBullet, { 700, 2, 0, -1, 1, 1 });

	/*
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
	*/


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

	levelOne[2].AddRythm({ 6 }, 3, 2.5 - 6);
	levelOne[2].AddTargetingSpawnPoints(69, 420, { 0 }, 1, 36, BulletType::BasicFireball, { 900, 1});
	levelOne[2].SortSpawnTimes();

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

	levelOne.insert(levelOne.begin(), BulletSpawner());

	levelOne[0].AddInstruction(4, 0, 0, 2);

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



	levelOne[0].AddRythm({ 1 }, 2, 0);

	allLevels.push_back(levelOne);
	//allLevels[1] = levelZero;
	//allLevels[0] = levelOne;
	//LEVEL TWO
	//VEE FULL LEVEL
	std::vector<BulletSpawner> levelTwo = std::vector<BulletSpawner>();
	levelTwo.push_back(BulletSpawner());
	levelTwo[0].AddRythm({ 0.46, 0.1, 0.1 }, 68, 0);//68
	
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0, BulletType::BasicBulletBlue, {700, 1});

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2, BulletType::BasicBulletBlue, { 700, 1 });
	

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[0].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[0].AddSpawnPoint(-2250, -1200, B1, 0+30, BulletType::BasicBullet, { 400, 1 });
	levelTwo[0].AddSpawnPoint(-2250, 1200, B4, 9+30, BulletType::BasicBullet, { 400, 1 });
	levelTwo[0].AddSpawnPoint(2250, -1200, B2, 18+30, BulletType::BasicBullet, { 400, 1 });
	levelTwo[0].AddSpawnPoint(2250, 1200, B3, 27+30, BulletType::BasicBullet, { 400, 1 });
	//hexagon
	
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1000, 1732), FVector2D(2000, 0), 3, 69, BulletType::BasicBullet, { 700, 1 });
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(2000, 0), FVector2D(1000, -1732), 3, 69, BulletType::BasicBullet, { 700, 1 });
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1000, -1732), FVector2D(-1000, -1732), 3, 69, BulletType::BasicBullet, { 700, 1 });
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1000, -1732), FVector2D(-2000, 0), 3, 69, BulletType::BasicBullet, { 700, 1 });
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-2000, 0), FVector2D(-1000, 1732), 3, 69, BulletType::BasicBullet, { 700, 1 });
	levelTwo[0].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1000, 1732), FVector2D(1000, 1732), 3, 69, BulletType::BasicBullet, { 700, 1 });
	

	//triangle blob

	//angled lines 
	levelTwo[0].SpawnBetweenTwoPoints(FVector2D(1000, 3500), FVector2D(3500, 1000), 5, 85, BulletType::HexagonBullet);
	levelTwo[0].SpawnBetweenTwoPoints(FVector2D(3500, -1000), FVector2D(1000, -3500), 5, 85, BulletType::HexagonBullet);
	levelTwo[0].SpawnBetweenTwoPoints(FVector2D(-1000, -3500), FVector2D(-3500, -1000), 5, 85, BulletType::HexagonBullet);
	levelTwo[0].SpawnBetweenTwoPoints(FVector2D(-3500, 1000), FVector2D(-1000, 3500), 5, 85, BulletType::HexagonBullet);

	std::vector<FVector2D> vecs = { FVector2D(-2000, -1000), FVector2D(-2000, 1000), FVector2D(2000, 1000), FVector2D(2000, -1000)};
	//std::vector<float> ys = { -1000, 1000, 1000, -1000 };

	for (int i = 0; i < 4; i++) {
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(1000, 1732)+vecs[i], FVector2D(2000, 0)+vecs[i], 3, 102+18*i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(2000, 0)+vecs[i], FVector2D(1000, -1732)+vecs[i], 3, 102+18*i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(1000, -1732)+vecs[i], FVector2D(-1000, -1732)+vecs[i], 3, 102+18*i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(-1000, -1732)+vecs[i], FVector2D(-2000, 0)+vecs[i], 3, 102+18*i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(-2000, 0)+vecs[i], FVector2D(-1000, 1732)+vecs[i], 3, 102+18*i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(vecs[i], FVector2D(-1000, 1732)+vecs[i], FVector2D(1000, 1732)+vecs[i], 3, 102+18*i, BulletType::BasicBullet, { 700, 1 });

		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(1000, 1732) -vecs[i], FVector2D(2000, 0) -vecs[i], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(2000, 0) -vecs[i], FVector2D(1000, -1732) -vecs[i], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(1000, -1732) -vecs[i], FVector2D(-1000, -1732) -vecs[i], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(-1000, -1732) -vecs[i], FVector2D(-2000, 0) -vecs[i], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(-2000, 0) -vecs[i], FVector2D(-1000, 1732) -vecs[i], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[0].AddProjectionFromPoint(-vecs[i], FVector2D(-1000, 1732) -vecs[i], FVector2D(1000, 1732) -vecs[i], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });

		if (i == 3) {
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(1000, 1732) + vecs[i-1], FVector2D(2000, 0) + vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(2000, 0) + vecs[i-1], FVector2D(1000, -1732) + vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(1000, -1732) + vecs[i-1], FVector2D(-1000, -1732) + vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(-1000, -1732) + vecs[i-1], FVector2D(-2000, 0) + vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(-2000, 0) + vecs[i-1], FVector2D(-1000, 1732) + vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(vecs[i-1], FVector2D(-1000, 1732) + vecs[i-1], FVector2D(1000, 1732) + vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });

			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(1000, 1732) - vecs[i-1], FVector2D(2000, 0) - vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(2000, 0) - vecs[i-1], FVector2D(1000, -1732) - vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(1000, -1732) - vecs[i-1], FVector2D(-1000, -1732) - vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(-1000, -1732) - vecs[i-1], FVector2D(-2000, 0) - vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(-2000, 0) - vecs[i-1], FVector2D(-1000, 1732) - vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
			levelTwo[0].AddProjectionFromPoint(-vecs[i-1], FVector2D(-1000, 1732) - vecs[i-1], FVector2D(1000, 1732) - vecs[i-1], 3, 102 + 18 * i, BulletType::BasicBullet, { 700, 1 });
		}
	}

	levelTwo.push_back(BulletSpawner());
	levelTwo[1].AddRythm({ 0.46, 0.1, 0.1 }, 37, 0);
	//vert one
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266, { -180 }, 500, 12, 0, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1216, { -180 }, 500, 12, 1, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266, { -180 }, 500, 12, 1, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1316, { -180 }, 500, 12, 1, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266, { -180 }, 500, 12, 2, BulletType::BasicBulletBlue, { 700, 1 });
	//horiz one
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 12, 3, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 12, 4, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 12, 4, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 12, 4, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 12, 5, BulletType::BasicBulletBlue, { 700, 1 });
	//vert two
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266-250, { -180 }, 500, 12, 6, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1216-250, { -180 }, 500, 12, 7, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266-250, { -180 }, 500, 12, 7, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1316-250, { -180 }, 500, 12, 7, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddLayersOfVerticalSpawnPoints(2531, 2250, -1266-250, { -180 }, 500, 12, 8, BulletType::BasicBulletBlue, { 700, 1 });
	//horiz two
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 12, 9, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 12, 10, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 12, 10, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 12, 10, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 12, 11, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[1].AddRythm({ 0.92 }, 15, 15.46);//was 15
	//levelTwo[1].AddSpawnPoints(0, 0, A1, 1, 900);
	//levelTwo[1].AddCorners({30, 60}, 1, 900);
	levelTwo[1].AddSpawnPoints(2250, 1000, A1, 4, 111, BulletType::BasicBullet, { 700, 1 });
	levelTwo[1].AddSpawnPoints(-2250, -1000, A1, 4, 112, BulletType::BasicBullet, { 700, 1 });
	levelTwo[1].AddSpawnPoints(-2250, 1000, A1, 4, 113, BulletType::BasicBullet, { 700, 1 });
	levelTwo[1].AddSpawnPoints(2250, -1000, A1, 4, 114, BulletType::BasicBullet, { 700, 1 });

	levelTwo[1].SortSpawnTimes();

	levelTwo.push_back(BulletSpawner());
	levelTwo[2].AddRythm({ 0.23, 0.05, 0.05 }, 91, 0);//91
	//levelTwo[2].AddRythm({ 0.46, 0.05, 0.05 }, 42, 15.84);
	//beat 1
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2, BulletType::BasicBulletBlue, { 1400, 1 });

	//beat 2
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5, BulletType::BasicBulletBlue, { 1400, 1 });



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
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 27, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 28, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2300, 1200, { -90 }, 1000, 28, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2200, 1200, { -90 }, 1000, 28, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 29, BulletType::BasicBulletBlue, { 1400, 1 });

	//filling layer 2
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 42, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 43, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2050, 1200, { -90 }, 1000, 43, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -1950, 1200, { -90 }, 1000, 43, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 44, BulletType::BasicBulletBlue, { 1400, 1 });

	//filling layer 3
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1500, 54, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1500, 55, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2050, 1200, { -90 }, 1500, 55, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -1950, 1200, { -90 }, 1500, 55, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1500, 56, BulletType::BasicBulletBlue, { 1400, 1 });

	//filling layer 4
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1500, 69, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1500, 70, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2300, 1200, { -90 }, 1500, 70, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2200, 1200, { -90 }, 1500, 70, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1500, 71, BulletType::BasicBulletBlue, { 1400, 1 });

	//filling layer 5
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 93, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 94, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2300, 1200, { -90 }, 1000, 94, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2200, 1200, { -90 }, 1000, 94, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 1000, 95, BulletType::BasicBulletBlue, { 1400, 1 });

	//filling layer 6
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 120, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 121, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2050, 1200, { -90 }, 1000, 121, BulletType::BasicBulletBlue, { 1400, 1 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -1950, 1200, { -90 }, 1000, 121, BulletType::BasicBulletBlue, { 1400, 1 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(4250, -2000, 1200, { -90 }, 1000, 122, BulletType::BasicBulletBlue, { 1400, 1 });

	//shifting layer 1
	levelTwo[2].ClearSlots(21,138, 6);
	levelTwo[2].ClearSlots(21,139, 6);
	levelTwo[2].ClearSlots(21,140, 6);

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250, 1200, { -90 }, 500, 138, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25});

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250+17.5, 1200, { -90 }, 500, 139, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3300+17.5, 1200, { -90 }, 500, 139, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3200+17.5, 1200, { -90 }, 500, 139, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250+35, 1200, { -90 }, 500, 140, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	//shifting layer 2
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000, 1200, { -90 }, 500, 159, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000 - 17.5, 1200, { -90 }, 500, 160, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2050 - 17.5, 1200, { -90 }, 500, 160, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -1950 - 17.5, 1200, { -90 }, 500, 160, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000 - 35, 1200, { -90 }, 500, 161, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	//shifting layer 3 
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250, 1200, { -90 }, 500, 180, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250 - 17.5, 1200, { -90 }, 500, 181, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2300 - 17.5, 1200, { -90 }, 500, 181, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2200 - 17.5, 1200, { -90 }, 500, 181, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250 - 35, 1200, { -90 }, 500, 182, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	//shifting layer 4
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000, 1200, { -90 }, 500, 201, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000 + 17.5, 1200, { -90 }, 500, 202, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3050 + 17.5, 1200, { -90 }, 500, 202, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2950 + 17.5, 1200, { -90 }, 500, 202, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000 + 35, 1200, { -90 }, 500, 203, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	//shifting layer 5
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250, 1200, { -90 }, 500, 222, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250 + 17.5, 1200, { -90 }, 500, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3300 + 17.5, 1200, { -90 }, 500, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3200 + 17.5, 1200, { -90 }, 500, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3250 + 35, 1200, { -90 }, 500, 224, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	//filling layer 5
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000, 1200, { -90 }, 1000, 222, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000 + 17.5, 1200, { -90 }, 1000, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3050 + 17.5, 1200, { -90 }, 1000, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2950 + 17.5, 1200, { -90 }, 1000, 223, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -3000 + 35, 1200, { -90 }, 1000, 224, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, 0.25 });
	//shifting layer 6
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000, 1200, { -90 }, 500, 243, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000 - 17.5, 1200, { -90 }, 500, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2050 - 17.5, 1200, { -90 }, 500, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -1950 - 17.5, 1200, { -90 }, 500, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2000 - 35, 1200, { -90 }, 500, 245, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	//filling layer 6
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250, 1200, { -90 }, 1000, 243, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250 - 17.5, 1200, { -90 }, 1000, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2300 - 17.5, 1200, { -90 }, 1000, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });
	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2200 - 17.5, 1200, { -90 }, 1000, 244, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });

	levelTwo[2].AddHorizontalWallOfSpawnPoints(5500, -2250 - 35, 1200, { -90 }, 1000, 245, BulletType::CurvedBulletReg, { 1400, 1, 1, 1, 1, -0.25 });


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

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 0, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200, { -90 }, 500, 6, 1, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 2, BulletType::BasicBulletBlue, { 700, 1 });


	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 3, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 700, 1 });
	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200, { -90 }, 500, 6, 4, BulletType::BasicBulletBlue, { 700, 1 });

	levelTwo[3].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 5, BulletType::BasicBulletBlue, { 700, 1 });

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
		levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0)+vecs[i], FVector2D(-1000, 1000) + vecs[i], FVector2D(1000, 1000) + vecs[i], 5, 0+18*i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0) + vecs[i], FVector2D(1000, 1000) + vecs[i], FVector2D(1000, -1000) + vecs[i], 5, 0 + 18 * i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0) + vecs[i], FVector2D(1000, -1000) + vecs[i], FVector2D(-1000, -1000) + vecs[i], 5, 0 + 18 * i, BulletType::BasicBullet, { 700, 1 });
		levelTwo[3].AddProjectionFromPoint(FVector2D(0, 0) + vecs[i], FVector2D(-1000, -1000) + vecs[i], FVector2D(-1000, 1000) + vecs[i], 5, 0 + 18 * i, BulletType::BasicBullet, { 700, 1 });
	}
	levelTwo[3].SpawnTriangleBlob(2500, 1410, 30 - 180, 600, 5, 158 - 18-110, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[3].SpawnTriangleBlob(2500, -1410, 60 + 90, 600, 5, 173 - 18-110, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[3].SpawnTriangleBlob(-2500, -1410, 30, 600, 5, 188 - 18-110, BulletType::HexagonBullet, { 700, 1 });
	levelTwo[3].SpawnTriangleBlob(-2500, 1410, -30, 600, 5, 202 - 18-110, BulletType::HexagonBullet, { 700, 1 });


	levelTwo[3].AddRythm({ 0.46 }, 40, 29.54);
	//levelTwo[3].AddCorners({ 18, 36, 54, 72 }, 2, 300);
	levelTwo[3].AddSpawnPoints(-2250, -1265, { 18, 36, 54, 72 }, 8, 300, BulletType::BasicBullet, { 700, 1 });
	levelTwo[3].AddSpawnPoints(-2250, 1265, { 18-90, 36-90, 54-90, 72-90 }, 8, 302, BulletType::BasicBullet, { 700, 1 });
	levelTwo[3].AddSpawnPoints(2250, 1265, { 18-180, 36-180, 54-180, 72-180 }, 8, 304, BulletType::BasicBullet, { 700, 1 });
	levelTwo[3].AddSpawnPoints(2250, -1265, { 18+90, 36+90, 54+90, 72+90 }, 8, 306, BulletType::BasicBullet, { 700, 1 });

	levelTwo[3].SortSpawnTimes();

	

	//levelTwo[0] = levelTwo[3];
	

	levelTwo[0].AddInstruction(4, 0, 0, 9999);
	allLevels.push_back(levelTwo);

	std::vector<BulletSpawner> levelThree = std::vector<BulletSpawner>();
	levelThree.push_back(BulletSpawner());

	levelThree[0].AddRythm({ 0.1 }, 300, 1);
	//levelThree[0].AddSpawnPoints(0, 0, { 0, 90, 180, 270 }, 1, 0);



	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 400, 0, BulletType::BasicBullet, { 700, 1.4 });

	levelThree[0].AddHorizontalWallOfSpawnPoints(2500, -2250, 1200, { -90 }, 100, 60, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(1750, 500, 1200, { -90 }, 100, 60, BulletType::BasicBullet, { 700, 1.4 });

	levelThree[0].AddHorizontalWallOfSpawnPoints(1750, -2250, 1200, { -90 }, 100, 90, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(2500, -250, 1200, { -90 }, 100, 90, BulletType::BasicBullet, { 700, 1.4 });

	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 120, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2100, 1200, { -90 }, 300, 123, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 126, BulletType::BasicBullet, { 700, 1.4 });

	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2100, 1200, { -90 }, 300, 120+26, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 123+26, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2100, 1200, { -90 }, 300, 126+26, BulletType::BasicBullet, { 700, 1.4 });

	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 120+52, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2100, 1200, { -90 }, 300, 123+52, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 126+52, BulletType::BasicBullet, { 700, 1.4 });

	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 120 + 78, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2100, 1200, { -90 }, 300, 123 + 78, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 126 + 78, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2100, 1200, { -90 }, 600, 120 + 78, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 600, 123 + 78, BulletType::BasicBullet, { 700, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2100, 1200, { -90 }, 600, 126 + 78, BulletType::BasicBullet, { 700, 1.4 });

	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 120 + 128, BulletType::BasicBullet, { 1050, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2400, 1200, { -90 }, 300, 122 + 128, BulletType::BasicBullet, { 1050, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 300, 124 + 128, BulletType::BasicBullet, { 1050, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2400, 1200, { -90 }, 600, 120 + 128, BulletType::BasicBullet, { 1050, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 600, 122 + 128, BulletType::BasicBullet, { 1050, 1.4 });
	levelThree[0].AddHorizontalWallOfSpawnPoints(4500, -2400, 1200, { -90 }, 600, 124 + 128, BulletType::BasicBullet, { 1050, 1.4 });


	levelThree[0].AddInstruction(4, 0, 0, 9999);
	allLevels.push_back(levelThree);


	std::vector<BulletSpawner> levelFour = std::vector<BulletSpawner>();
	levelFour.push_back(BulletSpawner());


	levelFour[0].AddRythm({ 1.09091*3-(0.2727*2), 0.5455+(0.2727/2), 0.5455+(0.2727/2) }, 6, -0.8);
	levelFour[0].AddSpawnPoints(0, 0, A1, 3, 0, BulletType::CurvedGrowingBullet, { 700, 1,2,1,1,1 });
	levelFour[0].AddSpawnPoints(0, 0, A1_2, 3, 1+6, BulletType::CurvedGrowingBullet, { 700, 1,2,1,1,1 });
	levelFour[0].AddSpawnPoints(0, 0, A1, 3, 2+12, BulletType::CurvedGrowingBullet, { 700, 1,2,1,1,1 });
	
	levelFour[0].ClearSlot(17);
	levelFour[0].ClearSlot(16);

	levelFour.push_back(BulletSpawner());
	levelFour[1].AddRythm({ 2*0.5455*0.85 }, 99, 0);
	levelFour[1].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500*0.85, 2, 0, BulletType::BasicBullet, { 400, 1.7 });
	levelFour[1].AddLayersOfHorizontalSpawnPoints(4500, -2250+(250*0.85), 1200, { -90 }, 500*0.85, 2, 1, BulletType::BasicBullet, { 400, 1.7 });

	levelFour[1].AddCorners({22.5, 45, 67.5}, 16, 10, BulletType::CurvedGrowingBullet, { 1050, 0.5, 3, 1, 1, 1 });




	levelFour[0].AddInstruction(4, 0, 0, 9999);
	allLevels.push_back(levelFour);

	//LEVEL FIVE: FLOWERING NIGHT
	std::vector<BulletSpawner> levelFive = std::vector<BulletSpawner>();
	levelFive.push_back(BulletSpawner());

	levelFive[0].AddRythm({ 0.784 }, 8, 0);

	std::vector<float> A1_a = std::vector<float>(8);
	std::vector<float> A1_b = std::vector<float>(8);
	std::vector<float> A1_c = std::vector<float>(4);
	std::vector<float> A1_d = std::vector<float>(4);
	for (int i = 0; i < A1.size(); i++) {
		if (i % 2 == 0) {
			A1_a[i / 2] = A1[i];
			if (i % 4 == 0) {
				A1_c[i / 4] = A1[i];
			}
		}
		else {
			A1_b[(i - 1) / 2] = A1[i];
			if (i % 4 == 1) {
				A1_d[(i-1) / 4] = A1[i];
			}
		}
	}
	//A1_b.pop_back();


	levelFive[0].AddTargetingSpawnPoints(69 , 420, A1_a, 2, 0, BulletType::KnifeBullet);
	levelFive[0].AddTargetingSpawnPoints(69, 420, A1_b, 2, 1, BulletType::KnifeBullet);
	
	
	levelFive[0].AddRythm({ 2 }, 10, 0);
	levelFive[0].AddSpawnPoints(-2250, -1265 - 1500, { 0 }, 1, 8, BulletType::CurvedBulletKnife, { 0.05, 1, 0, 360 / 0.03, 3000 * PI, 1, 0 });
	levelFive[0].AddSpawnPoints(-2250, 1265 + 1500, { 0 }, 1, 8, BulletType::CurvedBulletKnife, { 0.05, 1, 0, -360 / 0.03, 3000 * PI, 1, 0 });

	levelFive[0].AddSpawnPoints(2250, -1265 - 1500, { 180 }, 1, 8, BulletType::CurvedBulletKnife, { 0.05, 1, 0, -360 / 0.03, 3000 * PI, 1, 0 });
	levelFive[0].AddSpawnPoints(2250, 1265 + 1500, { 180 }, 1, 8, BulletType::CurvedBulletKnife, { 0.05, 1, 0, 360 / 0.03, 3000 * PI, 1, 0 });

	



	//levelFive[0].AddRythm({ 0.4 }, 1, 6);
	//levelFive[0].AddSpawnPoint(69, 420, {-120, -130, -140, -150}, 50, BulletType::KnifeBullet, { 900, 2 });
	levelFive[0].AddSpawnPointByTime(69, 420, { -120, -130, -140, -150 }, 6.4, BulletType::KnifeBulletRed, { 900, 1 });
	//levelFive[0].SortSpawnTimes();

	//levelFive.push_back(BulletSpawner());
	levelFive[0].AddRythm({ 0.392 }, 50, 6.4);

	levelFive[0].AddTargetingSpawnPoints(69, 420, A1_a, 2, 19, BulletType::KnifeBullet);
	levelFive[0].AddTargetingSpawnPoints(69, 420, A1_b, 2, 20, BulletType::KnifeBullet);


	//levelFive[0].AddRythm({ 0.4 }, 1, 14);
	//levelFive[0].AddSpawnPoint(69, 420, { -30, -40, -50, -60 }, 51, BulletType::KnifeBullet, { 900, 2 });
	levelFive[0].AddSpawnPointByTime(69, 420, { -30, -40, -50, -60 }, 8.0f+6.4f, BulletType::KnifeBulletRed, { 900, 1 });
	
	levelFive[0].AddRythm({ 0.784 * 2 }, 8, 9.0 - (0.784 * 2) + 6.4);
	levelFive[0].AddTargetingSpawnPoints(69, 420, { -30, 0, 30 }, 1, 51+19, BulletType::KnifeBulletRed, { 900, 1 });

	levelFive[0].AddRythm({ 2 }, 5, 15);
	levelFive[0].AddSpawnPoints(-2250, -1265 - 750, { 180 }, 1, 78, BulletType::CurvedKnifeRed, { 0.05, 1, 0, -720 / 0.03, 3000 * PI, 1, 0 });
	levelFive[0].AddSpawnPoints(-2250, 1265 + 750, { 180 }, 1, 78, BulletType::CurvedKnifeRed, { 0.05, 1, 0, 720 / 0.03, 3000 * PI, 1, 0 });

	levelFive[0].AddSpawnPoints(2250, -1265 - 750, { 0 }, 1, 78, BulletType::CurvedKnifeRed, { 0.05, 1, 0, 720 / 0.03, 3000 * PI, 1, 0 });
	levelFive[0].AddSpawnPoints(2250, 1265 + 750, { 0 }, 1, 78, BulletType::CurvedKnifeRed, { 0.05, 1, 0, -720 / 0.03, 3000 * PI, 1, 0 });

	levelFive[0].AddRythm({ 0.784 }, 8, 27.7f-(0.784*2));
	levelFive[0].AddTargetingSpawnPoints(69, 420, { -30, 0, 30 }, 1, 83, BulletType::KnifeBulletRed, { 900, 1 });

	levelFive[0].AddRythm({ 0.392 }, 50, 26.3);

	levelFive[0].AddTargetingSpawnPoints(69, 420, A1_c, 2, 91, BulletType::KnifeBullet, {1400, 1});
	levelFive[0].AddTargetingSpawnPoints(69, 420, A1_d, 2, 92, BulletType::KnifeBullet, { 1400, 1});

	levelFive[0].SortSpawnTimes();

	levelFive.push_back(BulletSpawner());
	
	levelFive[1].AddRythm({ 0.784 }, 8, 0);

	levelFive[1].AddTargetingSpawnPoints(69, 420, A1_a, 2, 0, BulletType::KnifeBullet);
	levelFive[1].AddTargetingSpawnPoints(69, 420, A1_b, 2, 1, BulletType::KnifeBullet);

	//levelFive[1].AddSpawnPointByTime(69, 420, { -120, -130, -140, -150 }, 6.4, BulletType::KnifeBulletRed, { 900, 1 });
	//levelFive[0].SortSpawnTimes();

	//levelFive.push_back(BulletSpawner());
	levelFive[1].AddRythm({ 0.392 }, 80, 6.4);

	levelFive[1].AddTargetingSpawnPoints(69, 420, A1_a, 2, 8, BulletType::KnifeBullet);
	levelFive[1].AddTargetingSpawnPoints(69, 420, A1_b, 2, 9, BulletType::KnifeBullet);


	//levelFive[0].AddRythm({ 0.4 }, 1, 14);
	//levelFive[0].AddSpawnPoint(69, 420, { -30, -40, -50, -60 }, 51, BulletType::KnifeBullet, { 900, 2 });
	//levelFive[1].AddSpawnPointByTime(69, 420, { -30, -40, -50, -60 }, 8.0f + 6.4f, BulletType::KnifeBulletRed, { 900, 1 });

	levelFive[1].AddRythm({ 0.784  }, 24, 9.0 - (0.784 * 2) + 6.4);
	levelFive[1].AddTargetingSpawnPoints(69, 420, { -30,  30 }, 2, 89, BulletType::KnifeBulletRed, { 900, 1 });

	//levelFive[1].AddRythm({ 0.784 }, 8, 27.7f - (0.784 * 2));
	levelFive[1].AddTargetingSpawnPoints(69, 420, { -30,  30 }, 2, 90 + 16, BulletType::KnifeBulletRed, { 900, 1 });

	/*levelFive[1].AddRythm({ 0.784 }, 16, 27.7f - (0.784 * 2) + (0.784*9));
	levelFive[1].AddTargetingSpawnPoints(69, 420, { -30, 0,  30 }, 1, 83 - 15 + 30 + 8, BulletType::KnifeBulletRed, { 1100, 1 });*/

	//levelFive[1].AddSpawnPointByTime(69, 420, D1, 8.0, BulletType::KnifeBulletRed, { 300, 1 });

	levelFive[1].SortSpawnTimes();

	levelFive.push_back(BulletSpawner());
	levelFive[2].AddRythm({ 0.392 }, 100, 0);
	//levelFive[2].AddTargetingDynamicSpawnPoints(69, 420, { -40, -20, 0, 20, 40, 20, 0, -20 }, 1, 0, BulletType::KnifeBulletRed, { 900, 1 });
	levelFive[2].AddTargetingSpawnPoints(69, 420, A1_a, 2, 0, BulletType::KnifeBullet);
	levelFive[2].AddTargetingSpawnPoints(69, 420, A1_b, 2, 1, BulletType::KnifeBullet);

	levelFive[2].AddRythm({ 0.784 * 2 }, 9, 6);
	levelFive[2].AddTargetingSpawnPoints(69, 420, { -40, -20, 20, 40 }, 1, 100, BulletType::KnifeBulletRed, { 900, 1 });

	levelFive[2].AddSpawnPointByTime(69, 420, D1, 8.0, BulletType::KnifeBulletRed, { 300, 1 });

	levelFive[2].AddRythm({ 0.392/2 }, 200, 0.392 * 50);
	levelFive[2].AddTargetingDynamicSpawnPoints(69, 420, { -40, -20, 0, 20, 40, 20, 0, -20 }, 1, 116, BulletType::KnifeBulletRed, { 900, 1 });

	levelFive[2].SortSpawnTimes();



	levelFive[0].AddInstruction(4, 0, 0, 9999);
	allLevels.push_back(levelFive);
	//LULLABY OF A DESERTED HELL
	std::vector<BulletSpawner> levelSix = std::vector<BulletSpawner>();
	levelSix.push_back(BulletSpawner());
	levelSix[0].AddRythm({ 0.35, 0.15, 0.2, 0.4 }, 45, 0);
	levelSix[0].AddDynamicSpawnPoints(0, 0, A1, 1, 0);

	levelSix[0].AddRythm({ 0.385 * 2 }, 65, 0);//16,8
	levelSix[0].AddTargetingSpawnPoints(0, 0, {-70, 0, 70}, 8, 191, BulletType::TrackingBullet, { 700, 1, 2, 90 });
	levelSix[0].AddCorners({ 45 }, 16, 191 + 4 * 7, BulletType::TrackingBullet, { 700, 1, 2, 90 });

	levelSix[0].AddSpawnPoints(-1500, 1265, { -90 }, 6, 183, BulletType::GhostBullet, {300, 1});
	levelSix[0].AddSpawnPoints(-2000, 1265, { -90 }, 6, 180, BulletType::GhostBullet, { 300, 1 });

	levelSix[0].AddSpawnPoints(-1750, -1265, { 90 }, 6, 180, BulletType::GhostBullet, { 300, 1 });
	levelSix[0].AddSpawnPoints(-1250, -1265, { 90 }, 6, 183, BulletType::GhostBullet, { 300, 1 });

	levelSix[0].AddSpawnPoints(1500, 1265, { -90 }, 6, 183, BulletType::GhostBullet, { 300, 1 });
	levelSix[0].AddSpawnPoints(2000, 1265, { -90 }, 6, 180, BulletType::GhostBullet, { 300, 1 });

	levelSix[0].AddSpawnPoints(1750, -1265, { 90 }, 6, 180, BulletType::GhostBullet, { 300, 1 });
	levelSix[0].AddSpawnPoints(1250, -1265, { 90 }, 6, 183, BulletType::GhostBullet, { 300, 1 });

	levelSix[0].SortSpawnTimes();

	levelSix.push_back(BulletSpawner());
	levelSix[1].AddRythm({ 0.385 * 2 }, 200, 0);

	levelSix[1].AddSpawnPoints(-1500, 1265, { -90 }, 6, 4, BulletType::GhostBullet, { 300, 1 });
	levelSix[1].AddSpawnPoints(-2000, 1265, { -90 }, 6, 1, BulletType::GhostBullet, { 300, 1 });

	levelSix[1].AddSpawnPoints(-1750, -1265, { 90 }, 6, 1, BulletType::GhostBullet, { 300, 1 });
	levelSix[1].AddSpawnPoints(-1250, -1265, { 90 }, 6, 4, BulletType::GhostBullet, { 300, 1 });

	levelSix[1].AddSpawnPoints(1500, 1265, { -90 }, 6, 4, BulletType::GhostBullet, { 300, 1 });
	levelSix[1].AddSpawnPoints(2000, 1265, { -90 }, 6, 1, BulletType::GhostBullet, { 300, 1 });

	levelSix[1].AddSpawnPoints(1750, -1265, { 90 }, 6, 1, BulletType::GhostBullet, { 300, 1 });
	levelSix[1].AddSpawnPoints(1250, -1265, { 90 }, 6, 4, BulletType::GhostBullet, { 300, 1 });

	levelSix[1].AddRythm({ 0.385 }, 150, 2);
	levelSix[1].AddSpawnPoints(69, 420, A1, 6, 200, BulletType::BasicBullet, {400, 1});
	levelSix[1].AddSpawnPoints(69, 420, A1_3, 6, 202, BulletType::BasicBullet, { 400, 1 });
	levelSix[1].AddSpawnPoints(69, 420, A1_4, 6, 204, BulletType::BasicBullet, { 400, 1 });

	levelSix[1].ClearSlots(12, 240);
	levelSix[1].ClearSlots(12, 242);
	levelSix[1].ClearSlots(12, 244);

	//levelSix[1].AddSpawnPoints(69, 420, A1, 2, 140, BulletType::BasicBullet, { 400, 1 });
	//levelSix[1].AddSpawnPoints(69, 420, A1_2, 2, 141, BulletType::BasicBullet, { 400, 1 });


	levelSix[1].AddTargetingSpawnPoints(69, 420, { 0 }, 8, 240, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });

	levelSix[1].AddTargetingSpawnPoints(69, 420, { -70, 70 }, 8, 292, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });

	levelSix[1].AddRythm({ 0.35, 0.15, 0.2, 0.4 }, 45, 59.75);

	levelSix[1].AddDynamicSpawnPoints(69, 420, A1, 1, 350);
	levelSix[1].AddDynamicSpawnPoints(69, 420, A1plus180, 1, 350);

	levelSix[1].AddRythm({ 0.385 * 2 }, 65, 61);//16,8

	levelSix[1].AddSpawnPoints(33002, -1265, { 90 }, 4, 530, BulletType::GhostBullet, { 300, 1 });

	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 530, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 534, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 538, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 542, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 546, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 550, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 554, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 558, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 562, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 566, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 570, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 574, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { 0 }, 578, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });


	//levelSix[1].AddCorner({ 45 }, 558, BulletType::TrackingBullet, { 700, 1, 2, 90 });
	//levelSix[1].AddCorner({ 45 }, 566, BulletType::TrackingBullet, { 700, 1, 2, 90 });

	levelSix[1].AddTargetingSpawnPoint(0, 0, {-70, 70 }, 558, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });
	levelSix[1].AddTargetingSpawnPoint(0, 0, { -70, 70 }, 566, BulletType::TrackingBullet, { 700, 1, 1.5, 90 });





	levelSix[1].SortSpawnTimes();


	
	levelSix[0].AddInstruction(4, 0, 0, 9999);//7
	allLevels.push_back(levelSix);

	//BELOVED TOMBOYISH GIRL
	std::vector<BulletSpawner> levelSeven = std::vector<BulletSpawner>();
	levelSeven.push_back(BulletSpawner());

	levelSeven[0].AddRythm({ 0.397*2 }, 100, 0.5);
	//levelSeven[0].AddTargetingSpawnPoints(0, 0, { 0, 180}, 1, 0, BulletType::FractureBullet, { 200, 2, 2, 500 });
	levelSeven[0].AddSpawnPoints(69, 420, A1, 4, 0, BulletType::BasicBulletBlue, { 700, 1});
	levelSeven[0].AddTargetingSpawnPoints(69, 420, {-50, 0, 50}, 2, 0, BulletType::BasicBulletBlue, { 700, 1 });
	levelSeven[0].AddTargetingSpawnPoints(69, 420, { -30, 30 }, 2, 1, BulletType::BasicBulletBlue, { 700, 1 });
	levelSeven[0].AddTargetingSpawnPoints(69, 420, { 90, -90}, 4, 38, BulletType::FractureBullet, { 200, 2, 2, 500 });
	levelSeven[0].AddTargetingSpawnPoints(69, 420, { 0 }, 4, 38+(4*8), BulletType::FractureBullet, { 200, 2, 2, 500 });

	levelSeven[0].AddRythm({ 0.397 * 2 }, 100, 0.5 + (200 * 0.397) + 8);
	levelSeven[0].AddSpawnPoints(69, 420, A1, 4, 0+100, BulletType::BasicBulletBlue, { 700, 1 });
	levelSeven[0].AddTargetingSpawnPoints(69, 420, { -50, 0, 50 }, 2, 0+100, BulletType::BasicBulletBlue, { 700, 1 });
	levelSeven[0].AddTargetingSpawnPoints(69, 420, { -30, 30 }, 2, 1+100, BulletType::BasicBulletBlue, { 700, 1 });
	levelSeven[0].AddSpawnPoints(69, 420, A1_2, 12, 10+100, BulletType::CirnoBullet, { 350, 1 });
	levelSeven[0].AddTargetingSpawnPoints(69, 420, { 90, -90 }, 4, 34+100, BulletType::FractureBullet, { 200, 2, 2, 500 });
	levelSeven[0].AddTargetingSpawnPoints(69, 420, { 0 }, 4, 34 + (4 * 8)+100, BulletType::FractureBullet, { 200, 2, 2, 500 });
	levelSeven[0].AddCorners({ 45 }, 4, 34 + (4 * 16) + 100, BulletType::FractureBullet, { 200, 2, 2, 500 });



	levelSeven[0].AddRythm({ 0.84 }, 5, 85);
	levelSeven[0].AddSpawnPoints(0, 0, { 0, 60, 120, 180, 240, 300 }, 1, 200, BulletType::BasicBulletBlue, { 500, 1 });
	std::vector<float> A60 = { 0, 60, 120, 180, 240, 300 };
	float t1 = 420;
	for (int i = 0; i < 6; i++) {
		levelSeven[0].AddSpawnPoint(t1*cosf((A60[i]+60)*(PI/180)), t1 * sinf((A60[i] + 60) * (PI / 180)), { A60[i] }, 201, BulletType::BasicBulletBlue, { 500, 1 });
		levelSeven[0].AddSpawnPoint(t1 * cosf((A60[i] - 60) * (PI / 180)), t1 * sinf((A60[i] - 60) * (PI / 180)), { A60[i] }, 201, BulletType::BasicBulletBlue, { 500, 1 });
	}
	


	levelSeven[0].SortSpawnTimes();





	levelSeven[0].AddInstruction(4, 0, 0, 9999);//7
	allLevels.push_back(levelSeven);

	std::vector<BulletSpawner> levelEight = std::vector<BulletSpawner>();
	levelEight.push_back(BulletSpawner());

	levelEight[0].AddRythm({ 0.5 }, 300, 0);

	levelEight.push_back(BulletSpawner());

	levelEight[1].AddRythm({ 0.22 }, 300, 0);
	levelEight[1].AddHorizontalWallOfSpawnPoints(4500, -2250, 1265, { -90 }, 600, 10, BulletType::BasicBullet, {700, 1.5});

	levelEight[1].AddHorizontalWallOfSpawnPoints(4500, -2250, 1265, { -90 }, 600, 20, BulletType::BasicBullet, { 700, 1.5 });
	levelEight[1].AddHorizontalWallOfSpawnPoints(4500, -2250+300, 1265, { -90 }, 600, 24, BulletType::BasicBullet, { 700, 1.5 });

	levelEight[1].AddHorizontalWallOfSpawnPoints(4500, -2250, 1265, { -90 }, 600, 34, BulletType::BasicBullet, { 700, 1.5 });
	levelEight[1].AddHorizontalWallOfSpawnPoints(4500, -2250 + 200, 1265, { -90 }, 600, 38, BulletType::BasicBullet, { 700, 1.5 });
	levelEight[1].AddHorizontalWallOfSpawnPoints(4500, -2250 + 400, 1265, { -90 }, 600, 42, BulletType::BasicBullet, { 700, 1.5 });



	//levelEight[1].AddSpawnPoint(0, 0, { 0 }, 0);


	levelEight.push_back(BulletSpawner());

	levelEight[2].AddRythm({ 0.46154 }, 100, 0.1);

	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250+400, 1265, { -90 }, 600, 12, 0, BulletType::BasicBullet, { 700, 1.5 });
	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250+200, 1265+300, { -90 }, 600, 12, 0, BulletType::BasicBullet, { 700, 1.5 });
	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1265+600, { -90 }, 600, 12, 0, BulletType::BasicBullet, { 700, 1.5 });

	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250 + 0, 1265, { -90 }, 600, 12, 6, BulletType::BasicBullet, { 700, 1.5 });
	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250 + 200, 1265 + 300, { -90 }, 600, 12, 6, BulletType::BasicBullet, { 700, 1.5 });
	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250 + 400, 1265 + 600, { -90 }, 600, 12, 6, BulletType::BasicBullet, { 700, 1.5 });

	levelEight[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1200, { -90 }, 200, 24, BulletType::CurvedBulletReg, { 400, 1.5, 1, 1, 1, 1.6 });
	levelEight[2].AddHorizontalWallOfSpawnPoints(4500, -2250, 1500, { -90 }, 200, 24, BulletType::CurvedBulletReg, { 400, 1.5, 1, 1, 1, -1.6 });

	levelEight[2].AddSpawnPoint(-2250, 1265, { -30, -45, -60 }, 12);
	levelEight[2].AddSpawnPoint(2250, 1265, { -30-90, -45-90, -60-90 }, 18);


	levelEight[2].ClearSlots(1, 25);

	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200, { -90 }, 500, 6, 30, BulletType::BasicBullet, { 700, 1 });

	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200+60, { -90 }, 500, 6, 30, BulletType::BasicBullet, { 700, 1 });
	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2300, 1200+60, { -90 }, 500, 6, 30, BulletType::BasicBullet, { 700, 1 });
	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2200, 1200+60, { -90 }, 500, 6, 30, BulletType::BasicBullet, { 700, 1 });

	levelEight[2].AddLayersOfHorizontalSpawnPoints(4500, -2250, 1200+120, { -90 }, 500, 6, 30, BulletType::BasicBullet, { 700, 1 });


	levelEight[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200, { -90 }, 500, 6, 30+3, BulletType::BasicBullet, { 700, 1 });

	levelEight[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200+60, { -90 }, 500, 6, 30+3, BulletType::BasicBullet, { 700, 1 });
	levelEight[2].AddLayersOfHorizontalSpawnPoints(4250, -2050, 1200+60, { -90 }, 500, 6, 30+3, BulletType::BasicBullet, { 700, 1 });
	levelEight[2].AddLayersOfHorizontalSpawnPoints(4250, -1950, 1200+60, { -90 }, 500, 6, 30+3, BulletType::BasicBullet, { 700, 1 });

	levelEight[2].AddLayersOfHorizontalSpawnPoints(4250, -2000, 1200+120, { -90 }, 500, 6, 30+3, BulletType::BasicBullet, { 700, 1 });


	levelEight[0].AddInstruction(4, 0, 0, 9999);//7
	allLevels.push_back(levelEight);


	//REACH FOR THE MOON
	std::vector<BulletSpawner> levelNine = std::vector<BulletSpawner>();
	levelNine.push_back(BulletSpawner());

	levelNine[0].AddRythm({ 0.784 }, 8, 0);


	levelNine[0].AddTargetingSpawnPoints(69, 420, A1_a, 2, 0, BulletType::KnifeBullet);
	levelNine[0].AddTargetingSpawnPoints(69, 420, A1_b, 2, 1, BulletType::KnifeBullet);


	levelNine[0].AddRythm({ 2 }, 10, 0);
	levelNine[0].AddSpawnPoints(-2250, -1265 - 1500, { 0 }, 1, 8, BulletType::CurvedBulletKnife, { 0.05, 1, 0, 360 / 0.03, 3000 * PI, 1, 0 });
	levelNine[0].AddSpawnPoints(-2250, 1265 + 1500, { 0 }, 1, 8, BulletType::CurvedBulletKnife, { 0.05, 1, 0, -360 / 0.03, 3000 * PI, 1, 0 });

	levelNine[0].AddSpawnPoints(2250, -1265 - 1500, { 180 }, 1, 8, BulletType::CurvedBulletKnife, { 0.05, 1, 0, -360 / 0.03, 3000 * PI, 1, 0 });
	levelNine[0].AddSpawnPoints(2250, 1265 + 1500, { 180 }, 1, 8, BulletType::CurvedBulletKnife, { 0.05, 1, 0, 360 / 0.03, 3000 * PI, 1, 0 });



	levelNine.push_back(BulletSpawner());
	levelNine[1].AddRythm({ 0.385 * 2 }, 200, 0);

	levelNine[1].AddSpawnPoints(-1500, 1265, { -90 }, 6, 4, BulletType::GhostBullet, { 300, 1 });
	levelNine[1].AddSpawnPoints(-2000, 1265, { -90 }, 6, 1, BulletType::GhostBullet, { 300, 1 });

	levelNine[1].AddSpawnPoints(-1750, -1265, { 90 }, 6, 1, BulletType::GhostBullet, { 300, 1 });
	levelNine[1].AddSpawnPoints(-1250, -1265, { 90 }, 6, 4, BulletType::GhostBullet, { 300, 1 });

	levelNine[1].AddSpawnPoints(1500, 1265, { -90 }, 6, 4, BulletType::GhostBullet, { 300, 1 });
	levelNine[1].AddSpawnPoints(2000, 1265, { -90 }, 6, 1, BulletType::GhostBullet, { 300, 1 });

	levelNine[1].AddSpawnPoints(1750, -1265, { 90 }, 6, 1, BulletType::GhostBullet, { 300, 1 });
	levelNine[1].AddSpawnPoints(1250, -1265, { 90 }, 6, 4, BulletType::GhostBullet, { 300, 1 });

	levelNine[1].AddRythm({ 0.385 }, 150, 2);
	levelNine[1].AddSpawnPoints(69, 420, A1, 6, 200, BulletType::BasicBullet, { 400, 1 });
	levelNine[1].AddSpawnPoints(69, 420, A1_3, 6, 202, BulletType::BasicBullet, { 400, 1 });
	levelNine[1].AddSpawnPoints(69, 420, A1_4, 6, 204, BulletType::BasicBullet, { 400, 1 });

	levelNine[1].ClearSlots(12, 240);
	levelNine[1].ClearSlots(12, 242);
	levelNine[1].ClearSlots(12, 244);

	levelNine.push_back(BulletSpawner());

	levelNine[2].AddRythm({ 1.33,0.3,0.3 }, 11, 0);
	levelNine[2].AddTargetingSpawnPoints(0, 0, { 0, 30, -30 }, 2, 0);
	levelNine[2].AddTargetingSpawnPoints(0, 0, { 0, 45, -45 }, 2, 1);
	levelNine[2].AddCorners({ 60, 30 }, 1, 21, BulletType::BasicBullet);

	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 10, 0, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 10, 0, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 10, 0, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 10, 0, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 10, 0, BulletType::BasicBullet, { 300, 1 });

	levelNine[2].AddSpawnPointByEquation(12, 10, &(EquationLibrary::xcircle), &(EquationLibrary::ycircle), &(EquationLibrary::acircle), BulletType::ExplodingBullet, { 450, 2, 0 });
	levelNine[2].AddRythm({ 2 }, 6, 4);
	levelNine[2].AddCorners({ 0 }, 1, 33, BulletType::CurvedBullet, { 700, 2, 0, 1, 1, 1 });
	levelNine[2].AddCorners({ 70 }, 1, 33, BulletType::CurvedBullet, { 700, 2, 0, -1, 1, 1 });
	levelNine[2].AddCorners({ 18, 36, 54, 72 }, 2, 33);

	levelNine[2].SortSpawnTimes();

	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 10, 29, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 10, 29, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 10, 29, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 10, 29, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 10, 29, BulletType::BasicBullet, { 300, 1 });

	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(0, 3250), FVector2D(1909, -2630), 5, 38, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(1909, -2630), FVector2D(-3091, 1000), 5, 38, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-3091, 1000), FVector2D(3091, 1000), 5, 38, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(3091, 1000), FVector2D(-1909, -2630), 5, 38, BulletType::BasicBullet, { 300, 1 });
	levelNine[2].AddProjectionFromPoint(FVector2D(0, 0), FVector2D(-1909, -2630), FVector2D(0, 3250), 5, 38, BulletType::BasicBullet, { 300, 1 });

	levelNine[0].AddInstruction(4, 0, 0, 9999);//7
	allLevels.push_back(levelNine);


}

LevelLibrary::LevelLibrary()
{

}

LevelLibrary::~LevelLibrary()
{
}
