// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

// Sets default values
ATarget::ATarget()
	: MoveScale(200)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>("TargetMesh");
	SetRootComponent(TargetMesh);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
	MoveDirection = FMath::VRand();
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MoveDelta = MoveDirection * MoveScale *
		(FMath::Sin(GetWorld()->GetTimeSeconds() + DeltaTime) - FMath::Sin(GetWorld()->GetTimeSeconds()));

	AddActorWorldOffset(MoveDelta, true);
}

