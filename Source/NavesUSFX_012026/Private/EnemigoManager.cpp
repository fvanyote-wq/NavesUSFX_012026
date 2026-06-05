#include "EnemigoManager.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ArrowComponent.h"
#include "EAAvion.h"
#include "EADron.h"
#include "ETTanque.h"
#include "EABarco.h"
#include "EALancha.h"
#include "ETSoldado.h"

AEnemigoManager::AEnemigoManager()
{
    // no necesitamos tick para el manager, ahorra rendimiento
    PrimaryActorTick.bCanEverTick = false;
    EnemigosVivosCuadrilla1 = 0;

    // ponemos una flecha como raiz para poder verlo y moverlo en el editor
    UArrowComponent* ArrowRoot = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowRoot"));
    RootComponent = ArrowRoot;
    ArrowRoot->SetArrowSize(2.0f);
}

void AEnemigoManager::BeginPlay()
{
    Super::BeginPlay();

    // aqui definimos en puro codigo c++ que enemigos lleva cada cuadrilla
    // usamos StaticClass() para obtener la referencia de la clase sin blueprints

    // enemigos de la primera oleada
    ClasesCuadrilla1.Add(AEAAvion::StaticClass());
    ClasesCuadrilla1.Add(AEAAvion::StaticClass());
    ClasesCuadrilla1.Add(AETTanque::StaticClass());

    // enemigos de la segunda oleada
    ClasesCuadrilla2.Add(AEABarco::StaticClass());
    ClasesCuadrilla2.Add(AEALancha::StaticClass());
    ClasesCuadrilla2.Add(AETSoldado::StaticClass());

    // spawneamos la primera cuadrilla al iniciar el juego
    SpawnCuadrilla(ClasesCuadrilla1, FVector(0.0f, -500.0f, 100.0f));
}

void AEnemigoManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemigoManager::SpawnCuadrilla(const TArray<TSubclassOf<AEnemigo>>& Clases, FVector PosicionBase)
{
    UWorld* World = GetWorld();
    if (!World) return;

    // recorremos el array de clases para crear cada enemigo
    for (int32 i = 0; i < Clases.Num(); i++)
    {
        if (Clases[i] != nullptr)
        {
            // separamos los enemigos 150 unidades en el eje x para que no se encimen
            FVector PosicionSpawn = PosicionBase + FVector(i * 150.0f, 0.0f, 0.0f);
            FRotator Rotacion = FRotator(0.0f, 90.0f, 0.0f);

            // creamos el actor en el mundo
            AEnemigo* NuevoEnemigo = World->SpawnActor<AEnemigo>(Clases[i], PosicionSpawn, Rotacion);

            if (NuevoEnemigo)
            {
                // sumamos uno al contador de enemigos vivos
                EnemigosVivosCuadrilla1++;

                // nos suscribimos al evento de muerte de este enemigo especifico
                NuevoEnemigo->OnEnemigoDestruido.AddDynamic(this, &AEnemigoManager::OnEnemigoDestruido);
            }
        }
    }
}

void AEnemigoManager::OnEnemigoDestruido()
{
    // restamos uno al contador porque un enemigo murio
    EnemigosVivosCuadrilla1--;

    // si el contador llega a cero, significa que ya no hay enemigos de la cuadrilla 1
    if (EnemigosVivosCuadrilla1 <= 0)
    {
        // usamos el FTimerHandle para esperar unos segundos antes de sacar la otra oleada
        GetWorld()->GetTimerManager().SetTimer(
            TimerHandle_SpawnCuadrilla2,
            this,
            &AEnemigoManager::SpawnCuadrilla2Callback,
            TiempoRetrasoSegundos,
            false // false significa que el timer solo se ejecuta una vez
        );
    }
}

void AEnemigoManager::SpawnCuadrilla2Callback()
{
    // esta funcion la llama el timer cuando se acaba el tiempo
    // aqui spawneamos la segunda cuadrilla en otra posicion del mapa
    SpawnCuadrilla(ClasesCuadrilla2, FVector(0.0f, 500.0f, 100.0f));
}