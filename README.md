# AssyncTaskGameplayTags

The solution its an async node with a static function that can be placed wherever you want and takes two objects (listener and target) the listener it's an actor but the target has to be a MyGameplayTagActor that has a variable called OwnedGameplayTags this variable it's a Gameplay Tag Container and it has de gameplay tags of the target and it's the variable checked for destroying the listener when it changes. As well I comented in both the MyGameplayTagActor and the AsyncTaskGameplayTagChanged some lines to use it with only one Gameplay Tag. I added a delegate to be called when there is a tag change.


How to use it:

- Place two actors, the listener actor could be an Actor, but the target has to be a MyGameplayTagActor.
- Set the gameplay tags that you want for the target actor.
- Call the function "WaitForGameplayTagContainerChange" in the listener actor and set the parameeters.
- Make sure you clicked on the replicated checkbox for being replicated in multiplayer.
- Press play.

Note: if you want to use this code in other project you must write in the PublicDependencyModuleNames in the build.cs file of the project "GameplayTags"
