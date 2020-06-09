#include "Stick.h"

Stick::Stick() :Handguns()
{
	setName("Stick");
	setWeaponType(WeaponType::Handgun);
	setWeight(1);
	setDamage(30);
	setStartDefense(15);
	setDefense(getStartDefense());
	setMovementSpeed(90);
	setRange(1.2);
	setLength(1.2);
}

Stick* Stick::clone() const
{
	return new Stick(*this);
}

void Stick::setLength(const double newLength)
{
	this->length = newLength;
}

double Stick::getLength() const
{
	return this->length;
}

void Stick::print() const
{
	Handguns::print();
	std::cout << "Length: " << getLength() << " m" << std::endl;
	Weapons::printStatus();
}
