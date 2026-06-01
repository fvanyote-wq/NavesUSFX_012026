#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Enemy.generated.h"

UCLASS()
class NAVESUSFX_012026_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	AEnemy();
	virtual void Tick(float DeltaTime) override;

	// Malla del enemigo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	//Material opcional
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UMaterialInterface* MaterialPersonalizado;

	//Velocidad de movimiento
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Velocidad = 200.0f;

	// Puntos de patrulla
	UPROPERTY(EditAnywhere, Category = "Movement")
	TArray<FVector> Waypoints;

private:
	int32 IndiceWaypoint = 0;
	void MoverHacia(const FVector& Objetivo, float DeltaTime);
};