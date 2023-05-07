#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameplayTagContainer.h"
#include "MyGameplayTagActor.h"
#include "Delegates/Delegate.h"
#include "AsyncTaskGameplayTagChanged.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleMulticastDelegateCustom);

UCLASS()
class UAsyncTaskGameplayTagChanged : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
        FSimpleMulticastDelegateCustom OnGameplayTagChanged;

    UFUNCTION(BlueprintCallable)
        static UAsyncTaskGameplayTagChanged* WaitForGameplayTagChange(AMyGameplayTagActor* targetActor, AActor* listenerActor);

private:
    virtual void Activate() override;

    AMyGameplayTagActor* targetActor;
    AActor* listenerActor;
    FTimerHandle TimerHandle;
    FGameplayTagContainer InitialGameplayTagContainer;
    // Use this in case you only want to use one gameplay tag
    //FGameplayTag InitialGameplayTag;
    void CheckGameplayTag();
};
