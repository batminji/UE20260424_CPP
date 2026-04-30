// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_CheckCombo.h"



void UAnimNotify_CheckCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	UE_LOG(LogTemp, Warning, TEXT("Check Combo Notify Triggered"));
}
