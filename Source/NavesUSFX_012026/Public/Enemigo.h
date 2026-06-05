#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Enemigo.generated.h"

// delegado para avisar cuando el enemigo muere
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnemigoDestruido);

UCLASS()
class NAVESUSFX_012026_API AEnemigo : public AActor
{
    GENERATED_BODY()

public:
    AEnemigo();

    // la malla que se ve en el escenario
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
    UStaticMeshComponent* MeshEnemigo;

    // evento que avisa cuando muere
    UPROPERTY(BlueprintAssignable, Category = "Eventos")
    FOnEnemigoDestruido OnEnemigoDestruido;

    // velocidad de movimiento
    UPROPERTY(EditAnywhere, Category = "Movimiento")
    float VelocidadMovimiento = 200.0f;

    // funcion que se llama cuando algo lo toca
    UFUNCTION()
    void AlSerTocado(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // funcion para matar al enemigo
    UFUNCTION(BlueprintCallable, Category = "Estado")
    virtual void Morir();
};