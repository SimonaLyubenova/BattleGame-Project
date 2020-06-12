#pragma once
#include "Weapons.h"

class Handguns :public Weapons
{
private:
	virtual void setNumberStartBulletsOfRefill(const int);
	virtual int getNumberStartBulletsOfRefill() const;
	virtual void setNumberCurrentBulletsOfRefill(const int);
	virtual int getNumberCurrentBulletsOfRefill() const;
	virtual bool areBulletsInRefill() const;
public:
	Handguns();
	virtual Handguns* clone() const=0;
	virtual void print() const;
};
