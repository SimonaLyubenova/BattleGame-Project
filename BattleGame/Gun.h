#pragma once
#include "Shooters.h"

class Gun :public Shooters
{
public:
	Gun();
	virtual Gun* clone() const;
	virtual void print() const;
};
