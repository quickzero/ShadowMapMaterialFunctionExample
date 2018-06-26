// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ShadowMapExamplePlayerController.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "ShadowMapExampleCharacter.h"
#include "Engine/World.h"
#include "Components/Button.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AShadowMapExamplePlayerController::AShadowMapExamplePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AShadowMapExamplePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AShadowMapExamplePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AShadowMapExamplePlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AShadowMapExamplePlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AShadowMapExamplePlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AShadowMapExamplePlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AShadowMapExamplePlayerController::OnResetVR);
}

void AShadowMapExamplePlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AShadowMapExamplePlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AShadowMapExampleCharacter* MyPawn = Cast<AShadowMapExampleCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				//UNavigationSystemV1::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AShadowMapExamplePlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AShadowMapExamplePlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		//UNavigationSystem* const NavSys = Cast<UNavigationSystem>(GetWorld()->GetNavigationSystem());
		//float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		//// We need to issue move command only if far enough in order for walk animation to play correctly
		//if (NavSys && (Distance > 120.0f))
		//{
		//	NavSys->SimpleMoveToLocation(this, DestLocation);
		//}

		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());
		if(Distance > 120.0f)
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
	}
}

void AShadowMapExamplePlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AShadowMapExamplePlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

