#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class TANK_WAR_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	//returns a frame by frame
	virtual void Tick(float DeltaSeconds) override;
	
	// How close can the AI tank get
	float AcceptanceRadius = 3000;

};
