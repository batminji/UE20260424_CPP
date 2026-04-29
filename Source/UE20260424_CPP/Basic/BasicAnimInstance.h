// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BasicCharacter.h"
#include "BasicAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE20260424_CPP_API UBasicAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	// virtual void NativeInitializeAnimation() override;
	// virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float TargetLeanAngle = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float CurrentLeanAngle = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float TargetScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float CurrentScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float AimPitch = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float AimYaw = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	EPoseState PoseState = EPoseState::Stand;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 bIsWeaponEquipped : 1;
};
