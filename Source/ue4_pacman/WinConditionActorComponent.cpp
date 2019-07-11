#include "WinConditionActorComponent.h"
#include "Engine/World.h"
#include "FoodieActor.h"
#include "Kismet/GameplayStatics.h"

UWinConditionActorComponent::UWinConditionActorComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UWinConditionActorComponent::BeginPlay()
{
    Super::BeginPlay();

    TArray<AActor*> actors;
    UGameplayStatics::GetAllActorsOfClass(this, AFoodieActor::StaticClass(), actors);

    for (auto& actor : actors) {
        AFoodieActor* foodie = Cast<AFoodieActor>(actor);
        if (foodie->FoddieType != EFoodieType::Regular) {
            continue;
        }
        RegularFoodiesLeft++;
        foodie->OnFoodieEaten().AddDynamic(this, &UWinConditionActorComponent::OnRegularFoodieEaten);
    }
}

void UWinConditionActorComponent::OnRegularFoodieEaten(EFoodieType foodieType)
{
    if (foodieType != EFoodieType::Regular) {
        UE_LOG(LogTemp, Warning, TEXT("[WinConditionActorComponent] Not a regular foodie [foodieType=%d]"), foodieType);
        return;
    }

    if (IsLevelCompleted()) {
        UE_LOG(LogTemp, Warning, TEXT("[WinConditionActorComponent] Level already completed"));
        return;
    }

    RegularFoodiesLeft--;
    UE_LOG(LogTemp, Log, TEXT("[WinConditionActorComponent] RegularFoodiesLeft=%d"), RegularFoodiesLeft);

    if (RegularFoodiesLeft <= 0)
    {
        UE_LOG(LogTemp, Log, TEXT("[WinConditionActorComponent] Level completed"));

        LevelCompleted = true;

        OnLevelCompleted.Broadcast();
    }
}
