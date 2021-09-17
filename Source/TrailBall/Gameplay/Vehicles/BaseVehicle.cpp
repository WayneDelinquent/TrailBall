// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseVehicle.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ABaseVehicle::ABaseVehicle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseModelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	RootComponent = BaseModelMesh;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	SplineSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spline Spawn Point"));
	SplineSpawnPoint->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseVehicle::BeginPlay()
{
	Super::BeginPlay();
	GetMesh()->SetPhysicsMaxAngularVelocityInDegrees(MaximumAngularVelocity);
}

// Called every frame
void ABaseVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ApplyRightForce();
	ApplyForwardForce();
	LimitLinearVelocity();
}

// Called to bind functionality to input
void ABaseVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("ForwardAxis", this, &ABaseVehicle::CalculateForwardAxis);
	PlayerInputComponent->BindAxis("RightAxis", this, &ABaseVehicle::CalculateRightAxis);
}

USceneComponent* ABaseVehicle::GetSplineSpawnPoint() 
{
	return SplineSpawnPoint;
}

void ABaseVehicle::CalculateForwardAxis(float Value) 
{
	ForwardAxis = Value;
}

void ABaseVehicle::CalculateRightAxis(float Value)
{
	RightAxis = Value;
}

void ABaseVehicle::ApplyRightForce()
{
	UE_LOG(LogTemp, Error, TEXT("You have not implemented a function to Apply Right Force"));
}

void ABaseVehicle::ApplyForwardForce()
{
	UE_LOG(LogTemp, Error, TEXT("You have not implemented a function to Apply Forward Force"));
}

void ABaseVehicle::LimitLinearVelocity() 
{
	FVector CurrentVelocity = BaseModelMesh->GetPhysicsLinearVelocity().GetClampedToMaxSize(MaximumForwardVelocity);
	BaseModelMesh->SetPhysicsLinearVelocity(CurrentVelocity);
}

UStaticMeshComponent* ABaseVehicle::GetMesh() 
{
	return BaseModelMesh;
}
