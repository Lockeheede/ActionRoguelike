// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile_.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "S_AttributeComponent.h"
#include "Kismet/GameplayStatics.h"

ASMagicProjectile_::ASMagicProjectile_()
{
	MoveComp->InitialSpeed = 1000.f;
}

void ASMagicProjectile_::BeginPlay()
{
	Super::BeginPlay();
}

void ASMagicProjectile_::Explode_Implementation()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());
}

void ASMagicProjectile_::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != GetInstigator()) //not NULL 
	{

		US_AttributeComponent* AttributeComp = Cast<US_AttributeComponent>(OtherActor->GetComponentByClass(US_AttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			AttributeComp->ApplyHealthChange(-Damage);
			Explode();
			Destroy();
		}
	}
}