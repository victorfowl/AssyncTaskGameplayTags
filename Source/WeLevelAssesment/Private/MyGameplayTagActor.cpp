// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameplayTagActor.h"

// Sets default values
AMyGameplayTagActor::AMyGameplayTagActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyGameplayTagActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyGameplayTagActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

