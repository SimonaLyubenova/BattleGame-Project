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
	void setID(const unsigned long newID)
	{
		this->id = newID;
	}

	unsigned long getID() const
	{
		return this->id;
	}

	virtual void setNumberStartBulletsInRefill(const int) = 0;
	virtual void setNumberCurrentBulletsInRefill(const int) = 0;
	virtual bool areBulletsInRefill() const = 0;

protected:
	void setName(const std::string newName)
	{
		this->name = newName;
	}

	void setWeight(const double newWeight)
	{
		this->weight = newWeight;
	}

	void setMovementSpeed(const int newMovementSpeed)
	{
		this->movementSpeed = newMovementSpeed;
	}

	void setDamage(const int newDamage)
	{
		this->damage = newDamage;
	}

	void setStartDefense(const int newStartDefense)
	{
		this->startDefense = newStartDefense;
	}

	void setDefense(const int newDefense)
	{
		this->defense = newDefense;
	}

	void setRange(const double newRange)
	{
		this->range = newRange;
	}

	void setStatus(const WeaponStatus newStatus)
	{
		this->status = newStatus;
	}

	void setWeaponType(const WeaponType newType)
	{
		this->type = newType;
	}

	bool isShooter() const
	{
		if (getWeaponType() == WeaponType::Shooter)
		{
			return true;
		}
		return false;
	}

	void printStatus() const
	{
		std::cout << "Status: ";
		switch (getStatus())
		{
		case 0: std::cout << "Strong" << std::endl;
			break;
		case 1: std::cout << "Damaged" << std::endl;
			break;
		case 2: std::cout << "Broken" << std::endl;
			break;
		}
	}
public:
	Weapons()
	{
		setID(countWeapons + 1);
		setName("Unknown weapon");
		setWeaponType(WeaponType::None);
		setWeight(0.0);
		setDamage(0);
		setStartDefense(0);
		setDefense(0);
		setMovementSpeed(0);
		setRange(0.0);
		setStatus(WeaponStatus::Strong);
		countWeapons++;
	}

	Weapons(const Weapons& weapon)
	{
		setID(countWeapons + 1);
		setName(weapon.getName());
		setWeaponType(weapon.getWeaponType());
		setWeight(weapon.getWeight());
		setDamage(weapon.getDamage());
		setStartDefense(weapon.getStartDefense());
		setDefense(weapon.getDefense());
		setMovementSpeed(weapon.getMovementSpeed());
		setRange(weapon.getRange());
		setStatus(weapon.getStatus());
		countWeapons++;
	}

	Weapons& operator=(const Weapons& weapon) //we need to take only the type and the status, other attributes are the same
	{
		if (this != &weapon)
		{
			setWeaponType(weapon.getWeaponType());
			setStatus(weapon.getStatus());
		}
		return *this;
	}
	virtual Weapons* clone() const = 0;

	std::string getName() const
	{
		return this->name;
	}

	double getWeight() const
	{
		return this->weight;
	}

	int getMovementSpeed() const
	{
		return this->movementSpeed;
	}

	int getDamage() const
	{
		return this->damage;
	}

	int getStartDefense() const
	{
		return this->startDefense;
	}

	int getDefense() const
	{
		return this->defense;
	}

	double getRange() const
	{
		return this->range;
	}

	WeaponStatus getStatus() const
	{
		return this->status;
	}

	WeaponType getWeaponType() const
	{
		return this->type;
	}

	virtual int getNumberStartBulletsInRefill() const = 0;
	virtual int getNumberCurrentBulletsInRefill() const = 0;

	virtual void print() const
	{
		std::cout << "ID: " << getID() << std::endl;
		std::cout << "Weapon: " << getName() << std::endl;
		std::cout << "Type: ";
		switch (getWeaponType())
		{
		case 0: std::cout << "None" << std::endl;
			break;
		case 1: std::cout << "Shooters" << std::endl;
			break;
		case 2: std::cout << "Handguns" << std::endl;
			break;
		}
		std::cout << "Weight: " << getWeight() << " kg" << std::endl;
		std::cout << "Damage: " << getDamage() << std::endl;
		std::cout << "Defense: " << getDefense() << "/" << getStartDefense() << std::endl;
		std::cout << "Movement speed: " << getMovementSpeed() << " units per second" << std::endl;
		std::cout << "Range: " << getRange() << " m" << std::endl;
	}
};
