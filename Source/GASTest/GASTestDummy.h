// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "GASTestDummy.generated.h"

class UAbilitySystemComponent;
class UGASTestBasicAttributeSet;

UCLASS()
class GASTEST_API AGASTestDummy : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	

	AGASTestDummy();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
	const UGASTestBasicAttributeSet* AttributeSet;

	virtual void BeginPlay() override;

};
