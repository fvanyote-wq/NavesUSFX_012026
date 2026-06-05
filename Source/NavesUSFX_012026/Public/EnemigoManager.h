#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.h" 
#include "EnemigoManager.generated.h"

UCLASS()
class NAVESUSFX_012026_API AEnemigoManager : public AActor
{
    GENERATED_BODY()

public:
    AEnemigoManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    // arrays para guardar las clases de enemigos de cada cuadrilla
    TArray<TSubclassOf<AEnemigo>> ClasesCuadrilla1;
    TArray<TSubclassOf<AEnemigo>> ClasesCuadrilla2;

    // tiempo que espera el timer antes de sacar la segunda cuadrilla
    float TiempoRetrasoSegundos = 3.0f;

    // contador para saber cuantos enemigos de la primera cuadrilla quedan vivos
    int32 EnemigosVivosCuadrilla1;

    // el FTimerHandle que nos pidio el profesor para controlar el tiempo
    FTimerHandle TimerHandle_SpawnCuadrilla2;

    // funcion para crear los enemigos en el escenario
    void SpawnCuadrilla(const TArray<TSubclassOf<AEnemigo>>& Clases, FVector PosicionBase);

    // funcion que se ejecuta cuando un enemigo avisa que murio
    UFUNCTION()
    void OnEnemigoDestruido();

    // funcion que llama el timer cuando se acaba el tiempo
    void SpawnCuadrilla2Callback();
};