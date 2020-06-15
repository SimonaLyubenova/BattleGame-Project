#pragma once
#include <iostream>
#include <string>
#include "Point3D.h"
#include "Weapons.h"
#include "Category.h"

static unsigned long countChampoins = 0;

class Champions
{
private:
	unsigned long championNumber;
	std::string name;
	int startHealth;
	int health;
	std::string spell;
	Category category;
	Point2D* location = nullptr;
	Weapons* weapon = nullptr;

	void setChampionNumber(const unsigned long newChampionNumber)
	{
		this->championNumber = newChampionNumber;
	}

	unsigned long getChampionNumber() const
	{
		return this->championNumber;
	}

	bool isTheSameAs(const Champions& champion) const
	{
		if (getChampionNumber() == champion.getChampionNumber())
		{
			return true;
		}
		return false;
	}

	void setLocation(const Point2D* newLocation)
	{
		if (newLocation == nullptr)
		{
			delete this->location;
			this->location = nullptr;
			return;
		}
		delete this->location;
		this->location = newLocation->clone();
	}

	bool hasLocation() const
	{
		if (getLocation())
		{
			return true;
		}
		return false;
	}

	void setWeapon(const Weapons* newWeapon)
	{
		if (newWeapon == nullptr)
		{
			delete this->weapon;
			this->weapon = nullptr;
			return;
		}
		delete this->weapon;
		this->weapon = newWeapon->clone();
	}

	bool isWeaponShooter() const
	{
		if (getWeapon()->isShooter())
		{
			return true;
		}
		return false;
	}

	bool areBulletsInWeapon() const
	{
		if (getWeapon()->areBulletsInRefill())
		{
			return true;
		}
		return false;
	}

	int getWeaponDamage() const
	{
		return getWeapon()->getDamage();
	}

	int getWeaponStartDefense() const
	{
		return getWeapon()->getStartDefense();
	}

	void setWeaponDefense(const int newWeaponDefense)
	{
		getWeapon()->setDefense(newWeaponDefense);
	}

	int getWeaponDefense() const
	{
		return getWeapon()->getDefense();
	}

	double getWeaponRange() const
	{
		return getWeapon()->getRange();
	}

	bool isInRangeWith(const Champions& champion, const double range)
	{
		double distance = getDistanceTo(champion);

		if (distance <= range)
		{
			return true;
		}
		return false;
	}
	
	void shoot()
	{
		try
		{
			int currentNumberOfBullets = getWeapon()->getNumberCurrentBulletsInRefill(); //take number of bullets in the refill of the weapon
			if (currentNumberOfBullets > 0)
			{
				currentNumberOfBullets--;
				getWeapon()->setNumberCurrentBulletsInRefill(currentNumberOfBullets);
			}
			else
			{
				throw std::exception("No bullets left in refill");
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Error in shooting: " << e.what() << std::endl;
		}	
	}

	int getDamageTo(Champions& champion)
	{
		int damage = 0;

		if (hasWeapon())
		{
			if (!isInRangeWith(champion, getWeaponRange()))
			{
				throwExceptionIfNotInRangeWith(champion, getWeaponRange());
				return 0;
			}
			if (isWeaponBroken())
			{
				throwExceptionIfWeaponIsBroken();
				return 0;
			}
			else if (isWeaponShooter())
			{
				if (!areBulletsInWeapon())
				{
					throwExceptionIfNoBulletsInWeapon();
					return 0;
				}
				else
				{
					shoot();
				}
			}
			damage = getWeaponDamage();
			if (champion.hasWeapon())
			{
				champion.defenseWithWeaponFrom(damage);
			}
		}
		else
		{
			if (!isInRangeWith(champion, 1.0))
			{
				throwExceptionIfNotInRangeWith(champion, 1.0);
				return 0;
			}
			else
			{
				damage = 15;
				if (champion.hasWeapon())
				{
					champion.defenseWithWeaponFrom(damage);
				}
			}
		}
		return damage;
	}

	void defenseWithWeaponFrom(int& realDamage)
	{
		realDamage = realDamage - getWeaponDefense(); //calculate the real damage
		if (realDamage <= 0) //this happens if weapon's defense is greater than the damage
		{
			realDamage = 10;
		}
		int currentWeaponDefense = getWeaponDefense();
		if (currentWeaponDefense > 0)
		{
			currentWeaponDefense--;
			setWeaponDefense(currentWeaponDefense);
			if (isWeaponStrong())
			{
				setWeaponStatus(Damaged);
			}
			if (currentWeaponDefense == 0)
			{
				setWeaponStatus(Broken);
			}
		}
	}

	void heal(Champions& champion)
	{
		int startChampionHealth = champion.getStartHealth();
		int currentChampionHealth = champion.getHealth();
		if (startChampionHealth != currentChampionHealth)
		{
			int healPower = 20;
			int newChampionHealth = currentChampionHealth + healPower;
			if (newChampionHealth > startChampionHealth)
			{
				champion.setHealth(startChampionHealth);
			}
			else
			{
				champion.setHealth(newChampionHealth);
			}
		}
	}

	void throwChampionNumberIfNotAlive(const Champions* champion)
	{
		if (!champion->isAlive())
		{
			throw champion->getChampionNumber();
		}
	}

	void throwExceptionIfNotInRangeWith(const Champions& champion, const double range)
	{
		try
		{
			if (!isInRangeWith(champion, range))
			{
				throw std::exception("Enemy is out of range");
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Error in range: " << e.what() << std::endl;
		}
	}

	void throwExceptionIfNoBulletsInWeapon()
	{
		try
		{
			if (!areBulletsInWeapon())
			{
				throw std::exception("Weapon doesn't have bullets in refill");
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	void throwExceptionIfWeaponIsBroken()
	{
		try
		{
			if (isWeaponBroken())
			{
				throw std::exception("Weapon is broken");
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Error in attack: " << e.what() << std::endl;
		}
	}

protected:
	void setStartHealth(const int newStartHealth)
	{
		this->startHealth = newStartHealth;
	}

	void setHealth(const int newHealth)
	{
		this->health = newHealth;
	}

	void setSpell(const std::string newSpell)
	{
		this->spell = newSpell;
	}

	void setCategory(const Category newCategory)
	{
		this->category = newCategory;
	}

	bool isHealer() const
	{
		if (getCategory() == Healers)
		{
			return true;
		}
		return false;
	}

	void makeHeal(Champions& champion)
	{
		try
		{
			throwChampionNumberIfNotAlive(this);
			throwChampionNumberIfNotAlive(&champion);

			if (isHealer() && champion.isHealer() && !isTheSameAs(champion))
			{
				throw std::exception("You cannot heal another healer");
			}
			else
			{
				heal(champion);
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in healing: Number " << catchedID << " is not alive" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Error in healing: " << e.what() << std::endl;
		}
	}

	void makeWeaponBrokenTo(Champions& champion)
	{
		try
		{
			throwChampionNumberIfNotAlive(this);
			throwChampionNumberIfNotAlive(&champion);

			if (isTheSameAs(champion))
			{
				throw std::exception("You cannot break your own weapon");
			}	

			if (champion.hasWeapon() && !champion.isWeaponBroken())
			{
				champion.setWeaponStatus(Broken);
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in breaking weapon: Number " << catchedID << " is not alive" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Error in breaking weapon: " << e.what() << std::endl;
		}
	}

	bool hasWeapon() const
	{
		if (getWeapon())
		{
			return true;
		}
		return false;
	}

	bool isWeaponBroken() const
	{
		if (getWeaponStatus() == Broken)
		{
			return true;
		}
		return false;
	}

	bool isWeaponStrong() const
	{
		if (getWeaponStatus() == Strong)
		{
			return true;
		}
		return false;
	}

	void setWeaponStatus(const WeaponStatus status)
	{
		getWeapon()->setStatus(status);
	}

public:
	Champions()
	{
		setChampionNumber(countChampoins + 1);
		setLocation(nullptr);
		setName("Unknown character");
		setCategory(Category::Humans);
		setStartHealth(0);
		setHealth(getStartHealth());
		setSpell("None");
		setWeapon(nullptr);
		countChampoins++;
	}

	Champions(const std::string newName, const Point2D& point)
	{
		setChampionNumber(countChampoins + 1);
		setLocation(&point);
		setName(newName);
		setCategory(Category::Humans);
		setStartHealth(0);
		setHealth(getStartHealth());
		setSpell("None");
		setWeapon(nullptr);
		countChampoins++;
	}

	Champions(const Champions& champion)
	{
		setChampionNumber(countChampoins + 1);
		setLocation(champion.getLocation());
		setName(champion.getName());
		setCategory(champion.getCategory());
		setStartHealth(champion.getStartHealth());
		setHealth(champion.getHealth());
		setSpell(champion.getSpell());
		setWeapon(champion.getWeapon());
		countChampoins++;
	}

	Champions& operator=(const Champions& champion)
	{
		if (this != &champion)
		{
			setLocation(champion.getLocation());
			setName(champion.getName());
			setCategory(champion.getCategory());
			setStartHealth(champion.getStartHealth());
			setHealth(champion.getHealth());
			setSpell(champion.getSpell());
			setWeapon(champion.getWeapon());
		}
		return *this;
	}

	virtual ~Champions()
	{
		delete this->location;
		delete this->weapon;
	}

	//champion's information methods
	void setName(const std::string newName)
	{
		this->name = newName;
	}

	std::string getName() const
	{
		return this->name;
	}

	int getStartHealth() const
	{
		return this->startHealth;
	}

	int getHealth() const
	{
		return this->health;
	}

	std::string getSpell() const
	{
		return this->spell;
	}

	Category getCategory() const
	{
		return this->category;
	}

	Point2D* getLocation() const
	{
		return this->location;
	}

	bool isAlive() const
	{
		if (getHealth() > 0)
		{
			return true;
		}
		return false;
	}

	//champion's actions
	double getDistanceTo2D(const Champions& champion)
	{
		try
		{
			if (hasLocation() && champion.hasLocation())
			{
				return getLocation()->Point2D::getDistanceTo(*champion.getLocation());
			}
	
			if (!hasLocation())
			{
				throw getChampionNumber();
			}
			else if (!champion.hasLocation())
			{
				throw champion.getChampionNumber();
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in getting distance2D: Number " << catchedID << " doesn't have location" << std::endl;
		}
		return -1.0;
	}

	double getDistanceTo(const Champions& champion)
	{
		try
		{
			if (hasLocation() && champion.hasLocation())
			{
				auto thisPoint = dynamic_cast<Point3D*>(getLocation());
				auto championPoint = dynamic_cast<Point3D*>(champion.getLocation());

				if (thisPoint && championPoint)
				{
					return getLocation()->getDistanceTo(*champion.getLocation());
				}
				return getDistanceTo2D(champion);
			}

			if (!hasLocation())
			{
				throw getChampionNumber();
			}
			else if (!champion.hasLocation())
			{
				throw champion.getChampionNumber();
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in getting distance: Number " << catchedID << " doesn't have location" << std::endl;
		}
		return -1.0;
	}

	void moveTo(const Point2D& point)
	{
		if (getLocation() != &point)
		{
			setLocation(&point);
		}
	}

	void moveTo(const Champions& champion)
	{
		try
		{
			if (!champion.hasLocation())
			{
				throw champion.getChampionNumber();
			}
			else if (getLocation() != champion.getLocation())
			{
				setLocation(champion.getLocation());
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in moving: Number " << catchedID << "doesn't have location" << std::endl;
		}
	}

	//weapon methods
	Weapons* getWeapon() const
	{
		return this->weapon;
	}

	WeaponStatus getWeaponStatus() const
	{
		return getWeapon()->getStatus();
	}

	void takeWeapon(Weapons& weapon)
	{
		try
		{
			throwChampionNumberIfNotAlive(this);

			if (!hasWeapon())
			{
				setWeapon(&weapon);
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in taking weapon: Number " << catchedID << " is not alive" << std::endl;
		}
	}

	void throwWeapon()
	{
		try
		{
			throwChampionNumberIfNotAlive(this);

			if (hasWeapon())
			{
				setWeapon(nullptr);
			}
	
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in throwing weapon: Number " << catchedID << " is not alive" << std::endl;
		}
	}

	void giveWeaponTo(Champions& champion)
	{
		try
		{
			throwChampionNumberIfNotAlive(this);
			throwChampionNumberIfNotAlive(&champion);

			if (!champion.hasWeapon())
			{
				champion.setWeapon(getWeapon());
				setWeapon(nullptr);
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in giving weapon: Number " << catchedID << " is not alive" << std::endl;
		}
	}

	void rechargeWeapon()
	{
		try
		{
			throwChampionNumberIfNotAlive(this);

			if (isWeaponShooter())
			{
				int startBullets = getWeapon()->getNumberStartBulletsInRefill();
				getWeapon()->setNumberCurrentBulletsInRefill(startBullets);
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in recharging weapon: Number " << catchedID << " is not alive" << std::endl;
		}
	}

	void repairWeapon()
	{
		try
		{
			throwChampionNumberIfNotAlive(this);

			if (hasWeapon())
			{
				int startWeaponDefense = getWeaponStartDefense();
				int currentWeaponDefense = getWeaponDefense();
				if (startWeaponDefense != currentWeaponDefense || isWeaponBroken())
				{
					setWeaponDefense(startWeaponDefense);
					setWeaponStatus(Strong);
				}
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in repairing weapon: Number " << catchedID << " is not alive" << std::endl;
		}
	}

	void attack(Champions& champion)
	{
		try
		{
			if (!getLocation() || !isAlive())
			{
				throw getChampionNumber();
			}
			else if (!champion.getLocation() || !champion.isAlive())
			{
				throw champion.getChampionNumber();
			}

			if (isTheSameAs(champion))
			{
				throw std::exception("You cannot attack yourself");
			}
			else
			{
				int damage = getDamageTo(champion);
				int currentEnemyHealth = champion.getHealth();
				int newEnemyHealth = currentEnemyHealth - damage;
				if (newEnemyHealth < 0)
				{
					newEnemyHealth = 0;
				}
				champion.setHealth(newEnemyHealth);
			}
		}
		catch (unsigned long catchedID)
		{
			std::cout << "Error in attacking: Number " << catchedID << " doesn't have location or is not alive" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Error in attacking: " << e.what() << std::endl;
		}
	}

	void printWeaponInformation() const
	{
		if (hasWeapon())
		{
			std::cout << "Weapon of number " << getChampionNumber() << ":" << std::endl;
			getWeapon()->print();
		}
		else
		{
			std::cout << "Number " << getChampionNumber() << " doesn't have a weapon" << std::endl;
		}	
	}

	//print information for champion
	virtual void print() const
	{
		std::cout << "Number: " << getChampionNumber() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Category: ";
		switch (getCategory())
		{
		case 0: std::cout << "Human" << std::endl;
			break;
		case 1: std::cout << "Assassin" << std::endl;
			break;
		case 2: std::cout << "Wizard" << std::endl;
			break;
		case 3: std::cout << "Healer" << std::endl;
			break;
		}
		std::cout << "Health: " << getHealth() << std::endl;
		std::cout << "Spell: " << getSpell() << std::endl;
		if (hasWeapon())
		{
			std::cout << "Weapon: " << getWeapon()->getName() << std::endl;
		}
	}

	//view champion's location
	void printLocation() const
	{
		if (hasLocation())
		{
			std::cout << "Number " << getChampionNumber() << " coordinates: " << std::endl;
			getLocation()->print();
		}
		else
		{
			std::cout << "Number " << getChampionNumber() << " doesn't have coordinates" << std::endl;
		}
	}

	virtual Champions* clone() const = 0;
};
