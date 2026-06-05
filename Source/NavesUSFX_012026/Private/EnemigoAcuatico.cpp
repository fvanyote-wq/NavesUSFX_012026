#include "EnemigoAcuatico.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
	// Los enemigos acuáticos usan una esfera o cilindro (forma de barco)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
		// Rotar para que quede horizontal
		MeshEnemigo->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
		MeshEnemigo->SetRelativeScale3D(FVector(2.0f, 0.5f, 0.5f));
	}

	// Velocidad lenta para acuáticos
	VelocidadMovimiento = 150.0f;
}