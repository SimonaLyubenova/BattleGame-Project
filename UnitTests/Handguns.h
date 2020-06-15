#pragma once
#include "Weapons.h"

class Handguns :public Weapons
{
private:
	virtual void setNumberStartBulletsInRefill(const int newNumberStartBullets) {}
	virtual void setNumberCurrentBulletsInRefill(const int newNumberCurrentBullets) {}
	virtual bool areBulletsInRefill() const { return false; }
public:
	Handguns::Handguns() :Weapons()
	{
		setName("Unknown handgun");
		setWeaponType(WeaponType::Handgun);
	}
	virtual Handguns* clone() const=0;

	virtual int getNumberStartBulletsInRefill() const { return 0; }
	virtual int getNumberCurrentBulletsInRefill() const { return 0; }

	virtual void print() const
	{
		Weapons::print();
		Weapons::printStatus();
	}
};
