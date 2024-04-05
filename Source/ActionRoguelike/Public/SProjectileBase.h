// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectileBase.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;
class UAudioComponent;

UCLASS(ABSTRACT)
class ACTIONROGUELIKE_API ASProjectileBase : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Effects")
	UParticleSystem* ImpactVFX;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* MoveComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystemComponent* EffectComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Effects")
	UAudioComponent* AudioComp;

	UFUNCTION()
	virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Explode();

	UFUNCTION()
	void PlayImpactSound();

	virtual void PostInitializeComponents() override;

public:
	// Sets default values for this actor's properties
	ASProjectileBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
};
