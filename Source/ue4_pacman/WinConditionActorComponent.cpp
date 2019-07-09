#include "WinConditionActorComponent.h"
#include "FoodieActor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

UWinConditionActorComponent::UWinConditionActorComponent()
{
    //PrimaryComponentTick.bCanEverTick = true;
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
    RegularFoodiesLeft--;

    UE_LOG(LogTemp, Log, TEXT("[WinConditionActorComponent] RegularFoodiesLeft=%d"), RegularFoodiesLeft);

    if (RegularFoodiesLeft <= 0)
    {
        // do something
    }
}
