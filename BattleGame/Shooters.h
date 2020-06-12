#pragma once
#include <iostream>
#include <string>
#include "Weapons.h"

class Shooters :public Weapons
{
private:
	Refill* refill = nullptr;

	virtual void setNumberStartBulletsOfRefill(const int);
	virtual int getNumberStartBulletsOfRefill() const;
	virtual void setNumberCurrentBulletsOfRefill(const int);
	virtual int getNumberCurrentBulletsOfRefill() const;
	virtual bool areBulletsInRefill() const;

public:
	Shooters();
	Shooters(const Shooters&);
	Shooters& operator=(const Shooters&);
	virtual ~Shooters();

	virtual Shooters* clone() const=0;

	void setRefill(const Refill*);
	Refill* getRefill() const;

	virtual void print() const;
};
