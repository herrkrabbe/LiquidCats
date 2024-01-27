// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCat.h"

APlayerCat::APlayerCat()
{
	PrimaryActorTick.bCanEverTick = true;

	PlayerSprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PlayerSprite"));
	SetRootComponent(PlayerSprite);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetUsingAbsoluteRotation(true);

	SpringArm->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 1000.f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 5.f;

	SpringArm->SetupAttachment(PlayerSprite);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = false;
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
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
	if (Speed) {
		PlayerSprite->AddRelativeLocation(FVector(DeltaX, DeltaY, 0.f) * Speed);
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
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::Red, FString::Printf(TEXT("X val : %f "), getVal));
	if (getVal)
	{
		DeltaX = getVal;
	}
}

void APlayerCat::MoveXAxisCompleted(const FInputActionValue& val)
{
	const float getVal = val.Get<float>();
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::Red, FString::Printf(TEXT("Reset ex value  : %f "), getVal));
	if (getVal)
	{
		Speed = 0;
	}
}