// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FearCharacter.h"
#include "WeaponBase.generated.h"

UCLASS(Blueprintable)
class FEAR_API UWeaponBase : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UWeaponBase(AFearCharacter* owner);
	UWeaponBase();

	virtual void PrimaryFire();
	virtual void SecondaryFire();
	virtual void ShootPrimary(); //Deals with subtracting ammo and casting shoot ray
	virtual void ShootEffects(); //Plays anims and sound

	virtual void Reload();

protected:

	UPROPERTY(EditAnywhere)
	int PrimaryAmmo = 15;

	UPROPERTY(EditAnywhere)
	int PrimaryAmmoMax = 30;

	UPROPERTY(EditAnywhere)
	class USoundBase* FireSound;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* FireAnimation;

public:
	UStaticMesh* GetWorldModel();

private:

	AFearCharacter* owner;
	ShootOrientation* GetShootOrientation();
	USkeletalMeshComponent* Mesh1P;


};
