// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "MyFirstGameGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACoin::ACoin()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 메시 컴포넌트 생성 + 루트로 설정
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	RootComponent = CoinMesh;

	// 충돌 설정 추가
	CoinMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CoinMesh->SetCollisionResponseToAllChannels(ECR_Overlap);

	// 오버랩 이벤트 켜기
	CoinMesh->SetGenerateOverlapEvents(true);

	// 오버랩 함수 연결
	CoinMesh->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();

	// 게임 시작시 GameMode에 코인 등록
	AMyFirstGameGameMode* GameMode = Cast<AMyFirstGameGameMode>(
		UGameplayStatics::GetGameMode(this)
	);

	if (GameMode) {
		GameMode->RegisterCoin();
	}

}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.f, 100.f * DeltaTime, 0.f));

}

void ACoin::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) {
	// 플레이어 캐릭터랑 닿았을 때만 실행
	if (OtherActor && OtherActor->ActorHasTag("Player")) {
		// 사운드 재생
		if (CoinSound) {
			UGameplayStatics::PlaySoundAtLocation(
				this,
				CoinSound,
				GetActorLocation()
			);
		}

		// 파티클 이펙트 재생
		if (CoinEffect) {
			UGameplayStatics::SpawnEmitterAtLocation(
				GetWorld(),
				CoinEffect,
				GetActorLocation()
			);
		}

		// GameMode에서 점수 추가
		AMyFirstGameGameMode* GameMode = Cast<AMyFirstGameGameMode>(
			UGameplayStatics::GetGameMode(this)
		);

		if (GameMode) {
			GameMode->AddScore(100);
			GameMode->CoinCollected();
		}

		// 코인 사라짐
		Destroy();
	}
}