// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TrailActorComponentBase.generated.h"

class ATrailBase;
struct FTimerHandle;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAILBALL_API UTrailActorComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTrailActorComponentBase();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void StartTrailGeneration();
	virtual void StopTrailGeneration();

private:
	void BindKeys();
	void SetSpawnPoint();
	void ExtendTrail();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trail", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ATrailBase> TrailClass;

	UPROPERTY()
	UInputComponent *InputComponent = nullptr;
		
	ATrailBase *CurrentTrail = nullptr;
	USceneComponent *TrailSpawnPoint;
	FTimerHandle TrailGenerationTimer;
	float TrailGenerationRate = 0.075f;
};
