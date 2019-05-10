// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Tank_War/Public/TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UProjectileComponent;
class AProjectile;

UCLASS()
class TANK_WAR_API ATank : public APawn
{
	GENERATED_BODY()

//hits the thing the line trace hits
public:
	// makes a method we can acctaully call from blueprint called 'setbarrelrefrence'
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// makes a method we can acctaully call from blueprint called 'setturretrefence'
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	//doesnt need a category beucase we wont chose this on the right hand side
	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	void AimAt(FVector HitLocation);

	//limits frame by frame shots
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

// the name comes from tankaimingcomponenet.cpp has the ability to have an refrence
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//makes a variable in the unreal editor like serializefeild
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000;

	//enforces Udamagetype classes and narrows our chouses to only projectile classes
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;
	
	
};
