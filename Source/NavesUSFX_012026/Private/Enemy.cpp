#include "Enemy.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	// Crear malla como raiz
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	// Malla
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (DefaultMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(DefaultMesh.Object);
	}
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Si no hay waypoints usar unos por defecto
	if (Waypoints.Num() == 0)
	{
		Waypoints.Add(GetActorLocation() + FVector(0.f, 500.f, 100.f));
		Waypoints.Add(GetActorLocation() + FVector(500.f, -500.f, 100.f));
		Waypoints.Add(GetActorLocation() + FVector(-500.f, -500.f, 100.f));
	}

	// Mover hacia el waypoint actual
	FVector Objetivo = Waypoints[IndiceWaypoint];
	MoverHacia(Objetivo, DeltaTime);
}

void AEnemy::MoverHacia(const FVector& Objetivo, float DeltaTime)
{
	FVector Direccion = Objetivo - GetActorLocation();
	float Distancia = Direccion.Size();

	// Si llego al waypoint, pasar al siguiente
	if (Distancia < 10.f)
	{
		IndiceWaypoint = (IndiceWaypoint + 1) % Waypoints.Num();
	}
	else
	{
		// Mover suavemente
		Direccion.Normalize();
		AddActorWorldOffset(Direccion * Velocidad * DeltaTime, true);
	}
}