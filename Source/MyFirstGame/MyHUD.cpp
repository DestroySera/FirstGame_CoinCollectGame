// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "MyFirstGameGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Canvas.h"

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	// GameMode에서 점수랑 시간 가져오기
	AMyFirstGameGameMode* GameMode = Cast<AMyFirstGameGameMode>(
		UGameplayStatics::GetGameMode(GetWorld())
	);

	if (GameMode)
	{
		// 점수 표시
		FString ScoreText = FString::Printf(
			TEXT("Score: %d"), GameMode->GetScore()
		);

		// 시간 표시
		FString TimeText = FString::Printf(
			TEXT("Time: %.0f"), GameMode->GetRemainingTime()
		);

		// 화면에 텍스트 그리기
		DrawText(ScoreText, FColor::White, 50.0f, 50.0f, nullptr, 2.f);
		DrawText(TimeText, FColor::Yellow, 50.0f, 100.0f, nullptr, 2.f);

		// Game Clear 표시
		if (GameMode->IsGameClear()) {
			DrawText(
				TEXT("Game Clear!"), 
				FColor::Green, 
				Canvas->SizeX / 2 - 100.f, 
				Canvas->SizeY / 2,
				nullptr, 4.f);

			// 재시작 안내 텍스트
			DrawText(
				TEXT("Press R to Restart"), 
				FColor::White, 
				Canvas->SizeX / 2 - 100.f, 
				Canvas->SizeY / 2 + 60.f,
				nullptr, 2.f);
		}

		// Game Over 표시
		if (GameMode->IsGameOver()) {
			DrawText(
				TEXT("Game Over!"), 
				FColor::Red, 
				Canvas->SizeX / 2 - 100.f, 
				Canvas->SizeY / 2,
				nullptr, 4.f);

			// 재시작 안내 텍스트
			DrawText(
				TEXT("Press R to Restart"),
				FColor::White,
				Canvas->SizeX / 2 - 100.f,
				Canvas->SizeY / 2 + 60.f,
				nullptr, 2.f);
		}
		
	}
}
