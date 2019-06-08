#include "EnemyPawn.h"
#include "EnemyPawnMovement.h"

AEnemyPawn::AEnemyPawn()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AEnemyPawn::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
