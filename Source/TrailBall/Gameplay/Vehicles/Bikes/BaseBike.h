// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreMinimal.h"
#include "../BaseVehicle.h"
#include "BaseBike.generated.h"

/**
 * 
 */
UCLASS()
class TRAILBALL_API ABaseBike : public ABaseVehicle
{
	GENERATED_BODY()

	virtual void ApplyRightForce() override;
	virtual void ApplyForwardForce() override;
};
