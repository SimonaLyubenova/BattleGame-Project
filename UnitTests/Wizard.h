#pragma once
#include "Champions.h"

class Wizard :public Champions
{
public:
	Wizard() :Champions()
	{
		setName("Unknown wizard");
		setCategory(Wizards);
		setStartHealth(1800);
		setHealth(getStartHealth());
		setSpell("Magic");
	}

	Wizard(const std::string newName, const Point2D& point) :Champions(newName, point)
	{
		setCategory(Wizards);
		setStartHealth(1800);
		setHealth(getStartHealth());
		setSpell("Magic");
	}

	virtual Wizard* clone() const
	{
		return new Wizard(*this);
	}

	void breakWeaponTo(Champions& champion)
	{
		this->makeWeaponBrokenTo(champion);
	}

	virtual void print() const
	{
		Champions::print();
	}
};
