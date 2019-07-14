#include "EnemyPawn.h"

void AEnemyPawn::Hunt()
{
    UE_LOG(LogTemp, Log, TEXT("[%s] Hunt()"), *GetName());

    state = EEnemyState::Default;

    StateChangedEvent.Broadcast(state);
}

void AEnemyPawn::Run()
{
    UE_LOG(LogTemp, Log, TEXT("[%s] Run()"), *GetName());

    state = EEnemyState::Vulnerable;

    StateChangedEvent.Broadcast(state);
}

void AEnemyPawn::Die()
{
    UE_LOG(LogTemp, Log, TEXT("[%s] Die()"), *GetName());

    state = EEnemyState::Dead;

    StateChangedEvent.Broadcast(state);
}
