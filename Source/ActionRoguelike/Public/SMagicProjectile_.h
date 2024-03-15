// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "SMagicProjectile_.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASMagicProjectile_ : public ASProjectileBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere)
	float Damage;

	//Base class using BlueprintNativeEvent, we must override the _Implementation not the Explode()
	virtual void Explode_Implementation() override;

	virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	virtual void BeginPlay() override;

public:
	ASMagicProjectile_();
};
