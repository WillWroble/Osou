// Fill out your copyright notice in the Description page of Project Settings.


#include "KillMe.h"
#include "Kismet/GameplayStatics.h"
//#include "InputCoreTypes.h"
#include "PaperSpriteComponent.h"
#include "Components/AudioComponent.h"
#include "BulletController.h"
#include "EngineUtils.h"


UWidget* childWidget;
UPaperSpriteComponent* sprite;
UPaperSpriteComponent* circleSprite;
//UAudioComponent* sound;
UAudioComponent* drumBeat;
UParticleSystemComponent* trail;
FParticleEmitterInstance* emitter;
APlayerController* pController;
ABulletController* bulletController;
FKey leftClick;
FKey space;
FVector direction;
FVector baseScale;
FVector scale;
FVector baseLocation;

bool isLevelFinsihedd;
bool wasClicked;
bool isMoving;
int screenW;
int screenH;
float travelTime;
float timeout;
bool hasStarted;
bool clicked;


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
	//currentMulti = speedMultis[0];
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
	
}

// Called every frame
void AKillMe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	clockTime += DeltaTime;
	if (rhythmBuffer < 0) {
		rhythmBuffer = 0;
	}
	else if (rhythmBuffer > 0) {
		rhythmBuffer -= DeltaTime;
	}
	if (isInvunerable == true) {
		invunerableTime += DeltaTime;
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
	if (trail != nullptr && trail->EmitterInstances.Num() > 0 && trail->EmitterInstances[0] != nullptr) {
		FVector tPoint;
		trail->EmitterInstances[0]->GetBeamTargetPoint(0, tPoint);
		if (tPoint != GetActorLocation()) {
			trail->SetBeamSourcePoint(0, GetActorLocation(), 0);
		}
	}
	if (clicked && !wasClicked && !isLevelFinsihedd) {
		drumBeat->Play();
		if (transitionTimes[transitionIndex + 1] < clockTime) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "BEAT CHANGE");
			rhythmBuffer = 3;
			if (ABulletController::levelIndex != 0) {
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
		trail = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), templateEmitter, FVector(0,2,0), FRotator(0));
		trail->SetBeamTargetPoint(0, this->GetActorLocation(), 0);
		trail->SetBeamSourcePoint(0, this->GetActorLocation(), 0);
		total++;
		if (timeout < (*currentBeat)[index] && hasStarted) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "EARLY");
			PopupType = 0;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				Health -= ((*currentBeat)[index] + 0.08 - timeout) * 5;
			}
			//ResetEverything();
		} else if (timeout < (*currentBeat)[index] + 0.05) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "A LITTLE EARLY");
			PopupType = 1;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				Health -= ((*currentBeat)[index] + 0.08 - timeout) * 5;
				Health += 0.1;
			}
		} else if (timeout > 0.16 + (*currentBeat)[index]) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LATE");
			PopupType = 2;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				Health -= (timeout - (*currentBeat)[index] - 0.08) * 5;
			}
			//ResetEverything();
		} else if (timeout > (*currentBeat)[index] + 0.11) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "A LITTLE LATE");
			PopupType = 3;
			OnSlightlyEarly();
			if (rhythmBuffer == 0) {
				Health -= (timeout - (*currentBeat)[index] - 0.08) * 5;
				Health += 0.1;
			}
		} else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "PERFECT!");
			if (Health < 0.7) {
				Health += 0.3;
			} else {
				Health = 1;
			}
			perfects++;
			PopupType = 4;
			OnSlightlyEarly();
		}
		if (Health <= 0) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "BAD RYTHM");
			if (ABulletController::levelIndex != 0) {
				ResetEverything();
			}
		}
		hasStarted = true;
		scale = baseScale;//FVector(0.06 + ((*currentBeat)[index] * 0.38));
		speed = baseSpeed / (*currentBeat)[index];
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
		direction.X = x - GetActorLocation().X;
		direction.Z = y - GetActorLocation().Z;
		direction.Normalize();
	}
	timeout += DeltaTime;
	if (timeout < (*currentBeat)[index] + 0.16) {
		scale -= FVector(DeltaTime * 0.24 / ((*currentBeat)[index] + 0.08)); //0.38
		circleSprite->SetRelativeScale3D(scale);
		if (timeout < (*currentBeat)[index]) {
			AddActorLocalOffset(direction * DeltaTime * speed * currentMulti);
		}
	}
	beatTime += DeltaTime;
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
	bulletController->ResetBullets();
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
	bulletController->border->ResetBorder();
	Health = 1;
	hScore = 0;
	tutHScore = 0;
	CloseWidget();
	isLevelFinsihedd = false;
	//RESET SOUND
	sound->Stop();
	if (ABulletController::levelIndex == 2) {
		sound->SetWaveParameter(FName("wave"), song1_4);
	}
	sound->Play();
}
void AKillMe::FinishedLevel()
{
	rScore = ((float)perfects / (float)total) * ((float)100);
	//hScore = 3;
	isLevelFinsihedd = true;
	currentLevel = levelConversion[ABulletController::levelIndex];
	OnFinishLevel();
}
void AKillMe::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		return;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
		if (isLevelFinsihedd || isInvunerable) {
			return;
		}
		UpdateHealthBar();
		hScore++;
		tutHScore++;
		if (hScore > 7) {
			if (ABulletController::levelIndex != 0) {
				ResetEverything();
			}
		}
		else {
			isInvunerable = true;
		}
		//ResetEverything();
	}
}

