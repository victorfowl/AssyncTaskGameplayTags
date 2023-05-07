// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "MyGameplayTagActor.generated.h"

UCLASS()
class WELEVELASSESMENT_API AMyGameplayTagActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyGameplayTagActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Tags")
		FGameplayTagContainer OwnedGameplayTags;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
