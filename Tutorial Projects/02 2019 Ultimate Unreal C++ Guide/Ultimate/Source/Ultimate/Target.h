// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class ULTIMATE_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* TargetMesh;

	FVector MoveDirection;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MoveScale;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
};
