#pragma once
#include "Champions.h"

class Healer :public Champions
{
public:
	Healer();
	Healer(const std::string, const Point2D&);
	virtual Healer* clone() const;
	virtual void print() const;
};
