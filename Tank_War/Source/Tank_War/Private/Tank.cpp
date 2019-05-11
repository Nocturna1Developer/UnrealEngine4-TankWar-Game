#include "../Tank_War/Public/Tank.h"
#include "../Tank_War/Public/TankBarrel.h"
#include "../Tank_War/Public/Projectile.h"
#include "../Tank_War/Public/TankAimingComponent.h"
#include "../Tank_War/Public/Tank.h"

ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//CREATES and aiming component in the bluprint editor
	//This is the base for everything, the edior inherites this 
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//CLARIFIES the current tank name is returning the location that has been passed
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

//no parameters beucase it will always point in the direction of the barrel
void ATank::Fire()
{
	//sets a timer so that it only fres witin certain inervals reloads the barrel
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	// Spawns a projectile at the socket location on the barrel and introduces the concept of projectile to the computer
	if (Barrel && isReloaded)
	{
		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		//resets lasttimefired
		LastFireTime = FPlatformTime::Seconds();
	}
}


//helps get start location of barrel
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	//since barrel is now local we have to set it
	//Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
	//Turret = TurretToSet;
}

