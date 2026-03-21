// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystem.h"
#include "Coin.generated.h"

UCLASS()
class MYFIRSTGAME_API ACoin : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// 코인 모양을 보여줄 메시 컴포넌트
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CoinMesh;

	// 플레이어가 닿았을 때 호출되는 함수
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	USoundBase* CoinSound;

	UPROPERTY(EditAnywhere)
	UParticleSystem* CoinEffect; // 파티클 추가

};