#include "FoodieActor.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

AFoodieActor::AFoodieActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AFoodieActor::BeginPlay()
{
    Super::BeginPlay();

    ShowRandomMesh();
}

void AFoodieActor::ShowRandomMesh()
{
    USceneComponent* sceneRoot = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("SceneRoot")));
    checkf(sceneRoot != nullptr, TEXT("Foodie needs a SceneRoot component with one or more static meshes"));

    TArray<USceneComponent*> children;
    sceneRoot->GetChildrenComponents(false, children);
    checkf(children.Num() > 0, TEXT("Foodie needs a SceneRoot component with one or more static meshes"));

    for (auto& child : children) {
        child->SetVisibility(false);
    }

    int32 randomIndex = FMath::RandRange(0, children.Num() - 1);
    children[randomIndex]->SetVisibility(true);
}

void AFoodieActor::Consume()
{
    UE_LOG(LogTemp, Log, TEXT("[%s] Consuming self [type=%d]"), *GetName(), FoddieType);

    UGameplayStatics::PlaySound2D(this, ConsumptionSound);
    FoodieEatenEvent.Broadcast();
    Destroy();
}

bool AFoodieActor::IsFoodie(AActor* actor) {
    return actor->ActorHasTag("Foodie.Regular")
        || actor->ActorHasTag("Foodie.PowerUp")
        || actor->ActorHasTag("Foodie.Fruit");
}
