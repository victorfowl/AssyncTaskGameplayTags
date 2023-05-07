#include "AsyncTaskGameplayTagChanged.h"
#include "GameplayTagContainer.h"

UAsyncTaskGameplayTagChanged* UAsyncTaskGameplayTagChanged::WaitForGameplayTagChange(AMyGameplayTagActor* targetActor, AActor* listenerActor)
{
    // Create the object AsyncTaskGamePlayTagChanged and set variables
    UAsyncTaskGameplayTagChanged* AsyncTask = NewObject<UAsyncTaskGameplayTagChanged>();
    AsyncTask->targetActor = targetActor;
    AsyncTask->listenerActor = listenerActor;
    AsyncTask->InitialGameplayTagContainer = targetActor != nullptr ? targetActor->OwnedGameplayTags : FGameplayTagContainer();
    // Use this in case you only want to use one gameplay tag
    //AsyncTask->InitialGameplayTag = targetActor != nullptr ? targetActor->OwnedGameplayTag : FGameplayTag();
    return AsyncTask;
}
void UAsyncTaskGameplayTagChanged::Activate()
{
    //Check if both actors are valid and if so execute first time the function.
    if (targetActor && listenerActor)
        GEngine->GetWorldFromContextObject(targetActor, EGetWorldErrorMode::LogAndReturnNull)->GetTimerManager().SetTimer(TimerHandle, this, &UAsyncTaskGameplayTagChanged::CheckGameplayTag, 0.2f);
}

void UAsyncTaskGameplayTagChanged::CheckGameplayTag()
{
    // Get the actual gameplay tag
    FGameplayTagContainer CurrentGameplayTagContainer = targetActor->OwnedGameplayTags;
    // Check if the gameplay tag has changed
    if (CurrentGameplayTagContainer != InitialGameplayTagContainer)
    {
        // Broadcast if there is a change and destroy the listening actor
        OnGameplayTagChanged.Broadcast();
        listenerActor->Destroy();
        return;
    }
    // Use this in case you only want to use one gameplay tag
    //FGameplayTag CurrentGameplayTag = targetActor->OwnedGameplayTag;
    //if (CurrentGameplayTag != InitialGameplayTag)
    //{
    //    // Broadcast if there is a change and destroy the listening actor
    //    OnGameplayTagChanged.Broadcast();
    //    listenerActor->Destroy();
    //    return;
    //}
    // Program the next execution of the function
    GEngine->GetWorldFromContextObject(targetActor, EGetWorldErrorMode::LogAndReturnNull)->GetTimerManager().SetTimer(TimerHandle, this, &UAsyncTaskGameplayTagChanged::CheckGameplayTag, 0.2f);
}
