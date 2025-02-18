#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class GAME_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    // 생성자
    AMovingPlatform();

    // Tick 함수
    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USceneComponent* SceneRoot; // Scene Root 추가

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* PlatformMesh;
    // 변수
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0"))
    float MoveSpeed; // 이동 속도

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0"))
    float MoveDistance; // 이동 거리

private:
    FVector InitialLocation; // 초기 위치
    bool bIsMovingForward; // 전진 방향 여부
};