#include "ListeningActor.h"

//I put this only for say in the constructor that I want to replicate this actor in multiplayer environments.
AListeningActor::AListeningActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
}
