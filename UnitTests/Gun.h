#pragma once
#include "Shooters.h"

class Gun :public Shooters
{
public:
	Gun() :Shooters()
	{
		setNumberStartBulletsInRefill(20);
		setNumberCurrentBulletsInRefill(getNumberStartBulletsInRefill());
		setName("Gun");
		setWeaponType(WeaponType::Shooter);
		setWeight(1.75);
		setDamage(80);
		setStartDefense(3);
		setDefense(getStartDefense());
		setMovementSpeed(130);
		setRange(35.0);
	}

	virtual Gun* clone() const
	{
		return new Gun(*this);
	}

	virtual void print() const
	{
		Shooters::print();
	}
};
