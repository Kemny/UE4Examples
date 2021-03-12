// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlueprintVariables.generated.h"

UCLASS()
class EXAMPLES_API ABlueprintVariables : public AActor
{
	GENERATED_BODY()

protected:
	// This variable can be changed from anywhere in the engine
	UPROPERTY(EditAnywhere, Category = "Examples")
	int32 EditAnywhereInt = 5;
	
	// This variable can be changed from the blueprint
	UPROPERTY(EditDefaultsOnly, Category = "Examples")
	int32 EditDefaultsInt = 5;
	
	// This variable can be changed from the inspector when placed in world
	UPROPERTY(EditInstanceOnly, Category = "Examples")
	int32 EditInlineInt = 5;
};
