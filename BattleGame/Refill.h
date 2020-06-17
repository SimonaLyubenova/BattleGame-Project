#pragma once

class Refill
{
private:
	//shooter weapons are abled to use all kind of Refill members
	friend class Shooters;
	friend class Sniper;
	friend class Gun;

	int numberStartBullets;
	int numberCurrentBullets;

	void setNumberStartBullets(const int);
	int getNumberStartBullets() const;
	void setNumberCurrentBullets(const int);
	int getNumberCurrentBullets() const;
	bool hasBullets() const;

	Refill* clone() const;

public:
	Refill(const int);
	void print() const;
};
