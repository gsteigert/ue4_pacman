#include "FoodieActor.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

AFoodieActor::AFoodieActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AFoodieActor::Consume()
{
    UE_LOG(LogTemp, Log, TEXT("[%s] Consuming self"), *GetName());

    UGameplayStatics::PlaySound2D(this, RegularFoodieConsumptionSound);
    FoodieEatenEvent.Broadcast();
    Destroy();
}
