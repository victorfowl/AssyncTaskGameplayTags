# AssyncTaskGameplayTags

First assessment:

The solution its an async node with a static function that can be placed wherever you want and takes two objects (listener and target) the listener it's an actor but the target has to be a MyGameplayTagActor that has a variable called OwnedGameplayTags this variable it's a Gameplay Tag Container and it has de gameplay tags of the target and it's the variable checked for destroying the listener when it changes. As well I comented in both the MyGameplayTagActor and the AsyncTaskGameplayTagChanged some lines to use it with only one Gameplay Tag. I added a delegate to be called when there is a tag change.


How to use it:

- Place two actors, the listener actor could be an Actor, but the target has to be a MyGameplayTagActor.
- Set the gameplay tags that you want for the target actor.
- Call the function "WaitForGameplayTagContainerChange" in the listener actor and set the parameeters.
- Make sure you clicked on the replicated checkbox for being replicated in multiplayer.
- Press play.

Note: if you want to use this code in other project you must write in the PublicDependencyModuleNames in the build.cs file of the project "GameplayTags"

Second assessment:

For this second assessment I did a custom async node used for binding the listening actor to the event dispatcher of the target actor with the static function CreateAsyncNode. I used three classes: TargetActor where I have a setter and getter for the boolean variable that it has and an event dispatcher that is called once the boolean changes it's value. ListeningActor it's the class of the listening actor that I only created for make sure that it replicates in multiplayer environments. And AsyncNode class that is the custom async node used to binding the listening actor to the target actor event dispatcher. You can bind events to the target actor event dispatcher "OnBooleanChanged" for adding behaviour when that change happens. The listening actor would be destroyed when the boolean in the target actor changes. The async node waits until this change happens to finish.
In the Level called "SecondExercise" under the folder "Second Assessment" you will find an example of usage, the target actor waits two seconds to change it's boolean value and then the listening actor it's destroyed. If you open the listening actor you will see how I binded it to the target actor event dispatcher.

How to use it:

- Place two actors, the listener actor could be an Actor (in this case dont forget to check the replicates checkbox), and the target has to be a TargetActor.
- For changing the boolean of the target actor you must use the setter "SetBooleanValue".
- In the listening actor call the function "CreateAsyncNode" and connect the pins.
- Press play.
- Change the boolean value to see the desired effect.
