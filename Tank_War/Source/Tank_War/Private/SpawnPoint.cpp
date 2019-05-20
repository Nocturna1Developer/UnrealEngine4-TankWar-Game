// Copyright EmbraceIT Ltd.


#include "../Tank_War/Public/SpawnPoint.h"
#include "Kismet/GameplayStatics.h"
#include "Tank_War.h"


USpawnPoint::USpawnPoint()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Spawns a actor, protects it, and attaches it to the SpwanPointcomponent (NewActor)
// This will prevent any blueprint construction scripts call begin play after the initial setup is done
// If spawned actor is null attach the right componenets
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	SpawnedActor = GetWorld()->SpawnActorDeferred<AActor>(SpawnClass, GetComponentTransform());
	if (!SpawnedActor) return;
	SpawnedActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	UGameplayStatics::FinishSpawningActor(SpawnedActor, GetComponentTransform());
}


// Called every frame
void USpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

