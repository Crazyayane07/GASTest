// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "AbilitySystemInterface.h"
#include "GASTestCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
class UAbilitySystemComponent;
class UGASTestBasicAttributeSet;
class UTP_WeaponComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AGASTestCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AGASTestCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	UFUNCTION(BlueprintImplementableEvent, Category = "Weapon")
	void Fire();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	UTP_WeaponComponent* GetWeaponComponent();

	void SetWeaponComponentRef(UTP_WeaponComponent* NewWeaponComp);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
	const UGASTestBasicAttributeSet* AttributeSet;

	UTP_WeaponComponent* WeaponComp;

	virtual void BeginPlay();

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

};

