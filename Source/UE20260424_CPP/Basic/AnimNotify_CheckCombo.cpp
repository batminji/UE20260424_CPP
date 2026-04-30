// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_CheckCombo.h"
#include "BasicCharacter.h"


void UAnimNotify_CheckCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	ABasicCharacter* Pawn = Cast<ABasicCharacter>(MeshComp->GetOwner());
	if (Pawn)
	{
		Pawn->CheckCombo();
	}
}
