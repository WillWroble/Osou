// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include "InGameCharacter.generated.h"

enum InstructionMode {move, resize, teleport, wait, instaRotate, flipHoriz, playAnim};

struct CharacterInstruction {
	InstructionMode ins;
	float duration;
	float x;
	float y;
};
UCLASS()
class OSOU_API AInGameCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	std::vector<CharacterInstruction> instructions;
	int ins_index;
	float timer;
	FVector delta;
	FVector scale;
	FVector scaleDelta;
	CharacterInstruction currentInstruction;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddInstruction(InstructionMode ins, float duration, float x, float y);

	UFUNCTION(BlueprintImplementableEvent)
		void PlayAnimOne();
	UFUNCTION(BlueprintImplementableEvent)
		void PlayAnimTwo();
	UFUNCTION(BlueprintImplementableEvent)
		void PlayAnimThree();
	UFUNCTION(BlueprintImplementableEvent)
		void PlayAnimFour();
	UFUNCTION(BlueprintImplementableEvent)
		void PlayAnimFive();

};
