// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncNode.h"

UAsyncNode* UAsyncNode::CreateAsyncNode(UObject* WorldContextObject)
{
    UAsyncNode* Node = NewObject<UAsyncNode>();
    Node->WorldContextObject = WorldContextObject;
    return Node;
}