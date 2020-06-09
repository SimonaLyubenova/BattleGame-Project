#pragma once
#include "Handguns.h"

class Stick :public Handguns
{
private:
	double length;
	void setLength(const double);
	double getLength() const;

public:
	Stick();
	virtual Stick* clone() const;
	virtual void print() const;
};
