#pragma once
#include <iostream>
#include <string>
#include "Weapons.h"

class Shooters :public Weapons
{
private:
	Refill* refill = nullptr;

public:
	Shooters();
	Shooters(const Shooters&);
	Shooters& operator=(const Shooters&);
	virtual ~Shooters();

	virtual Shooters* clone() const=0;

	virtual void setRefill(const Refill*);
	virtual Refill* getRefill() const;

	virtual void print() const;
};
