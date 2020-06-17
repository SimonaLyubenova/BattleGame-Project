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
	unsigned long championID;
	std::string name;
	int startHealth;
	int health;
	std::string spell;
	Category category;
	Point2D* location = nullptr;
	Weapons* weapon = nullptr;

	void setChampionID(const unsigned long);
	unsigned long getChampionID() const;
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

	void makeHealTo(Champions&);

	void throwChampionIDIfNotAlive(const Champions*);
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
	void increaseHealthTo(Champions&);
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

	virtual Champions* clone() const = 0;

	//champion's information methods
	void setName(const std::string);
	std::string getName() const;

	//view champion's location
	void printLocation() const;

	//champion's methods in moving and calculating distance
	double getDistanceTo2D(const Champions&);
	double getDistanceTo(const Champions&);
	void moveTo(const Point2D&);
	void moveTo(const Champions&);

	//champion's methods connected with weapons
	void takeWeapon(Weapons&);
	void throwWeapon();
	void giveWeaponTo(Champions&);
	void rechargeWeapon();
	void repairWeapon();
	void printWeaponInformation() const;

	//champion's attack method
	void attack(Champions&);

	//print information for champion
	virtual void print() const;
};
