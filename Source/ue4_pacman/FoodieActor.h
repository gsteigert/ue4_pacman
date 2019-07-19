#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FoodieActor.generated.h"

class USoundCue;

UENUM()
enum class EFoodieType : uint8 {
    Regular,
    PowerUp,
    Fruit
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoodieEatenEvent, EFoodieType, foodieType);

UCLASS()
class UE4_PACMAN_API AFoodieActor : public AActor
{
    GENERATED_BODY()
    
public:
    AFoodieActor();
    virtual void BeginPlay() override;
    void Consume();
    static bool IsFoodie(AActor* actor);
    FFoodieEatenEvent& OnFoodieEaten() { return FoodieEatenEvent; }

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FFoodieEatenEvent FoodieEatenEvent;

    UPROPERTY(EditAnywhere, Category = "Setup")
    EFoodieType FoddieType = EFoodieType::Regular;

private:
    UPROPERTY(EditAnywhere, Category = "Setup")
    USoundCue* ConsumptionSound;

    void ShowRandomMesh();
};
