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
	unsigned long number;
	std::string name;
	int health;
	std::string spell;
	Category category;
	Point2D* location = nullptr;
	Weapons* weapon = nullptr;

	void setNumber(const unsigned long);
	unsigned long getNumber() const;

	void setLocation(const Point2D*);
	Point2D* getLocation() const;

	void setWeapon(const Weapons*);
	Weapons* getWeapon() const;

	bool hasLocation() const;
	bool hasWeapon() const;

	void shoot();
	int getDamageTo(Champions&);

	bool isWeaponShooter() const;
	Refill* getWeaponRefill() const;
	bool areBulletsInWeapon() const;
	int getWeaponDamage() const;
	int getWeaponStartDefense() const;
	void setWeaponDefense(const int);
	int getWeaponDefense() const;
	double getWeaponRange() const;
	void setWeaponStatus(const WeaponStatus);
	WeaponStatus getWeaponStatus() const;
	void defenseWithWeapon(Champions&, int&);

//protected:
	

public:
	Champions();
	Champions(const std::string, const Point2D&);
	Champions(const Champions&);
	Champions& operator=(const Champions&);
	virtual ~Champions();

	//champion's information methods
	void setName(const std::string);
	std::string getName() const;
	void setHealth(const int);
	int getHealth() const;
	void setSpell(const std::string);
	std::string getSpell() const;
	void setCategory(const Category);
	Category getCategory() const;

	//view champion's location
	void printLocation() const;

	//champion's actions
	double getDistanceTo2D(const Champions&); //should be private
	double getDistanceTo(const Champions&); //should be private
	void moveTo(const Point2D&);
	void moveTo(const Champions&);

	//virtual Champions* clone() const;

	//weapon methods
	void takeWeapon(const Weapons&);
	void throwWeapon();
	void giveWeaponTo(Champions&);
	void rechargeWeapon();
	void repairWeapon();
	void attack(Champions&);
	void printWeaponInformation() const;

	//print information for champion
	virtual void print() const;
};
