// Fill out your copyright notice in the Description page of Project Settings.


#include "S_AttributeComponent.h"

US_AttributeComponent::US_AttributeComponent()
{
	HealthMax = 100;
	Health = HealthMax;
}

bool US_AttributeComponent::ApplyHealthChange(float Delta) {
	float OldHealth = Health;

	Health = FMath::Clamp(Health + Delta, 0.0f, HealthMax);

	float ActualDelta = Health - OldHealth;

	OnHealthChanged.Broadcast(nullptr, this, Health, ActualDelta);

	return ActualDelta != 0;
}

bool US_AttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

float US_AttributeComponent::GetHealthMax() const
{
	return HealthMax;
}

bool US_AttributeComponent::IsFullHealth() const
{
	return Health == HealthMax;
}







