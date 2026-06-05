// Fill out your copyright notice in the Description page of Project Settings.


#include "EALancha.h"

AEALancha::AEALancha()
{
	// Lancha rápida y pequeña
	MeshEnemigo->SetRelativeScale3D(FVector(1.5f, 0.5f, 0.5f));
	VelocidadMovimiento = 220.0f;
}