#include "../Tank_War/Public/TankAIController.h"
#include "Tank_War.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(PlayerTank->GetName()));
	}
}

//every frame the AI move toward player, aim toward player, and fires if ready
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
}

//this is so we determine what tank is being contolled, the AI or human?
ATank* ATankAIController::GetControlledTank() const
{
	//gets the current tank
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{
	//gets the player tank here and the pawn of the tank
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!PlayerTank)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);

	

}


