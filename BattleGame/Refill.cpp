#include "Refill.h"

Refill::Refill(const int numberBullets)
{
	setNumberBullets(numberBullets);
	setNumberStartBullets(numberBullets);
}

Refill* Refill::clone() const
{
	return new Refill(*this);
}

void Refill::setNumberBullets(const int numberBullets)
{
	this->numberBullets = numberBullets;
}

int Refill::getNumberBullets() const
{
	return this->numberBullets;
}

void Refill::setNumberStartBullets(const int newStartBullets)
{
	this->numberStartBullets = newStartBullets;
}
int Refill::getNumberStartBullets() const
{
	return this->numberStartBullets;
}

bool Refill::hasBullets() const
{
	if (getNumberBullets() > 0)
	{
		return true;
	}
	return false;
}

void Refill::print() const
{
	std::cout << "Bullets: " << getNumberBullets() << std::endl;
}