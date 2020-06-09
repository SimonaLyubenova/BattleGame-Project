#include "Human.h"

Human::Human() :Champions()
{
	setName("Unknown human");
	setSpell("Barrier");
}

Human::Human(const std::string newName, const Point2D& point) :Champions(newName, point)
{
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