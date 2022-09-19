// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameCharacter.h"

// Sets default values
AInGameCharacter::AInGameCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	ins_index = 0;
	timer = 0;
	scale = FVector(3);
	delta = FVector(0);
	CharacterInstruction waitZero;
	waitZero.ins = InstructionMode::wait;
	waitZero.duration = 0;
	instructions.insert(instructions.begin(), waitZero);
}

// Called every frame
void AInGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timer += DeltaTime;
	if (timer > instructions[ins_index].duration) {
		if (ins_index+1 >= instructions.size()) {
			return;
		}
		ins_index++;
		timer = 0;
		if (instructions[ins_index].ins == InstructionMode::move) {
			delta = (FVector(instructions[ins_index].x, 0, instructions[ins_index].y) - GetActorLocation())/ instructions[ins_index].duration;
		}
		else if (instructions[ins_index].ins == InstructionMode::resize) {
			scale = GetActorScale3D();//FVector(instructions[ins_index].x);
			scaleDelta = FVector((scale.X - instructions[ins_index].x )/ instructions[ins_index].duration);
		}
		else if (instructions[ins_index].ins == InstructionMode::resize) {
			SetActorLocation(FVector(instructions[ins_index].x, 0, instructions[ins_index].y));
		}
		else if (instructions[ins_index].ins == InstructionMode::instaRotate) {
			SetActorRotation(FRotator(instructions[ins_index].x, 0, 0));
		}
		else if (instructions[ins_index].ins == InstructionMode::flipHoriz) {
			SetActorRotation(FRotator(0, GetActorRotation().Yaw + 180, 0));
		}
		else if (instructions[ins_index].ins == InstructionMode::playAnim) {
			if (instructions[ins_index].x == 1) {
				//play one
				PlayAnimOne();
			}
			else if (instructions[ins_index].x == 2) {
				PlayAnimTwo();
			}
			else if (instructions[ins_index].x == 3) {
				PlayAnimThree();
			}
			else if (instructions[ins_index].x == 4) {
				PlayAnimFour();
			}
			else {
				PlayAnimFive();
			}
		}
	}
	if (instructions[ins_index].ins == InstructionMode::move) {
		AddActorLocalOffset(delta*DeltaTime);
	}
	else if (instructions[ins_index].ins == InstructionMode::resize) {
		scale -= scaleDelta*DeltaTime;
		SetActorScale3D(scale);
	}

}

void AInGameCharacter::AddInstruction(InstructionMode ins, float duration, float x, float y)
{
	CharacterInstruction temp;
	temp.duration = duration;
	temp.x = x;
	temp.y = y;
	temp.ins = ins;
	instructions.push_back(temp);
}

