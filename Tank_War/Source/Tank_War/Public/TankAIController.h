#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class TANK_WAR_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	//returns a frame by frame
	virtual void Tick(float DeltaSeconds) override;
	
	//trying to get player controller here
	ATank* GetPlayerTank() const;
	
};
