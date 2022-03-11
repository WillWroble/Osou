// Fill out your copyright notice in the Description page of Project Settings.


#include "KillMe.h"
#include "Kismet/GameplayStatics.h"
//#include "InputCoreTypes.h"
#include "PaperSpriteComponent.h"
#include "Components/AudioComponent.h"
#include "BulletController.h"
#include "EngineUtils.h"



UPaperSpriteComponent* sprite;
UPaperSpriteComponent* circleSprite;
UAudioComponent* sound;
UAudioComponent* drumBeat;
UParticleSystemComponent* trail;
FParticleEmitterInstance* emitter;
APlayerController* pController;
ABulletController* bulletController;
AAkAmbientSound* musicEvent;
AAkAmbientSound* endMusicEvent;
FKey leftClick;
FKey space;
FVector direction;
FVector baseScale;
FVector scale;
FVector baseLocation;
//FAkAudioDevice* audioDevice;

bool wasClicked;
bool isMoving;
int screenW;
int screenH;
float travelTime;
float timeout;
bool hasStarted;


// Sets default values
AKillMe::AKillMe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	baseScale = FVector(0.3); //0.1675
	PrimaryActorTick.bCanEverTick = true;
	wasClicked = false;
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
	tones = std::vector<std::vector<float>>(99);
	beatTime = 0;
	hasStarted = false;
	Health = 1;
	PopupType = 0;
	beatIndex = 0;

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
	currentTones = &(tones[0]);
	if (templateEmitter == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DIDNT FIND CIRCLE COMPONENT"));
	}
	if (bulletController == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DIDNT FIND BULLET CONTROLLER"));
	}
	if (drumBeat == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DIDNT FIND DRUMBEAT"));
	}
	//audioDevice = FAkAudioDevice::Get();
	//musicEvent = FAkAudioDevice::Get()->PostEvent("Music", this);
	//emitter->SetHaltSpawning(true);
	scale = baseScale;
	//speed = baseSpeed / (*currentBeat)[0];
	//currentBeat.clear();
	TActorIterator<AAkAmbientSound> Itr(GetWorld());
	musicEvent = *Itr;
	//++Itr;
	//endMusicEvent = *Itr;

}

// Called every frame
void AKillMe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	clockTime += DeltaTime;
	
	bool clicked = pController->IsInputKeyDown(leftClick) || pController->IsInputKeyDown(space);
	if(trail != nullptr && trail->EmitterInstances.Num() > 0)
		trail->SetBeamSourcePoint(0, this->GetActorLocation(), 0);
	if (clicked && !wasClicked) {
		//drumBeat->Play();
		//musicEvent->StartPlaying();
		currentTone = (*currentTones)[index];
		if (transitionTimes[transitionIndex + 1] < clockTime) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "BEAT CHANGE");
			transitionIndex++;
			currentBeat = &(beats[transitionIndex]);
			currentTones = &(tones[transitionIndex]);
			if (beats[transitionIndex + 1].size() == 0) {
				//just reset for now
				transitionIndex = 0;
			}
			index = 0;
			clockTime = 0;
		}
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "hello??");
		trail = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), templateEmitter, FVector(0,2,0), FRotator(0));
		trail->SetBeamTargetPoint(0, this->GetActorLocation(), 0);
		trail->SetBeamSourcePoint(0, this->GetActorLocation(), 0);

		if (timeout < (*currentBeat)[index] && hasStarted) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "EARLY");
			Health -= ((*currentBeat)[index] + 0.08 - timeout) * 5;
			error = ((*currentBeat)[index] + 0.08 - timeout) * 5;
			error = FMath::Clamp(error, 0.0f, 0.25f);
			error += 0.5;
			PopupType = 0;
			OnSlightlyEarly();
			//ResetEverything();
		} else if (timeout < (*currentBeat)[index] + 0.05) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "A LITTLE EARLY");
			Health -= ((*currentBeat)[index] + 0.08 - timeout) * 5;
			error = ((*currentBeat)[index] + 0.08 - timeout) * 5;
			error = FMath::Clamp(error, 0.0f, 0.25f);
			error += 0.5;
			PopupType = 1;
			OnSlightlyEarly();
		} else if (timeout > 0.16 + (*currentBeat)[index]) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LATE");
			Health -= (timeout - (*currentBeat)[index] - 0.08) * 5;
			error = (timeout - (*currentBeat)[index] - 0.08) * 5;
			error = FMath::Clamp(error, 0.0f, 0.25f);
			error = 0.5 - error;
			PopupType = 2;
			OnSlightlyEarly();
			//ResetEverything();
		} else if (timeout > (*currentBeat)[index] + 0.11) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "A LITTLE LATE");
			Health -= (timeout - (*currentBeat)[index] - 0.08) * 5;
			error = (timeout - (*currentBeat)[index] - 0.08) * 5;
			error = FMath::Clamp(error, 0.0f, 0.25f);
			error = 0.5 - error;
			PopupType = 3;
			OnSlightlyEarly();
		} else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "PERFECT!");
			if (Health < 0.7) {
				Health += 0.3;
			} else {
				Health = 1;
			}
			error = 0;
			PopupType = 4;
			OnSlightlyEarly();
		}
		if (Health <= 0) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "BAD RYTHM");
			ResetEverything();
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
			AddActorLocalOffset(direction * DeltaTime * speed);
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
void AKillMe::AddRythm(std::vector<float> beat, std::vector<float> tone, int in)
{
	beats[in] = beat;
	tones[in] = tone;
}
void AKillMe::SetTransitions(std::vector<float> ts)
{
	transitionTimes = ts;
}
void AKillMe::ResetEverything()
{
	bulletController->ResetBullets();
	transitionIndex = 0;
	index = 0;
	currentBeat = &(beats[0]);
	currentTones = &(tones[0]);
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
	//RESET SOUND
	sound->Stop();
	sound->Play();
	

}
void AKillMe::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
		//ResetEverything();
	}
}

