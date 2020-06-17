#pragma once
#include "Weapons.h"

class Shooters :public Weapons
{
private:
	Refill* refill = nullptr;
	void setRefill(const Refill*);
	Refill* getRefill() const;

protected:
	virtual void setNumberStartBulletsInRefill(const int);
	virtual int getNumberStartBulletsInRefill() const;
	virtual void setNumberCurrentBulletsInRefill(const int);
	virtual int getNumberCurrentBulletsInRefill() const;
	virtual bool areBulletsInRefill() const;

public:
	Shooters();
	Shooters(const Shooters&);
	Shooters& operator=(const Shooters&);
	virtual ~Shooters();
	virtual Shooters* clone() const = 0;
	virtual void print() const;
};
