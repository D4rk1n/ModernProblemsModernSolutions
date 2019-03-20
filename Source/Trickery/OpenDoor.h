// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/StaticMeshActor.h"

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpen);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClose);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRICKERY_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	UPROPERTY(BlueprintAssignable)
		FOnOpen OnOpen;
	UPROPERTY(BlueprintAssignable)
		FOnClose OnClose;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

private:
	AActor* Owner=nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* BPlate=nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* RPlate=nullptr;
	UPROPERTY(EditAnywhere)
		AActor * RedChair=nullptr;
	UPROPERTY(EditAnywhere)
		AActor * BlueChair=nullptr;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
