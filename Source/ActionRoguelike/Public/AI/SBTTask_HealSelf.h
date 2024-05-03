// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "SBTTask_HealSelf.generated.h"

/**
 * 
 */
class SAttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API USBTTask_HealSelf : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:

protected:
	void Healing(UBehaviorTreeComponent& OwnerComp);
};
