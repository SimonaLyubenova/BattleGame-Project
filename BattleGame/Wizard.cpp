#include "Wizard.h"

Wizard::Wizard() :Champions()
{
	setName("Unknown wizard");
	setCategory(Wizards);
	setHealth(1800);
	setSpell("Magic");
}

Wizard::Wizard(const std::string newName, const Point2D& point) :Champions(newName, point)
{
	setCategory(Wizards);
	setHealth(1800);
	setSpell("Magic");
}

Wizard* Wizard::clone() const
{
	return new Wizard(*this);
}

void Wizard::print() const
{
	Champions::print();
}