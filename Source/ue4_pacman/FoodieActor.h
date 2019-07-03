#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FoodieActor.generated.h"

class USoundCue;

UENUM()
enum class EFoodieType : uint8 {
    Regular,
    PowerUp
};

UCLASS()
class UE4_PACMAN_API AFoodieActor : public AActor
{
    GENERATED_BODY()
    
public:
    AFoodieActor();
    void Consume();

    DECLARE_EVENT(AFoodieActor, FFoodieEatenEvent)
    FFoodieEatenEvent& OnFoodieEaten() { return FoodieEatenEvent; }

private:
    FFoodieEatenEvent FoodieEatenEvent;

    UPROPERTY(EditAnywhere, Category = "Setup")
    USoundCue* ConsumptionSound;

    UPROPERTY(EditAnywhere, Category = "Setup")
    EFoodieType FoddieType = EFoodieType::Regular;
};
