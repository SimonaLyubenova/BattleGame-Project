#pragma once
#include "Shooters.h"

class Sniper :public Shooters
{
public:
	Sniper();
	virtual Sniper* clone() const;
	virtual void print() const;
};
