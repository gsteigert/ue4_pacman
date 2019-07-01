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

    if (!Frozen)
    {
        AddMovementInput(GetActorForwardVector());
    }
}

void APacmanPawn::SetDirection(const FVector direction)
{
    // imagine an airplane making these rotational movements and you'll end up with:
    // Pitch = around Y axis, Yaw = around the Z axis, Roll = around the X axis

    if (direction == FVector::UpVector) {
        SetActorRotation(FRotator(0, 270, 0));
    }
    else if (direction == FVector::DownVector) {
        SetActorRotation(FRotator(0, 90, 0));
    }
    else if (direction == FVector::RightVector) {
        SetActorRotation(FRotator(0, 0, 0));
    }
    else if (direction == FVector::LeftVector) {
        SetActorRotation(FRotator(0, 180, 180));
    }
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
