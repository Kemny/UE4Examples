#include "ExampleProperties.h"

#define LOG(Text) UE_LOG(LogTemp, Warning, TEXT(Text))
#define LOG_STRING(PARAM) UE_LOG(LogTemp, Warning, TEXT("%s"), *PARAM)

void AExampleProperties::BlueprintSetterFunction(const int32 NewNumber) { LOG("BlueprintSetterFunction Called") Number = NewNumber; }
int32 AExampleProperties::BlueprintGetterFunction()  { LOG("BlueprintGetterFunction Called") return Number; }