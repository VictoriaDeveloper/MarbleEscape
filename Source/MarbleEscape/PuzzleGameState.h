// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PuzzleGameState.generated.h"

UENUM(BlueprintType)
enum class EGameDirection : uint8
{
    Up,
    Down,
    Left,
    Right
};

/**
 * 
 */
UCLASS()
class MARBLEESCAPE_API APuzzleGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
    APuzzleGameState();

	// Function to change direction
    void ChangeDirection();

	// Current game direction
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EGameDirection CurrentDirection;

    // Timer handle
    FTimerHandle DirectionTimerHandle;
protected:
    // Called when the game starts
    virtual void BeginPlay() override;
};
