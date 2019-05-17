// Copyright EmbraceIT Ltd.

#include "../Tank_War/Public/Tank.h"
#include "Tank_War.h"

// We want the percenatge becuase we need to implement it in the bluprint editor
float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}
// Always starts the game at full health and super prevents game from being broken
void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

// The float was copy and pasted
float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	// Rounds the defualt float DamageAmount to DamagePoints
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return DamageToApply;
}