#pragma once
#include "Champions.h"

class Wizard :public Champions
{
public:
	Wizard();
	Wizard(const std::string, const Point2D&);
	virtual Wizard* clone() const;
	void breakWeaponTo(Champions&);
	virtual void print() const;
};
