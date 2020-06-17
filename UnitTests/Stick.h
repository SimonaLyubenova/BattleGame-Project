#pragma once
#include "Handguns.h"

class Stick :public Handguns
{
private:
	double length;
	void setLength(const double newLength)
	{
		this->length = newLength;
	}

	double getLength() const
	{
		return this->length;
	}

public:
	Stick() :Handguns()
	{
		setName("Stick");
		setWeaponType(WeaponType::Handgun);
		setWeight(1);
		setDamage(30);
		setStartDefense(15);
		setDefense(getStartDefense());
		setMovementSpeed(500);
		setRange(1.2);
		setLength(1.2);
	}
	virtual Stick* clone() const
	{
		return new Stick(*this);
	}
	virtual void print() const
	{
		Handguns::print();
		std::cout << "Length: " << getLength() << " m" << std::endl;
		Weapons::printStatus();
	}
};
