// Cred to Udemy

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

// allows us to hide certain categoires and specfies class to use
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANK_WAR_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//we want to be able to elevate the barrel
	void Elevate(float DegreesPerSecond);

private:
	// adds serializable feilds in Tank_BP 
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;

	
};
