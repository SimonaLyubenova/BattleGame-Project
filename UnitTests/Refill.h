#pragma once
#include <iostream>

class Refill
{
private:
	friend class Shooters;
	friend class Sniper;
	friend class Gun;
	int numberStartBullets;
	int numberCurrentBullets;

	void setNumberCurrentBullets(const int numberBullets)
	{
		this->numberCurrentBullets = numberBullets;
	}

	int getNumberCurrentBullets() const
	{
		return this->numberCurrentBullets;
	}

	void setNumberStartBullets(const int newStartBullets)
	{
		this->numberStartBullets = newStartBullets;
	}
	int getNumberStartBullets() const
	{
		return this->numberStartBullets;
	}

	bool hasBullets() const
	{
		if (getNumberCurrentBullets() > 0)
		{
			return true;
		}
		return false;
	}

public:
	Refill(const int numberBullets)
	{
		setNumberCurrentBullets(numberBullets);
		setNumberStartBullets(numberBullets);
	}

	Refill* clone() const
	{
		return new Refill(*this);
	}
	void print() const
	{
		std::cout << "Bullets: " << getNumberCurrentBullets() << "/" << getNumberStartBullets() << std::endl;
	}
};
