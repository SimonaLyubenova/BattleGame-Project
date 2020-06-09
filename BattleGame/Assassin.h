#pragma once
#include "Champions.h"

class Assassin :public Champions
{
public:
	Assassin();
	Assassin(const std::string, const Point2D&);
	virtual Assassin* clone() const;
	virtual void print() const;
};
