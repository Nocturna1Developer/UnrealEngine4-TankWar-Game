// Copyright EmbraceIT Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// this is becuase we need many diffrent states for out aiming reticle
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};


//tells the system that a tank barrel exists, forward declaration
class UTankBarrel;
class UTankTurret;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANK_WAR_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	//tells the tank to start aiming at a paticular spot
	void AimAt(FVector HitLocation, float LaunchSpeed);

	void MoveBarrelTowards(FVector AimDirection);

// Protect this beucase we asking this to refrence this property from subclass Aiming componenet blueprint
// C++ is the parent, blueprint is the subclasss
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;

private:
	//use the 'U' beucase its a codeing standard, it a a class that inherits from UObject 
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UTankAimingComponent();
	
};
