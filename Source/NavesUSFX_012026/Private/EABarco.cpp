// Fill out your copyright notice in the Description page of Project Settings.


#include "EABarco.h"

AEABarco::AEABarco()
{
	// Barco grande
	MeshEnemigo->SetRelativeScale3D(FVector(3.0f, 0.8f, 0.8f));
	VelocidadMovimiento = 130.0f;
}