#include "../Tank_War/Public/TankAIController.h"
#include "../Tank_War/Public/Tank.h"
#include "Tank_War.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

//every frame the AI move toward player, aim toward player, and fires if ready
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		//finds the player tank
		auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
		auto ControlledTank = Cast<ATank>(GetPawn());

		if (PlayerTank)
		{
			// TODO Move towards the player

			// Aim towards the player
			ControlledTank->AimAt(PlayerTank->GetActorLocation());

			//AI fires where the barrel is pointing every frame
			ControlledTank->Fire(); 
		}
}


