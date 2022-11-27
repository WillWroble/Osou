// Fill out your copyright notice in the Description page of Project Settings.


#include "KillMe.h"
#include "BulletController.h"
//#include "Kismet/GameplayStatics.h"
////#include "InputCoreTypes.h"
//#include "PaperSpriteComponent.h"
//#include "Components/AudioComponent.h"
//#include "BulletController.h"
//#include "EngineUtils.h"


//UWidget* childWidget;
//UPaperSpriteComponent* sprite;
//UPaperSpriteComponent* circleSprite;
////UAudioComponent* sound;
//UAudioComponent* drumBeat;
//UParticleSystemComponent* trail;
//FParticleEmitterInstance* emitter;
//APlayerController* pController;
ABulletController* bulletController;
//FKey leftClick;
//FKey space;
//FVector direction;
//FVector baseScale;
//FVector scale;
//FVector baseLocation;
//
//bool isLevelFinsihedd;
//bool wasClicked;
//bool isMoving;
//int screenW;
//int screenH;
//int skipCount;
//int successivePerfects;
//float travelTime;
//float timeout;
//float relativeTimeout;
//float travelTimeout;
//bool hasStarted;
//bool clicked;

bool AKillMe::is4HealthStatic = false;
// Sets default values
AKillMe::AKillMe()
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
	relativeTimeout = 0;
	travelTimeout = 0;
	direction = FVector(0, 0, 0);
	screenW = 0; screenH = 0;
	index = 0;
	relativeIndex = 0;
	transitionIndex = 0;
	skipCount = 0;
	baseSpeed = 1200 * 0.2; //700
	speed = baseSpeed;
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
	rhythmDelayConstant = 0;
	successivePerfects = 0;
	isTimeFrozen = false;
	is4Health = is4HealthStatic;


}

// Called when the game starts or when spawned
void AKillMe::BeginPlay()
{
	Super::BeginPlay();
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
	bulletController = *It;
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
	currentMulti = speedMultis[0];
	rhythmDelayConstant = rhythmDelayConstants[0];
	if (templateEmitter == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DIDNT FIND CIRCLE COMPONENT"));
	}
	if (bulletController == nullptr) {
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
	rhythmBuffer = 2;
	circleCount = 0;
	levelConversion = { 8, 12, 23, 19, 20, 11, 14, 13, 9 };
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
		sound->SetWaveParameter(FName("wave"), song9);
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
	else if (li == 8) {
		sound->SetWaveParameter(FName("wave"), song10);
	}
	else {
		sound->SetWaveParameter(FName("wave"), song2);
	}
	
}

// Called every frame
void AKillMe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	pController->GetViewportSize(screenW, screenH);
	if (!isTimeFrozen) {
		clockTime += (DeltaTime*ABulletController::audioCoeff);
	}
	if (clockTime < rhythmDelayConstant) {
		//return;
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

			} else {
				sprite->SetVisibility(true);
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
		//drumBeat->Play();
		//if (transitionTimes[transitionIndex + 1] < clockTime) {
		//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "BEAT CHANGE");
		//	rhythmBuffer = 3;
		//	if (ABulletController::levelIndex != 0) {
		//		transitionIndex++;
		//		if (beats[transitionIndex + 1].size() == 0) {
		//			//just reset for now
		//			transitionIndex = 0;
		//			FinishedLevel();
		//		}
		//		currentBeat = &(beats[transitionIndex]);
		//		currentMulti = speedMultis[transitionIndex];
		//	}
		//	index = 0;
		//	clockTime = 0;
		//}
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "hello??");
		trail = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), templateEmitter, this->GetActorLocation(), FRotator(0));
		//trail->SetBeamTargetPoint(0, this->GetActorLocation(), 0);
		trail->SetBeamSourcePoint(0, this->GetActorLocation(), 0);
		//total++;
		if (relativeTimeout < ((*currentBeat)[relativeIndex]+rhythmDelayConstant)-0.12 && hasStarted) {//&& hasStarted
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "EARLY");
			PopupType = 0;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				//Health -= (((*currentBeat)[relativeIndex]+rhythmDelayConstant) - relativeTimeout) * 4/1 * .5 *(2-Health);
				Health -= ((((*currentBeat)[relativeIndex]) - 0.08) + 0.08 - relativeTimeout) * 2;
			}
			successivePerfects = 0;
			//ResetEverything();
		} else if (relativeTimeout < ((*currentBeat)[relativeIndex]+rhythmDelayConstant) - 0.07) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "A LITTLE EARLY");
			PopupType = 1;
			OnSlightlyEarly();
			/*if (rhythmBuffer == 0) {
				Health -= (((*currentBeat)[relativeIndex]+rhythmDelayConstant) - relativeTimeout) * 5/1 * 1 * (2 - Health);
				Health += 0.15;
			}*/
			if (rhythmBuffer == 0) {
				Health -= ((((*currentBeat)[relativeIndex]) - 0.08) + 0.08 - relativeTimeout) * 3;
				Health += 0.15;
			}
			successivePerfects = 0;

		} else if (relativeTimeout > 0.12 + ((*currentBeat)[relativeIndex]+rhythmDelayConstant)) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LATE");
			PopupType = 2;
			OnSlightlyEarly();
			/*if (rhythmBuffer == 0) {
				Health -= (relativeTimeout - ((*currentBeat)[relativeIndex]+rhythmDelayConstant)) * 4/1 * .5 * (2 - Health);
			}*/
			if (rhythmBuffer == 0) {
				Health -= (relativeTimeout - (((*currentBeat)[relativeIndex]) - 0.08) - 0.08) * 2;
			}
			//ResetEverything();
			successivePerfects = 0;

		} else if (relativeTimeout > ((*currentBeat)[relativeIndex]+rhythmDelayConstant) + 0.07) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "A LITTLE LATE");
			PopupType = 3;
			OnSlightlyEarly();
			/*if (rhythmBuffer == 0) {
				Health -= (relativeTimeout - ((*currentBeat)[relativeIndex]+rhythmDelayConstant)) * 5/1 * 1 * (2 - Health);
				Health += 0.15;
			}*/
			if (rhythmBuffer == 0) {
				Health -= (relativeTimeout - (((*currentBeat)[relativeIndex]) - 0.08) - 0.08) * 3;
				Health += 0.15;
			}
			successivePerfects = 0;

		} else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "PERFECT!");
			
			//Health += 0.1f*successivePerfects;
			
			Health += 0.3;
			if (Health > 1) {
				Health = 1;
			}
			
			successivePerfects++;
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
				wasClicked = true;
				ResetEverything();
				return;
			}
		}

		if (relativeTimeout < 0) {
			//ahead (ahead now)
			//do nothing
		}
		else if (relativeTimeout > ((*currentBeat)[relativeIndex]+rhythmDelayConstant)) {
			//behind (aligned now)
			relativeTimeout = timeout;
			relativeIndex = index;
		}
		else {
			//aligned (early now)
			if (relativeTimeout > ((*currentBeat)[relativeIndex] + rhythmDelayConstant)/2) {
				relativeTimeout = timeout - ((*currentBeat)[index] + rhythmDelayConstant);
				relativeIndex = (relativeIndex + 1) % currentBeat->size();
				skipCount++;
			}
		}

		travelTimeout = 0;
		
		hasStarted = true;
		//scale = baseScale;//FVector(0.06 + ((*currentBeat)[index]+rhythmDelayConstant * 0.38));
		//speed = baseSpeed / (*currentBeat)[index]+rhythmDelayConstant; //(*currentBeat)[index]+rhythmDelayConstant
		//index++;
		//if (index == currentBeat->size()) {
		//	//reset beat
		//	index = 0;
		//}
		//timeout = 0;
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
	}

	timeout += (DeltaTime*ABulletController::audioCoeff);
	relativeTimeout += (DeltaTime*ABulletController::audioCoeff);
	travelTimeout += (DeltaTime*ABulletController::audioCoeff);
	if (travelTimeout < ((*currentBeat)[relativeIndex]+rhythmDelayConstant)) {
		AddActorLocalOffset(direction * DeltaTime * ABulletController::audioCoeff * speed * currentMulti);//speed*currentMulti
		//AddActorLocalOffset(GetActorLocation()* DeltaTime* speed* currentMulti);
	}
	else {
		direction = FVector(0);
	}
	if (clockTime < rhythmDelayConstant) {
		//return;
	}
	if (timeout < (*currentBeat)[index]+rhythmDelayConstant) { //+0.16
		scale -= FVector(DeltaTime * ABulletController::audioCoeff * 0.2 / ((*currentBeat)[index]+rhythmDelayConstant+0)); //0.38 //0.24
		for (int i = 0; i < extraBeatCircles.size(); i++) {
			extraScales[i] -= 1*(DeltaTime * ABulletController::audioCoeff * 0.2 / ((*currentBeat)[savedIndex] + rhythmDelayConstant + 0));
		}
		if (scale.X < 0) {
			scale = FVector(0);
		}
		circleSprite->SetRelativeScale3D(scale);
		for (int i = 0; i < extraBeatCircles.size(); i++) {
			extraBeatCircles[i]->SetActorScale3D(FVector(extraScales[i]));
		}
		/*if (extraScales.size() != 0 && extraScales[0] <= 0) {
			extraBeatCircles[0]->Destroy();
			extraBeatCircles.erase(extraBeatCircles.begin());
			extraScales.erase(extraScales.begin());
			circleCount--;
		}*/
	}
	else {
		//reset circle and beat
		if (circleCount != 0 && index != savedIndex) {
			extraBeatCircles[0]->Destroy();
			extraBeatCircles.erase(extraBeatCircles.begin());
			extraScales.erase(extraScales.begin());
			circleCount--;
			for (int i = 0; i < extraBeatCircles.size(); i++) {
				extraScales[i] -= 1 * (DeltaTime * ABulletController::audioCoeff * 0.2 / ((*currentBeat)[savedIndex] + rhythmDelayConstant + 0));
			}
			for (int i = 0; i < extraBeatCircles.size(); i++) {
				extraBeatCircles[i]->SetActorScale3D(FVector(extraScales[i]));
			}
		}
		float temp1 = (*currentBeat)[index] + rhythmDelayConstant;
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
				rhythmDelayConstant = rhythmDelayConstants[transitionIndex];
			}
			index = 0;
			clockTime = 0;
		}
		else {
			if (relativeTimeout == timeout && rhythmDelayConstant != 0) {
				relativeTimeout -= rhythmDelayConstant;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "XQCL");
				
			}
			rhythmDelayConstant = 0;
		}
		total++;

		if(extraScales.empty())// || baseScale.X > extraScales[extraScales.size()-1])
			scale = baseScale;//FVector(0.06 + ((*currentBeat)[index]+rhythmDelayConstant * 0.38));


		speed = baseSpeed;// / (*currentBeat)[0]; //(*currentBeat)[index]+rhythmDelayConstant

		index++;
		if (index == currentBeat->size()) {
			//reset beat
			index = 0;
		}
		FVector totalScale(baseScale);
		if (extraScales.empty()){// || baseScale.X > extraScales[extraScales.size() - 1]) {
			while (index + 1 + circleCount < currentBeat->size() && (*currentBeat)[index + 1 + circleCount] <= 0.4 && circleCount < 6) {//0.4
				circleCount++;
				totalScale += FVector(1) * ((*currentBeat)[index + circleCount]) * (ABulletController::audioCoeff * 0.2 / ((*currentBeat)[index] + rhythmDelayConstant + 0));//((*currentBeat)[index + 1 + circleCount]) * ((FVector(timeout - temp1)* (0.2 / ((*currentBeat)[index] + rhythmDelayConstant + 0)))/DeltaTime);
				extraBeatCircles.push_back(GetWorld()->SpawnActor<ABeatCircle>(BeatCircle, FVector(0), FRotator(0)));
				extraBeatCircles[extraBeatCircles.size() - 1]->SetActorScale3D(totalScale);
				extraBeatCircles[extraBeatCircles.size() - 1]->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
				extraScales.push_back(totalScale.X);
			}
			savedIndex = index;
		}
		scale -= FVector((timeout - temp1) * 0.2 / ((*currentBeat)[index]+rhythmDelayConstant + 0)); //0.24

		for (int i = 0; i < extraBeatCircles.size(); i++) {
			extraScales[i] -= 1*(timeout - temp1) * 0.2 / ((*currentBeat)[index] + rhythmDelayConstant + 0);
		}

		timeout = timeout - temp1;
	}
	if (relativeTimeout > fmaxf(((*currentBeat)[relativeIndex]) + (((*currentBeat)[index]) / 2), ((*currentBeat)[relativeIndex]) + 0.16) && rhythmDelayConstant == 0) {
		//force later relative update
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "FORCED LATE");
		PopupType = 2;
		OnSlightlyEarly();
		if (rhythmBuffer == 0) {
			Health -= (relativeTimeout - ((*currentBeat)[relativeIndex] + rhythmDelayConstant)) * 4 / 1 * 0.5 * (2 - Health);
		}
		if (Health < 0) {
			Health = 0;
		}
		successivePerfects = 0;
		if (Health <= 0 && !isTimeFrozen) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "BAD RYTHM");
			if (ABulletController::levelIndex != 0 && ABulletController::levelIndex != 8) {
				ResetEverything();
				return;
			}
		}
		relativeTimeout = timeout;
		relativeIndex = index;

	}

	beatTime += (DeltaTime*ABulletController::audioCoeff);
	if (beatTime > (*currentBeat)[0]) {
		beatTime = 0;
		metronomeSpeed = 1 / (*currentBeat)[0];
		beatIndex++;
		if (beatIndex == currentBeat->size()) {
			beatIndex = 0;
		}
		OnBeatChange();
	}

	wasClicked = clicked;
	//if (timeout > 1 && !isTimeFrozen) {
	//	//ResetEverything();
	//	if (ABulletController::levelIndex == 0) {
	//		if (bulletController->tutorialTime < 28) {
	//			//do nothing
	//		}
	//		else {
	//			Health = 0;
	//		}
	//	}
	//	else {
	//		ResetEverything();
	//	}
	//	//Health = 0;
	//}
}
void AKillMe::AddRythm(std::vector<float> beat, int in)
{
	beats[in] = beat;
}
void AKillMe::SetTransitions(std::vector<float> ts)
{
	transitionTimes = ts;
}
void AKillMe::setSpeedMultis(std::vector<float> s)
{
	speedMultis = s;
}
void AKillMe::AddTextInstruction(int type, float start, float duration, FString textContent, float interval, int count)
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
void AKillMe::ResetEverything()
{
	//return;
	rhythmBuffer = 2;
	bulletController->ResetBullets();
	transitionIndex = 0;
	index = 0;
	relativeIndex = 0;
	currentBeat = &(beats[0]);
	currentMulti = speedMultis[0];
	rhythmDelayConstant = rhythmDelayConstants[0];
	scale = baseScale;
	circleSprite->SetRelativeScale3D(scale);
	speed = baseSpeed;// / (*currentBeat)[0];
	timeout = 0;
	relativeTimeout = 0;
	travelTimeout = 0;
	clockTime = 0;
	this->SetActorLocation(baseLocation);
	trail = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), templateEmitter, FVector(0, 2, 0), FRotator(0));
	trail->SetBeamTargetPoint(0, this->GetActorLocation(), 0);
	trail->SetBeamSourcePoint(0, this->GetActorLocation(), 0);
	direction = FVector(0, 0, 0);
	hasStarted = false;
	bulletController->border->ResetBorder();
	Health = 1;
	hScore = 0;
	tutHScore = 0;
	bulletController->tutorialTime = 0;
	bulletController->tutFirstTime = true;
	if (ABulletController::levelIndex == 1)
	{
		sound->SetWaveParameter(FName("wave"), song0);
	}
	CloseWidget();
	isLevelFinsihedd = false;
	//RESET SOUND
	sound->Stop();
	if (ABulletController::levelIndex == 2) {
		sound->SetWaveParameter(FName("wave"), song1_4);
	}
	sound->Play();
	bulletController->isTimeFrozen = false;
	isTimeFrozen = false;
	for (int i = 0; i < extraBeatCircles.size(); i++) {
		extraBeatCircles[i]->SetActorHiddenInGame(true);
	}
}
void AKillMe::StopEverything()
{
	bulletController->isTimeFrozen = true;
	isTimeFrozen = true;
	sound->FadeOut(2, 0);
}
void AKillMe::FinishedLevel()
{
	rScore = ((float)perfects / (float)total) * ((float)100);
	//hScore = 3;
	//isLevelFinsihedd = true;
	currentLevel = levelConversion[ABulletController::levelIndex];
	StopEverything();
	OnFinishLevel();
}
void AKillMe::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		//return;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
		if (isLevelFinsihedd || isInvunerable || isTimeFrozen) {
			return;
		}
		UpdateHealthBar();
		hScore++;
		tutHScore++;
		streakCount = 0;
		if (hScore > 7 || (hScore > 3 && is4Health)) {
			if (ABulletController::levelIndex != 0 && ABulletController::levelIndex != 8) {
				ResetEverything();
			}
		}
		else {
			isInvunerable = true;
		}
		AInGameCharacter* c = bulletController->character;
		if (c->behaviors[c->beh_index].beh == BehaviorMode::alert || c->behaviors[c->beh_index].beh == BehaviorMode::idle) {
			if(ABulletController::levelIndex == 1)
				c->PlayAnimFour();
		}
		//ResetEverything();
	}
}

