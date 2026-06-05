// Fill out your copyright notice in the Description page of Project Settings.


#include "ETCamion.h"

AETCamion::AETCamion()
{
	// Camión de tamaño medio
	MeshEnemigo->SetRelativeScale3D(FVector(2.5f, 1.2f, 1.2f));
	VelocidadMovimiento = 180.0f;
}