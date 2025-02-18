#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // Scene Root 생성
    RootComponent = SceneRoot; // RootComponent 설정

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    PlatformMesh->SetupAttachment(SceneRoot); // Scene Root에 메쉬 부착

    // 메쉬 및 머티리얼 설정 (Item.cpp에서 가져온 부분)
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_CornerFrame.SM_CornerFrame"));
    if (MeshAsset.Succeeded())
    {
        PlatformMesh->SetStaticMesh(MeshAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
    if (MaterialAsset.Succeeded())
    {
        PlatformMesh->SetMaterial(0, MaterialAsset.Object);
    }

    // 초기값 설정 (기존 코드)
    MoveSpeed = 100.0f;
    MoveDistance = 500.0f;
    bIsMovingForward = true;
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 이동 방향 설정
    float MoveDirection = bIsMovingForward ? 1.0f : -1.0f;

    // 이동 거리 계산
    FVector CurrentLocation = GetActorLocation();
    float DistanceMoved = (CurrentLocation - InitialLocation).Size();

    // 이동
    if (DistanceMoved < MoveDistance)
    {
        SetActorLocation(CurrentLocation + GetActorRightVector() * MoveSpeed * MoveDirection * DeltaTime);
    }
    else
    {
        // 방향 전환
        bIsMovingForward = !bIsMovingForward;
        InitialLocation = CurrentLocation; // 초기 위치 갱신
    }
}