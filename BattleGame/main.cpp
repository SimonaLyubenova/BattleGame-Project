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
    //Point3D one(1, 11, 15);
    //Point2D two(3, 8);
    //Point2D two(2, 2);
    //Point3D three(5, 5, 5);

    //two = one;
    //Point3D point(1, 1, 1);
    //point = three;

    //double a = one.getDistanceTo(two);
    //cout << a << endl;
    //cout << two.getDistanceTo(one) << endl;

    //one.print();
    //two.print();
    //point.print();

    //Weapons weapon;
    //weapon.print();

    

    /*Sword one;
    Sword sword;
    sword.setStatus(WeaponStatus::Damaged);
    sword.print();
    cout << endl;
    Sword two(sword);
    //sword = two;
    //sword.Weapons::operator=(two);
    two.print();*/

    /*Sword sniper;
    sniper.print();
    sniper.setStatus(Broken);
    Sword one;
    cout << endl;
    one.print();
    cout << endl;
    one = sniper;
    one.print();*/

    //Weapons* w = new Sniper();

    //Shooters* s = new Sniper();
    /*Sniper s;
    s.setStatus(Broken);
    Refill* r = new Refill(50);
    s.setRefill(r);
    Sniper w;
    Sword f;
    w = s;
    w.print();

    cout << endl;

    Gun g;
    g.print();

    g.setRefill(r);
    cout << endl;
    g.print();

    cout << endl;

    Stick stick;
    stick.print();
    stick.setStatus(Damaged);
    stick.setLength(10);

    cout << endl;
    Stick two;
    two = stick;
    two.print();*/

    //Sniper sniper;
    //sniper.print();


    //Shooters* w = new Sniper();
    //w->print();

    /*Refill* refill = new Refill(50);

    Sword sword;
    sword.print();
    cout << endl;
    //Sniper sniper;
    Weapons* weapon = new Sniper();
    weapon->print();
    cout << endl;
    Weapons* weapon2 = sword.clone();
    weapon2->print();
    cout << endl;

    sword.setStatus(Damaged);
    weapon2 = sword.clone();
    weapon2->print();
    cout << endl;
    weapon = weapon2->clone();

    //Sniper one;
    weapon->print();
    /*cout << endl;
    one = sniper;
    one.print();

    delete weapon;
    delete weapon2;*/

    /*Stick s;
    s.print();
    cout << endl;
    s.setLength(50);
    s.setStatus(Damaged);
    Stick m(s);
    m.print();
    cout << endl;*/

    Point3D one(1, 1, 5);
    Point3D two(1, 2, 1);
    Point2D third(1, 1);

    Human h("Hiii", third);
    Healer w("Snake", two);
    Healer healer("Mine", one);

    healer.print();
    cout << endl;
    
    Sniper gun;
    //gun.setStatus(Broken);
    h.takeWeapon(gun);
    //w.breakWeaponTo(h);
    h.printWeaponInformation();

    for (int i = 0; i < 3; i++)
    {
        w.attack(h);
    }
    cout << endl;
    h.repairWeapon();
    h.printWeaponInformation();
    cout << endl;
    h.print();
    cout << endl;
    //healer.heal(w);
    h.attack(w);
    w.print();
    cout << endl;
    h.rechargeWeapon();
    h.printWeaponInformation();
    //.attack(a);
    //cout << endl;
    //a.print();

    /*Sniper sniper;
    Sword sword;
    s.takeWeapon(sniper);
    s.print();
    cout << endl;
    s.printWeaponInformation();
    cout << endl;
    a.takeWeapon(sword);
    a.print();
    cout << endl;
    a.printWeaponInformation();
    cout << endl;

    a.attack(s);
    s.print();*/
    
    return 0;
}
