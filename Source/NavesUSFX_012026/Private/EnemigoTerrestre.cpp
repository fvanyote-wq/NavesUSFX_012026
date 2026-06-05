#include "EnemigoTerrestre.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
	// Los enemigos terrestres usan un cubo por defecto (forma de tanque/vehículo)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
		MeshEnemigo->SetRelativeScale3D(FVector(1.5f, 1.0f, 0.8f));
	}

	// Velocidad media para terrestres
	VelocidadMovimiento = 200.0f;
}