// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include

UCLASS()
class TANK_WAR_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
//prototypes the functions
private:
	ATank* GetControlledTank() const;
	
	//makes sure somthing else is up the inheritance tree with same excat name
	virtual void BeginPlay() override;

	//frame by frame
	virtual void Tick(float DeltaTime) override;

	// Start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	//gets the location of the dot
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	//how far the crosshaor can detect
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	//this will tell us the direction we are pointing at in the world (up, down etc.)
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	//return the location that the crosshair is on
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
