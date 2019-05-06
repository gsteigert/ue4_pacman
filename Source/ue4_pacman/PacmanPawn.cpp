#include "PacmanPawn.h"

APacmanPawn::APacmanPawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APacmanPawn::BeginPlay()
{
    Super::BeginPlay();
}

void APacmanPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector velocity = Direction * Speed * DeltaTime;
    FVector newLocation = GetActorLocation() + velocity;

    SetActorLocation(newLocation);
}

void APacmanPawn::SetDirection(const FVector& direction) {
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] SetDirection(%s)"), *direction.ToString());
    Direction = direction;
}
