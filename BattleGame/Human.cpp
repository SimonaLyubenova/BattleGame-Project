#include "Human.h"

Human::Human() :Champions()
{
	setName("Unknown human");
	setCategory(Category::Humans);
	setStartHealth(500);
	setHealth(getStartHealth());
	setSpell("Barrier");
}

Human::Human(const std::string newName, const Point2D& point) :Champions(newName, point)
{
	setCategory(Category::Humans);
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