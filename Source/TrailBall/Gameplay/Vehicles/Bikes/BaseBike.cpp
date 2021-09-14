// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBike.h"

void ABaseBike::ApplyAxisForces()
{
    if (ForwardAxis == 0.f && RightAxis == 0.f) return;

    UE_LOG(LogTemp, Warning, TEXT("Pushing"));
    FVector ForwardVector = GetOwner()->GetActorForwardVector();
    GetMesh()->AddForce(ForwardVector * ForwardThrust * ForwardAxis);
    UE_LOG(LogTemp, Warning, TEXT("Forward - %s"), *ForwardVector.ToString());
}