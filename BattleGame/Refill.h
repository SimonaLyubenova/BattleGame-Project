#pragma once

class Refill
{
private:
	//shooter weapons are abled to use all kind of Refill members
	friend class Shooters;

	int numberStartBullets;
	int numberCurrentBullets;

	void setNumberStartBullets(const int);
	int getNumberStartBullets() const;
	void setNumberCurrentBullets(const int);
	int getNumberCurrentBullets() const;
	bool hasBullets() const;

	Refill* clone() const;
	void print() const;
};
