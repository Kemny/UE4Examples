// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlueprintFunctions.generated.h"



// Custom Enum For ExpandEnumAsExecs
UENUM()
enum class EFunctionReturns : uint8
{
	Error,
	Possibility1,
	Possibility2,
};

UCLASS()
class EXAMPLES_API ABlueprintFunctions : public AActor
{
	GENERATED_BODY()

private:
	
protected:
	// Only works by default with: Possessed Pawns, Player Controllers, Player Input, Cheat Managers, Game Modes, Game Instances, overriden Game Engine classes, and Huds
	// Leaving it here to keep all examples in the same place
	// Callable In Game Console
	UFUNCTION(Exec)
    void ConsoleCallableFunction();
	
	// Callable In Blueprints with Execution
	UFUNCTION(BlueprintCallable, Category = "Examples")
    void BlueprintCallableFunction();

	// Needs to return a value
	// Callable In Blueprints without Execution
	UFUNCTION(BlueprintPure, Category = "Examples")
    int32 BlueprintPureFunction();

	// Usually used in blueprint libraries
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext)) // Alternative meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject")
	static void StaticWorldContextFunction(UObject* WorldContextObject);
	
	// Callable In Editor. Spawns a button in the inspector
	UFUNCTION(CallInEditor, Category = "Examples")
	void EditorCallableFunction();

	// Collapse parameters by name
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (AdvancedDisplay="Arg3, Arg4"))
    void BlueprintCallableAdvanced1Function(int32 Arg1 = 1, int32 Arg2 = 2, int32 Arg3 = 3, int32 Arg4 = 4);

	// Collapse parameters by number
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (AdvancedDisplay=2))
    void BlueprintCallableAdvanced2Function(int32 Arg1 = 1, int32 Arg2 = 2, int32 Arg3 = 3, int32 Arg4 = 4);

	// Templated Array
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (ArrayParm = "TargetArray"))
	void BlueprintGenericArrayFunction(const TArray<UObject*> &TargetArray);
	
	// Templated Array With Dependant Parameters and Dependant return value
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (ArrayParm = "TargetArray", ArrayTypeDependentParams = "Dependant", DeterminesOutputType = "TargetArray"))
	UObject* DependantFunction(const TArray<UObject*> &TargetArray, UObject*& Dependant);

	// Add a plus pin
	UFUNCTION(BlueprintPure, Category = "Examples", meta = (CommutativeAssociativeBinaryOperator = "true"))
	int32 CommutativeAssociativeBinaryFunction(int32 A, int32 B);

	// Compact function, can be both pure and blueprint callable
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (CompactNodeTitle="Compact"))
	void CompactFunction();

	// Templated Structure
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (CustomStructureParam = "TargetStruct"))
    void CustomStructureParamFunction(UProperty* TargetStruct);

	// Defaults the Actor Pointer to self. Still visible in inspector
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (DefaultToSelf = "ActorPointer"))
	void DefaultToSelfFunction(UPARAM(DisplayName = "Another Pointer [Default Self]") AActor* ActorPointer);
	
	// Defaults the Actor Pointer to self. Hidden In Inspector
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (DefaultToSelf = "ActorPointer", HidePin = "ActorPointer"))
	void HiddenDefaultToSelfFunction(AActor* ActorPointer);
	
	// Hides the self pin
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (HideSelfPin = "true"))
	void HiddenSelfFunction();
	
	// Marks a function as deprecated, can add a deprecation message
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (DeprecatedFunction, DeprecationMessage = "Called Deprecated Function!"))
	void DeprecatedFunction(AActor* ActorPointer);

	// ChangeTheName
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (DisplayName = "Change Name Function"))
	void Cpp_ChangeNameFunction();
	
	// Multiple Output Pins
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (ExpandEnumAsExecs = "Returns"))
	void MultipleOutputsFunction(EFunctionReturns& Returns);

	// When searching banana in blueprints, this function will show up
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (KeyWords = "Banana"))
	void KeywordedFunction();
	
	// Marks the function as latent (the nodes with the clock icon like 'Delay')
	// Can add latent info for callback
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (Latent, LatentInfo = "LatentInfo"))
	void LatentFunction(FLatentActionInfo LatentInfo);

	// To indicate that you're working with Material Parameter Collections
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (MaterialParameterCollectionFunction = "true"))
	void MaterialParameterCollectionFunction(UMaterialParameterCollection* Collection);
	
	// Display just as break struct node
	UFUNCTION(BlueprintPure, Category = "Examples", meta = (NativeBreakFunc))
    int32 BreakableFunction(int32 Arg1, int32 Arg2, int32 Arg3, int32 Arg4);

	// For Long Tooltips
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (ToolTip="Long tooltip"))
    void LongTooltipFunction();

	// For Short Tooltips
	UFUNCTION(BlueprintCallable, Category = "Examples", meta = (ShortToolTip="Short tooltip"))
    void ShortTooltipFunction();

	// Won't be visible in the editor
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly)
	void InternalFunction();
	


};
