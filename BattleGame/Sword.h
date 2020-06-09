#pragma once
#include "Handguns.h"

class Sword :public Handguns
{
public:
	Sword();
	virtual Sword* clone() const;
	virtual void print() const;
};
