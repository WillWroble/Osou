// Fill out your copyright notice in the Description page of Project Settings.


#include "FractureBullet.h"

void AFractureBullet::BeginPlay()
{
	Super::BeginPlay();
	/*child1 = (UActorComponent*)(this->GetComponentsByTag(UActorComponent::StaticClass(), "tag1"))[0];
	child2 = (UActorComponent*)(this->GetComponentsByTag(UActorComponent::StaticClass(), "tag2"))[0];
	child3 = (UActorComponent*)(this->GetComponentsByTag(UActorComponent::StaticClass(), "tag3"))[0];
	child4 = (UActorComponent*)(this->GetComponentsByTag(UActorComponent::StaticClass(), "tag4"))[0];
	child5 = (UActorComponent*)(this->GetComponentsByTag(UActorComponent::StaticClass(), "tag5"))[0];
	child6 = (UActorComponent*)(this->GetComponentsByTag(UActorComponent::StaticClass(), "tag6"))[0];*/
	myChildren = TArray<UChildActorComponent*>();
	TArray<UActorComponent*> allTagged = this->GetComponentsByTag(UChildActorComponent::StaticClass(), "tag1");
	for (int i = 0; i < 6; i++) {
		myChildren.Add((UChildActorComponent*)(allTagged[i]));
	}
}

void AFractureBullet::UpdateMovement(float DeltaTime)
{
	time += DeltaTime;

	if (time > coeffeceints[2]) {
		//begin fracturing
		for (int i = 0; i < myChildren.Num(); i++) {
			myChildren[i]->GetChildActor()->AddActorLocalOffset(FVector(0, 0, -1) * coeffeceints[3] * DeltaTime);
		}
	}
	//move normally
	AddActorLocalOffset(FVector(1, 0, 0) * coeffeceints[0] * DeltaTime);

}
