// Copyright EmbraceIT Ltd.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include

class UTankTankAimingComponent;

UCLASS()
class TANK_WAR_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
// Responsible for helping the player aim.
protected:
	// protected because the blueprint we are using this in is a subclass
	// this is like our 'Event Play' function in blurprint that passes a aiming comp refrence
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);
	
private:
	//makes sure somthing else is up the inheritance tree with same excat name
	virtual void BeginPlay() override;

	//frame by frame
	virtual void Tick(float DeltaTime) override;

	// Start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	//gets the location of the dot
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	//how far the crosshaor can detect
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	//this will tell us the direction we are pointing at in the world (up, down etc.)
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	//return the location that the crosshair is on
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
