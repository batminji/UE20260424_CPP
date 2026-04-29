// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"
#include "BasicCharacter.h"


//void UBasicAnimInstance::NativeInitializeAnimation()
//{
//}
//
//void UBasicAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
//{
//	Super::NativeInitializeAnimation();
//
//	ABasicCharacter* Character = Cast<ABasicCharacter>(TryGetPawnOwner());
//	if (Character)
//	{
//		Speed = Character->GetCharacterMovement()->Velocity.Size2D();
//
//		Direction = UKismetAnimationLibrary::CalculateDirection(Character->GetVelocity(), Character->GetActorRotation());
//
//		LeanAngle = Character->LeanAngle;
//	}
//}

void UBasicAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	ABasicCharacter* Character = Cast<ABasicCharacter>(TryGetPawnOwner());
	if (Character)
	{
		Speed = Character->GetCharacterMovement()->Velocity.Size2D();

		Direction = UKismetAnimationLibrary::CalculateDirection(Character->GetVelocity(), Character->GetActorRotation());

		TargetLeanAngle = Character->TargetAngle;
		CurrentLeanAngle = FMath::FInterpTo(CurrentLeanAngle, TargetLeanAngle, DeltaSeconds, 5.0f);
		
		TargetScale = Character->TargetScale;
		CurrentScale = FMath::Clamp(FMath::FInterpTo(CurrentScale, TargetScale, DeltaSeconds, 1.0f), 1.0f, 5.0f);

		FRotator AimOffset = Character->GetAimOffset();
		AimPitch = AimOffset.Pitch;
		AimYaw = AimOffset.Yaw;
	}
}
