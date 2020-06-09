#pragma once
#include <iostream>

class Refill
{
private:
	int numberStartBullets;
	int numberBullets;

public:
	Refill(const int);
	Refill* clone() const; //this function help us in class Shooter where we set a refill
	void setNumberStartBullets(const int);
	int getNumberStartBullets() const;
	void setNumberBullets(const int);
	int getNumberBullets() const;
	bool hasBullets() const;
	void print() const;
};
