#include "Assassin.h"

Assassin::Assassin() :Champions()
{
	setName("Unknown assassin");
	setCategory(Category::Assassins);
	setStartHealth(1500);
	setHealth(getStartHealth());
	setSpell("Ignite");
}

Assassin::Assassin(const std::string newName, const Point2D& point) :Champions(newName, point)
{
	setCategory(Category::Assassins);
	setStartHealth(1500);
	setHealth(getStartHealth());
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