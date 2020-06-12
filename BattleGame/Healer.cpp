#include "Healer.h"

Healer::Healer() :Champions()
{
	setName("Unknown healer");
	setCategory(Healers);
	setStartHealth(1000);
	setHealth(getStartHealth());
	setSpell("Heal");
}

Healer::Healer(const std::string newName, const Point2D& point) :Champions(newName, point)
{
	setCategory(Healers);
	setStartHealth(1000);
	setHealth(getStartHealth());
	setSpell("Heal");
}

Healer* Healer::clone() const
{
	return new Healer(*this);
}

void Healer::heal(Champions& champion)
{
	this->makeHeal(champion);
}

void Healer::print() const
{
	Champions::print();
}