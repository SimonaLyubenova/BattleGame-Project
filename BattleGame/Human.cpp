#include "Human.h"

Human::Human() :Champions()
{
	setName("Unknown human");
	setCategory(Humans);
	setStartHealth(500);
	setHealth(getStartHealth());
	setSpell("Barrier");
}

Human::Human(const std::string newName, const Point2D& point) :Champions(newName, point)
{
	setCategory(Humans);
	setStartHealth(500);
	setHealth(getStartHealth());
	setSpell("Barrier");
}

Human* Human::clone() const
{
	return new Human(*this);
}

void Human::print() const
{
	Champions::print();
}