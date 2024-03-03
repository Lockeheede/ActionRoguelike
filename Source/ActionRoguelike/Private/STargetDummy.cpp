// Fill out your copyright notice in the Description page of Project Settings.


#include "STargetDummy.h"

// Sets default values
ASTargetDummy::ASTargetDummy()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	AttributeComp = CreateDefaultSubobject<US_AttributeComponent>("AttributeComp");
	AttributeComp->OnHealthChanged.AddDynamic(this, &ASTargetDummy::OnHealthChanged);
}

void ASTargetDummy::OnHealthChanged(AActor* InstigatorActor, US_AttributeComponent* OwningComp, float NewHealth, float Delta)
{
	if (Delta < 0.f)
	{
		MeshComp->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
	}
}


