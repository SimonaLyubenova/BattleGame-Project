#pragma once
#include "Champions.h"

class Healer :public Champions
{
public:
	Healer();
	Healer(const std::string, const Point2D&);
	virtual Healer* clone() const;
	void heal(Champions&);
	virtual void print() const;
};
