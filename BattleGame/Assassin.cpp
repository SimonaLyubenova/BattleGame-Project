#include "Assassin.h"

Assassin::Assassin() :Champions()
{
	setName("Unknown assassin");
	setCategory(Assassins);
	setHealth(1500);
	setSpell("Ignite");
}

Assassin::Assassin(const std::string newName, const Point2D& point) :Champions(newName, point)
{
	setCategory(Assassins);
	setHealth(1500);
	setSpell("Ignite");
}

Assassin* Assassin::clone() const
{
	return new Assassin(*this);
}

void Assassin::print() const
{
	Champions::print();
}