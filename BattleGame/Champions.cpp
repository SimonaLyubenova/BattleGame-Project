#include "Champions.h"

Champions::Champions()
{
	setNumber(countChampoins + 1);
	setLocation(nullptr);
	setName("Unknown character");
	setCategory(Category::Humans);
	setStartHealth(500);
	setHealth(getStartHealth());
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
	setStartHealth(500);
	setHealth(getStartHealth());
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
	setStartHealth(champion.getStartHealth());
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
		setStartHealth(champion.getStartHealth());
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
	if (getWeapon()->areBulletsInRefill())
	{
		return true;
	}
	return false;
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

void Champions::setName(const std::string newName)
{
	this->name = newName;
}

std::string Champions::getName() const
{
	return this->name;
}

void Champions::setStartHealth(const int newStartHealth)
{
	this->startHealth = newStartHealth;
}

int Champions::getStartHealth() const
{
	return this->startHealth;
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

bool Champions::isAlive() const
{
	if (getHealth() > 0)
	{
		return true;
	}
	return false;
}

bool Champions::isHealer() const
{
	if (getCategory() == Healers)
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

bool Champions::hasWeapon() const
{
	if (getWeapon())
	{
		return true;
	}
	return false;
}

bool Champions::isWeaponBroken() const
{
	if (getWeaponStatus() == Broken)
	{
		return true;
	}
	return false;
}

bool Champions::isWeaponStrong() const
{
	if (getWeaponStatus() == Strong)
	{
		return true;
	}
	return false;
}

void Champions::setWeaponStatus(const WeaponStatus status)
{
	getWeapon()->setStatus(status);
}

WeaponStatus Champions::getWeaponStatus() const
{
	return getWeapon()->getStatus();
}

void Champions::takeWeapon(Weapons& weapon)
{
	if (isAlive() && !hasWeapon())
	{
		setWeapon(&weapon);
	}
}

void Champions::throwWeapon()
{
	if (isAlive() && hasWeapon())
	{
		setWeapon(nullptr);
	}
}

void Champions::giveWeaponTo(Champions& champion)
{
	if (isAlive() && champion.isAlive() && !champion.hasWeapon())
	{
		champion.setWeapon(getWeapon());
		setWeapon(nullptr);
	}
}

void Champions::rechargeWeapon()
{
	if (isAlive() && isWeaponShooter())
	{
		int startBullets = getWeapon()->getNumberStartBulletsOfRefill();
		getWeapon()->setNumberCurrentBulletsOfRefill(startBullets);
	}
}

void Champions::repairWeapon()
{
	if (isAlive() && hasWeapon())
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

void Champions::shoot()
{
	int currentNumberOfBullets = getWeapon()->getNumberCurrentBulletsOfRefill(); //take number of bullets in the refill of the weapon
	if (currentNumberOfBullets > 0)
	{
		currentNumberOfBullets--;
		getWeapon()->setNumberCurrentBulletsOfRefill(currentNumberOfBullets);
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
		if (champion.isWeaponStrong())
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
	int damage = 0;

	if (hasWeapon())
	{
		if (distance <= getWeaponRange() && !isWeaponBroken()) //if the enemy is in the range of the weapon and the weapon is not broken
		{
			if (isWeaponShooter() && areBulletsInWeapon())
			{
				shoot();
			}
			else if(isWeaponShooter() && !areBulletsInWeapon())
			{
				return 0;
			}

			damage = getWeaponDamage();
			if (champion.hasWeapon()) //check if the enemy has a weapon in order to know if it has defense
			{
				defenseWithWeapon(champion, damage);
			}
		}
	}
	else
	{
		if (distance <= 1)
		{
			damage = 15;
			if (champion.hasWeapon()) //check if the enemy has weapon in order to calculate the real damage + the defense of the weapon
			{
				defenseWithWeapon(champion, damage);
			}
		}
	}
	return damage;
}

void Champions::attack(Champions& champion)
{
	if (!getLocation() || !champion.getLocation())
	{
		return;
	}
	if (champion.isAlive() && getNumber() != champion.getNumber())
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
	else if (getNumber() != champion.getNumber())
	{
		std::cout << "You cannot attack " << champion.getNumber() << "!" << std::endl;
	}
	else
	{
		std::cout << "You cannot attack yourself!" << std::endl;
	}
}

void Champions::makeHeal(Champions& champion)
{
	if (isHealer() && champion.isHealer() && getNumber() != champion.getNumber()) //a healer cannot heal another healer, but can heal himself
	{
		return;
	}
	if (isAlive() && champion.isAlive())
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
}

void Champions::makeWeaponBrokenTo(Champions& champion)
{
	if (getNumber() == champion.getNumber()) //nobody cannot break its own weapon
	{
		return;
	}
	if (isAlive() && champion.isAlive())
	{
		if (champion.hasWeapon() && !champion.isWeaponBroken())
		{
			champion.setWeaponStatus(Broken);
		}
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
