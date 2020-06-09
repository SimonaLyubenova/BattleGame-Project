#include "Handguns.h"

Handguns::Handguns() :Weapons()
{
	setName("Unknown handgun");
	setWeaponType(WeaponType::Handgun);
}

void Handguns::setRefill(const Refill*) {};
Refill* Handguns::getRefill() const { return nullptr; }

void Handguns::print() const
{
	Weapons::print();
}