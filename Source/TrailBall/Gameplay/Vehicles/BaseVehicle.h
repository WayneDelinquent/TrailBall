// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseVehicle.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TRAILBALL_API ABaseVehicle : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent *BaseModelMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent *SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent *Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent *SplineSpawnPoint;

public:
	ABaseVehicle();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	USceneComponent *GetSplineSpawnPoint();

protected:
	virtual void BeginPlay() override;

	virtual void CalculateForwardAxis(float Value);
	virtual void CalculateRightAxis(float Value);

	virtual void ApplyRightForce();
	virtual void ApplyForwardForce();
	virtual void LimitLinearVelocity();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Physics", meta = (AllowPrivateAccess = "true"))
	float MaximumForwardVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Physics", meta = (AllowPrivateAccess = "true"))
	float ForwardThrust;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Physics", meta = (AllowPrivateAccess = "true"))
	float MaximumAngularVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Physics", meta = (AllowPrivateAccess = "true"))
	float RotationalThrust;

	virtual UStaticMeshComponent *GetMesh();

	float ForwardAxis = 0.f;
	float RightAxis = 0.f;
};
