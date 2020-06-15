#pragma once
#include "Champions.h"

class Assassin :public Champions
{
public:
	Assassin() :Champions()
    {
        setName("Unknown assassin");
        setCategory(Assassins);
        setStartHealth(1500);
        setHealth(getStartHealth());
        setSpell("Ignite");
    }

    Assassin(const std::string newName, const Point2D& point) :Champions(newName, point)
    {
        setCategory(Assassins);
        setStartHealth(1500);
        setHealth(getStartHealth());
        setSpell("Ignite");
    }

    virtual Assassin* clone() const
    {
        return new Assassin(*this);
    }

    virtual void print() const
    {
        Champions::print();
    }
};
