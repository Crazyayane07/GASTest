// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASTestBasicAttributeSet.generated.h"

UCLASS()
class GASTEST_API UGASTestBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Health;

public:

	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UGASTestBasicAttributeSet, Health);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Health);
};
