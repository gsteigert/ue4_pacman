#include "PacmanController.h"
#include "Runtime/Core/Public/Math/Vector.h"

APacmanPawn* APacmanController::GetPacmanPawn() {
    return Cast<APacmanPawn>(GetPawn());
}

void APacmanController::SetupInputComponent() {
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

void APacmanController::MoveUpPressed() {
    GetPacmanPawn()->SetVerticalMovementInput(1.0f);
}

void APacmanController::MoveDownPressed() {
    GetPacmanPawn()->SetVerticalMovementInput(-1.0f);
}

void APacmanController::MoveUpOrDownReleased() {
    GetPacmanPawn()->SetVerticalMovementInput(0.0f);
}

void APacmanController::MoveRightPressed() {
    GetPacmanPawn()->SetHorizontalMovementInput(1.0f);
}

void APacmanController::MoveLeftPressed() {
    GetPacmanPawn()->SetHorizontalMovementInput(-1.0f);
}

void APacmanController::MoveRightOrLeftReleased() {
    GetPacmanPawn()->SetHorizontalMovementInput(0.0f);
}
