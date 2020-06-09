#include "Healer.h"

Healer::Healer() :Champions()
{
	setName("Unknown healer");
	setCategory(Healers);
	setHealth(1000);
	setSpell("Heal");
}

Healer::Healer(const std::string newName, const Point2D& point) :Champions(newName, point)
{
	setCategory(Healers);
	setHealth(1000);
	setSpell("Heal");
}

Healer* Healer::clone() const
{
	return new Healer(*this);
}

void Healer::print() const
{
	Champions::print();
}