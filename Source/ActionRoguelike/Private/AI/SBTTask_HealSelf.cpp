// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTTask_HealSelf.h"
#include "AIController.h"
#include "S_AttributeComponent.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackboardComponent.h"

void Healing(UBehaviorTreeComponent& OwnerComp) 
{
	APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ensure(AIPawn))
	{
		US_AttributeComponent* AttributeComp = US_AttributeComponent::GetAttributes(AIPawn);
		if (ensure(AttributeComp))
		{
			AttributeComp->ApplyHealthChange(AIPawn, AttributeComp->GetHealthMax());
		}
	}
}
