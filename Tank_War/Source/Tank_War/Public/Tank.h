// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANK_WAR_API ATank : public APawn
{
	GENERATED_BODY()

//hits the thing the line trace hits
public:
	void AimAt(FVector HitLocation);

	// makes a method we can acctaully call from blueprint called 'setbarrelrefrence'
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

// the name comes from tankaimingcomponenet.cpp has the ability to have an refrence
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//makes a variable in the unreal editor like serializefeild
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000;
	
	
};
