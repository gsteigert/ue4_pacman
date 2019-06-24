#include "EnemyPawn.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "AIController.h"

void AEnemyPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!Frozen)
    {
        APawn* pacman = GetWorld()->GetFirstPlayerController()->GetPawn();
        AAIController* aiController = Cast<AAIController>(GetController());

        aiController->MoveToActor(pacman, 0.0f, false);
    }
}
