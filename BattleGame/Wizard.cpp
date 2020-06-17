#include "Wizard.h"

Wizard::Wizard() :Champions()
{
	setName("Unknown wizard");
	setCategory(Category::Wizards);
	setStartHealth(1800);
	setHealth(getStartHealth());
	setSpell("Magic");
}

Wizard::Wizard(const std::string newName, const Point2D& point) :Champions(newName, point)
{
	setCategory(Category::Wizards);
	setStartHealth(1800);
	setHealth(getStartHealth());
	setSpell("Magic");
}

Wizard* Wizard::clone() const
{
	return new Wizard(*this);
}

void Wizard::breakWeaponTo(Champions& champion)
{
	this->makeWeaponBrokenTo(champion);
}

void Wizard::print() const
{
	Champions::print();
}