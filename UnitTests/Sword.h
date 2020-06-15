#pragma once
#include "Handguns.h"

class Sword :public Handguns
{
public:
	Sword() :Handguns()
	{
		setName("Sword");
		setWeaponType(WeaponType::Handgun);
		setWeight(2.5);
		setDamage(50);
		setStartDefense(25);
		setDefense(getStartDefense());
		setMovementSpeed(410);
		setRange(1.5);
	}

	virtual Sword* clone() const
	{
		return new Sword(*this);
	}

	virtual void print() const 
	{
		Handguns::print();
	}
};
