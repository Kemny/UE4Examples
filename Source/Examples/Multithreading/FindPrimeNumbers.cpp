// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPrimeNumbers.h"

#define LOG(Text) UE_LOG(LogTemp, Warning, TEXT(Text))
#define LOG_STRING(PARAM) UE_LOG(LogTemp, Warning, TEXT("%s"), *PARAM)

bool FFindPrimeNumbersTask::Start()
{
	if (p_RunnableThread == nullptr)
	{
		p_RunnableThread = FRunnableThread::Create(this, TEXT("FFindPrimeNumbersTask"));
	}

	LOG("Thread Started")
	
	return false;
}

uint32 FFindPrimeNumbersTask::Run()
{
	// Return failed if variables aren't set correctly
	if (!VariablesValid())
		return 0;	

	for (size_t i = 1; i <= LoopNum; i+=2)
	{
		if (bIsDead)
			goto Finish_Thread;
		
		for (size_t j = 3; j <= i; j+=2)
		{
			if (i % j == 0 && i != j)
			{
				goto Finish_Loop;
			}
		}
		GEngine->AddOnScreenDebugMessage(i, EConstraintFrame::Frame1, FColor::Magenta, FString::FromInt(i));
		
		Finish_Loop:
		continue;

		Finish_Thread:
		LOG("Thread Killed")
		break;
	}

	// Broadcast the even on the game thread for thread safety purposes
	AsyncTask(ENamedThreads::GameThread, [this]()
    {
		LOG("Thread Finished")
        Callback.Broadcast();
    });

	// Return success
	return 1;
}

void FFindPrimeNumbersTask::Shutdown()
{
	if (p_RunnableThread != nullptr)
	{
		bIsDead = true;
		p_RunnableThread->WaitForCompletion();
		p_RunnableThread = nullptr;
	}
}
void FFindPrimeNumbersTask::Stop()
{
	Shutdown();
}