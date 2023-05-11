// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"

// Sets default values
ATargetActor::ATargetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ATargetActor::SetBooleanValue(bool NewValue)
{
    if (bBooleanValue != NewValue)
    {
        bBooleanValue = NewValue;
        OnBooleanChanged.Broadcast();
    }
}
