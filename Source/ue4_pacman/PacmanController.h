#pragma once

#include "PacmanPawn.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PacmanController.generated.h"

/**
 * Controls the player's Pacman pawn.
 *
 * Startup flow: SetupInputComponent, SetPlayer, SetPawn (multiple times), BeginPlayingState, OnPossess, BeginPlay
 * Shutdown flow: SetPawn, OnUnPossess, SetPawn, OnUnPossess
 */
UCLASS()
class UE4_PACMAN_API APacmanController : public APlayerController
{
    GENERATED_BODY()

protected:
    void SetupInputComponent() override;
    APacmanPawn* GetPacmanPawn();

    UFUNCTION(BlueprintCallable)
    void MoveUp();
    UFUNCTION(BlueprintCallable)
    void MoveDown();
    UFUNCTION(BlueprintCallable)
    void MoveLeft();
    UFUNCTION(BlueprintCallable)
    void MoveRight();

};
