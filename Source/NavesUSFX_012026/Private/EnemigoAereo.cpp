#include "EnemigoAereo.h"

AEnemigoAereo::AEnemigoAereo()
{
	// Los enemigos aéreos usan un cono por defecto (forma de avión)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
		MeshEnemigo->SetRelativeScale3D(FVector(1.5f, 1.0f, 0.8f));
		// Escala más pequeña para aéreos
		MeshEnemigo->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.5f));
	}

	// Los aéreos se mueven más rápido
	VelocidadMovimiento = 350.0f;
}