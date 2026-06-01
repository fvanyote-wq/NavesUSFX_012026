#include "SpawnerEnemigos.h"
#include "Components/SceneComponent.h"
#include "Enemy.h"

ASpawnerEnemigos::ASpawnerEnemigos()
{
	PrimaryActorTick.bCanEverTick = false;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));

}

void ASpawnerEnemigos::BeginPlay()
{
	Super::BeginPlay();

	//validacion
	if (!ClaseEnemigo)
	{
		return;
	}

	// parametros seguros de spawn
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	//Bucle de generacion en BeginPlay
	for (int32 i = 0; i < Cantidad; ++i)
	{
		FVector Posicion = GetActorLocation() + (Espaciado * i);
		GetWorld()->SpawnActor<AEnemy>(ClaseEnemigo, Posicion, FRotator::ZeroRotator, Params);
	}
}