#include "Sword.h"

Sword::Sword() :Handguns()
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

Sword* Sword::clone() const
{
	return new Sword(*this);
}

void Sword::print() const 
{
	Handguns::print();
	Weapons::printStatus();
}