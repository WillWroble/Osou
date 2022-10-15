// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperFlipbookComponent.h"
#include "KillMe.h"
#include <vector>
#include "InGameCharacter.generated.h"

enum InstructionMode {move, resize, teleport, wait, instaRotate, flipHoriz, playAnim, startDash, endDash, setRotation};
enum BehaviorMode {avoidHoriz, followHoriz, idle, alert, glide, float_};

struct CharacterInstruction {
	InstructionMode ins;
	float duration;
	float x;
	float y;
};
struct CharacterBehavior {
	BehaviorMode beh;
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
	std::vector<CharacterBehavior> behaviors;

	bool isStopped;
	int ins_index;
	int beh_index;
	float timer;
	float timer2;
	FVector delta;
	FVector scale;
	FVector scaleDelta;
	CharacterInstruction currentInstruction;
	UPaperFlipbookComponent* flipBook;
	AKillMe* player;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddInstruction(InstructionMode ins, float duration, float x, float y);
	void AddInstructions(InstructionMode ins, float duration, float x, float y, int count);
	void AddBehavior(BehaviorMode beh, float duration, float x, float y);
	void PointTowardsPlayer();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int levelIndex_BP;
	UFUNCTION(BlueprintImplementableEvent)
		void InitAnims();
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
	UFUNCTION(BlueprintImplementableEvent)
		void StartDashAnim();
	UFUNCTION(BlueprintImplementableEvent)
		void EndDashAnim();
	UFUNCTION(BlueprintImplementableEvent)
		void SetDefaultAnimToDash();
	UFUNCTION(BlueprintImplementableEvent)
		void SetDefaultAnimToIdle();
	UFUNCTION(BlueprintImplementableEvent)
		void SetDefaultAnimToFloat();


};
