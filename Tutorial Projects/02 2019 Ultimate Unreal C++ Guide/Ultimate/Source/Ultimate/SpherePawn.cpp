// Fill out your copyright notice in the Description page of Project Settings.


#include "SpherePawn.h"
#include <GameFramework/FloatingPawnMovement.h>
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "Bullet.h"

// Sets default values
ASpherePawn::ASpherePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

    CameraArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	CameraArm->SetupAttachment(StaticMesh);
	CameraArm->TargetArmLength = 500.0f;

    Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	//Camera->SetRelativeLocation(FVector(-500.f, 0, 0));
	Camera->SetupAttachment(CameraArm);

	SetRootComponent(StaticMesh);

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
}

// Called when the game starts or when spawned
void ASpherePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpherePawn::MoveForward(float Amount)
{
	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * Amount);
}

void ASpherePawn::MoveRight(float Amount)
{
    FloatingPawnMovement->AddInputVector(GetActorRightVector() * Amount);
}

void ASpherePawn::Turn(float Amount)
{
	AddControllerYawInput(Amount);
}

void ASpherePawn::LookUp(float Amount)
{
	AddControllerPitchInput(Amount);
}

void ASpherePawn::Shoot()
{
	if (BulletClass) {
		FActorSpawnParameters spawnParams;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		spawnParams.bNoFail = true;
		spawnParams.Owner = this;
		spawnParams.Instigator = this;

		FTransform bulletSpawnTransform;
		bulletSpawnTransform.SetLocation(GetActorLocation() + GetActorForwardVector() * 500.0f);
		bulletSpawnTransform.SetRotation(GetActorRotation().Quaternion());
		GetWorld()->SpawnActor<ABullet>(BulletClass, bulletSpawnTransform, spawnParams);
	}
}

// Called every frame
void ASpherePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpherePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASpherePawn::Shoot);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASpherePawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASpherePawn::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ASpherePawn::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASpherePawn::LookUp);
}

