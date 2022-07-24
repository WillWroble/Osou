// Fill out your copyright notice in the Description page of Project Settings.


#include "RhythmTest.h"

// Sets default values
ARhythmTest::ARhythmTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	testCompleted = false;
	messageCounter = 0;
	messageTime = 0;
	messageClockTime = 0;
	messageIndex = 0;
	testClockTime = 0;

}

// Called when the game starts or when spawned
void ARhythmTest::BeginPlay()
{
	Super::BeginPlay();
	prevTime = 0;
	collectionMode = false;
	pController = GetWorld()->GetFirstPlayerController();
	sound = (UAudioComponent*)(this->GetComponentsByTag(UAudioComponent::StaticClass(), "tag1"))[0];

	BindToInput();

	AddTextInstruction(0, 1, 3, FString("hello, you selected an Osou True Rhythm Stage"));
	AddTextInstruction(0, 5, 3, FString("Osou True Rhythm is an experimental game mode that requires high levels of audio perscision"));
	AddTextInstruction(0, 9, 3, FString("in order to play you must complete a short rhythm test to calibrate the game to your device's audio playback"));
	AddTextInstruction(1, 13, 1, FString("start clicking to the 120 bpm beat in: "), 1, 3);



}

// Called every frame
void ARhythmTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	messageClockTime += DeltaTime;
	if (messageClockTime > 22 && !testCompleted) {
		
		testClockTime += DeltaTime;
	}
	if (testClockTime > 0) {
		if (!sound->IsPlaying()) {
			sound->Play();
		}
	}
	if (testClockTime > 30) {
		//finished collecting data
		sound->Stop();
		clickTimes.erase(clickTimes.begin());
		float m = mean(clickTimes);
		float s = stddev(clickTimes);
		if (s > 0.05) {
			//bad deviation
			testClockTime = -15;
			DisplayMessage(FString("your BPM has high deviations, try again"), 1, 1, 0);
			clickTimes.clear();
		}
		else if (m / 0.5 > 1.05 || m / 0.5 < 0.95) {
			//off beat
			testClockTime = -15;
			DisplayMessage(FString("your BPM is very different from the 120BPM playing either your speakers are way too fast/slow or you are off beat, try again"), 1, 1, 0);
			clickTimes.clear();
		}
		else {
			//test completed

			ABulletController::audioCoeff = 0.5/m;
			DisplayMessage(FString("Test Completed successfully you can now begin the level"), 0, 3, 0);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(ABulletController::audioCoeff));
			testClockTime = 0;
			testCompleted = true;
			
		}
	}
	if (messages.size() > messageIndex && messageClockTime > messages[messageIndex].startTime) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "PLAYING MESSAGE");
		currentMessage = messages[messageIndex];
		isDisplayMessage = true;
		messageIndex++;
	}
	if (isDisplayMessage) {
		if (currentMessage.type == 0) {
			if (messageTime == 0) {
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "PLAYING MESSAGE START");
				content = currentMessage.message;
				FadeInText();
			}
			messageTime += DeltaTime;
			if (messageTime > currentMessage.duration) {
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "PLAYING MESSAGE END");
				FadeOutText();
				messageTime = 0;
				isDisplayMessage = false;
			}
		}
		else {
			if (messageTime == 0) {
				content = currentMessage.message;
				FadeInText();
				messageCounter = 1;
			}
			else if (messageTime > currentMessage.duration + currentMessage.interval) {
				currentMessage.interval = 0;
				if (messageCounter % 2 == 0) {
					//start next number
					if (messageCounter == currentMessage.count * 2 + 2) {
						content = FString("now!");
					}
					else {
						content = FString::FromInt(currentMessage.count + 1 - (messageCounter / 2));
					}
					FadeInText();
				}
				else {
					//start fading out
					FadeOutText();
				}
				messageCounter++;
				messageTime = 0.001;

			}
			messageTime += DeltaTime;
			if (messageCounter == currentMessage.count * 2 + 4) {
				isDisplayMessage = false;
				messageTime = 0;
				messageCounter = 0;
			}
		}
	}
	
}

void ARhythmTest::LeftClick()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LEFT CLICK");
	if (testClockTime <= 0) {
		return;
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LEFT CLICK REGISTERED");

	float timeStamp = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	clickTimes.push_back(timeStamp - prevTime);
	prevTime = timeStamp;
}
void ARhythmTest::AddTextInstruction(int type, float start, float duration, FString textContent, float interval, int count)
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
void ARhythmTest::DisplayMessage(FString message, int type, float duration, float start)
{

	on_screen_message temp;
	temp.type = type;
	temp.duration = duration;
	temp.startTime = start;
	temp.message = message;
	temp.count = 3;
	temp.interval = 7;
	currentMessage = temp;
	isDisplayMessage = true;
}
float ARhythmTest::mean(std::vector<float> items)
{
	//return 0.0f;
	float sum = 0;
	for (int i = 0; i < items.size(); i++) {
		sum += items[i];
	}
	return sum / items.size();
}
float ARhythmTest::stddev(std::vector<float> v)
{
	float ave = mean(v);
	double E = 0;
	for (int i = 0; i < v.size(); i++)
		E += (v[i] - ave) * (v[i] - ave);
	return sqrt(E/v.size());
}
void ARhythmTest::BindToInput()
{
	// Initialize our component
	InputComponent = NewObject<UInputComponent>(this);
	InputComponent->RegisterComponent();
	if (InputComponent)
	{
		// Bind inputs here
		// InputComponent->BindAction("Jump", IE_Pressed, this, &AUnrealisticPawn::Jump);
		// etc...
		InputComponent->BindAction("LeftClick", IE_Pressed, this, &ARhythmTest::LeftClick);
		//InputComponent->BindAction("ScrollUp", IE_Pressed, this, &ALevelBlockManager::ScrollUp);

		// Now hook up our InputComponent to one in a Player
		// Controller, so that input flows down to us
		EnableInput(pController);
	}
}

