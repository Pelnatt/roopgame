#include "RotatingObject.h"

ARotatingObject::ARotatingObject()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    RotatingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotatingMesh"));
    RotatingMesh->SetupAttachment(SceneRoot);

    // �޽� �� ��Ƽ���� ����
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
    if (MeshAsset.Succeeded())
    {
        RotatingMesh->SetStaticMesh(MeshAsset.Object);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load mesh! Check the path.")); // ���� �޽��� �߰�
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_CobbleStone_Smooth.M_CobbleStone_Smooth"));
    if (MaterialAsset.Succeeded())
    {
        RotatingMesh->SetMaterial(0, MaterialAsset.Object);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load material! Check the path.")); // ���� �޽��� �߰�
    }


    // �ʱⰪ ����
    RotationSpeed = 45.0f; // �ʴ� 45�� ȸ��
    InitialRotation = GetActorRotation(); // �ʱ� ȸ�� �� ����
}

void ARotatingObject::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ȸ�� (AddActorLocalRotation ���)
    FRotator DeltaRotation(0.0f, RotationSpeed * DeltaTime, 0.0f); // Yaw ȸ��
    AddActorLocalRotation(DeltaRotation);

    // �Ǵ� SetActorRotation() ��� (�Ʒ� �ּ� ó���� �ڵ�)
    // FRotator NewRotation = GetActorRotation();
    // NewRotation.Yaw += RotationSpeed * DeltaTime; // Yaw �� ȸ��
    // SetActorRotation(NewRotation);
}