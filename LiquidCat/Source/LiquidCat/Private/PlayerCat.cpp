// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCat.h"

APlayerCat::APlayerCat()
{
	PrimaryActorTick.bCanEverTick = true;

	PlayerSprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PlayerSprite"));
	SetRootComponent(PlayerSprite);
}

void APlayerCat::BeginPlay()
{
	Super::BeginPlay();
	InitLocation = PlayerSprite->GetComponentLocation();

	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController) {
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (subsystem) {
			subsystem->AddMappingContext(IMCPlayerInput, 0);
		}
	}
}

void APlayerCat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Speed)
	{
		this->AddMovementInput(FVector(DeltaX, DeltaY, 0), Speed);
		//PlayerSprite->AddRelativeLocation(FVector(DeltaX, DeltaY, 0.f) * Speed);
	}

}

void APlayerCat::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhanceInputCom = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhanceInputCom->BindAction(IA_MoveRigthLeft, ETriggerEvent::Triggered, this, &APlayerCat::MoveXAxis);
		EnhanceInputCom->BindAction(IA_MoveRigthLeft, ETriggerEvent::Completed, this, &APlayerCat::MoveXAxisCompleted);
	}
}


void APlayerCat::MoveXAxis(const FInputActionValue& val)
{
	const float getVal = val.Get<float>();
	if (getVal)
	{
		DeltaX = getVal;
	}
}

void APlayerCat::MoveXAxisCompleted(const FInputActionValue& val)
{
	const float getVal = val.Get<float>();
	if (getVal)
	{
		DeltaX = 0;
	}
}