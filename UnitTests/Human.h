#pragma once
#include "Champions.h"

class Human :public Champions
{
public:
	Human() :Champions()
	{
		setName("Unknown human");
		setCategory(Humans);
		setStartHealth(500);
		setHealth(getStartHealth());
		setSpell("Barrier");
	}

	Human(const std::string newName, const Point2D& point) :Champions(newName, point)
	{
		setCategory(Humans);
		setStartHealth(500);
		setHealth(getStartHealth());
		setSpell("Barrier");
	}

	virtual Human* clone() const
	{
		return new Human(*this);
	}

	virtual void print() const
	{
		Champions::print();
	}
};
