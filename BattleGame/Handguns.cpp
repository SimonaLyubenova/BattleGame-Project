#include "Handguns.h"

Handguns::Handguns() :Weapons()
{
	setName("Unknown handgun");
	setWeaponType(WeaponType::Handgun);
}

void Handguns::setNumberStartBulletsInRefill(const int newNumberStartBullets) {}
int Handguns::getNumberStartBulletsInRefill() const { return 0; }
void Handguns::setNumberCurrentBulletsInRefill(const int newNumberCurrentBullets) {}
int Handguns::getNumberCurrentBulletsInRefill() const { return 0; }
bool Handguns::areBulletsInRefill() const { return false; }

void Handguns::print() const
{
	Weapons::print();
}