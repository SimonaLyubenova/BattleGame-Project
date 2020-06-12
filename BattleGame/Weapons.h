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
	friend class Champions;
	unsigned long id;
	std::string name;
	double weight;
	int damage;
	int startDefense;
	int defense;
	int movementSpeed;
	double range;
	WeaponType type;
	WeaponStatus status;
	void setID(const unsigned long);
	unsigned long getID() const;

	virtual void setNumberStartBulletsOfRefill(const int) = 0;
	virtual int getNumberStartBulletsOfRefill() const = 0;
	virtual void setNumberCurrentBulletsOfRefill(const int) = 0;
	virtual int getNumberCurrentBulletsOfRefill() const = 0;
	virtual bool areBulletsInRefill() const = 0;

protected:
	void setName(const std::string);
	std::string getName() const;
	void setWeaponType(const WeaponType);
	WeaponType getWeaponType() const;
	void setWeight(const double);
	double getWeight() const;
	void setDamage(const int);
	int getDamage() const;
	void setStartDefense(const int);
	int getStartDefense() const;
	void setDefense(const int);
	int getDefense() const;
	void setMovementSpeed(const int);
	int getMovementSpeed() const;
	void setRange(const double);
	double getRange() const;
	void setStatus(const WeaponStatus);
	WeaponStatus getStatus() const;
	bool isShooter() const;

	void printStatus() const;
public:
	Weapons();
	Weapons(const Weapons&);
	Weapons& operator=(const Weapons&);
	virtual Weapons* clone() const = 0;

	virtual void print() const;
};
