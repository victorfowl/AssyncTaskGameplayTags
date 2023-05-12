// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncNode.h"

UAsyncNode* UAsyncNode::CreateAsyncNode(AActor* ListeningActor, ATargetActor* TargetActor)
{
    UAsyncNode* Node = NewObject<UAsyncNode>();
    Node->ListeningActor = ListeningActor;
    Node->TargetActor = TargetActor;
    return Node;
}

void UAsyncNode::Activate()
{
    if (TargetActor)
    {
        // Bind the listening actor to the target actor's event dispatcher
        TargetActor->OnBooleanChanged.AddDynamic(this, &UAsyncNode::OnBooleanValueChanged);
    }

    // Call the parent Activate function to start the async task
    Super::Activate();
}

void UAsyncNode::OnBooleanValueChanged()
{
    if (ListeningActor)
    {
        // Destroy the listening actor
        ListeningActor->Destroy();
    }
    // Call the parent SetReadyToDestroy function to complete the async task
    SetReadyToDestroy();
}