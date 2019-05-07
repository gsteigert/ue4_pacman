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

    AddMovementInput(VerticalDirection + HorizontalDirection);
}

void APacmanPawn::SetVerticalMovementInput(const float value) {
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] SetVerticalMovementInput(%d)"), value);

    VerticalDirection = FVector::UpVector * FMath::Clamp(value, -1.0f, 1.0f);
}

void APacmanPawn::SetHorizontalMovementInput(const float value) {
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] SetHorizontalMovementInput(%d)"), value);

    HorizontalDirection = FVector::RightVector * FMath::Clamp(value, -1.0f, 1.0f);
}
