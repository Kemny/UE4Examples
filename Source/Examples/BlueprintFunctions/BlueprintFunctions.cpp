// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFunctions.h"

#define LOG(Text) UE_LOG(LogTemp, Warning, TEXT(Text))
#define LOG_STRING(PARAM) UE_LOG(LogTemp, Warning, TEXT("%s"), *PARAM)

void ABlueprintFunctions::ConsoleCallableFunction() { LOG("ConsoleCallableFunction Called") }
void ABlueprintFunctions::BlueprintCallableFunction() { LOG("BlueprintCallableFunction Called") }
void ABlueprintFunctions::EditorCallableFunction() { LOG("EditorCallableFunction Called") }
int32 ABlueprintFunctions::BlueprintPureFunction() { LOG("BlueprintPureFunction Called") return 0; }
void ABlueprintFunctions::StaticWorldContextFunction(UObject* WorldContextObject)  { LOG("StaticWorldContextFunction Called") }
void ABlueprintFunctions::BlueprintCallableAdvanced1Function(int32 Arg1, int32 Arg2, int32 Arg3, int32 Arg4) { LOG("BlueprintCallableAdvanced1Function Called") }
void ABlueprintFunctions::BlueprintCallableAdvanced2Function(int32 Arg1, int32 Arg2, int32 Arg3, int32 Arg4) { LOG("BlueprintCallableAdvanced2Function Called") }
void ABlueprintFunctions::BlueprintGenericArrayFunction(const TArray<UObject*>& TargetArray) { LOG("BlueprintGenericArrayFunctionn Called") }
UObject* ABlueprintFunctions::DependantFunction(const TArray<UObject*>& TargetArray, UObject*& Dependant) { LOG("DependantFunction Called") return nullptr; }
int32 ABlueprintFunctions::CommutativeAssociativeBinaryFunction(int32 A, int32 B) { LOG("CommutativeAssociativeBinaryFunction Called") return 0; }
void ABlueprintFunctions::CompactFunction() { LOG("CompactFunction Called") }
void ABlueprintFunctions::CustomStructureParamFunction(UProperty* TargetStruct) { LOG("CustomStructureParamFunction Called") }
void ABlueprintFunctions::DefaultToSelfFunction(AActor* ActorPointer) { LOG("DefaultToSelfFunction Called") }
void ABlueprintFunctions::HiddenDefaultToSelfFunction(AActor* ActorPointer) { LOG("ActorPointer Called") }
void ABlueprintFunctions::HiddenSelfFunction() { LOG("HiddenSelfFunction Called") }
void ABlueprintFunctions::DeprecatedFunction(AActor* ActorPointer) { LOG("DeprecatedFunction Called") }
void ABlueprintFunctions::Cpp_ChangeNameFunction() { LOG("Cpp_ChangeNameFunction Called") }
void ABlueprintFunctions::MultipleOutputsFunction(EFunctionReturns& Returns) { LOG("MultipleOutputsFunction Called") }
void ABlueprintFunctions::KeywordedFunction() { LOG("KeywordedFunction Called") }
void ABlueprintFunctions::LatentFunction(FLatentActionInfo LatentInfo) { LOG("LatentFunction Called") }
void ABlueprintFunctions::MaterialParameterCollectionFunction(UMaterialParameterCollection* Collection) { LOG("MaterialParameterCollectionFunction Called") }
int32 ABlueprintFunctions::BreakableFunction(int32 Arg1, int32 Arg2, int32 Arg3, int32 Arg4) { LOG("MaterialParameterCollectionFunction Called") return 0; }
void ABlueprintFunctions::LongTooltipFunction() { LOG("LongTooltipFunction Called") }
void ABlueprintFunctions::ShortTooltipFunction() { LOG("ShortTooltipFunction Called") }
void ABlueprintFunctions::InternalFunction() { LOG("ShortTooltipFunction Called") }


