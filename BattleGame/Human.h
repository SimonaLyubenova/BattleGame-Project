#pragma once
#include "Champions.h"

class Human :public Champions
{
public:
	Human();
	Human(const std::string, const Point2D&);
	virtual Human* clone() const;
	virtual void print() const;
};
