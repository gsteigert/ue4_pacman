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
    InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacmanController::MoveDownPressed);
    InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacmanController::MoveRightPressed);
    InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacmanController::MoveLeftPressed);
}

void APacmanController::MoveUpPressed()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetDirection(FVector::UpVector);
    }
}

void APacmanController::MoveDownPressed()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetDirection(FVector::DownVector);
    }
}

void APacmanController::MoveRightPressed()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetDirection(FVector::RightVector);
    }
}

void APacmanController::MoveLeftPressed()
{
    if (PAWN_IS_AVAILABLE) {
        GetPacmanPawn()->SetDirection(FVector::LeftVector);
    }
}
