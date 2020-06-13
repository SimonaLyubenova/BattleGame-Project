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

	void setChampionNumber(const unsigned long);
	unsigned long getChampionNumber() const;
	bool isTheSameAs(const Champions&) const;

	void setLocation(const Point2D*);
	Point2D* getLocation() const;
	bool hasLocation() const;

	void setWeapon(const Weapons*);
	Weapons* getWeapon() const;
	bool isWeaponShooter() const;
	bool areBulletsInWeapon() const;
	int getWeaponDamage() const;
	int getWeaponStartDefense() const;
	void setWeaponDefense(const int);
	int getWeaponDefense() const;
	double getWeaponRange() const;
	bool isInRangeWith(const Champions&, const double);
	
	void shoot();
	int getDamageTo(Champions&);
	void defenseWithWeaponFrom(int&);

	void heal(Champions&);

	void throwChampionNumberIfNotAlive(const Champions*);
	void throwExceptionIfNotInRangeWith(const Champions&, const double);
	void throwExceptionIfNoBulletsInWeapon();
	void throwExceptionIfWeaponIsBroken();

protected:
	void setStartHealth(const int);
	int getStartHealth() const;
	void setHealth(const int);
	int getHealth() const;
	void setSpell(const std::string);
	std::string getSpell() const;
	void setCategory(const Category);
	Category getCategory() const;
	bool isAlive() const;
	bool isHealer() const;
	void makeHeal(Champions&);
	void makeWeaponBrokenTo(Champions&);

	bool hasWeapon() const;
	bool isWeaponBroken() const;
	bool isWeaponStrong() const;
	void setWeaponStatus(const WeaponStatus);
	WeaponStatus getWeaponStatus() const;

public:
	Champions();
	Champions(const std::string, const Point2D&);
	Champions(const Champions&);
	Champions& operator=(const Champions&);
	virtual ~Champions();

	//champion's information methods
	void setName(const std::string);
	std::string getName() const;

	//champion's actions
	double getDistanceTo2D(const Champions&);
	double getDistanceTo(const Champions&);
	void moveTo(const Point2D&);
	void moveTo(const Champions&);

	//weapon methods
	void takeWeapon(Weapons&);
	void throwWeapon();
	void giveWeaponTo(Champions&);
	void rechargeWeapon();
	void repairWeapon();
	void attack(Champions&);
	void printWeaponInformation() const;

	//print information for champion
	virtual void print() const;

	//view champion's location
	void printLocation() const;

	virtual Champions* clone() const = 0;
};
