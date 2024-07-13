
#include "GASTestDummy.h"
#include "AbilitySystemComponent.h"
#include "GASTestBasicAttributeSet.h"

AGASTestDummy::AGASTestDummy()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp")); 
}

void AGASTestDummy::BeginPlay()
{
	Super::BeginPlay();	

	if (IsValid(AbilitySystemComponent))
	{
		 AttributeSet = AbilitySystemComponent->GetSet<UGASTestBasicAttributeSet>();
	}
}

UAbilitySystemComponent* AGASTestDummy::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGASTestDummy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

