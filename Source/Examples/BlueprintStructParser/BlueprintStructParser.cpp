// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintStructParser.h"

void UBlueprintStructParser::ReceiveSomeStruct_impl(FProperty* Property, FString CustomName, void* StructPtr)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *CustomName);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Property->GetAuthoredName());
	
	FStructProperty* StructProperty = CastField<FStructProperty>(Property);

	//check for null
	if (!StructProperty)
		return;
	
	// Walk the structs' properties
	for (TFieldIterator<FProperty> PropertyIt(StructProperty->Struct); PropertyIt; ++PropertyIt)
	{
		// Never assume ArrayDim is always 1
		for (int32 ArrayIndex = 0; ArrayIndex < PropertyIt->ArrayDim; ArrayIndex++)
		{
			// This grabs the pointer to where the property value is stored
			void* ValuePtr = PropertyIt->ContainerPtrToValuePtr<void>(StructPtr, ArrayIndex);

			// Parse this property
			ParseProperty(PropertyIt->GetAuthoredName(), *PropertyIt, ValuePtr);
		}
	}
}

void UBlueprintStructParser::ParseProperty(const FString& PropertyName, FProperty* Property, void* ValuePtr)
{
	float FloatValue;
	int32 IntValue;
	bool BoolValue;
	FString StringValue;
	FName NameValue;
	FText TextValue;

	if (TryParseInt(Property, ValuePtr, IntValue))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Int32] %s = '%i'"), *PropertyName, IntValue);
	}
	else if (TryParseFloat(Property, ValuePtr, FloatValue))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Float] %s = '%d'"), *PropertyName, FloatValue);
	}
	else if (TryParseBool(Property, ValuePtr, BoolValue))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Bool] %s = '%s'"), *PropertyName, *(BoolValue ? "bool: True" : "bool: False"));
	}
	else if (TryParseName(Property, ValuePtr, NameValue))
	{
		UE_LOG(LogTemp, Warning, TEXT("[FName] %s ='%s'"), *PropertyName, *NameValue.ToString());
	}
	else if (TryParseString(Property, ValuePtr, StringValue))
	{
		UE_LOG(LogTemp, Warning, TEXT("[FString] %s = '%s'"), *PropertyName, *StringValue);
	}
	else if (TryParseText(Property, ValuePtr, TextValue))
	{
		UE_LOG(LogTemp, Warning, TEXT("[FText] %s = '%s'"), *PropertyName, *TextValue.ToString());
	}
	else if (TryParseArray(Property, ValuePtr, PropertyName))
	{
		
	}
	else if (TryParseMap(Property, ValuePtr, PropertyName))
	{
		
	}
	// Reading a nested struct
	else if (Property)
	{
		ReceiveSomeStruct_impl(Property, PropertyName, ValuePtr);
	}
}

bool UBlueprintStructParser::TryParseInt(FProperty* Property, void* ValuePtr, int32& OutValue)
{
	if (FNumericProperty* NumericProperty = CastField<FNumericProperty>(Property))
	{
		if (NumericProperty->IsInteger())
		{
			OutValue = NumericProperty->GetSignedIntPropertyValue(ValuePtr);
			return true;
		}
	}
	return false;
}

bool UBlueprintStructParser::TryParseFloat(FProperty* Property, void* ValuePtr, float& OutValue)
{
	if (FNumericProperty* NumericProperty = CastField<FNumericProperty>(Property))
	{
		if (NumericProperty->IsFloatingPoint())
		{
			OutValue = NumericProperty->GetFloatingPointPropertyValue(ValuePtr);
			return true;
		}
	}
	
	return false;
}

bool UBlueprintStructParser::TryParseBool(FProperty* Property, void* ValuePtr, bool& OutValue)
{
	if (FBoolProperty* BoolProperty = CastField<FBoolProperty>(Property))
	{
		OutValue = BoolProperty->GetPropertyValue(ValuePtr);
		return true;
	}
	
	return false;
}

bool UBlueprintStructParser::TryParseName(FProperty* Property, void* ValuePtr, FName& OutValue)
{
	if (FNameProperty* NameProperty = CastField<FNameProperty>(Property))
	{
		OutValue = NameProperty->GetPropertyValue(ValuePtr);
		return true;
	}
	
	return false;
}
bool UBlueprintStructParser::TryParseString(FProperty* Property, void* ValuePtr, FString& OutValue)
{
	if (FStrProperty* StringProperty = CastField<FStrProperty>(Property))
	{
		OutValue = StringProperty->GetPropertyValue(ValuePtr);
		return true;
	}
	
	return false;
}

bool UBlueprintStructParser::TryParseText(FProperty* Property, void* ValuePtr, FText& OutValue)
{
	if (FTextProperty* TextProperty = CastField<FTextProperty>(Property))
	{
		OutValue = TextProperty->GetPropertyValue(ValuePtr);
		return true;
	}
	return false;
}

bool UBlueprintStructParser::TryParseArray(FProperty* Property, void* ValuePtr, const FString& ArrayName)
{
	if (FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Property))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Array] %s'"), *ArrayName);
		UE_LOG(LogTemp, Warning, TEXT("-----------"));
		// We need the helper to get to the items of the array       
		FScriptArrayHelper Helper(ArrayProperty, ValuePtr);
		for (int32 i = 0, n = Helper.Num(); i < n; ++i)
		{
			ParseProperty(ArrayName, ArrayProperty->Inner, Helper.GetRawPtr(i));
		}
		UE_LOG(LogTemp, Warning, TEXT("-----------"));
		
		return true;
	}
	return false;
}
bool UBlueprintStructParser::TryParseMap(FProperty* Property, void* ValuePtr, const FString& MapName)
{
	if (FMapProperty* MapProperty = CastField<FMapProperty>(Property))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Map] %s'"), *MapName);
		UE_LOG(LogTemp, Warning, TEXT("-----------"));
		// We need the helper to get to the items of the array       
		FScriptMapHelper Helper(MapProperty, ValuePtr);
		
		int32 Size = Helper.Num();
		for(int32 i = 0; Size; ++i )
		{
			if(Helper.IsValidIndex(i))
			{
				
				ParseProperty(FString::FromInt(i) + "Key", Helper.GetKeyProperty(), Helper.GetKeyPtr(i));
				ParseProperty(FString::FromInt(i) + "Val", Helper.GetValueProperty(), Helper.GetValuePtr(i));
				--Size;
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("-----------"));
		
		return true;
	}
	return false;
}
