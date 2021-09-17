// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "../Vehicles/BaseVehicle.h"
#include "TrailBase.h"
#include "TrailActorComponentBase.h"

// Sets default values for this component's properties
UTrailActorComponentBase::UTrailActorComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTrailActorComponentBase::BeginPlay()
{
	Super::BeginPlay();

	BindKeys();
	SetSpawnPoint();
}

// Called every frame
void UTrailActorComponentBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTrailActorComponentBase::BindKeys() 
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("SpawnTrail", IE_Pressed, this, &UTrailActorComponentBase::StartTrailGeneration);
		InputComponent->BindAction("SpawnTrail", IE_Released, this, &UTrailActorComponentBase::StopTrailGeneration);
	}
}

void UTrailActorComponentBase::SetSpawnPoint() 
{
	TrailSpawnPoint = Cast<ABaseVehicle>(GetOwner())->GetSplineSpawnPoint();
}

void UTrailActorComponentBase::StartTrailGeneration() 
{
	UE_LOG(LogTemp, Warning, TEXT("Start Trail"));
	CurrentTrail = GetWorld()->SpawnActor<ATrailBase>(TrailClass, TrailSpawnPoint->GetComponentLocation(), TrailSpawnPoint->GetComponentRotation());
	GetWorld()->GetTimerManager().SetTimer(TrailGenerationTimer, this, &UTrailActorComponentBase::ExtendTrail, TrailGenerationRate, true);
}

void UTrailActorComponentBase::ExtendTrail() 
{
	UE_LOG(LogTemp, Warning, TEXT("Extend Trail"));
	CurrentTrail->AddNewSplinePoint(TrailSpawnPoint->GetComponentLocation(), 5.f);
}

void UTrailActorComponentBase::StopTrailGeneration()
{
	UE_LOG(LogTemp, Warning, TEXT("Stop Trail"));
	GetWorld()->GetTimerManager().ClearTimer(TrailGenerationTimer);
	CurrentTrail = nullptr;
}