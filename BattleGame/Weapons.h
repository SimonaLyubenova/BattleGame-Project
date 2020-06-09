#pragma once
#include <iostream>
#include <string>
#include "WeaponStatus.h"
#include "WeaponType.h"
#include "Refill.h"

static unsigned long countWeapons = 0;

class Weapons
{
private:
	unsigned long id;
	std::string name;
	double weight;
	int damage;
	int defense;
	int startDefense;
	int movementSpeed;
	double range;

	WeaponType type;
	WeaponStatus status;

	void setID(const unsigned long);
	unsigned long getID() const;

protected:
	void setName(const std::string);

	void setWeaponType(const WeaponType);

	void setWeight(const double);
	double getWeight() const;
	
	void setStartDefense(const int);
	
	void setMovementSpeed(const int);
	int getMovementSpeed() const;
	void setRange(const double);
	
	void printStatus() const;
	
public:
	Weapons();
	Weapons(const Weapons&);
	Weapons& operator=(const Weapons&);
	virtual Weapons* clone() const=0;
	virtual void setRefill(const Refill*) = 0;
	virtual Refill* getRefill() const = 0;

	std::string getName() const;

	void setDamage(const int);
	int getDamage() const;

	int getStartDefense() const;
	void setDefense(const int);
	int getDefense() const;
	double getRange() const;

	bool isShooter() const;

	WeaponType getWeaponType() const;

	void setStatus(const WeaponStatus);
	WeaponStatus getStatus() const;

	virtual void print() const;
};
