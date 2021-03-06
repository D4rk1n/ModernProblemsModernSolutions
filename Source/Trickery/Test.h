// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine.h"
#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Test.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRICKERY_API UTest : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTest();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	AActor* Owner = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PPlate = nullptr;
	UPROPERTY(EditAnywhere)
		AActor * AOpen = nullptr;
	UPROPERTY(EditAnywhere)
		AActor * POpen = nullptr;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
