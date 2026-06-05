// Fill out your copyright notice in the Description page of Project Settings.


#include "ETBlindado.h"

AETBlindado::AETBlindado()
{
	// Blindado muy grande y lento
	MeshEnemigo->SetRelativeScale3D(FVector(2.2f, 1.8f, 1.3f));
	VelocidadMovimiento = 100.0f;
}