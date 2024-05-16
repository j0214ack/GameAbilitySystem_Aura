// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/HighlightableInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(InputSubsystem);

	InputSubsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue &InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator CurrentYawRotation(0.0f, GetControlRotation().Yaw, 0.0f);
	const FVector CurrentForwardDirection = FRotationMatrix(CurrentYawRotation).GetUnitAxis(EAxis::X);
	const FVector CurrentRightDirection = FRotationMatrix(CurrentYawRotation).GetUnitAxis(EAxis::Y);
	const FVector MovementDirection = CurrentForwardDirection * InputAxisVector.Y + CurrentRightDirection * InputAxisVector.X;
	GetPawn()->AddMovementInput(MovementDirection.GetSafeNormal());
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Camera, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	Highlight(CursorHit.GetActor());
}

void AAuraPlayerController::Highlight(AActor* Target)
{
	LastHighlightable = CurrentHighlightable;
	CurrentHighlightable = Target;

	if (LastHighlightable != CurrentHighlightable)
	{
		if (LastHighlightable)
		{
			LastHighlightable->Unhighlight();
		}

		if (CurrentHighlightable)
		{
			CurrentHighlightable->Highlight();
		}
	}
}
