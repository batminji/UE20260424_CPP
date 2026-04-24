// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void ABasicPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (IsLocalPlayerController())
    {
        UEnhancedInputLocalPlayerSubsystem* Subsystem = 
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
        if (Subsystem)
        {
            Subsystem->ClearAllMappings();
            for (const auto& IMC : IMCArray)
            {
                if (IMC.IsValid())
                {
                    Subsystem->AddMappingContext(IMC.LoadSynchronous(), 0);
                }
            }
        }
    }
}

void ABasicPlayerController::OnUnPossess()
{
    Super::OnUnPossess();

    if (IsLocalPlayerController())
    {
        UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
        if (Subsystem)
        {
            Subsystem->ClearAllMappings();
        }
    }
}
