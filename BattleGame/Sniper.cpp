#include "Sniper.h"

Sniper::Sniper() :Shooters()
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

Sniper* Sniper::clone() const
{
	return new Sniper(*this);
}

void Sniper::print() const
{
	Shooters::print();
}