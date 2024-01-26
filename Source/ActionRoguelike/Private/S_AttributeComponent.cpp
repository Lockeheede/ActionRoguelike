// Fill out your copyright notice in the Description page of Project Settings.


#include "S_AttributeComponent.h"

US_AttributeComponent::US_AttributeComponent()
{
	Health = 100;
}

bool US_AttributeComponent::ApplyHealthChange(float Delta) {
	Health += Delta;

	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);

	return true;
}







