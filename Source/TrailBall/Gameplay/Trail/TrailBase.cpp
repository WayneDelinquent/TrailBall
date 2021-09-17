// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "TrailBase.h"

ATrailBase::ATrailBase()
{
    Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
    RootComponent = Spline;
}

void ATrailBase::AddNewSplinePoint(FVector SplineLocation, float SplineLifespan) 
{
    Spline->AddSplinePoint(SplineLocation, ESplineCoordinateSpace::World, true);
    USplineMeshComponent *SplineMesh = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass());
    SplineMesh->CreationMethod = EComponentCreationMethod::UserConstructionScript;
    SplineMesh->SetStaticMesh(SplineStaticMesh);
    SplineMesh->SetMobility(EComponentMobility::Movable);
    SplineMesh->AttachToComponent(Spline, FAttachmentTransformRules::KeepWorldTransform);

    int32 SplineCount = Spline->GetNumberOfSplinePoints();

    SplineMesh->SetStartAndEnd(
        Spline->GetLocationAtSplinePoint(SplineCount - 2, ESplineCoordinateSpace::Local),
        Spline->GetTangentAtSplinePoint(SplineCount - 2, ESplineCoordinateSpace::Local),
        Spline->GetLocationAtSplinePoint(SplineCount - 1, ESplineCoordinateSpace::Local),
        Spline->GetTangentAtSplinePoint(SplineCount - 1, ESplineCoordinateSpace::Local)
    );

    SetLifeSpan(SplineLifespan);

}