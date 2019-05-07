#include "PacmanController.h"
#include "Math/Vector.h"

#define PAWN_IS_AVAILABLE GetPawn() != nullptr

APacmanPawn* APacmanController::GetPacmanPawn() const
{
    return Cast<APacmanPawn>(GetPawn());
}

void APacmanController::SetupInputComponent()
{
    Super::SetupInputComponent();
    UE_LOG(LogTemp, Log, TEXT("[PacmanController] SetupInputComponent()"));

    InputComponent->BindAction("MoveUp", IE_Pressed, this, &APacmanController::MoveUpPressed);
    InputComponent->BindAction("MoveUp", IE_Released, this, &APacmanController::MoveUpOrDownReleased);
    InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacmanController::MoveDownPressed);
    InputComponent->BindAction("MoveDown", IE_Released, this, &APacmanController::MoveUpOrDownReleased);
    InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacmanController::MoveRightPressed);
    InputComponent->BindAction("MoveRight", IE_Released, this, &APacmanController::MoveRightOrLeftReleased);
    InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacmanController::MoveLeftPressed);
    InputComponent->BindAction("MoveLeft", IE_Released, this, &APacmanController::MoveRightOrLeftReleased);
}

void APacmanController::MoveUpPressed()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetVerticalMovementInput(1.0f);
    }
}

void APacmanController::MoveDownPressed()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetVerticalMovementInput(-1.0f);
    }
}

void APacmanController::MoveUpOrDownReleased()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetVerticalMovementInput(0.0f);
    }
}

void APacmanController::MoveRightPressed()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetHorizontalMovementInput(1.0f);
    }
}

void APacmanController::MoveLeftPressed()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetHorizontalMovementInput(-1.0f);
    }
}

void APacmanController::MoveRightOrLeftReleased()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetHorizontalMovementInput(0.0f);
    }
}
