// Cred to Udemy

#include "../Tank_War/Public/TankBarrel.h"
#include "Tank_War.h"


//
void UTankBarrel::Elevate(float RelativeSpeed)
{
	//controls how fast barrel moves 
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	//now we can actually move the barrel up and down 
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	//we have to clamp the rotation to prevent the barrel from looking weird
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	
	//sets the yaw and roll
	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}
