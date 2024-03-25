// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerup_HealthPotion.h"
#include "S_AttributeComponent.h"

ASPowerup_HealthPotion::ASPowerup_HealthPotion()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	//Disable collision, instead we use SphereComp to handle interaction
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);
}

void ASPowerup_HealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}
	
	US_AttributeComponent* AttributeComp = Cast<US_AttributeComponent>(InstigatorPawn->GetComponentByClass(US_AttributeComponent::StaticClass()));
	//Check if not already at MaxHealth
	if (ensure(AttributeComp) && !AttributeComp->IsFullHealth())
	{
		//Only Activate if healed successfully
		if (AttributeComp->ApplyHealthChange(AttributeComp->GetHealthMax()))
		{
			HideAndCooldownPowerup();
		}
	}
}

