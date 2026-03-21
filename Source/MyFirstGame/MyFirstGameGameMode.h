// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstGameGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AMyFirstGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AMyFirstGameGameMode();

	// 점수 추가 함수
	void AddScore(int32 Amount);
	// 현재 점수 가져오기
	int32 GetScore() const;
	float GetRemainingTime() const;

	// 코인 등록 + 수집 함수 추가
	void RegisterCoin(); // 코인 총 개수 등록
	void CoinCollected(); // 코인 수집 시 호출

protected:
	virtual void BeginPlay() override;

private:
	// 현재 점수
	int32 CurrentScore;
	float RemainingTime;
	int32 TotalCoins; // 전체 코인 수
	int32 CollectedCoins; // 수집한 코인 수

	// 타이머 핸들 ( 타이머 제어용 )
	FTimerHandle TimerHandle;

	// 1초마다 호출될 함수
	void CountDown();

public:
	bool IsGameClear() const;
	bool IsGameOver() const;

private:
	bool bGameClear;
	bool bGameOver;

public:
	void RestartGame();
};



