#include "Handguns.h"

Handguns::Handguns() :Weapons()
{
	setName("Unknown handgun");
	setWeaponType(WeaponType::Handgun);
}

void Handguns::setNumberStartBulletsOfRefill(const int newNumberStartBullets) {}
int Handguns::getNumberStartBulletsOfRefill() const { return 0; }
void Handguns::setNumberCurrentBulletsOfRefill(const int newNumberCurrentBullets) {}
int Handguns::getNumberCurrentBulletsOfRefill() const { return 0; }
bool Handguns::areBulletsInRefill() const { return false; }

void Handguns::print() const
{
	Weapons::print();
	Weapons::printStatus();
}