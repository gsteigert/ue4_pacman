#include "PacmanPawn.h"
#include "EnemyPawn.h"
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

    if (!Frozen)
    {
        AddMovementInput(GetActorForwardVector());
    }
}

void APacmanPawn::SetDirection(const FVector direction)
{
    // rotation uses pitch, yaw and roll concepts;
    // given that X is forward, Z is up and Y is right:
    // Pitch = around Y axis, Yaw = around the Z axis, Roll = around the X axis

    if (Frozen) {
        // do nothing
    }
    else if (direction == FVector::UpVector) {
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

    if (AFoodieActor::IsFoodie(otherActor)) {
        Cast<AFoodieActor>(otherActor)->Consume();
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
