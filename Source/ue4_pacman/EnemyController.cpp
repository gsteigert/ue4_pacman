#include "EnemyController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "EnemyPawn.h"

void AEnemyController::Tick(float deltaTime)
{
    APawn* pacman = GetWorld()->GetFirstPlayerController()->GetPawn();
    APawn* enemy = GetPawn();

    if (pacman && enemy) {
        UE_LOG(LogTemp, Log, TEXT("[%s] Chase Pacman requested"), *enemy->GetName());

        // The following call requests an AI path find towards the given actor (Pacman);
        // If a path is found, it will invoke UEnemyMovementComponent::RequestDirectMove(...) at some point
        MoveToActor(pacman, 10.0f);
    }
}
