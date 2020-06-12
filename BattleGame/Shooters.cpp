#include "Shooters.h"

Shooters::Shooters() :Weapons()
{
	this->refill = new Refill(10);
	this->refill->setNumberStartBullets(10);
	setName("Unknown shooter");
	setWeaponType(WeaponType::Shooter);
}

Shooters::Shooters(const Shooters& shooter) :Weapons(shooter)
{
	setRefill(shooter.getRefill());
}

Shooters& Shooters::operator=(const Shooters& shooter)
{
	if (this != &shooter)
	{
		Weapons::operator=(shooter);
		setRefill(shooter.getRefill());
	}
	return *this;
}

Shooters::~Shooters()
{
	delete this->refill;
}

void Shooters::setRefill(const Refill* newRefill)
{
	if (newRefill == nullptr)
	{
		delete this->refill;
		this->refill = nullptr;
		return;
	}
	delete this->refill;
	this->refill = newRefill->clone();
}

Refill* Shooters::getRefill() const
{
	return this->refill;
}

void Shooters::setNumberStartBulletsOfRefill(const int newNumberStartBullets)
{
	getRefill()->setNumberStartBullets(newNumberStartBullets);
}

int Shooters::getNumberStartBulletsOfRefill() const
{
	return getRefill()->getNumberStartBullets();
}

void Shooters::setNumberCurrentBulletsOfRefill(const int newNumberCurrentBullets)
{
	getRefill()->setNumberCurrentBullets(newNumberCurrentBullets);
}

int Shooters::getNumberCurrentBulletsOfRefill() const
{
	return getRefill()->getNumberCurrentBullets();
}

bool Shooters::areBulletsInRefill() const
{
	if (getRefill()->getNumberCurrentBullets() > 0)
	{
		return true;
	}
	return false;
}

void Shooters::print() const
{
	Weapons::print();
	getRefill()->Refill::print();
	Weapons::printStatus();
}