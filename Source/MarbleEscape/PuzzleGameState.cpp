// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleGameState.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Engine/World.h"

APuzzleGameState::APuzzleGameState()
{

    // Initialize the current direction to Up
    CurrentDirection = EGameDirection::Up;
}

void APuzzleGameState::BeginPlay()
{

    // Call the parent class' BeginPlay()
    Super::BeginPlay();

    // Set up a timer to call ChangeDirection every 5 seconds
    GetWorld()->GetTimerManager().SetTimer(DirectionTimerHandle, this, &APuzzleGameState::ChangeDirection, 5.0f, true);
}

void APuzzleGameState::ChangeDirection()
{

    // Switch on the current direction
    switch (CurrentDirection)
    {

    // Check if the direction is up
    case EGameDirection::Up:

        // Set the next direction
        CurrentDirection = EGameDirection::Down;

        // Break;
        break;

    // Check if the direction is down
    case EGameDirection::Down:

        // Set the next direction
        CurrentDirection = EGameDirection::Left;

        // Break
        break;

    // Check if the direction is left
    case EGameDirection::Left:

        // Set the next direction
        CurrentDirection = EGameDirection::Right;
        
        // Break
        break;

    // Check if the direction is right
    case EGameDirection::Right:

        // Set the next direction
        CurrentDirection = EGameDirection::Up;
        
        // Break
        break;
    }
}