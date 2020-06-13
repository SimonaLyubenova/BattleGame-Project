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
    Point3D one(10, 2, 5);
    Point3D two(1, 2, 1);
    Point2D third(1, 1);

    Gun gun;
    Human h("A", one);
    //h.takeWeapon(gun);
    Assassin a("B", third);
    h.print();
    cout << endl;
    a.print();
    cout << endl;
    h.attack(h);
    for (int i = 0; i < 6; i++)
    {
        h.attack(a);
    }
    for (int i = 0; i < 8; i++)
    {
        a.attack(h);
    }
    h.attack(a);
    h.attack(a);

    h.print();
    cout << endl;
    a.print();
    cout << endl;
    h.printWeaponInformation();

    return 0;
}
