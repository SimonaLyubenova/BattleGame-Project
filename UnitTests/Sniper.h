#pragma once
#include <iostream>
#include <string>
#include "Shooters.h"

class Sniper :public Shooters
{
public:
	Sniper() :Shooters()
	{
		setNumberStartBulletsInRefill(10);
		setNumberCurrentBulletsInRefill(getNumberStartBulletsInRefill());
		setName("Sniper");
		setWeaponType(WeaponType::Shooter);
		setWeight(8.0);
		setDamage(100);
		setStartDefense(4);
		setDefense(getStartDefense());
		setMovementSpeed(200);
		setRange(70.0);
	}
	
	virtual Sniper* clone() const
	{
		return new Sniper(*this);
	}

	virtual void print() const
	{
		Shooters::print();
	}
};
