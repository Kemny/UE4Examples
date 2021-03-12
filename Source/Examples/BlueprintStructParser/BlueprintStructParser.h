// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../../../Plugins/Developer/RiderLink/Source/RD/thirdparty/clsocket/src/ActiveSocket.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintStructParser.generated.h"

UCLASS()
class EXAMPLES_API UBlueprintStructParser : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Examples", CustomThunk, meta = (Keywords = "Struct sample test testing", CustomStructureParam = "AnyStruct"))
	static void ReceiveSomeStruct(UStruct* AnyStruct, FString CustomName = "Yee");

	DECLARE_FUNCTION(execReceiveSomeStruct)
	{
		// Steps into the stack, walking to the next property in it
		Stack.Step(Stack.Object, nullptr);

		// Grab the last property found when we walked the stack
		// This does not contains the property value, only its type information
		FProperty* StructProperty = CastField<FProperty>(Stack.MostRecentProperty);

		// Grab the base address where the struct actually stores its data
		// This is where the property value is truly stored
		void* StructPtr = Stack.MostRecentPropertyAddress;

		
		P_GET_PROPERTY(FStrProperty, CustomName);
		// We need this to wrap up the stack
		P_FINISH;

		// Iterate through the struct
		ReceiveSomeStruct_impl(StructProperty, CustomName, StructPtr);
	}


	static void ReceiveSomeStruct_impl(FProperty* Property, FString CustomName, void* StructPtr);
	static void ParseProperty(const FString& PropertyName,FProperty* Property, void* ValuePtr);
	
	static bool TryParseInt(FProperty* Property, void* ValuePtr, int32& OutValue);
	static bool TryParseFloat(FProperty* Property, void* ValuePtr, float& OutValue);
	static bool TryParseBool(FProperty* Property, void* ValuePtr, bool& OutValue);
	static bool TryParseName(FProperty* Property, void* ValuePtr, FName& OutValue);
	static bool TryParseString(FProperty* Property, void* ValuePtr, FString& OutValue);
	static bool TryParseText(FProperty* Property, void* ValuePtr, FText& OutValue);
	static bool TryParseArray(FProperty* Property, void* ValuePtr, const FString& ArrayName);
	static bool TryParseMap(FProperty* Property, void* ValuePtr, const FString& MapName);
};