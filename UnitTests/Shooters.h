#pragma once
#include <iostream>
#include <string>
#include "Weapons.h"

class Shooters :public Weapons
{
private:
	Refill* refill = nullptr;

protected:
	virtual void setNumberStartBulletsInRefill(const int newNumberStartBullets)
	{
		getRefill()->setNumberStartBullets(newNumberStartBullets);
	}

	virtual void setNumberCurrentBulletsInRefill(const int newNumberCurrentBullets)
	{
		getRefill()->setNumberCurrentBullets(newNumberCurrentBullets);
	}

	virtual bool areBulletsInRefill() const
	{
		if (getNumberCurrentBulletsInRefill() > 0)
		{
			return true;
		}
		return false;
	}

public:
	Shooters() :Weapons()
	{
		this->refill = new Refill(10);
		this->refill->setNumberStartBullets(10);
		setName("Unknown shooter");
		setWeaponType(WeaponType::Shooter);
	}

	Shooters(const Shooters& shooter) :Weapons(shooter)
	{
		setRefill(shooter.getRefill());
	}

	Shooters& operator=(const Shooters& shooter)
	{
		if (this != &shooter)
		{
			Weapons::operator=(shooter);
			setRefill(shooter.getRefill());
		}
		return *this;
	}

	virtual ~Shooters()
	{
		delete this->refill;
	}

	virtual Shooters* clone() const=0;

	void setRefill(const Refill* newRefill)
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

	Refill* getRefill() const
	{
		return this->refill;
	}

	virtual int getNumberStartBulletsInRefill() const
	{
		return getRefill()->getNumberStartBullets();
	}

	virtual int getNumberCurrentBulletsInRefill() const
	{
		return getRefill()->getNumberCurrentBullets();
	}

	virtual void print() const
	{
		Weapons::print();
		getRefill()->Refill::print();
		Weapons::printStatus();
	}
};
