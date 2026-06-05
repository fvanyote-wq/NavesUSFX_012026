// Fill out your copyright notice in the Description page of Project Settings.


#include "ETTanque.h"

AETTanque::AETTanque()
{
	// Tanque más grande y lento
	MeshEnemigo->SetRelativeScale3D(FVector(2.0f, 1.5f, 1.0f));
	VelocidadMovimiento = 120.0f;
}
