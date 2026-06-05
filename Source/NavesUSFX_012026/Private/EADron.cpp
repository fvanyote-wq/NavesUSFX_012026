// Fill out your copyright notice in the Description page of Project Settings.


#include "EADron.h"

AEADron::AEADron()
{
	// Dron más pequeño y lento
	MeshEnemigo->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	VelocidadMovimiento = 250.0f;
}