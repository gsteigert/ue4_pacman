#include "PacmanController.h"
#include "Runtime/Core/Public/Math/Vector.h"

APacmanPawn* APacmanController::GetPacmanPawn() {
	return Cast<APacmanPawn>(GetPawn());
}

void APacmanController::SetupInputComponent() {
	Super::SetupInputComponent();
	UE_LOG(LogTemp, Log, TEXT("[PacmanController] SetupInputComponent()"));

	InputComponent->BindAction("MoveUp", IE_Pressed, this, &APacmanController::MoveUp);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacmanController::MoveDown);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacmanController::MoveLeft);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacmanController::MoveRight);
}

void APacmanController::MoveUp() {
	UE_LOG(LogTemp, Log, TEXT("[PacmanController] MoveUp()"));
	GetPacmanPawn()->SetDirection(FVector::UpVector);
}

void APacmanController::MoveDown() {
	UE_LOG(LogTemp, Log, TEXT("[PacmanController] MoveDown()"));
	GetPacmanPawn()->SetDirection(FVector::DownVector);
}

void APacmanController::MoveLeft() {
	UE_LOG(LogTemp, Log, TEXT("[PacmanController] MoveLeft()"));
	GetPacmanPawn()->SetDirection(FVector::LeftVector);
}

void APacmanController::MoveRight() {
	UE_LOG(LogTemp, Log, TEXT("[PacmanController] MoveRight()"));
	GetPacmanPawn()->SetDirection(FVector::RightVector);
}
