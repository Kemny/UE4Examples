// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintAsync.h"
#include "../FindPrimeNumbers.h"

UBlueprintAsync::UBlueprintAsync(const FObjectInitializer& ObjectInitializer):
    Super(ObjectInitializer),
    LoopNum(0)
{
}

UBlueprintAsync* UBlueprintAsync::StartThread(const int32& NumberOfLoops)
{
	UBlueprintAsync* BlueprintNode = NewObject<UBlueprintAsync>();
	BlueprintNode->LoopNum = NumberOfLoops;
	return BlueprintNode;
	
}

void UBlueprintAsync::Activate()
{
	if (LoopNum <= 0)
		return;

	FPrimeThreadFinishedDelegate OnPrimeNumbersFound;
	OnPrimeNumbersFound.AddUniqueDynamic(this, &UBlueprintAsync::OnFinished);
	this->PrimeNumberFinderTask = MakeShareable(new FFindPrimeNumbersTask(LoopNum, OnPrimeNumbersFound));

	// Start the service
	if (PrimeNumberFinderTask.IsValid())
		PrimeNumberFinderTask->Start();
}

void UBlueprintAsync::BeginDestroy()
{
	if (PrimeNumberFinderTask.IsValid())
		PrimeNumberFinderTask->Shutdown();

	Super::BeginDestroy();
}

void UBlueprintAsync::OnFinished()
{
	OnThreadFinished.Broadcast();
}
