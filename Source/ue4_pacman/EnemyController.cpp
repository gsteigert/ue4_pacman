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
        //UE_LOG(LogTemp, Log, TEXT("[%s] Chase Pacman requested"), *enemy->GetName());

        // The following call requests an AI path movement towards Pacman;
        // The goal here is to actually collide with Pacman
        MoveToActor(pacman, 0.0f, false);
    }
}
