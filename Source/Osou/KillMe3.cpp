// Fill out your copyright notice in the Description page of Project Settings.


#include "KillMe3.h"
#include "BulletController.h"

ABulletController* bulletController3;
// Sets default values
AKillMe3::AKillMe3()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	baseScale = FVector(0.3); //0.1675
	PrimaryActorTick.bCanEverTick = true;
	isLevelFinsihedd = false;
	wasClicked = false;
	clicked = false;
	isMoving = false;
	travelTime = 0;
	timeout = 0;
	direction = FVector(0, 0, 0);
	screenW = 0; screenH = 0;
	index = 0;
	transitionIndex = 0;
	baseSpeed = 1200 * 0.2; //700
	baseLocation = FVector(0, 2, 0);
	clockTime = 0;
	beats = std::vector<std::vector<float>>(99);
	beatTime = 0;
	hasStarted = false;
	Health = 1;
	PopupType = 0;
	beatIndex = 0;
	rhythmBuffer = 0;
	tutHScore = 0;
	isTimeFrozen = false;

}

// Called when the game starts or when spawned
void AKillMe3::BeginPlay()
{
	Super::BeginPlay();
	TActorIterator<ABulletController> It(GetWorld());
	bulletController3 = *It;
	flipBook = (UPaperFlipbookComponent*)(this->GetComponentsByTag(UPaperFlipbookComponent::StaticClass(), "flipbook"))[0];
	hexPlane = (UStaticMeshComponent*)(this->GetComponentsByTag(UStaticMeshComponent::StaticClass(), "plane"))[0];
	/*
	//pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pController = GetWorld()->GetFirstPlayerController();
	sprite = (UPaperSpriteComponent*)this->RootComponent;
	circleSprite = (UPaperSpriteComponent*)(this->GetComponentsByTag(UPaperSpriteComponent::StaticClass(), "tag1"))[0];
	sound = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag2"))[0];
	drumBeat = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag3"))[0];
	APawn* evilPawn = pController->GetPawn();
	if (evilPawn != nullptr) {
		evilPawn->Destroy();
	}
	//trail = (UParticleSystemComponent*)(this->GetComponentsByTag(UParticleSystemComponent::StaticClass(), "tag2"))[0];
	trail = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), templateEmitter, FVector(0), FRotator(0));
	trail->SetBeamSourcePoint(0, this->GetActorLocation(), 0);
	trail->SetBeamTargetPoint(0, this->GetActorLocation(), 0);
	TActorIterator<ABulletController> It(GetWorld());
	bulletController3 = *It;
	//emitter = trail->EmitterInstances[0];
	leftClick = FKey("LeftMouseButton");
	space = FKey("SpaceBar");
	pController->GetViewportSize(screenW, screenH);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, *(FString::FromInt(screenW)));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, *(FString::FromInt(screenH)));
	pController->bShowMouseCursor = true;
	pController->bEnableClickEvents = true;
	pController->bEnableMouseOverEvents = true;
	sprite->OnComponentBeginOverlap.AddDynamic(this, &AKillMe::OnOverlapBegin);
	currentBeat = &(beats[0]);
	//currentMulti = speedMultis[0];
	if (templateEmitter == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DIDNT FIND CIRCLE COMPONENT"));
	}
	if (bulletController3 == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DIDNT FIND BULLET CONTROLLER"));
	}
	if (sound == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DIDNT FIND SOUND"));
	}
	if (drumBeat == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DIDNT FIND DRUMBEAT"));
	}
	//emitter->SetHaltSpawning(true);
	scale = baseScale;
	hScore = 0;
	rScore = 1;
	perfects = 0;
	total = 0;
	invunerableTime = 0;
	iCounter = 0;
	isInvunerable = false;
	currentLevel = 0;
	levelConversion = { 8, 12, 23, 13, 14, 15, 16, 17, 18 };
	for (int i = 0; i < 70; i++) {
		levelConversion.push_back(-1);
	}
	//speed = baseSpeed / (*currentBeat)[0];
	//currentBeat.clear();
	//textBox->SetText(FText::FromString("I fucking hate unreal engine"));
	int li = ABulletController::levelIndex;
	if (li == 0)
	{
		//sound->SetWaveParameter(FName("wave"), song0);
	}
	else if (li == 1) {
		sound->SetWaveParameter(FName("wave"), song2);
	}
	else if (li == 2) {
		sound->SetWaveParameter(FName("wave"), song1_4);
	}
	else if (li == 3) {
		sound->SetWaveParameter(FName("wave"), song4);
	}
	else if (li == 4) {
		sound->SetWaveParameter(FName("wave"), song5);
	}
	else if (li == 5) {
		sound->SetWaveParameter(FName("wave"), song6);
	}
	else if (li == 6) {
		sound->SetWaveParameter(FName("wave"), song7);
	}
	else if (li == 7) {
		sound->SetWaveParameter(FName("wave"), song8);
	}
	else {
		sound->SetWaveParameter(FName("wave"), song2);
	}
	*/
}

// Called every frame
void AKillMe3::Tick(float DeltaTime)
{
	Super::Super::Tick(DeltaTime);
	pController->GetViewportSize(screenW, screenH);
	if (!isTimeFrozen) {
		clockTime += (DeltaTime*ABulletController::audioCoeff);
	}
	if (rhythmBuffer < 0) {
		rhythmBuffer = 0;
	}
	else if (rhythmBuffer > 0) {
		rhythmBuffer -= (DeltaTime*ABulletController::audioCoeff);
	}
	if (isInvunerable == true) {
		invunerableTime += (DeltaTime*ABulletController::audioCoeff);
		if (invunerableTime > iCounter * 0.1) {
			if (iCounter % 2 == 0) {
				sprite->SetVisibility(false);
				hexPlane->SetVisibility(false);
				flipBook->SetVisibility(false);
				//circleSprite->SetVisibility(false);

			}
			else {
				sprite->SetVisibility(true);
				hexPlane->SetVisibility(true);
				flipBook->SetVisibility(true);
				//circleSprite->SetVisibility(true);
			}
			iCounter++;
		}
		if (invunerableTime > 1.5) {
			isInvunerable = false;
			invunerableTime = 0;
			iCounter = 0;
		}
	}
	clicked = pController->IsInputKeyDown(leftClick) || pController->IsInputKeyDown(space);
	if (trail != nullptr) {
		if (trail->IsPendingKill()) {
			trail = nullptr;
		}
		else {
			trail->SetBeamSourcePoint(0, GetActorLocation(), 0);
		}
	}
	/*if (IsValid(trail) && trail->EmitterInstances.Num() > 0 && trail->EmitterInstances[0] != nullptr) {
		FVector tPoint;
		trail->EmitterInstances[0]->GetBeamTargetPoint(0, tPoint);
		if (tPoint != GetActorLocation()) {
			trail->SetBeamSourcePoint(0, GetActorLocation(), 0);
		}
	}
	else if (trail != nullptr && trail->IsPendingKill()) {
		trail = nullptr;
	}*/
	if (clicked && !wasClicked && !isLevelFinsihedd) {
		drumBeat->Play();
		if (transitionTimes[transitionIndex + 1] < clockTime) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "BEAT CHANGE");
			rhythmBuffer = 3;
			if (ABulletController::levelIndex != 0 && ABulletController::levelIndex != 8) {
				transitionIndex++;
				if (beats[transitionIndex + 1].size() == 0) {
					//just reset for now
					transitionIndex = 0;
					FinishedLevel();
				}
				currentBeat = &(beats[transitionIndex]);
				currentMulti = speedMultis[transitionIndex];
			}
			index = 0;
			clockTime = 0;
		}
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "hello??");
		trail = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), templateEmitter, this->GetActorLocation(), FRotator(0));
		//trail->SetBeamTargetPoint(0, this->GetActorLocation(), 0);
		trail->SetBeamSourcePoint(0, this->GetActorLocation(), 0);
		total++;
		if (timeout < (((*currentBeat)[index])-0.08) && hasStarted) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "EARLY");
			PopupType = 0;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				Health -= ((((*currentBeat)[index])-0.08) + 0.08 - timeout) * 4 * 0.5;
			}
			//ResetEverything();
		}
		else if (timeout < (((*currentBeat)[index])-0.08) + 0.05) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "A LITTLE EARLY");
			PopupType = 1;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				Health -= ((((*currentBeat)[index])-0.08) + 0.08 - timeout) * 5 * 0.5;
				Health += 0.15*0.5;
			}
		}
		else if (timeout > 0.16 + (((*currentBeat)[index])-0.08)) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LATE");
			PopupType = 2;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				Health -= (timeout - (((*currentBeat)[index])-0.08) - 0.08) * 4 * 0.5;
			}
			//ResetEverything();
		}
		else if (timeout > (((*currentBeat)[index])-0.08) + 0.11) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "A LITTLE LATE");
			PopupType = 3;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				Health -= (timeout - (((*currentBeat)[index])-0.08) - 0.08) * 5 * 0.5;
				Health += 0.15*0.5;
			}
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "PERFECT!");
			if (Health < 0.7) {
				Health += 0.3*0.5;
			}
			else {
				Health = 1;
			}
			perfects++;
			PopupType = 4;
			OnSlightlyEarly();
		}
		if (Health < 0) {
			Health = 0;
		}
		if (Health <= 0 && !isTimeFrozen) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "BAD RYTHM");
			if (ABulletController::levelIndex != 0 && ABulletController::levelIndex != 8) {
				ResetEverything();
			}
		}
		hasStarted = true;
		scale = baseScale;//FVector(0.06 + ((((*currentBeat)[index])-0.08) * 0.38));
		speed = baseSpeed / (((*currentBeat)[index])-0.08);
		index++;
		if (index == currentBeat->size()) {
			//reset beat
			index = 0;
		}
		timeout = 0;
		isMoving = true;
		//CALCULATE DIRECTION
		float x = 0; float y = 0;
		pController->GetMousePosition(x, y);
		y = screenH - y;
		y = y - (screenH / 2);
		x = x - (screenW / 2);
		x = x * 4500 / screenW;
		y = y * 4500 / screenW;
		direction.X = x - GetActorLocation().X;//x-
		direction.Z = y - GetActorLocation().Z;//y-
		direction.Normalize();
		if (direction.X < 0) {
			flipBook->SetRelativeRotation(FRotator(0, 0, 0));
		}
		else {
			flipBook->SetRelativeRotation(FRotator(0, 180, 0));
		}
		StartGlide();
	}
	timeout += (DeltaTime*ABulletController::audioCoeff);
	if (timeout < (((*currentBeat)[index])-0.08) + 0.16) {
		scale -= FVector(DeltaTime * ABulletController::audioCoeff * 0.24 / ((((*currentBeat)[index])-0.08) + 0.08)); //0.38
		circleSprite->SetRelativeScale3D(scale);
		if (timeout < (((*currentBeat)[index])-0.08)) {
			AddActorLocalOffset(direction * DeltaTime* ABulletController::audioCoeff* speed * currentMulti);//speed*currentMulti
			//AddActorLocalOffset(GetActorLocation()* DeltaTime* speed* currentMulti);
		}
		else {
			if (direction != FVector(0)) {
				EndGlide();
				//flipBook->AddLocalRotation(FRotator(0, 180, 0));
			}
			direction = FVector(0);
			
		}
	}
	beatTime += (DeltaTime*ABulletController::audioCoeff);
	if (beatTime > (*currentBeat)[beatIndex]) {
		beatTime = 0;
		metronomeSpeed = 1 / (*currentBeat)[beatIndex];
		beatIndex++;
		if (beatIndex == currentBeat->size()) {
			beatIndex = 0;
		}
		OnBeatChange();
	}

	wasClicked = clicked;
	if (timeout > 3 && !isTimeFrozen) {
		//ResetEverything();
		if (ABulletController::levelIndex == 0 || ABulletController::levelIndex == 8) {
			if (bulletController3->tutorialTime < 28) {
				//do nothing
			}
			else {
				Health = 0;
			}
		}
		else {
			ResetEverything();
		}
		//Health = 0;
	}
}
void AKillMe3::AddRythm(std::vector<float> beat, int in)
{
	beats[in] = beat;
}
void AKillMe3::SetTransitions(std::vector<float> ts)
{
	transitionTimes = ts;
}
void AKillMe3::setSpeedMultis(std::vector<float> s)
{
	speedMultis = s;
}
void AKillMe3::AddTextInstruction(int type, float start, float duration, FString textContent, float interval, int count)
{
	on_screen_message temp;
	temp.duration = duration;
	temp.startTime = start;
	temp.type = type;
	temp.message = textContent;
	temp.interval = interval;
	temp.count = count;
	messages.push_back(temp);
}
void AKillMe3::ResetEverything()
{
	//return;
	bulletController3->ResetBullets();
	transitionIndex = 0;
	index = 0;
	currentBeat = &(beats[0]);
	scale = baseScale;
	speed = baseSpeed / (*currentBeat)[0];
	timeout = 0;
	clockTime = 0;
	this->SetActorLocation(baseLocation);
	trail = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), templateEmitter, FVector(0, 2, 0), FRotator(0));
	trail->SetBeamTargetPoint(0, this->GetActorLocation(), 0);
	trail->SetBeamSourcePoint(0, this->GetActorLocation(), 0);
	direction = FVector(0, 0, 0);
	hasStarted = false;
	bulletController3->border->ResetBorder();
	Health = 1;
	hScore = 0;
	tutHScore = 0;
	CloseWidget();
	isLevelFinsihedd = false;

	bulletController3->tutorialTime = 0;
	bulletController3->tutFirstTime = true;
	/*if (ABulletController::levelIndex == 1)
	{
		sound->SetWaveParameter(FName("wave"), song0);
	}*/

	//RESET SOUND
	sound->Stop();
	if (ABulletController::levelIndex == 2) {
		sound->SetWaveParameter(FName("wave"), song1_4);
	}
	if (ABulletController::levelIndex != 0 && ABulletController::levelIndex != 8) {
		sound->Play();
	}
	bulletController3->isTimeFrozen = false;
	isTimeFrozen = false;
}


