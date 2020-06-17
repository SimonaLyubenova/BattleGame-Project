#pragma once
#include "Champions.h"

class Healer :public Champions
{
public:
	Healer() :Champions()
	{
		setName("Unknown healer");
		setCategory(Healers);
		setStartHealth(1000);
		setHealth(getStartHealth());
		setSpell("Heal");
	}

	Healer(const std::string newName, const Point2D& point) :Champions(newName, point)
	{
		setCategory(Healers);
		setStartHealth(1000);
		setHealth(getStartHealth());
		setSpell("Heal");
	}

	virtual Healer* clone() const
	{
		return new Healer(*this);
	}

	void heal(Champions& champion)
	{
		this->increaseHealthTo(champion);
	}

	virtual void print() const
	{
		Champions::print();
	}
};
