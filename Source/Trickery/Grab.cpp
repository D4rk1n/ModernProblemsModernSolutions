// Fill out your copyright notice in the Description page of Project Settings.

#include "Grab.h"


// Sets default values for this component's properties
UGrab::UGrab()
{
	
		
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UGrab::BeginPlay()
{
	Super::BeginPlay();
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle) UE_LOG(LogTemp, Warning, TEXT("Physics Handle Working"));
	SetupInputComponent();	
}

void UGrab::SetupInputComponent()
{
	Input = GetOwner()->FindComponentByClass<UInputComponent>();
	if (Input)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input working"));
		Input->BindAction("Grab", IE_Pressed, this, &UGrab::Grab);
		//Input->BindAction("Grab", IE_Released, this, &UGrab::Release);
		while(PhysicsHandle->GrabbedComponent) Input->BindAction("Grab", IE_Pressed, this, &UGrab::Release);
	}
}

void UGrab::Grab() {
	
	auto Grabbed = Hit.GetComponent();
	if(Hit.GetActor())
	PhysicsHandle->GrabComponent(Grabbed, NAME_None, Grabbed->GetOwner()->GetActorLocation(), true);
	
}
void UGrab::Release() {

	PhysicsHandle->ReleaseComponent();
}

// Called every frame
void UGrab::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	RayTrace();
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(End);
		Input->BindAction("Grab", IE_Pressed, this, &UGrab::Release);
	}
	else Input->BindAction("Grab", IE_Pressed, this, &UGrab::Grab);

	
}

void UGrab::RayTrace()
{
	FCollisionQueryParams Qpara(FName(), false, GetOwner());
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PLocation, PRotation);
	End = PRotation.Vector()*Reach + PLocation;
	GetWorld()->LineTraceSingleByObjectType(Hit, PLocation, End, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), Qpara);
	//if(Hit.GetActor()) UE_LOG(LogTemp, Error, TEXT("lol"));

}

