// Copyright EmbraceIT Ltd.

#pragma once

#include "../Tank_War/Public/TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UProjectileComponent;
class UTankMovementComponent;
class AProjectile;

// 'editduafualts' basically means each actor must have the same value 
// only lets you chnage it in the blueprint editor

UCLASS()
class TANK_WAR_API ATank : public APawn
{
	GENERATED_BODY()

//hits the thing the line trace hits
public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	void AimAt(FVector HitLocation);

// the name comes from tankaimingcomponenet.cpp has the ability to have an refrence
protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	// will allow us to drag the component to the blueprint editor
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	//makes a variable in the unreal editor like serializefeild
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;;

	//enforces Udamagetype classes and narrows our chouses to only projectile classes
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//limits frame by frame shots
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	
	
	
};
