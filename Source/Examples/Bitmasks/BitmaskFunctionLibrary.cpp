// Fill out your copyright notice in the Description page of Project Settings.

#include "BitmaskFunctionLibrary.h"

#define LOG(Text) UE_LOG(LogTemp, Warning, TEXT(Text))

void UBitmaskFunctionLibrary::ReadBitmask(int32 Bitmask)
{
	// To check for flags, you can convert the enum to int32
	if (Bitmask & static_cast<int32>(ELowLevelBitmask::One))
		LOG("Bitmask: One")

	// or use the high level macros we defined
	if (Bitmask & FLAG_2)
		LOG("Bitmask: Two")
	
	// You can also make functions for flag checking to make it more beginner friendly
	if (CheckFlag(Bitmask, FLAG_3))
		LOG("Bitmask: Three")
	
	// You cannot compare to 0 because bitwise & is true only if both are 1
	// Just compare it to 0
    if (Bitmask == 0)
    	LOG("Bitmask: None")
}

bool UBitmaskFunctionLibrary::CheckFlag(const int32 Bitmask, const int32 Flag)
{
	return Bitmask & Flag;
}
