// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BasicCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;

UENUM(BlueprintType)
enum class EPoseState : uint8
{
	Stand = 0		UMETA(DisplayName = "Stand"),
	Crouch = 1		UMETA(DisplayName = "Crouch"),
	Prone = 2		UMETA(DisplayName = "Prone")
};

UCLASS()
class UE20260424_CPP_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Look;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Jump;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Lean;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Scale;

	void Move(const FInputActionValue& InValue);

	void Look(const FInputActionValue& InValue);

	void Lean(const FInputActionValue& InValue);
	
	void BigHead(const FInputActionValue& InValue);

	FRotator GetAimOffset() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat")
	float TargetAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat")
	float TargetScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	EPoseState PoseState = EPoseState::Stand;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 bIsWeaponEquipped : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 ComboCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 PlayingComboIndex = 0;

	UFUNCTION(BlueprintCallable)
	void CheckCombo();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Anim")
	TObjectPtr<UAnimMontage> ComboMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	uint8 bIsAttacking : 1;

	UFUNCTION(BlueprintCallable)
	void ComboAttack();

	UFUNCTION()
	void OnComboMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void PlayComboMonstage();
};
