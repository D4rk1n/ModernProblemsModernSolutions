// Fill out your copyright notice in the Description page of Project Settings.

#include "Test.h"

// Sets default values for this component's properties
UTest::UTest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTest::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	POpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (AOpen&&PPlate)
	{
		//UE_LOG(LogTemp, Warning, TEXT("lol "));
		if (PPlate->IsOverlappingActor(AOpen))	{
			UE_LOG(LogTemp, Warning, TEXT("Actor that opens "))
			FRotator r(0, -50, 0);
			Owner->SetActorRotation(r);
		}
		if (PPlate->IsOverlappingActor(POpen)) {
			UE_LOG(LogTemp, Warning, TEXT("Pawn that opens "))
				FRotator r(0, -50, 0);
			Owner->SetActorRotation(r);
		}
	}
	// ...
}

