// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExampleProperties.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FExampleDelegate);

UCLASS(Config = "CustomConfig")
class EXAMPLES_API AExampleProperties : public AActor
{
	GENERATED_BODY()

protected:
	// EditAnywhere: This variable can be changed from anywhere in the engine
	// Category: This variable will be categorized if exposed to blueprint
	UPROPERTY(EditAnywhere, Category = "Examples")
	int32 EditAnywhereInt;
	
	// This variable can be changed from the blueprint
	UPROPERTY(EditDefaultsOnly, Category = "Examples")
	int32 EditDefaultsInt;
	
	// This variable can be changed from the inspector when placed in world
	UPROPERTY(EditInstanceOnly, Category = "Examples")
	int32 EditInstanceInt;
	
	// This variable cannot be changed from blueprint
	UPROPERTY(BlueprintReadOnly, Category = "Examples")
	int32 ReadOnlyInt;
	
	// This variable can be changed and accessed from blueprint
	UPROPERTY(BlueprintReadWrite, Category = "Examples")
	int32 ReadWriteInt;
	
	// This variable will be put inside the .ini file depending on the class metadata
	UPROPERTY(Config, BlueprintReadOnly, VisibleAnywhere, Category = "Examples")
	int32 ConfigInt;
	
	// This variable isn't affected by undo in editor
	UPROPERTY(NonTransactional, EditAnywhere, Category = "Examples")
	int32 NativeInt;

	// This variable will be saved by reflection system
	UPROPERTY(SaveGame, EditAnywhere, Category = "Examples")
	int32 SavedInt;
	
	// This variable cannot be duplicated
	UPROPERTY(DuplicateTransient, EditAnywhere, Category = "Examples")
	int32 DuplicateTransientInt;
	
	// This array's size cannot be changed in the inspector
	UPROPERTY(EditFixedSize, EditAnywhere, Category = "Examples")
	TArray<int32> FixedSizeArray;

	// This variable will be put in dropdowns
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Examples")
	int32 AdvancedDisplayInt;

	// This delegate can be assigned in blueprints
	UPROPERTY(BlueprintAssignable, Category = "Examples")
	FExampleDelegate AssignableDelegate;
	
	// This delegate can be called in blueprints
	UPROPERTY(BlueprintCallable, Category = "Examples")
	FExampleDelegate CallableDelegate;

protected:
	
protected:
	// Setter Function for Number Variable
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Examples")
    void BlueprintSetterFunction(const int32 NewNumber);

	// Getter Function for Number Variable
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "Examples")
    int32 BlueprintGetterFunction();

private:
	// Number Variable, Hidden from blueprints
	UPROPERTY(BlueprintGetter = BlueprintGetterFunction, BlueprintSetter = BlueprintSetterFunction, Category = "Examples")
	int32 Number = 0;
};
