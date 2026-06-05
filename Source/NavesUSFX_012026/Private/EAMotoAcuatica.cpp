// Fill out your copyright notice in the Description page of Project Settings.


#include "EAMotoAcuatica.h"

AEAMotoAcuatica::AEAMotoAcuatica()
{
	// Moto acuática muy rápida y pequeña
	MeshEnemigo->SetRelativeScale3D(FVector(1.0f, 0.4f, 0.4f));
	VelocidadMovimiento = 280.0f;
}