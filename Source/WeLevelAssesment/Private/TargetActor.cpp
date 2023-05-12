#include "TargetActor.h"

ATargetActor::ATargetActor()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ATargetActor::SetBooleanValue(bool NewValue)
{
    if (bBoolean != NewValue)
    {
        bBoolean = NewValue;
        OnBooleanChanged.Broadcast();
    }
}

bool ATargetActor::GetBooleanValue()
{
    return bBoolean;
}