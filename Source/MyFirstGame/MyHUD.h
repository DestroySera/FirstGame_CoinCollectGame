// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYFIRSTGAME_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	// 매 프레임마다 화면에 그리는 함수
	virtual void DrawHUD() override;
	
};
