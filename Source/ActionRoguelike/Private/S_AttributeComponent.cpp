// Fill out your copyright notice in the Description page of Project Settings.


#include "S_AttributeComponent.h"
#include "SGameModeBase.h"

US_AttributeComponent::US_AttributeComponent()
{
	HealthMax = 100;
	Health = HealthMax;
}

bool US_AttributeComponent::ApplyHealthChange(AActor* InstigatorActor, float Delta) {
	float OldHealth = Health;

	Health = FMath::Clamp(Health + Delta, 0.0f, HealthMax);

	float ActualDelta = Health - OldHealth;

	OnHealthChanged.Broadcast(InstigatorActor, this, Health, ActualDelta);

	//Died
	if (ActualDelta < 0.0f && Health == 0.f)
	{
		ASGameModeBase* GM = GetWorld()->GetAuthGameMode<ASGameModeBase>();
		if (GM)
		{
			GM->OnActorKilled(GetOwner(), InstigatorActor);
		}
	}

	return ActualDelta != 0;
}

US_AttributeComponent* US_AttributeComponent::GetAttributes(AActor* FromActor)
{
	if (FromActor)
	{
		return Cast<US_AttributeComponent>(FromActor->GetComponentByClass(US_AttributeComponent::StaticClass()));
	}
	return nullptr;
}

bool US_AttributeComponent::IsActorAlive(AActor* Actor)
{
	US_AttributeComponent* AttributeComp = GetAttributes(Actor);
	if (AttributeComp)
	{
		return AttributeComp->IsAlive();
	}

	return false;
}

bool US_AttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

float US_AttributeComponent::GetHealthMax() const
{
	return HealthMax;
}

float US_AttributeComponent::GetHealth() const
{
	return Health;
}

bool US_AttributeComponent::IsFullHealth() const
{
	return Health == HealthMax;
}







