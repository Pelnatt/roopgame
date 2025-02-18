#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingObject.generated.h"

UCLASS()
class GAME_API ARotatingObject : public AActor
{
    GENERATED_BODY()

public:
    ARotatingObject();

    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USceneComponent* SceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* RotatingMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation", meta = (ClampMin = "0.0"))
    float RotationSpeed; // ȸ�� �ӵ� (�ʴ� ȸ�� ����)

private:
    FRotator InitialRotation;
};