// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "BaseBike.h"

void ABaseBike::ApplyRightForce()
{
    if (FMath::IsNearlyZero(RightAxis))
        return;
        
    FVector CurrentVelocity = GetMesh()->GetPhysicsLinearVelocity();
    FVector UpVector = GetOwner()->GetActorUpVector();

    FVector NewTorque = RotationalThrust * RightAxis * UpVector;
    GetMesh()->AddTorqueInDegrees(NewTorque, FName(), true);
}

void ABaseBike::ApplyForwardForce()
{
    if (FMath::IsNearlyZero(ForwardAxis))
        return;

    FVector ForwardVector = GetMesh()->GetForwardVector();
    GetMesh()->AddForce(ForwardVector * ForwardThrust * ForwardAxis, FName(), true);
}