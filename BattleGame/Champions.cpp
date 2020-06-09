#include "Champions.h"

Champions::Champions()
{
	setNumber(countChampoins + 1);
	setLocation(nullptr);
	setName("Unknown character");
	setCategory(Category::Humans);
	setHealth(500);
	setSpell("None");
	setWeapon(nullptr);
	countChampoins++;
}

Champions::Champions(const std::string newName, const Point2D& point)
{
	setNumber(countChampoins + 1);
	setLocation(&point);
	setName(newName);
	setCategory(Category::Humans);
	setHealth(500);
	setSpell("None");
	setWeapon(nullptr);
	countChampoins++;
}

Champions::Champions(const Champions& champion)
{
	setNumber(countChampoins + 1);
	setLocation(champion.getLocation());
	setName(champion.getName());
	setCategory(champion.getCategory());
	setHealth(champion.getHealth());
	setSpell(champion.getSpell());
	setWeapon(champion.getWeapon());
	countChampoins++;
}

Champions& Champions::operator=(const Champions& champion)
{
	if (this != &champion)
	{
		setLocation(champion.getLocation());
		setName(champion.getName());
		setCategory(champion.getCategory());
		setHealth(champion.getHealth());
		setSpell(champion.getSpell());
		setWeapon(champion.getWeapon());
	}
	return *this;
}

Champions::~Champions()
{
	delete this->location;
	delete this->weapon;
}

void Champions::setNumber(const unsigned long newNumber)
{
	this->number = newNumber;
}

unsigned long Champions::getNumber() const
{
	return this->number;
}

void Champions::setLocation(const Point2D* newLocation)
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

Point2D* Champions::getLocation() const
{
	return this->location;
}

bool Champions::hasLocation() const
{
	if (getLocation())
	{
		return true;
	}
	return false;
}

void Champions::setName(const std::string newName)
{
	this->name = newName;
}

std::string Champions::getName() const
{
	return this->name;
}

void Champions::setHealth(const int newHealth)
{
	this->health = newHealth;
}

int Champions::getHealth() const
{
	return this->health;
}

void Champions::setSpell(const std::string newSpell)
{
	this->spell = newSpell;
}

std::string Champions::getSpell() const
{
	return this->spell;
}

void Champions::setCategory(const Category newCategory)
{
	this->category = newCategory;
}

Category Champions::getCategory() const
{
	return this->category;
}

Refill* Champions::getWeaponRefill() const
{
	return getWeapon()->getRefill();
}

int Champions::getWeaponDamage() const
{
	return getWeapon()->getDamage();
}

int Champions::getWeaponStartDefense() const
{
	return getWeapon()->getStartDefense();
}

void Champions::setWeaponDefense(const int newWeaponDefense)
{
	getWeapon()->setDefense(newWeaponDefense);
}

int Champions::getWeaponDefense() const
{
	return getWeapon()->getDefense();
}

double Champions::getWeaponRange() const
{
	return getWeapon()->getRange();
}

void Champions::setWeaponStatus(const WeaponStatus status)
{
	getWeapon()->setStatus(status);
}

WeaponStatus Champions::getWeaponStatus() const
{
	return getWeapon()->getStatus();
}

bool Champions::isWeaponShooter() const
{
	if (getWeapon()->isShooter())
	{
		return true;
	}
	return false;
}

bool Champions::areBulletsInWeapon() const
{
	if (getWeaponRefill()->hasBullets())
	{
		return true;
	}
	return false;
}

double Champions::getDistanceTo2D(const Champions& champion)
{
	if (hasLocation() && champion.hasLocation())
	{
		return getLocation()->Point2D::getDistanceTo(*champion.getLocation());
	}
	std::cout << "Number " << getNumber() << " or number " << champion.getNumber() << " doesn't have a location" << std::endl;
	return 0.0;
}

double Champions::getDistanceTo(const Champions& champion)
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
	std::cout << "Number " << getNumber() << " or number " << champion.getNumber() << " doesn't have a location" << std::endl;
	return -1.0;
}

void Champions::moveTo(const Point2D& point)
{
	if (getLocation() != &point)
	{
		setLocation(&point);
	}
}

void Champions::moveTo(const Champions& champion)
{
	if (champion.hasLocation() && getLocation() != champion.getLocation())
	{
		setLocation(champion.getLocation());
	}
}

void Champions::setWeapon(const Weapons* newWeapon)
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

Weapons* Champions::getWeapon() const
{
	return this->weapon;
}

bool Champions::hasWeapon() const
{
	if (getWeapon())
	{
		return true;
	}
	return false;
}

void Champions::takeWeapon(const Weapons& newWeapon)
{
	setWeapon(&newWeapon);
}

void Champions::throwWeapon()
{
	if (hasWeapon())
	{
		setWeapon(nullptr);
	}
}

void Champions::giveWeaponTo(Champions& champion)
{
	if (!champion.hasWeapon())
	{
		champion.setWeapon(getWeapon());
		setWeapon(nullptr);
	}
}

void Champions::rechargeWeapon()
{
	if (isWeaponShooter())
	{
		int startBullets = getWeaponRefill()->getNumberStartBullets();
		getWeaponRefill()->setNumberBullets(startBullets);
	}
}

void Champions::repairWeapon()
{
	if (hasWeapon())
	{
		int startWeaponDefense = getWeaponStartDefense();
		int currentWeaponDefense = getWeaponDefense();
		if (startWeaponDefense != currentWeaponDefense)
		{
			setWeaponDefense(startWeaponDefense);
			setWeaponStatus(Strong);
		}
	}
}

void Champions::shoot()
{
	int currentNumberOfBullets = getWeaponRefill()->getNumberBullets(); //take number of bullets in the refill of the weapon
	if (currentNumberOfBullets > 0)
	{
		currentNumberOfBullets--;
		getWeaponRefill()->setNumberBullets(currentNumberOfBullets);
	}
}

void Champions::defenseWithWeapon(Champions& champion, int& realDamage)
{
	realDamage = realDamage - champion.getWeaponDefense(); //calculate the real damage
	if (realDamage <= 0)
	{
		realDamage = 10;
	}
	int currentEnemyWeaponDefense = champion.getWeaponDefense();
	if (currentEnemyWeaponDefense > 0)
	{
		currentEnemyWeaponDefense--;
		champion.setWeaponDefense(currentEnemyWeaponDefense);
		if (champion.getWeaponStatus() == Strong)
		{
			champion.setWeaponStatus(Damaged);
		}
		if (currentEnemyWeaponDefense == 0)
		{
			champion.setWeaponStatus(Broken);
		}
	}
}

int Champions::getDamageTo(Champions& champion)
{
	double distance = getDistanceTo(champion);
	int realDamage = 0;

	if (hasWeapon())
	{
		if (distance <= getWeaponRange()) //if the enemy is in the range of the weapon
		{
			if (isWeaponShooter() && areBulletsInWeapon())
			{
				shoot();
			}
			else if(isWeaponShooter() && !areBulletsInWeapon())
			{
				return 0;
			}

			realDamage = getWeaponDamage();
			if (champion.hasWeapon()) //check if the enemy has a weapon in order to know if it has defense
			{
				defenseWithWeapon(champion, realDamage);
			}
		}
	}
	else
	{
		if (distance <= 1)
		{
			realDamage = 15;
			if (champion.hasWeapon()) //check if the enemy has weapon in order to calculate the real damage + the defense of the weapon
			{
				defenseWithWeapon(champion, realDamage);
			}
		}
	}
	return realDamage;
}

void Champions::attack(Champions& champion)
{
	if (!getLocation() || !champion.getLocation())
	{
		return;
	}
	if (champion.getHealth() > 0 && getNumber() != champion.getNumber())
	{
		int realDamage = getDamageTo(champion);
		int currentEnemyHealth = champion.getHealth();
		int newEnemyHealth = currentEnemyHealth - realDamage;
		if (newEnemyHealth < 0)
		{
			newEnemyHealth = 0;
		}
		champion.setHealth(newEnemyHealth);
	}
	else if (getNumber() != champion.getNumber())
	{
		std::cout << "You cannot attack " << champion.getNumber() << "!" << std::endl;
	}
	else
	{
		std::cout << "You cannot attack yourself!" << std::endl;
	}
}

void Champions::print() const
{
	std::cout << "Number: " << getNumber() << std::endl;
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

void Champions::printLocation() const
{
	if (hasLocation())
	{
		std::cout << "Number " << getNumber() << " coordinates: " << std::endl;
		getLocation()->print();
	}
	else
	{
		std::cout << "Number " << getNumber() << " doesn't have coordinates" << std::endl;
	}
}

void Champions::printWeaponInformation() const
{
	if (hasWeapon())
	{
		std::cout << "Weapon of number " << getNumber() << ":" << std::endl;
		getWeapon()->print();
	}
	else
	{
		std::cout << "Number " << getNumber() << " doesn't have a weapon" << std::endl;
	}
}
