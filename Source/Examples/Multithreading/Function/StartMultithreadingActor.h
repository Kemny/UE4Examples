// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StartMultithreadingActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCppTaskFinishedDelegate);

UCLASS()
class EXAMPLES_API AStartMultithreadingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStartMultithreadingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

	UPROPERTY(BlueprintAssignable)
	FCppTaskFinishedDelegate OnThreadFinished;
	
	UFUNCTION()
    void OnFinished();

	UPROPERTY(EditAnywhere)
	int32 NumberOfLoops = 1000;
	TSharedPtr<class FFindPrimeNumbersTask> PrimeNumberFinderTask = nullptr;

};
