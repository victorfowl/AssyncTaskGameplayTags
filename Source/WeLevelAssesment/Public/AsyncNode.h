#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TargetActor.h"
#include "ListeningActor.h"
#include "AsyncNode.generated.h"

UCLASS()
class WELEVELASSESMENT_API UAsyncNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

    //Creation of the async node
    UFUNCTION(BlueprintCallable, Category = "Custom Async Node")
        static UAsyncNode* CreateAsyncNode(AActor* ListeningActor, ATargetActor* TargetActor);

    virtual void Activate() override;

    //Function to execute the end of the async node
    UFUNCTION()
        void OnBooleanValueChanged();


private:
    AActor* ListeningActor;
    ATargetActor* TargetActor;
};
