#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Delegates/Delegate.h"
#include "AsyncNode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBooleanValueChanged);

UCLASS()
class WELEVELASSESMENT_API UAsyncNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Custom Async Node")
        static UAsyncNode* CreateAsyncNode(UObject* WorldContextObject);

    UPROPERTY(BlueprintAssignable)
        FBooleanValueChanged BooleanValueChanged;

protected:
    UPROPERTY()
        UObject* WorldContextObject;
};
