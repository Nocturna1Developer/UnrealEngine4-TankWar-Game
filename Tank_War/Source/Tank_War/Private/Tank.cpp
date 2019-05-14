// Copyright EmbraceIT Ltd.

#include "../Tank_War/Public/Tank.h"
#include "../Tank_War/Public/TankBarrel.h"
#include "../Tank_War/Public/Projectile.h"
#include "../Tank_War/Public/TankAimingComponent.h"
#include "../Tank_War/Public/Tank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ Construct"), *TankName)
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::AimAt(FVector HitLocation)
{
	// snsures that 
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	//sets a timer so that it only fres witin certain inervals reloads the barrel
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	// Spawns a projectile at the socket location on the barrel and introduces the concept of projectile to the computer
	if (isReloaded)
	{
		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		//resets lasttimefired
		LastFireTime = FPlatformTime::Seconds();
		Projectile->LaunchProjectile(LaunchSpeed);
	}
}
