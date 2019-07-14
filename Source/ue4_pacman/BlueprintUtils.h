#pragma once

#include "GameFramework/Actor.h"

class UE4_PACMAN_API BlueprintUtils {
public:
    template <class VarType>
    static void SetProperty(AActor* actor, FName propertyName, VarType newValue);
};

template<class VarType>
inline void BlueprintUtils::SetProperty(AActor * actor, FName propertyName, VarType newValue)
{
    checkf(actor, TEXT("Actor cannot be null"));

    UProperty* property = actor->GetClass()->FindPropertyByName(propertyName);

    checkf(property, TEXT("Property not found in %s: '%s'"),
        *actor->GetName(), *propertyName.ToString());

    VarType* ptrValue = property->ContainerPtrToValuePtr<VarType>(actor);

    checkf(ptrValue, TEXT("Container pointer not found in %s: %s"),
        *actor->GetName(), *propertyName.ToString());

    *ptrValue = newValue;
}
