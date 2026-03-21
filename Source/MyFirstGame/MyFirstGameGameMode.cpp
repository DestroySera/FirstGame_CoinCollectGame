// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyFirstGameGameMode.h"
#include "MyHUD.h"
#include "Kismet/GameplayStatics.h"

AMyFirstGameGameMode::AMyFirstGameGameMode()
{
	CurrentScore = 0;
	RemainingTime = 60.f; // 30초 제한
	TotalCoins = 0;
	CollectedCoins = 0;
	bGameClear = false;
	bGameOver = false;

	// HUD 클래스 설정
	HUDClass = AMyHUD::StaticClass();
}

void AMyFirstGameGameMode::RestartGame()
{
	UGameplayStatics::OpenLevel(
		this, 
		FName(*GetWorld()->GetName()), 
		false
	);
}

void AMyFirstGameGameMode::RegisterCoin()
{
	TotalCoins++;
}

void AMyFirstGameGameMode::CoinCollected()
{
	CollectedCoins++;
	if (CollectedCoins >= TotalCoins) {
		GetWorldTimerManager().ClearTimer(TimerHandle);
		bGameClear = true;
		UE_LOG(LogTemp, Warning, TEXT("Game Clear! Final Score: %d"), CurrentScore);
	}
}

void AMyFirstGameGameMode::BeginPlay()
{
	Super::BeginPlay();
	// 1초마다 CountDown 함수 호출
	GetWorldTimerManager().SetTimer(
		TimerHandle, 
		this, 
		&AMyFirstGameGameMode::CountDown, 
		1.f, // 1초 마다
		true // 반복
	);
}

void AMyFirstGameGameMode::CountDown()
{
	RemainingTime -= 1.f; // 1초 감소
	UE_LOG(LogTemp, Warning, TEXT("Remaining Time: %.0f"), RemainingTime);

	if (RemainingTime <= 0) {
		// 타이머 종료
		GetWorldTimerManager().ClearTimer(TimerHandle);
		bGameOver = true;
		UE_LOG(LogTemp, Warning, TEXT("Game Over!"));
	}
}

void AMyFirstGameGameMode::AddScore(int32 Amount)
{
	CurrentScore += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Current Score: %d"), CurrentScore);
}

int32 AMyFirstGameGameMode::GetScore() const
{
	return CurrentScore;
}

float AMyFirstGameGameMode::GetRemainingTime() const {
	return RemainingTime;
}

bool AMyFirstGameGameMode::IsGameClear() const
{
	return bGameClear;
}

bool AMyFirstGameGameMode::IsGameOver() const
{
	return bGameOver;
}