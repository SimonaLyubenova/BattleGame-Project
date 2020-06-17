#include <iostream>
#include "Point2D.h"
#include "Point3D.h"
#include "Sword.h"
#include "Sniper.h"
#include "Gun.h"
#include "Stick.h"
#include "Champions.h"
#include "Human.h"
#include "Assassin.h"
#include "Wizard.h"
#include "Healer.h"

using namespace std;

int main()
{
	Point3D point3D(5, 5, 1);
	Point2D point2D(5, 4);
	Gun gun;
	Stick stick;
	Healer healer("Ben", point2D);
	healer.takeWeapon(gun);
	Wizard wizard("Fred", point3D);
	wizard.takeWeapon(stick);

	for (int i = 0; i < 100; i++)
	{
		healer.attack(wizard);
	}

	wizard.attack(healer);

	wizard.print();
	cout << endl;
	healer.printWeaponInformation();

	cout << endl << endl;
	wizard.throwWeapon();
	healer.giveWeaponTo(wizard);
	wizard.print();
	cout << endl;
	healer.print();
	cout << endl;
	wizard.printWeaponInformation();
	cout << endl;
	healer.printWeaponInformation();

	return 0;
}
