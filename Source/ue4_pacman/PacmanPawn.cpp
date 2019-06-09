#include "PacmanPawn.h"
#include "FoodieActor.h"

APacmanPawn::APacmanPawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APacmanPawn::BeginPlay()
{
    Super::BeginPlay();

    OnActorHit.AddDynamic(this, &APacmanPawn::OnHit);
    OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
}

void APacmanPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AddMovementInput(VerticalDirection + HorizontalDirection);
}

void APacmanPawn::SetVerticalMovementInput(const float value) {
    //UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] SetVerticalMovementInput(%f)"), value);

    VerticalDirection = GetActorUpVector() * FMath::Clamp(value, -1.0f, 1.0f);
}

void APacmanPawn::SetHorizontalMovementInput(const float value) {
    //UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] SetHorizontalMovementInput(%f)"), value);

    HorizontalDirection = GetActorRightVector() * FMath::Clamp(value, -1.0f, 1.0f);
}

void APacmanPawn::OnOverlapBegin(AActor* overlappedActor, AActor* otherActor)
{
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] OnOverlapBegin(overlappedActor=%s, otherActor=%s)"),
        *overlappedActor->GetName(), *otherActor->GetName());

    if (otherActor->ActorHasTag("Foodie.Regular")) {
        ConsumeRegularFoodie(Cast<AFoodieActor>(otherActor));
    }
}

void APacmanPawn::ConsumeRegularFoodie(AFoodieActor* foodie)
{
    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] ConsumeRegularFoodie(%s)"), *foodie->GetName());

    foodie->Consume();
}

void APacmanPawn::OnHit(AActor* selfActor, AActor* otherActor, FVector normalImpulse, const FHitResult& hit)
{
    if (otherActor->ActorHasTag("Enemy")) {
        UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] OnHit(otherActor=%s, hit=%s)"),
            *otherActor->GetName(), *hit.ToString());

        Die();
    }
}

void APacmanPawn::Die()
{
    // avoid multiple die events from being thrown
    if (IsPendingKillPending()) {
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("[PacmanPawn] Die()"));

    PacmanDiedEvent.Broadcast();
    Destroy();
}
