// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SInteractionComponent.h"
#include "S_AttributeComponent.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class USInteractionComponent;
class UAnimMontage;
class US_AttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> DashProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> BlackHoleProjectileClass;

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	US_AttributeComponent* AttributeComp;
	
	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	FTimerHandle TimerHandle_PrimaryAttack;
	FTimerHandle TimerHandle_Dash;
	FTimerHandle TimerHandle_BlackHole;

	UFUNCTION()
	void SpawnProjectile(TSubclassOf<AActor> ClassToSpawn);

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, US_AttributeComponent* OwningComp, float NewHealth, float Delta);

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Movement 
	void MoveForward(float Value);
	void MoveRight(float Value);

	// Action
	void PrimaryAttack();
	void PrimaryInteract();
	void PrimaryAttack_TimeElapsed();
	void Dash();
	void Dash_TimeElapsed();
	void BlackHole();
	void BlackHole_TimeElapsed();

	//Properties
	float AttackAnimDelay = 0.2f;

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
