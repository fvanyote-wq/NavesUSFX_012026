#include "Enemigo.h"
#include "UObject/ConstructorHelpers.h"

AEnemigo::AEnemigo()
{
    // activamos el tick para que se mueva en cada frame
    PrimaryActorTick.bCanEverTick = true;

    // creamos la malla y la ponemos como raiz del actor
    MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
    RootComponent = MeshEnemigo;

    // buscamos el cubo basico de unreal para que tenga forma visible
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    
    // si encontro la malla, se la asignamos al componente
    if (MeshAsset.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(MeshAsset.Object);
    }

    // aumentamos la escala para que se vea mejor
    MeshEnemigo->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

    // configuramos la colision para detectar cuando el jugador lo toca
    MeshEnemigo->SetGenerateOverlapEvents(true);
    MeshEnemigo->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    MeshEnemigo->OnComponentBeginOverlap.AddDynamic(this, &AEnemigo::AlSerTocado);
}

void AEnemigo::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemigo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // movemos al enemigo hacia adelante usando su velocidad
    if (MeshEnemigo)
    {
        AddActorLocalOffset(FVector(VelocidadMovimiento * DeltaTime, 0, 0));
    }
}

void AEnemigo::Morir()
{
    // emitimos la senal al delegado para que el manager se entere
    OnEnemigoDestruido.Broadcast();
    // destruimos el actor del escenario
    Destroy();
}

void AEnemigo::AlSerTocado(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // si lo toca otro actor que no sea el mismo, lo matamos
    if (OtherActor && OtherActor != this)
    {
        Morir();
    }
}