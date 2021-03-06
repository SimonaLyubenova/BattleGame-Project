#include "Champions.h"

Champions::Champions()
{
	setChampionID(countChampoins + 1);
	setLocation(nullptr);
	setName("Unknown character");
	setCategory(Category::Humans);
	setStartHealth(0);
	setHealth(getStartHealth());
	setSpell("None");
	setWeapon(nullptr);
	countChampoins++;
}

Champions::Champions(const std::string newName, const Point2D& point)
{
	setChampionID(countChampoins + 1);
	setLocation(&point);
	setName(newName);
	setCategory(Category::Humans);
	setStartHealth(0);
	setHealth(getStartHealth());
	setSpell("None");
	setWeapon(nullptr);
	countChampoins++;
}

Champions::Champions(const Champions& champion)
{
	setChampionID(countChampoins + 1);
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

void Champions::setChampionID(const unsigned long newChampionID)
{
	this->championID = newChampionID;
}

unsigned long Champions::getChampionID() const
{
	return this->championID;
}

bool Champions::isTheSameAs(const Champions& champion) const
{
	if (getChampionID() == champion.getChampionID())
	{
		return true;
	}
	return false;
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

bool Champions::isInRangeWith(const Champions& champion, const double range)
{
	double distance = getDistanceTo(champion);

	try
	{
		if (distance < 0)
		{
			throw std::exception("Range cannot be calculated");
		}

		if (distance <= range)
		{
			return true;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Error in range: " << e.what() << std::endl;
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
	try
	{
		if (hasLocation() && champion.hasLocation())
		{
			return getLocation()->Point2D::getDistanceTo(*champion.getLocation());
		}

		if (!hasLocation())
		{
			throw getChampionID();
		}
		else if (!champion.hasLocation())
		{
			throw champion.getChampionID();
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in getting distance2D: Champion number " << catchedID << " doesn't have location" << std::endl;
	}
	return -1.0;
}

double Champions::getDistanceTo(const Champions& champion)
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
			throw getChampionID();
		}
		else if (!champion.hasLocation())
		{
			throw champion.getChampionID();
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in getting distance: Champion number " << catchedID << " doesn't have location" << std::endl;
	}
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
	try
	{
		if (!champion.hasLocation())
		{
			throw champion.getChampionID();
		}
		else if (getLocation() != champion.getLocation())
		{
			setLocation(champion.getLocation());
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in moving: Champion number " << catchedID << "doesn't have location" << std::endl;
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
	if (getWeaponStatus() == WeaponStatus::Broken)
	{
		return true;
	}
	return false;
}

bool Champions::isWeaponStrong() const
{
	if (getWeaponStatus() == WeaponStatus::Strong)
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
	try
	{
		throwChampionIDIfNotAlive(this);

		if (!hasWeapon())
		{
			setWeapon(&weapon);
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in taking weapon: Champion number " << catchedID << " is not alive" << std::endl;
	}
}

void Champions::throwWeapon()
{
	try
	{
		throwChampionIDIfNotAlive(this);

		if (hasWeapon())
		{
			setWeapon(nullptr);
		}

	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in throwing weapon: Champion number " << catchedID << " is not alive" << std::endl;
	}
}

void Champions::giveWeaponTo(Champions& champion)
{
	try
	{
		throwChampionIDIfNotAlive(this);
		throwChampionIDIfNotAlive(&champion);

		if (!champion.hasWeapon())
		{
			champion.setWeapon(getWeapon());
			setWeapon(nullptr);
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in giving weapon: Champion number " << catchedID << " is not alive" << std::endl;
	}
}

void Champions::rechargeWeapon()
{
	try
	{
		throwChampionIDIfNotAlive(this);

		if (isWeaponShooter())
		{
			int startBullets = getWeapon()->getNumberStartBulletsInRefill();
			getWeapon()->setNumberCurrentBulletsInRefill(startBullets);
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in recharging weapon: Champion number " << catchedID << " is not alive" << std::endl;
	}
}

void Champions::repairWeapon()
{
	try
	{
		throwChampionIDIfNotAlive(this);

		if (hasWeapon())
		{
			int startWeaponDefense = getWeaponStartDefense();
			int currentWeaponDefense = getWeaponDefense();
			if (startWeaponDefense != currentWeaponDefense || isWeaponBroken())
			{
				setWeaponDefense(startWeaponDefense);
				setWeaponStatus(WeaponStatus::Strong);
			}
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in repairing weapon: Champion number " << catchedID << " is not alive" << std::endl;
	}
}

void Champions::shoot()
{
	try
	{
		int currentNumberOfBullets = getWeapon()->getNumberCurrentBulletsInRefill();
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

void Champions::defenseWithWeaponFrom(int& realDamage)
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
			setWeaponStatus(WeaponStatus::Damaged);
		}
		if (currentWeaponDefense == 0)
		{
			setWeaponStatus(WeaponStatus::Broken);
		}
	}
}

int Champions::getDamageTo(Champions& champion)
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

void Champions::attack(Champions& champion)
{
	try
	{
		if (!getLocation() || !isAlive())
		{
			throw getChampionID();
		}
		else if (!champion.getLocation() || !champion.isAlive())
		{
			throw champion.getChampionID();
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
		std::cout << "Error in attacking: Champion number " << catchedID << " doesn't have location or is not alive" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error in attacking: " << e.what() << std::endl;
	}
}

void Champions::makeHealTo(Champions& champion)
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

void Champions::increaseHealthTo(Champions& champion)
{
	try
	{
		throwChampionIDIfNotAlive(this);
		throwChampionIDIfNotAlive(&champion);

		if (isHealer() && champion.isHealer() && !isTheSameAs(champion))
		{
			throw std::exception("You cannot heal another healer");
		}
		else
		{
			makeHealTo(champion);
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in healing: Champion number " << catchedID << " is not alive" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error in healing: " << e.what() << std::endl;
	}
}

void Champions::makeWeaponBrokenTo(Champions& champion)
{
	try
	{
		throwChampionIDIfNotAlive(this);
		throwChampionIDIfNotAlive(&champion);

		if (isTheSameAs(champion))
		{
			throw std::exception("You cannot break your own weapon");
		}

		if (champion.hasWeapon() && !champion.isWeaponBroken())
		{
			champion.setWeaponStatus(WeaponStatus::Broken);
		}
	}
	catch (unsigned long catchedID)
	{
		std::cout << "Error in breaking weapon: Champion number " << catchedID << " is not alive" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error in breaking weapon: " << e.what() << std::endl;
	}
}

void Champions::throwChampionIDIfNotAlive(const Champions* champion)
{
	if (!champion->isAlive())
	{
		throw champion->getChampionID();
	}
}

void Champions::throwExceptionIfNotInRangeWith(const Champions& champion, const double range)
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

void Champions::throwExceptionIfNoBulletsInWeapon()
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

void Champions::throwExceptionIfWeaponIsBroken()
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

void Champions::print() const
{
	std::cout << "Champion number: " << getChampionID() << std::endl;
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
		std::cout << "Champion number " << getChampionID() << " coordinates: " << std::endl;
		getLocation()->print();
	}
	else
	{
		std::cout << "Champion number " << getChampionID() << " doesn't have coordinates" << std::endl;
	}
}

void Champions::printWeaponInformation() const
{
	if (hasWeapon())
	{
		std::cout << "Weapon of champion number " << getChampionID() << ":" << std::endl;
		getWeapon()->print();
	}
	else
	{
		std::cout << "Champion number " << getChampionID() << " doesn't have a weapon" << std::endl;
	}
}
