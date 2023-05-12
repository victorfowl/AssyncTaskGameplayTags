#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/Delegate.h"
#include "TargetActor.generated.h"

//Declaration of the event dispatcher.
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBooleanChanged);

UCLASS()
class WELEVELASSESMENT_API ATargetActor : public AActor
{
	GENERATED_BODY()

private:

    bool bBoolean;
	
public:	
	ATargetActor();

    //Event dispatcher to know when the boolean changes.
    UPROPERTY(BlueprintAssignable, Category = "Target Actor")
        FBooleanChanged OnBooleanChanged;

    //Setter of the boolean
    UFUNCTION(BlueprintCallable, Category = "Target Actor")
        void SetBooleanValue(bool NewValue);

    //Getter of the boolean
    UFUNCTION(BlueprintCallable, Category = "Target Actor")
        bool GetBooleanValue();
};
