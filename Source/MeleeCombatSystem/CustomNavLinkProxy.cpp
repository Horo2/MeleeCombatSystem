// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomNavLinkProxy.h"
#include "NavigationSystem.h"

void ACustomNavLinkProxy::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// Update SmartLink with PointLink information
	UpdateSmartLinkFromPointLink();
}

void ACustomNavLinkProxy::UpdateSmartLinkFromPointLink()
{
	if (NavLinkComponent)
	{
		// Set the start and end points of the SmartLink
		NavLinkComponent->SetLinkStart(PointLinkStart);
		NavLinkComponent->SetLinkEnd(PointLinkEnd);

		// Optionally, update any other SmartLink properties here
	}
}