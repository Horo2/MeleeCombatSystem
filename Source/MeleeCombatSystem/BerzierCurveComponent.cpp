// Fill out your copyright notice in the Description page of Project Settings.


#include "BerzierCurveComponent.h"

// Sets default values for this component's properties
UBerzierCurveComponent::UBerzierCurveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBerzierCurveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBerzierCurveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FVector2D> UBerzierCurveComponent::BerzierCurve(TArray<FVector2D> src)
{
	//不存在1阶
	if	(	src.Num()<1		)
	{
			return			src							;
	}
	//-----------------------------t的分布步数------------------------------------
	const float				step = 0.01					;
	//---------------------------------------------------------------------------
	//	-----------------------------返回值-----------------------------------------
	TArray<FVector2D>		res							;
	//	----------------------------------------------------------------------------

	//	---------------------------2阶 一条直线------------------------------------
	if (	src	.Num()==1	)
	{
		for (float t=0	;	t<1	;	t+=step)
		{
			res.Add(src[0])								;
		}
			return			res							;
	}
	//	--------------------------------------------------------------------------


	//-----------------------------------3阶 及以上-----------------------------------------

	//---------------------------src1是起点到最后一个点的上一个点-----------------------------
	TArray<FVector2D>		src1						;
	//-------------------------------------------------------------------------------------

	//---------------------------src2是从第二个点到最后一个点---------------------------------
	TArray<FVector2D>		src2						;
	//--------------------------------------------------------------------------------------

	//---------------------------对src1,src2赋值 --------------------------------------------
	for (int32 i=0;i<src.Num()-1;i++)
	{
		src1				.Add(src[i])				;
		UE_LOG(LogTemp, Warning, TEXT("==%s\t"),*src1[i].ToString());
	}
	for (int32 j = 0; j < src.Num(); j++)
	{
		src2				.Add(src[j])				;
		UE_LOG(LogTemp, Warning, TEXT("==%s\t"), *src2[j].ToString());
	}
		src2				.RemoveAt(0)				;
	//---------------------------------------------------------------------------------------

	//----------------------------递归调用所有的点--------------------------------------------
		TArray<FVector2D>	pln1=BerzierCurve(src1)		;

		TArray<FVector2D>	pln2=BerzierCurve(src2)		;
	//---------------------------------------------------------------------------------------
	for (float t=0;t<1;t+=step)
	{

		
		FVector2D	tmp									;
		//-------------------------------------应用贝塞尔曲线算法------------------------------
		tmp					=	(
								(1.0	- t)
									*
								pln1[FMath::RoundToInt(1.0 / step * t)] 
								)
							+	(
								t
									* 
								pln2[FMath::RoundToInt(1.0 / step * t)]
								)						;
		//------------------------------------------------------------------------------------
		//--------------------最终得到的点就是贝塞尔曲线上的点的位置了-----------------------
		res					.	Add	(tmp)				; 
		//--------------------------------------------------------------------------------
	}
		return					res						;
	//-----------------------------------------------------------------------------------
}