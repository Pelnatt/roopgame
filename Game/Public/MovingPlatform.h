#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class GAME_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    // ������
    AMovingPlatform();

    // Tick �Լ�
    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USceneComponent* SceneRoot; // Scene Root �߰�

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* PlatformMesh;
    // ����
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0"))
    float MoveSpeed; // �̵� �ӵ�

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0"))
    float MoveDistance; // �̵� �Ÿ�

private:
    FVector InitialLocation; // �ʱ� ��ġ
    bool bIsMovingForward; // ���� ���� ����
};