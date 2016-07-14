// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "HairLayer.generated.h"

UCLASS()
class ARCHSHAIRYLAB_API AHairLayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHairLayer();

	AHairLayer(FName InName, int InId);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	FName Name;

	UPROPERTY(BlueprintReadWrite)
	int Id;

	UPROPERTY(BlueprintReadWrite)
	bool IsLocked = false;

	UPROPERTY(BlueprintReadWrite)
	bool IsVisible = true;
};
