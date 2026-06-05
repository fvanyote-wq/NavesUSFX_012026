// Fill out your copyright notice in the Description page of Project Settings.


#include "ETSoldado.h"

AETSoldado::AETSoldado()
{
	// Soldado más pequeño (usa cápsula o cubo pequeño)
	MeshEnemigo->SetRelativeScale3D(FVector(0.6f, 0.6f, 1.2f));
	VelocidadMovimiento = 150.0f;
}