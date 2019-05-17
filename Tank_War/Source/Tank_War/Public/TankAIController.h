#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class TANK_WAR_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	// When the pawn is possesed this gets called
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossedTankDeath();
};

