#include "RotatingObject.h"

ARotatingObject::ARotatingObject()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    RotatingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotatingMesh"));
    RotatingMesh->SetupAttachment(SceneRoot);

    // 메쉬 및 머티리얼 설정
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
    if (MeshAsset.Succeeded())
    {
        RotatingMesh->SetStaticMesh(MeshAsset.Object);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load mesh! Check the path.")); // 오류 메시지 추가
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_CobbleStone_Smooth.M_CobbleStone_Smooth"));
    if (MaterialAsset.Succeeded())
    {
        RotatingMesh->SetMaterial(0, MaterialAsset.Object);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load material! Check the path.")); // 오류 메시지 추가
    }


    // 초기값 설정
    RotationSpeed = 45.0f; // 초당 45도 회전
    InitialRotation = GetActorRotation(); // 초기 회전 값 저장
}

void ARotatingObject::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 회전 (AddActorLocalRotation 사용)
    FRotator DeltaRotation(0.0f, RotationSpeed * DeltaTime, 0.0f); // Yaw 회전
    AddActorLocalRotation(DeltaRotation);

    // 또는 SetActorRotation() 사용 (아래 주석 처리된 코드)
    // FRotator NewRotation = GetActorRotation();
    // NewRotation.Yaw += RotationSpeed * DeltaTime; // Yaw 축 회전
    // SetActorRotation(NewRotation);
}