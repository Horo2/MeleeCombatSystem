// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/NavLinkProxy.h"
#include "CustomNavLinkProxy.generated.h"

/**
 * 
 */
UCLASS()
class MELEECOMBATSYSTEM_API ACustomNavLinkProxy : public ANavLinkProxy
{
	GENERATED_BODY()
public:
	virtual void PostInitializeComponents() override;

private:
	void UpdateSmartLinkFromPointLink();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FVector PointLinkStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FVector PointLinkEnd;
};
