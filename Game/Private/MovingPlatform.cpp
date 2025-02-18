#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // Scene Root ����
    RootComponent = SceneRoot; // RootComponent ����

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    PlatformMesh->SetupAttachment(SceneRoot); // Scene Root�� �޽� ����

    // �޽� �� ��Ƽ���� ���� (Item.cpp���� ������ �κ�)
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

    // �ʱⰪ ���� (���� �ڵ�)
    MoveSpeed = 100.0f;
    MoveDistance = 500.0f;
    bIsMovingForward = true;
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // �̵� ���� ����
    float MoveDirection = bIsMovingForward ? 1.0f : -1.0f;

    // �̵� �Ÿ� ���
    FVector CurrentLocation = GetActorLocation();
    float DistanceMoved = (CurrentLocation - InitialLocation).Size();

    // �̵�
    if (DistanceMoved < MoveDistance)
    {
        SetActorLocation(CurrentLocation + GetActorRightVector() * MoveSpeed * MoveDirection * DeltaTime);
    }
    else
    {
        // ���� ��ȯ
        bIsMovingForward = !bIsMovingForward;
        InitialLocation = CurrentLocation; // �ʱ� ��ġ ����
    }
}