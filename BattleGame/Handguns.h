#pragma once
#include "Weapons.h"

class Handguns :public Weapons
{
private:
	virtual void setNumberStartBulletsInRefill(const int);
	virtual int getNumberStartBulletsInRefill() const;
	virtual void setNumberCurrentBulletsInRefill(const int);
	virtual int getNumberCurrentBulletsInRefill() const;
	virtual bool areBulletsInRefill() const;
public:
	Handguns();
	virtual Handguns* clone() const = 0;
	virtual void print() const;
};
