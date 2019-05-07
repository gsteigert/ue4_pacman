#include "PacmanPawn.h"
#include "FoodieActor.h"

APacmanPawn::APacmanPawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APacmanPawn::BeginPlay()
{
    Super::BeginPlay();

    OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
}

void APacmanPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AddMovementInput(VerticalDirection + HorizontalDirection);
}

void APacmanPawn::SetVerticalMovementInput(const float value) {
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] SetVerticalMovementInput(%d)"), value);

    VerticalDirection = FVector::UpVector * FMath::Clamp(value, -1.0f, 1.0f);
}

void APacmanPawn::SetHorizontalMovementInput(const float value) {
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] SetHorizontalMovementInput(%d)"), value);

    HorizontalDirection = FVector::RightVector * FMath::Clamp(value, -1.0f, 1.0f);
}

void APacmanPawn::OnOverlapBegin(AActor* overlappedActor, AActor* otherActor)
{
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] OnOverlapBegin(overlappedActor=%s, otherActor=%s)"),
        *overlappedActor->GetName(), *otherActor->GetName());

    if (otherActor->ActorHasTag("Foodie.Regular")) {
        ConsumeRegularFoodie(Cast<AFoodieActor>(otherActor));
    }
}

void APacmanPawn::ConsumeRegularFoodie(AFoodieActor* foodie) {
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] ConsumeRegularFoodie(%s)"), *foodie->GetName());

    foodie->Consume();
}
