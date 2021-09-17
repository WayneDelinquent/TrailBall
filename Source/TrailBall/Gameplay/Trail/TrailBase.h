// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/SplineMeshActor.h"
#include "TrailBase.generated.h"

class USplineComponent;

UCLASS()
class TRAILBALL_API ATrailBase : public AActor
{
	GENERATED_BODY()

public:
	ATrailBase();

	void AddNewSplinePoint(FVector SplineLocation, float SplineLifespan);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trail", meta = (AllowPrivateAccess = "true"))
	USplineComponent *Spline;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trail", meta = (AllowPrivateAccess = "true"))
	UStaticMesh *SplineStaticMesh;
};
