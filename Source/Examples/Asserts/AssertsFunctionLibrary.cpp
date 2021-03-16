// Fill out your copyright notice in the Description page of Project Settings.


#include "AssertsFunctionLibrary.h"

#define LOG(Text) UE_LOG(LogTemp, Warning, TEXT(Text))
#define LOG_STRING(PARAM) UE_LOG(LogTemp, Warning, TEXT("%s"), *PARAM)

void UAssertsFunctionLibrary::FailCheck()
{
	// Will crash the engine
	// This won't run in builds
	check(false);
}

void UAssertsFunctionLibrary::FailCheckWithMessage()
{
	// Will crash the engine with a message
	checkf(false, TEXT("Custom message check failed"));
}

void UAssertsFunctionLibrary::FailVerify()
{
	// Almost same as check
	// This will run in builds
	verify(false);
	verifyf(false, TEXT("Any assert including Verifyf can also print messages"))
}

void UAssertsFunctionLibrary::FailEnsure()
{
	// Won't crash the engine, but will print an error message in the log
	// Will only happen once every compile
	ensure(false);
	ensureMsgf(false, TEXT("Ensure can also have custom messages"));
}

void UAssertsFunctionLibrary::FailEnsureAlways()
{
	// Won't crash the engine, but will print an error message in the log
	// Will always happen
	ensureAlways(false);
	ensureAlwaysMsgf(false, TEXT("You guessed it! Also has a message variant"));
}

void UAssertsFunctionLibrary::EnsuredFunction(const bool bTriggerEnsure)
{
	if (ensureAlways(!bTriggerEnsure))
	{
		LOG("Ensure Passsed!")
	}
}
