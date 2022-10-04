// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameCharacter.h"
#include "BulletController.h"

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
	isStopped = true;
	ins_index = 0;
	beh_index = 0;
	timer = 0;
	timer2 = 0;
	scale = FVector(3);
	delta = FVector(0);
	levelIndex_BP = ABulletController::levelIndex;
	InitAnims();
	CharacterInstruction waitZero;
	waitZero.ins = InstructionMode::wait;
	waitZero.duration = 0;
	CharacterBehavior defaultIdle;
	defaultIdle.beh = BehaviorMode::idle;
	defaultIdle.duration = 0;
	flipBook = (UPaperFlipbookComponent*)(this->GetComponentsByTag(UPaperFlipbookComponent::StaticClass(), "flipbook"))[0];
	instructions.insert(instructions.begin(), waitZero);
	behaviors.insert(behaviors.begin(), defaultIdle);
	//player = nullptr;
}

// Called every frame
void AInGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timer += DeltaTime*ABulletController::audioCoeff;
	timer2 += DeltaTime * ABulletController::audioCoeff;

	if (timer2 > behaviors[beh_index].duration) {
		if (beh_index + 1 < behaviors.size()) {

			beh_index++;
			timer2 = 0;
			if (behaviors[beh_index].beh == BehaviorMode::followHoriz) {
				SetDefaultAnimToIdle();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "FOLLOW");
			}
			else if (behaviors[beh_index].beh == BehaviorMode::avoidHoriz) {
				SetDefaultAnimToIdle();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "AVOID");
			}
			else if (behaviors[beh_index].beh == BehaviorMode::idle || behaviors[beh_index].beh == BehaviorMode::alert) {
				SetDefaultAnimToIdle();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "IDLE");
			}
			else if (behaviors[beh_index].beh == BehaviorMode::glide) {
				SetDefaultAnimToDash();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "GLIDE");
				if (behaviors[beh_index].x < GetActorLocation().X) {
					flipBook->SetRelativeRotation(FRotator(0, 180, 0));
				}
				else {
					flipBook->SetRelativeRotation(FRotator(0, 0, 0));
				}
				delta = (FVector(behaviors[beh_index].x, 10, behaviors[beh_index].y) - GetActorLocation()) / behaviors[beh_index].duration;
			}
			else if (behaviors[beh_index].beh == BehaviorMode::float_) {
				SetDefaultAnimToIdle();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "FLOAT");
				/*if (behaviors[beh_index].x < GetActorLocation().X) {
					flipBook->SetRelativeRotation(FRotator(0, 0, 0));
				}
				else {
					flipBook->SetRelativeRotation(FRotator(0, 180, 0));
				}*/
				delta = (FVector(behaviors[beh_index].x, 10, behaviors[beh_index].y) - GetActorLocation()) / behaviors[beh_index].duration;
			}
		}
	}
	if (behaviors[beh_index].beh == BehaviorMode::followHoriz) {

		if (GetActorLocation().X > fmaxf(1 * player->GetActorLocation().X, -1200)) {
			//SetActorRelativeRotation(FRotator(0, 180, 0));
			float diff = GetActorLocation().X - fmaxf(1 * player->GetActorLocation().X, -1200);
			float fdelta = 500 * DeltaTime;
			if (diff > 400 || !isStopped) {
				isStopped = false;
				flipBook->SetRelativeRotation(FRotator(0, 180, 0));
				if (diff < fdelta) {
					AddActorLocalOffset(diff * FVector(-1, 0, 0));
					//flipBook->SetRelativeRotation(FRotator(0, 0, 0));
					isStopped = true;
				}
				else {
					AddActorLocalOffset(fdelta * FVector(-1, 0, 0));
				}
				
			}
		}
		else if (GetActorLocation().X < fminf(1 * player->GetActorLocation().X, 1200)) {
			//SetActorRelativeRotation(FRotator(0, 0, 0));
			float diff = GetActorLocation().X - fminf(1 * player->GetActorLocation().X, 1200);
			float fdelta = 500 * DeltaTime;
			if (-diff > 400 || !isStopped) {
				isStopped = false;
				flipBook->SetRelativeRotation(FRotator(0, 0, 0));
				if (-diff < fdelta) {
					AddActorLocalOffset(-diff * FVector(1, 0, 0));
					//flipBook->SetRelativeRotation(FRotator(0, 180, 0));
					isStopped = true;
				}
				else {
					AddActorLocalOffset(fdelta * FVector(1, 0, 0));
				}

			}
		}
	}
	else if (behaviors[beh_index].beh == BehaviorMode::avoidHoriz) {
		PointTowardsPlayer();
		if (GetActorLocation().X > fmaxf(-1 * player->GetActorLocation().X, -1200)) {
			float diff = GetActorLocation().X - fmaxf(-1 * player->GetActorLocation().X, -1200);
			float fdelta = 500 * DeltaTime;
			if (diff > 400 || !isStopped) {
				isStopped = false;
				//flipBook->SetRelativeRotation(FRotator(0, 180, 0));
				if (diff < fdelta) {
					AddActorLocalOffset(diff * FVector(-1, 0, 0));
					PointTowardsPlayer();
					isStopped = true;
				}
				else {
					AddActorLocalOffset(fdelta * FVector(-1, 0, 0));
				}

			}
		}
		else if(GetActorLocation().X < fminf(-1 * player->GetActorLocation().X, 1200)){
			float diff = GetActorLocation().X - fminf(-1 * player->GetActorLocation().X, 1200);
			float fdelta = 500 * DeltaTime;
			if (-diff > 400 || !isStopped) {
				isStopped = false;
				//flipBook->SetRelativeRotation(FRotator(0, 0, 0));
				if (-diff < fdelta) {
					AddActorLocalOffset(-diff * FVector(1, 0, 0));
					PointTowardsPlayer();
					isStopped = true;
				}
				else {
					AddActorLocalOffset(fdelta * FVector(1, 0, 0));
				}
			}
		}
	}
	else if (behaviors[beh_index].beh == BehaviorMode::glide) {
		AddActorLocalOffset(delta* DeltaTime);
		/*if (behaviors[beh_index].x < GetActorLocation().X) {
			flipBook->SetRelativeRotation(FRotator(0, 180, 0));
		}
		else {
			flipBook->SetRelativeRotation(FRotator(0, 0, 0));
		}*/
	}
	else if (behaviors[beh_index].beh == BehaviorMode::float_) {
		AddActorLocalOffset(delta * DeltaTime);
		/*if (behaviors[beh_index].x < GetActorLocation().X) {
			flipBook->SetRelativeRotation(FRotator(0, 180, 0));
		}
		else {
			flipBook->SetRelativeRotation(FRotator(0, 0, 0));
		}*/
	}
	else if (behaviors[beh_index].beh == BehaviorMode::alert) {
		PointTowardsPlayer();
	}
	if (timer > instructions[ins_index].duration) {
		if (ins_index+1 >= instructions.size()) {
			return;
		}
		ins_index++;
		timer = 0;
		if (instructions[ins_index].ins == InstructionMode::move) {
			delta = (FVector(instructions[ins_index].x, 10, instructions[ins_index].y) - GetActorLocation())/ instructions[ins_index].duration;
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
			//SetActorRotation(FRotator(0, GetActorRotation().Yaw + 180, 0));
			flipBook->AddLocalRotation(FRotator(0, 180, 0));
		}
		else if (instructions[ins_index].ins == InstructionMode::setRotation) {
			//SetActorRotation(FRotator(0, GetActorRotation().Yaw + 180, 0));
			flipBook->SetRelativeRotation(FRotator(0, instructions[ins_index].x, 0));
		}
		else if (instructions[ins_index].ins == InstructionMode::playAnim) {
			PointTowardsPlayer();
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
		else if (instructions[ins_index].ins == InstructionMode::startDash) {
			StartDashAnim();
		}
		else if (instructions[ins_index].ins == InstructionMode::endDash) {
			EndDashAnim();
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

void AInGameCharacter::AddInstructions(InstructionMode ins, float duration, float x, float y, int count)
{
	for (int i = 0; i < count; i++) {
		AddInstruction(ins, duration, x, y);
	}
}

void AInGameCharacter::AddBehavior(BehaviorMode beh, float duration, float x, float y)
{
	CharacterBehavior temp;
	temp.duration = duration;
	temp.x = x;
	temp.y = y;
	temp.beh = beh;
	behaviors.push_back(temp);
}

void AInGameCharacter::PointTowardsPlayer()
{
	if (GetActorLocation().X < player->GetActorLocation().X) {
		flipBook->SetRelativeRotation(FRotator(0, 0, 0));
	}
	else {
		flipBook->SetRelativeRotation(FRotator(0, 180, 0));
	}
}

