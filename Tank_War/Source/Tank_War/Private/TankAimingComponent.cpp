#include "../Tank_War/Public/TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../Tank_War/Public/TankBarrel.h"
#include "../Tank_War/Public/TankTurret.h"
#include "Tank_War.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

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
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	// calls the move barrel function 
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

// MoveBarrelTowards at paticular aim direction
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!Barrel || !Turret) { return; }

	// gets the x direction of the barrel to get ,rotation gets yaw, pitch, and roll
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	//gets the diff of roation
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

