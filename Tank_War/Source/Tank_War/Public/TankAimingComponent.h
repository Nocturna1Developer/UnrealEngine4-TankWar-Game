// Cred to Udemy

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_WAR_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// the barrel is a static mesh componenet
	// we use this to allow a refrence to the starting of the barrel
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//tells the tank to start aiming at a paticular spot
	void AimAt(FVector HitLocation, float LaunchSpeed);

//use the 'U' beucase its a codeing standard, it a a class that inherits from UObject 
private:
	UStaticMeshComponent* Barrel = nullptr;
};
