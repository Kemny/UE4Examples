// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssertsFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLES_API UAssertsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void FailCheck();
	
	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void FailCheckWithMessage();
	
	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void FailVerify();
	
	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void FailEnsure();
	
	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void FailEnsureAlways();

	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void EnsuredFunction(bool bTriggerEnsure);
};
