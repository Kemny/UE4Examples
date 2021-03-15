#include "StartMultithreadingActor.h"
#include "../FindPrimeNumbers.h"

// Sets default values
AStartMultithreadingActor::AStartMultithreadingActor()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AStartMultithreadingActor::BeginPlay()
{
	Super::BeginPlay();

	if (NumberOfLoops <= 0)
		return;

	FPrimeThreadFinishedDelegate OnPrimeNumbersFound;
	OnPrimeNumbersFound.AddUniqueDynamic(this, &AStartMultithreadingActor::OnFinished);
	this->PrimeNumberFinderTask = MakeShareable(new FFindPrimeNumbersTask(NumberOfLoops, OnPrimeNumbersFound));

	// Start the service
	if (PrimeNumberFinderTask.IsValid())
		PrimeNumberFinderTask->Start();
}

void AStartMultithreadingActor::BeginDestroy()
{
	if (PrimeNumberFinderTask.IsValid())
	PrimeNumberFinderTask->Shutdown();

	Super::BeginDestroy();
}

void AStartMultithreadingActor::OnFinished()
{
	OnThreadFinished.Broadcast();
}