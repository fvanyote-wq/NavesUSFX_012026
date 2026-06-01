#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerEnemigos.generated.h"


 //Genera instancias de AEnemy automaticamente al iniciar el nivel

UCLASS()
class NAVESUSFX_012026_API ASpawnerEnemigos : public AActor
{
	GENERATED_BODY()

public:
	ASpawnerEnemigos();

protected:
	virtual void BeginPlay() override;

public:
	// Clase de enemigo a instanciar
	UPROPERTY(EditAnywhere, Category = "Configuracion")
	TSubclassOf<class AEnemy> ClaseEnemigo;

	// Cantidad de naves a generar
	UPROPERTY(EditAnywhere, Category = "Configuracion", meta = (ClampMin = "1", ClampMax = "50"))
	int32 Cantidad = 5;

	// Distancia entre cada nave generada
	UPROPERTY(EditAnywhere, Category = "Configuracion")
	FVector Espaciado = FVector(300.f, 0.f, 0.f);
};