// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/Delegate.h"
#include "TargetActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBooleanChanged);

UCLASS()
class WELEVELASSESMENT_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetActor();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Actor")
        bool bBooleanValue;

    UPROPERTY(BlueprintAssignable, Category = "Target Actor")
        FBooleanChanged OnBooleanChanged;

    UFUNCTION(BlueprintCallable, Category = "Target Actor")
        void SetBooleanValue(bool NewValue);
};
