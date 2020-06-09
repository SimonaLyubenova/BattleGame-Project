#pragma once
#include "Weapons.h"

class Handguns :public Weapons
{
public:
	Handguns();

	virtual Handguns* clone() const=0;

	virtual void setRefill(const Refill*);
	virtual Refill* getRefill() const;

	virtual void print() const;
};
