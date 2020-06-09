#include "Weapons.h"

Weapons::Weapons()
{
	setID(countWeapons + 1);
	setName("Unknown weapon");
	setWeaponType(WeaponType::None);
	setWeight(0.0);
	setDamage(0);
	setStartDefense(0.0);
	setDefense(0);
	setMovementSpeed(0);
	setRange(0.0);
	setStatus(WeaponStatus::Strong);
	countWeapons++;
}

Weapons::Weapons(const Weapons& weapon)
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

Weapons& Weapons::operator=(const Weapons& weapon) //we need to take only the type and the status, other attributes are the same
{
	if (this != &weapon)
	{
		setWeaponType(weapon.getWeaponType());
		setStatus(weapon.getStatus());
	}
	return *this;
}

void Weapons::setID(const unsigned long newID)
{
	this->id = newID;
}

unsigned long Weapons::getID() const
{
	return this->id;
}

void Weapons::setName(const std::string newName)
{
	this->name = newName;
}

std::string Weapons::getName() const
{
	return this->name;
}

void Weapons::setWeight(const double newWeight)
{
	this->weight = newWeight;
}

double Weapons::getWeight() const
{
	return this->weight;
}

void Weapons::setMovementSpeed(const int newMovementSpeed)
{
	this->movementSpeed = newMovementSpeed;
}

int Weapons::getMovementSpeed() const
{
	return this->movementSpeed;
}

void Weapons::setDamage(const int newDamage)
{
	this->damage = newDamage;
}

int Weapons::getDamage() const
{
	return this->damage;
}

void Weapons::setStartDefense(const int newStartDefense)
{
	this->startDefense = newStartDefense;
}

int Weapons::getStartDefense() const
{
	return this->startDefense;
}

void Weapons::setDefense(const int newDefense)
{
	this->defense = newDefense;
}

int Weapons::getDefense() const
{
	return this->defense;
}

void Weapons::setRange(const double newRange)
{
	this->range = newRange;
}

double Weapons::getRange() const
{
	return this->range;
}

void Weapons::setStatus(const WeaponStatus newStatus)
{
	this->status = newStatus;
}

WeaponStatus Weapons::getStatus() const
{
	return this->status;
}

void Weapons::setWeaponType(const WeaponType newType)
{
	this->type = newType;
}

WeaponType Weapons::getWeaponType() const
{
	return this->type;
}

bool Weapons::isShooter() const
{
	if (getWeaponType() == WeaponType::Shooter)
	{
		return true;
	}
	return false;
}

void Weapons::printStatus() const
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

void Weapons::print() const
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

