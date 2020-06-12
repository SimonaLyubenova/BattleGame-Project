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

	void setNumberStartBullets(const int);
	int getNumberStartBullets() const;
	void setNumberCurrentBullets(const int);
	int getNumberCurrentBullets() const;
	bool hasBullets() const;

public:
	Refill(const int);
	Refill* clone() const;
	void print() const;
};
