// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HAL/Runnable.h"
#include "FindPrimeNumbers.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrimeThreadFinishedDelegate);

// Dummy class to let FFindPrimeNumbersTask be in it's own file
UCLASS()
class EXAMPLES_API UFindPrimeNumbers : public UObject
{
	GENERATED_BODY()
	
};

class FFindPrimeNumbersTask : public FRunnable
{
	FPrimeThreadFinishedDelegate Callback;
	int32 LoopNum;
	FCriticalSection Context;

	FThreadSafeBool bIsDead = false;
	
	bool VariablesValid() const
	{
		return LoopNum > 0;
	}
	public:
	FFindPrimeNumbersTask(const int32 LoopNum, FPrimeThreadFinishedDelegate Callback) :
		Callback(Callback),
		LoopNum(LoopNum)
	{}

	// Begin the service
	bool Start();

	// Stop the service
	virtual void Shutdown();

	protected:		
	/** FRunnable Interface implementation for 'Init' */
	virtual bool Init() override { return VariablesValid(); }

	/** FRunnable Interface implementation for 'Stop' */
	virtual void Stop() override;

	/** FRunnable Interface implementation for 'Run' */
	virtual uint32 Run() override;

	FRunnableThread* p_RunnableThread = nullptr;
};