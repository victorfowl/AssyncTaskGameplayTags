// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsyncNode.h"
#include "TargetActor.h"
#include "Delegates/DelegateSignatureImpl.inl"
#include "ListeningActor.generated.h"

UCLASS()
class WELEVELASSESMENT_API AListeningActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AListeningActor();

	UFUNCTION(BlueprintCallable, Category = "Listening Actor")
		void BindToTargetActor(ATargetActor* TargetActor, UAsyncNode* AsyncNode);

	void DestroyThisActor();

};
