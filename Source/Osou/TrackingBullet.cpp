// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackingBullet.h"
AKillMe* ATrackingBullet::player = nullptr;

void ATrackingBullet::BeginPlay()
{
	Super::BeginPlay();
	niag = (UNiagaraComponent*)(this->GetComponentsByTag(UNiagaraComponent::StaticClass(), "tag1"))[0];
	
}
void ATrackingBullet::UpdateMovement(float DeltaTime) {
	FVector delta = (player->GetActorLocation() - GetActorLocation());
	float theta = atan2f(delta.Z, delta.X) * 180 / PI;
	//if (fmod((GetActorRotation().Pitch+360),360) < fmod((theta+360), 360)) {
	FRotator fixed;// = GetActorRotation().Pitch;
	if (abs(abs(GetActorRotation().Yaw) - 180) < 0.001 && abs(abs(GetActorRotation().Roll) - 180) < 0.001) {
		fixed = GetActorRotation().GetEquivalentRotator();
	}
	else {
		fixed = GetActorRotation();
	}
	niag->SetFloatParameter(FName("relativeAngle"), -fixed.Pitch -90);
	float diff = (fixed.Pitch - theta);
	float normalizedDiff = FRotator::NormalizeAxis(diff);
	//if ((diff < 0 && diff > -180) || (diff > 180 && diff < 360) || (diff < -360 && diff > -540) || (diff > )) {
	if (abs(normalizedDiff) > coeffeceints[3] || time > 4) {
		//do nothing
	}
	else if(normalizedDiff < 0) {
		
		AddActorLocalRotation(FRotator(30 * DeltaTime * coeffeceints[2], 0, 0));
	}
	else {

		AddActorLocalRotation(FRotator(-30 * DeltaTime * coeffeceints[2], 0, 0));
		
	}

	time += DeltaTime;
	AddActorLocalOffset(FVector(1, 0, 0) * coeffeceints[0] * DeltaTime);

}

