// Fill out your copyright notice in the Description page of Project Settings.


#include "ListeningActor.h"

// Sets default values
AListeningActor::AListeningActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AListeningActor::BindToTargetActor(ATargetActor* TargetActor, UAsyncNode* AsyncNode)
{
    if (TargetActor && AsyncNode)
    {
        AsyncNode->BooleanValueChanged.AddDynamic(this, &AListeningActor::DestroyThisActor);
        //TargetActor->OnBooleanChanged.AddDynamic(AsyncNode, &UAsyncNode::BooleanValueChanged.Broadcast);
    }
}

void AListeningActor::DestroyThisActor() {
    Destroy();
}