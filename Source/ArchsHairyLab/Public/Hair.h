// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Hair.generated.h"

UCLASS()
class ARCHSHAIRYLAB_API AHair : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHair();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//// LAYER ////
	UPROPERTY(BlueprintReadWrite)
	TArray<class AHairLayer*> HairLayers;

	UPROPERTY(BlueprintReadWrite)
	int LayerId = 0;

	UFUNCTION(BlueprintCallable, Category = "Layers")
	void AddNewLayer();


	//// HAIR ATTRIBUTES ////

	UPROPERTY(BlueprintReadWrite)
	float GlobalXWidth = 50.0f;

	UPROPERTY(BlueprintReadWrite)
	float GlobalYWidth = 10.0f;


	//// PROCEDURAL MESH GENERATION ////

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProceduralMeshData* StartMeshData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProceduralMeshData* MiddleMeshData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProceduralMeshData* EndMeshData;

	UPROPERTY(BlueprintReadWrite)
	FVector AnchorLengthStart = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	FVector AnchorLengthEnd = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	FVector AnchorWidthStart = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	FVector AnchorWidthEnd = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	FVector AnchorThicknessStart = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	FVector AnchorThicknessEnd = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> EndPointsA;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> EndPointsB;
	UPROPERTY(BlueprintReadWrite)
	FVector P1 = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	FVector P2 = FVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite)
	float Weight = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void SetupMesh();

	UFUNCTION(BlueprintCallable, Category = "Prodecural Mesh Methods")
	void CalculateEndPoints(TArray<FVector> InVertices);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void AssignPositions(FVector InP1, FVector InP2);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	AHairSegment* SpawnSegment();

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void ExtendSegment();

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	AHairNode* SpawnNode(AMyPlayerController* Controller, UWorld* World, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void SetNodeLocation(AHairNode* Node, FVector Location, bool IsPropToChildren);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void UpdateHair();
	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void UpdateLayer(class AHairLayer* InLayer);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void UpdateSegment(class AHairSegment* InSegment);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void ClearMeshData(AHairSegment* InSegment);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
		FVector MapVertex(FVector V, AHairSegment* Segment, float Distance, float InWeight);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void AddVertices(int FirstIndex, TArray<FVector> InVertices, AHairSegment* InSegment, float Distance);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void AddTriangles(AHairSegment* InSegment);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void AddUVs(AHairSegment* InSegment, bool IsFirst);

	
	//// NODE ////

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SelectNode(AHairNode* Node);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void DeselectNode(AHairNode* Node);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void DeselectAllNodes();

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SetNodeVisibility(AHairSegment* Segment, bool IsVisible);

	//// SEGMENT ////

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SetSelectedSegmentXWidth(float InVal);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SetSelectedSegmentFallOff(float InVal);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SetSelectedQuality(float InVal);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SelectSegment(AHairSegment* Segment);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void RemoveSegment(AHairSegment* Segment);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void RemoveSelected();

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void DeselectSegment(AHairSegment* Segment);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void DeselectAllSegments();

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void DeselectAll();


	//// LAYER ////

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SelectLayer(AHairLayer* Layer, bool IsAppend);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void RemoveLayer(AHairLayer* Layer);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SetLayerLock(AHairLayer* Layer, bool IsLocked);

	UFUNCTION(BlueprintCallable, Category = "Selection")
	void SetLayerVisibility(AHairLayer* Layer, bool IssVisible);


	//// FILE MANAGEMENT ////

	UFUNCTION(BlueprintCallable, Category = "File Management")
	void ExportHair();

	
	//// MISC ////
	UFUNCTION(BlueprintCallable, Category = "Misc")
	AMyPlayerController* GetController();
};
