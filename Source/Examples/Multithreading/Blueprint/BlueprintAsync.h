// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "BlueprintAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBlueprintTaskFinishedDelegate);

UCLASS()
class EXAMPLES_API UBlueprintAsync : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FBlueprintTaskFinishedDelegate OnThreadFinished;
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "Examples")
    static UBlueprintAsync* StartThread(const int32& NumberOfLoops = 1000);

	virtual void Activate() override;
	virtual void BeginDestroy() override;
	
private:
	UFUNCTION()
	void OnFinished();
	 
	int32 LoopNum;
	TSharedPtr<class FFindPrimeNumbersTask> PrimeNumberFinderTask = nullptr;
	
};

