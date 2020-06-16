# BattleGame-Project
BattleGame is a project for Clean Code course in Sofia University. It simulates a game which has some types of champions and weapons. 

# *Classes*
Constructors, destructors, setters, getters and additional methods are implemented where is necessary
* class Point2D <br>
It has following members:
  * cooridnate **double x**
  * coordinate **double y**
  * methods **void setX(), void setY(), double getX(), double getY()**
  * method **double getZ()** which helps us in class Point3D to calculate distance between different points (from 2D and 3D dimensions)
  * method **double getDistanceTo()** which accepts point in 2D dimension and calculates distance between two points in 2D dimension
  * method **void print()** which gives us information about coordinates **x** and **y**
  
* class Point3D - inherits **class Point2D** <br>
It has following members:
  * coordinate **double z**
  * methods **void setZ(), void getZ()**
  * method **double getDistanceTo()** which accepts point in 2D dimension and has following rules:
    * if argument point is in 3D dimension, then the function should return the distance in 3D dimension
    * if argument point is in 2D dimension, then the function should return the distance in 2D dimension (using only coordinates x and y)
  * method **void print()** which gives us information about all coordinates
  
* class Refill <br>
This class is needed for weapons which are shooters (weapons with bullets) <br>
It has following members:
  * variable **int numberStartBullets** which will save information about the capacity of every single refill
  * variable **int numberCurrentBullets** which will save information about the number of bullets which are left in the refill <br>
  after shooting from weapons
  * method **void print()** which gives us information about the refill
  
* abstract class Weapons <br>
It has following members:
  * variable **unsigned long weaponID** which is used to make every single weapon object unique (this is done with the variable
  **static unsigned long countWeapons**)
  * variable **string name**
  * variable **double weight**
  * variable **int damage**
  * variable **int startDefense** which we need in order to define if weapon is damaged or broken after attack or to restore <br>
  first value of the defense after using method **void repairWeapon()** in **class Champions**
  * variable **int defense**
  * variable **int movementSpeed**
  * variable **double range** which helps us to define the allowable distance between champions
  * variable **WeaponType type** which is used to define if weapon is None, Shooter or Handgun
  * variable **WeaponStatus status** which is used to define is weapon is Strong, Damaged or Broken
  * method **void print()** which gives us information about every weapon object
  
* abstract class Shooters - inherits **class Weapons** <br>
It has the following members:
  * object **Refill'*' refill** - every shooter has refill which is full with bullets
  * method **void print()** which gives us information about every shooter object
  
* abstract class Handguns - inherits **class Weapons** <br>
It has the following members:
  * method **void print()** which gives us information about every handgun object
  
* class Sniper - inherits **class Shooters** <br>
It has the following members:
  * method **void print()** which gives us information about every sniper object
  
* class Gun - inherits **class Shooters** <br>
It has the following members:
  * method **void print()** which gives us information about every gun object
  
* class Sword - inherits **class Handguns** <br>
It has the following members:
  * method **void print()** which gives us information about every sword object
  
* class Stick - inherits **class Handguns** <br>
It has the following members:
  * variable **double length**
  * method **void print()** which gives us information about every stick object
  
* abstract class Champions <br>
It has the following members:
  * variable **unsigned long championID** which is used to make every single champion object unique (this is done with the variable
  **static unsigned long countChampions**)
  * variable **string name**
  * variable **int startHealth** which we need in order to define if champion is attacked or to restore champion health with <br>
  help of healer
  * variable **int health**
  * variable **string spell**
  * variable **Category category** which gives us information if a champion is Human, Assassin, Wizard or Healer
  * variable **Point2D'*' location** which stores location of created champion (it can be Point2D or Point3D)
  * variable **Weapons* weapon** which stores weapon of created champion (it can be Sniper, Gun, Sword, Stick or none of them)
  * methods **void setName()** and **string getName()** - the champion's name can be changed at any time
  * method **double getDistanceTo2D()** which accepts champion with point in 2D or in 3D dimension and the calculated <br>
  distance should be in 2D dimension (using only coordinates **x** and **y**)
  * method **double getDistanceTo()** which accepts champion with point in 2D or in 3D dimension and the calculated <br>
  distance follows these rules:
    * if one of the locations are in 2D dimension, then the calculated distance should be in 2D dimension
    * if two of the locations are in 2D dimension, then the calculated distance should be in 2D dimension
    * if two of the locations are in 3D dimenstion, then the calculated distance should be in 3D dimension
  * method **void moveTo()** which accepts point in 2D or 3D dimension and should change champion's location depending to <br>
  accepted point
  * method **void moveTo** which accepts other champion and should change champion's location to other champion's location
  * method **void takeWeapon()** which gives a chance to a champion to take weapon if it doesn't have
  * method **void throwWeapon()** which gives a chance to a champion to "throw" its weapon
  * method **void giveWeaponTo()** which accepts as an argument other champion and has these rules:
    * if the main champion has weapon and uses this method, then it doesn't have this weapon anymore
    * if the other champion doesn't have weapon, then it takes the main champion's weapon
  * method **void rechargeWeapon()** which gives a chance to a champion to recharge its shooter weapon (sniper or gun)
  * method **void repairWeapon()** which gives a chance to a champion to repair its weapon if it is damaged or broken
  * method **void attack()** which accrepts as an argument other champion and has these rules:
    * other champion can be attacked only if it is in range with the main champion (this depends alos if the main character <br>
    has a weapon - as example weapon sniper has range 70 m, which means that the allowed distance is greater than in situation <br>
    when the main character doesn't have a weapon
    * other champion can defend itself if it has a weapon
  * method **void printWeaponInformation()** which gives us information about a champion's weapon
  * method **void printLocation()** which gives us information about a champion's coordinates
  * method **void print()** which gives us information about every champion object
  
* class Human - inherits **class Champions** <br>
It has following members:
  * method **void print()** which gives us information about every human object
  
* class Assassin - inherits **class Champions** <br>
It has following members:
  * method **void print()** which gives us information about every assassin object
  
* class Wizard - inherits **class Champions** <br>
It has following members:
  * method **void breakWeaponTo()** which accepts as an argument other champion and every wizard object can "breaks" <br>
  other champion's weapon (one wizard is not allowed to break its weapon)
  * method **void print()** which gives us information about every wizard object
  
* class Healer - inherits **class Champions** <br>
It has following members:
  * method **void heal()** which accepts as an argument other champion and every healer object can increse health of <br>
  other champion. It has these rules:
    * one healer can heal everyone except other healer
    * one healer can heal itself
  * method **void print()** which gives us information about every healer object
  
**_Snipers, guns, swords and sticks have different names and values connected with weight, damage, defense, type <br>
and all other variables. Same is valid for humans, assassins, wizards and healers - they have different names and values <br>
connected with health, spells and other variables. The description summarizes the integrity of the project. More detailed <br>
infromation can be received after project review._**
