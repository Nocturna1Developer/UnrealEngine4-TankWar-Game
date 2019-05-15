#include "../Tank_War/Public/TankAIController.h"
#include "../Tank_War/Public/TankAimingComponent.h"
#include "Tank_War.h"

// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

//every frame the AI move toward player, aim toward player, and fires if ready
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move towards the player (PathFinding)
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aims towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fires towards the player
	AimingComponent->Fire(); 
		
}


