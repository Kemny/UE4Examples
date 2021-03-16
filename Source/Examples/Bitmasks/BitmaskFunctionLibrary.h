// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BitmaskFunctionLibrary.generated.h"

/*
 * Multiple ways to write numbers in c++
 * 
 * ----------------------------------------------------------------
 * Decimal Numbers
 * _____________________________
 * Number	| Syntax	| Binary
 * _____________________________
 * 0		0			0000 0000
 * 1		1			0000 0001
 * 2		2			0000 0010
 * 4		4			0000 0100
 * 8		8			0000 1000
 * 16		16			0001 0000
 * 32		32			0010 0000
 * 64		64			0100 0000
 * 128		128			1000 0000
 * ----------------------------------------------------------------
 * Binary Numbers
 * _____________________________
 * Number	| Syntax	| Binary
 * _____________________________
 * 0		0b0			0000 0000
 * 1		0b1			0000 0001
 * 2		0b10		0000 0010
 * 4		0b100		0000 0100
 * 8		0b1000		0000 1000
 * 16		0b10000		0001 0000
 * 32		0b100000	0010 0000
 * 64		0b1000000	0100 0000
 * 128		0b10000000	1000 0000
 * ----------------------------------------------------------------
 * Hexadecimal Numbers
 * _____________________________
 * Number	| Syntax	| Binary
 * _____________________________
 * 0		0x0			0000 0000
 * 1		0x1			0000 0001
 * 2		0x2			0000 0010
 * 4		0x4			0000 0100
 * 8		0x8			0000 1000
 * 16		0x10		0001 0000
 * 32		0x20		0010 0000
 * 64		0x40		0100 0000
 * 128		0x40		1000 0000
 * ----------------------------------------------------------------
 * Binary Shift (Personal Favorite)
 * _____________________________
 * Number	| Syntax	| Binary
 * _____________________________
 * 0		0			0000 0000
 * 1		1 << 0		0000 0001
 * 2		1 << 1		0000 0010
 * 4		1 << 2		0000 0100
 * 8		1 << 3		0000 1000
 * 16		1 << 4		0001 0000
 * 32		1 << 5		0010 0000
 * 64		1 << 6		0100 0000
 * 128		1 << 7		1000 0000
 * ----------------------------------------------------------------
 */

// Declare the bitmask
// All bitmasks need to have 0 as their default values
UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class ELowLevelBitmask : uint8
{
	// The 0 values always needs to be a decimal 0, macros also don't work
	NONE	=	0		UMETA(Hidden),					// 0000 0000
	One		=	1		UMETA(DisplayName = "One"),		// 0000 0001
	Two		=	1 << 1	UMETA(DisplayName = "Two"),		// 0000 0010
	Three	=	1 << 2	UMETA(DisplayName = "Three"),	// 0000 0100
	// And so on
};

// To spice things up, let's use decimals for the high level one
#define FLAG_0 0
#define FLAG_1 1
#define FLAG_2 2
#define FLAG_3 4

// Declare the bitmask
// All bitmasks need to have 0 as their default values
UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EHighLevelBitmask : uint8
{
	
	NONE	=	0 UMETA(Hidden),					// 0000 0000
	One		=	FLAG_1 UMETA(DisplayName = "One"),	// 0000 0001
	Two		=	FLAG_2 UMETA(DisplayName = "Two"),	// 0000 0010
	Three	=	FLAG_3 UMETA(DisplayName = "Three")	// 0000 0100
	// And so on
};

// C++ Operations
ENUM_CLASS_FLAGS(ELowLevelBitmask);
ENUM_CLASS_FLAGS(EHighLevelBitmask);

UCLASS()
class EXAMPLES_API UBitmaskFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// Using a bitmask in a function is done with UPARAM
	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void EnterLLBitmask(UPARAM(meta = (Bitmask, BitmaskEnum = "ELowLevelBitmask")) int32 Bitmask) { ReadBitmask(Bitmask); }
	
	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void EnterHLBitmask(UPARAM(meta = (Bitmask, BitmaskEnum = "EHighLevelBitmask")) int32 Bitmask) { ReadBitmask(Bitmask); }

	// This function assumes that both bitmasks are the same for my convenience.
	UFUNCTION(BlueprintCallable, Category = "Examples")
	static void ReadBitmask(int32 Bitmask);

	static bool CheckFlag(const int32 Bitmask, const int32 Flag);
};
