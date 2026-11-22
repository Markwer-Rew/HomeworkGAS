// Fill out your copyright notice in the Description page of Project Settings.


#include "HomeCharacterBase.h"

#include "BasicAttributeSet.h"

// Sets default values
AHomeCharacterBase::AHomeCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(AscReplicationMode);
	
	BasicAttributeSet = CreateDefaultSubobject<UBasicAttributeSet>(TEXT("AttributeSet"));
 
}

// Called when the game starts or when spawned
void AHomeCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHomeCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void AHomeCharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}


// Called every frame
void AHomeCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHomeCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

class UAbilitySystemComponent* AHomeCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}



