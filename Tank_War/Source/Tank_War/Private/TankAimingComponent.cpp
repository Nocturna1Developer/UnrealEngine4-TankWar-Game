#include "../Tank_War/Public/TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../Tank_War/Public/TankBarrel.h"
#include "Tank_War.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// get the name of the thing the tank is aiming at
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//we do this to protect the barrel and prevent errors
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	// gets the socket from the barrel asset we creeated
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	//if we have a solution move to the next code block
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	// calls the move barrel function 
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	// If no solution found do nothing
}

// MoveBarrelTowards at paticular aim direction
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// gets the x direction of the barrel to get ,rotation gets yaw, pitch, and roll
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	//gets the diff of roation
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(5);
}