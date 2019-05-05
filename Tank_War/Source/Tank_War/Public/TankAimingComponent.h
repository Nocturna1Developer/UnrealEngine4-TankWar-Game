// Cred to Udemy

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//tells the system that a tank barrel exists forward declaration
class UTankBarrel;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_WAR_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// the barrel is a static mesh componenet
	// we use this to allow a refrence to the starting of the barrel
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	//tells the tank to start aiming at a paticular spot
	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	//use the 'U' beucase its a codeing standard, it a a class that inherits from UObject 
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
