#include "pch.h"
#include "CppUnitTest.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Human.h"
#include "Assassin.h"
#include "Sniper.h"
#include "Gun.h"
#include "Sword.h"
#include <cmath>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		//Tests for Point2D
		TEST_METHOD(TestIfSelfDistanceInPoint2DIs0)
		{
			Point2D point(1, 11);
			double distance = point.getDistanceTo(point);
			Assert::AreEqual(0.0, distance);
		}
		TEST_METHOD(TestIfDistanceInPoint2DIsSqrt2)
		{
			Point2D pointOne(1, -1);
			Point2D pointTwo(2, -2);
			double numberForCheck = sqrt(2);
			double distance = pointOne.getDistanceTo(pointTwo);
			Assert::AreEqual(numberForCheck, distance);
		}
		TEST_METHOD(TestIfDistanceInPoint2DIsSqrt8)
		{
			Point2D pointOne(0, 0);
			Point2D pointTwo(2, 2);
			double numberForCheck = sqrt(8);
			double distance = pointOne.getDistanceTo(pointTwo);
			Assert::AreEqual(numberForCheck, distance);
		}
		TEST_METHOD(TestIfDistanceInPoint2DIs0)
		{
			Point2D pointOne(0, 0);
			Point2D pointTwo;
			double distance = pointOne.getDistanceTo(pointTwo);
			Assert::AreEqual(0.0, distance);
		}

		//Tests for Point3D
		TEST_METHOD(TestIfSelfDistanceInPoint3DIs0)
		{
			Point3D point(1, 11, 15);
			double distance = point.getDistanceTo(point);
			Assert::AreEqual(0.0, distance);
		}

		TEST_METHOD(TestIfDistanceInPoint3DIsSqrt29)
		{
			Point3D pointOne(1, 11, 15);
			Point3D pointTwo(3, 8, 11);
			double numberForCheck = sqrt(29);
			double distance = pointOne.getDistanceTo(pointTwo);
			Assert::AreEqual(numberForCheck, distance);
		}

		//Test Point2D and Point3D together
		TEST_METHOD(TestIfDistanceBetweenPoint2DAndPoint3DIsSqrt13)
		{
			Point2D pointIn2D(1, 11);
			Point3D pointIn3D(3, 8, 11);
			double numberForCheck = sqrt(13);
			double distance = pointIn2D.getDistanceTo(pointIn3D);
			Assert::AreEqual(numberForCheck, distance);
		}

		TEST_METHOD(TestIfDistanceBetweenPoint3DAndPoint2DIsSqrt13)
		{
			Point3D pointIn3D(1, 11, 15);
			Point2D pointIn2D(3, 8);
			double numberForCheck = sqrt(13);
			double distance = pointIn3D.getDistanceTo(pointIn2D);
			Assert::AreEqual(numberForCheck, distance);
		}

		TEST_METHOD(TestIfDistanceBetweenPoint2DAndPoint3DEqualsDistanceBetweenPoint3DAndPoint2D)
		{
			Point2D pointIn2D(3, 100);
			Point3D pointIn3D(1, 20, 300);
			double distanceBetweenPoint2DAndPoint3D = pointIn2D.getDistanceTo(pointIn3D);
			double distanceBetweenPoint3DAndPoint2D = pointIn3D.getDistanceTo(pointIn2D);
			Assert::AreEqual(distanceBetweenPoint2DAndPoint3D, distanceBetweenPoint3DAndPoint2D);
		}

		//Test Human Default Constructor
		TEST_METHOD(TestIfNameFromHumanDefaultConstructorIsUnknownHuman)
		{
			Human human;
			std::string humanName(human.getName());
			std::string unknownHumanName("Unknown human");
			Assert::AreEqual(0, humanName.compare(unknownHumanName));
		}

		/*TEST_METHOD(TestIfLocationFromHumanDefaultConstructorIsNullptr)
		{
			Human human;
			Point2D* checkLocation = nullptr;
			//Assert::AreEqual(checkLocation, human.getLocation());
			Assert::AreSame(checkLocation, human.getLocation());
		}*/

		TEST_METHOD(TestIfCategoryFromHumanDefaultConstructorIsHumans)
		{
			Human human;
			Category humanCategory = human.getCategory();
			Assert::AreEqual(static_cast<int>(Category::Humans), static_cast<int>(humanCategory));
		}

		TEST_METHOD(TestIfStartHealthFromHumanDefaultConstructorIs500)
		{
			Human human;
			int humanStartHealth = human.getStartHealth();
			Assert::AreEqual(500, humanStartHealth);
		}

		TEST_METHOD(TestIfHealthFromHumanDefaultConstructorIs500)
		{
			Human human;
			int humanHealth = human.getHealth();
			Assert::AreEqual(500, humanHealth);
		}

		TEST_METHOD(TestIfSpellFromHumanDefaultConstructorIsBarrier)
		{
			Human human;
			std::string humanSpell = human.getSpell();
			Assert::AreEqual(0, humanSpell.compare("Barrier"));
		}

		//Test Human Parameter Constructor

		TEST_METHOD(TestIfNameFromHumanParameterConstructorIsSetName)
		{
			Point3D point3D(1, 2, 3);
			Human human("A", point3D);
			std::string humanName(human.getName());
			std::string unknownHumanName("A");
			Assert::AreEqual(0, humanName.compare(unknownHumanName));
		}

		/*TEST_METHOD(TestIfLocationFromHumanParameterConstructorIsSetLocation)
		{
			Point2D* point3D = new Point3D(1, 2, 3);
			Human human("A", *point3D);
			//Assert::AreEqual(point3D, human.getLocation());
			Assert::AreSame(point3D, human.getLocation());
		}*/

		TEST_METHOD(TestIfCategoryFromHumanParameterConstructorIsHumans)
		{
			Point3D point3D(1, 2, 3);
			Human human("A", point3D);
			Category humanCategory = human.getCategory();
			Assert::AreEqual(static_cast<int>(Category::Humans), static_cast<int>(humanCategory));
		}

		TEST_METHOD(TestIfStartHealthFromHumanParameterConstructorIs500)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			int humanStartHealth = human.getStartHealth();
			Assert::AreEqual(500, humanStartHealth);
		}

		TEST_METHOD(TestIfHealthFromHumanParameterConstructorIs500)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			int humanHealth = human.getHealth();
			Assert::AreEqual(500, humanHealth);
		}

		TEST_METHOD(TestIfSpellFromHumanParameterConstructorIsBarrier)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			std::string humanSpell = human.getSpell();
			Assert::AreEqual(0, humanSpell.compare("Barrier"));
		}

		//Test Human Copy Constructor
		TEST_METHOD(TestIfNameFromHumanCopyConstructorIsSameAsOtherHumanName)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Human testingHuman(human);
			std::string humanName(human.getName());
			std::string testingHumanName(testingHuman.getName());
			Assert::AreEqual(0, humanName.compare(testingHumanName));
		}

		TEST_METHOD(TestIfCategoryFromHumanCopyConstructorIsSameAsOtherHumanCategory)
		{
			Point3D point3D(1, 2, 3);
			Human human("A", point3D);
			Human testingHuman(human);
			Category humanCategory = human.getCategory();
			Category testingHumanCategory = testingHuman.getCategory();
			Assert::AreEqual(static_cast<int>(humanCategory), static_cast<int>(testingHumanCategory));
		}

		TEST_METHOD(TestIfStartHealthFromHumanCopyConstructorIsSameAsOtherHumanStartHealth)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Human testingHuman(human);
			int humanStartHealth = human.getStartHealth();
			Assert::AreEqual(human.getStartHealth(), testingHuman.getStartHealth());
		}

		TEST_METHOD(TestIfHealthFromHumanCopyConstructorIsSameAsOtherHumanHealth)
		{
			Point3D point3D(1, 2, 3);
			Human human("A", point3D);
			Human testingHuman(human);
			Assert::AreEqual(human.getHealth(), testingHuman.getHealth());
		}

		TEST_METHOD(TestIfSpellFromHumanCopyConstructorIsSameAsOtherHumanSpell)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Human testingHuman(human);
			std::string humanSpell = human.getSpell();
			std::string testingHumanSpell = testingHuman.getSpell();
			Assert::AreEqual(0, humanSpell.compare(testingHumanSpell));
		}

		//Test Human Overloading Operator=
		TEST_METHOD(TestIfNameFromHumanOverloadingOperatorIsSameAsOtherHumanName)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Human testingHuman;
			testingHuman = human;
			std::string humanName(human.getName());
			std::string testingHumanName(testingHuman.getName());
			Assert::AreEqual(0, humanName.compare(testingHumanName));
		}

		TEST_METHOD(TestIfCategoryFromHumanOverloadingOperatorIsSameAsOtherHumanCategory)
		{
			Point3D point3D(1, 2, 3);
			Human human("A", point3D);
			Human testingHuman;
			testingHuman = human;
			Category humanCategory = human.getCategory();
			Category testingHumanCategory = testingHuman.getCategory();
			Assert::AreEqual(static_cast<int>(humanCategory), static_cast<int>(testingHumanCategory));
		}

		TEST_METHOD(TestIfStartHealthFromHumanOverloadingOperatorIsSameAsOtherHumanStartHealth)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Human testingHuman;
			testingHuman = human;
			int humanStartHealth = human.getStartHealth();
			Assert::AreEqual(human.getStartHealth(), testingHuman.getStartHealth());
		}

		TEST_METHOD(TestIfHealthFromHumanOverloadingOperatorIsSameAsOtherHumanHealth)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Human testingHuman;
			testingHuman = human;
			Assert::AreEqual(human.getHealth(), testingHuman.getHealth());
		}

		TEST_METHOD(TestIfSpellFromHumanOverloadingOperatorIsSameAsOtherHumanSpell)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Human testingHuman;
			testingHuman = human;
			std::string humanSpell = human.getSpell();
			std::string testingHumanSpell = testingHuman.getSpell();
			Assert::AreEqual(0, humanSpell.compare(testingHumanSpell));
		}

		//Test Gun Default Constructor
		TEST_METHOD(TestIfNameFromGunDefaultConstructorIsGun)
		{
			Gun gun;
			std::string gunName = gun.getName();
			Assert::AreEqual(0, gunName.compare("Gun"));
		}

		TEST_METHOD(TestIfTypeFromGunDefaultConstructorIsShooter)
		{
			Gun gun;
			WeaponType gunType = gun.getWeaponType();
			Assert::AreEqual(static_cast<int>(WeaponType::Shooter), static_cast<int>(gunType));
		}

		TEST_METHOD(TestIfNumberStartBulletsFromGunDefaultConstructorAre20)
		{
			Gun gun;
			int numberStartBullets = gun.getNumberStartBulletsInRefill();
			Assert::AreEqual(20, numberStartBullets);
		}

		TEST_METHOD(TestIfNumberCurrentBulletsFromGunDefaultConstructorAreEqualNumberStartBullets)
		{
			Gun gun;
			int numberStartBullets = gun.getNumberStartBulletsInRefill();
			int numberCurrentBullets = gun.getNumberCurrentBulletsInRefill();
			Assert::AreEqual(numberStartBullets, numberCurrentBullets);
		}

		TEST_METHOD(TestIfWeightFromGunDefaultConstructorIs175grams)
		{
			Gun gun;
			double gunWeight = gun.getWeight();
			Assert::AreEqual(1.75, gunWeight);
		}

		TEST_METHOD(TestIfDamageFromGunDefaultConstructorIs80)
		{
			Gun gun;
			int gunDamage = gun.getDamage();
			Assert::AreEqual(80, gunDamage);
		}

		TEST_METHOD(TestIfStartDefenseFromGunDefaultConstructorIs3)
		{
			Gun gun;
			int gunStartDefense = gun.getStartDefense();
			Assert::AreEqual(3, gunStartDefense);
		}

		TEST_METHOD(TestIfCurrentDefenseFromGunDefaultConstructorEqualsStartDefense)
		{
			Gun gun;
			int gunStartDefense = gun.getStartDefense();
			int gunCurrentDefense = gun.getDefense();
			Assert::AreEqual(gunStartDefense, gunCurrentDefense);
		}

		TEST_METHOD(TestIfMovementSpeedFromGunDefaultConstructorIs130)
		{
			Gun gun;
			int gunMovementSpeed = gun.getMovementSpeed();
			Assert::AreEqual(130, gunMovementSpeed);
		}

		TEST_METHOD(TestIfRangeFromGunDefaultConstructorIs35)
		{
			Gun gun;
			double gunRange = gun.getRange();
			Assert::AreEqual(35.0, gunRange);
		}

		TEST_METHOD(TestIfStatusFromGunDefaultConstructorIsStrong)
		{
			Gun gun;
			WeaponStatus gunStatus = gun.getStatus();
			Assert::AreEqual(static_cast<int>(WeaponStatus::Strong), static_cast<int>(gunStatus));
		}

		//Test Gun Copy Constructor
		TEST_METHOD(TestIfNameFromGunCopyConstructorIsSameAsOtherGunName)
		{
			Gun gun;
			Gun testingGun(gun);
			std::string gunName = gun.getName();
			std::string testingGunName = testingGun.getName();
			Assert::AreEqual(0, gunName.compare(testingGunName));
		}

		TEST_METHOD(TestIfTypeFromGunDefaultConstructorIsSameAsOtherGunType)
		{
			Gun gun;
			Gun testingGun(gun);
			WeaponType gunType = gun.getWeaponType();
			WeaponType testingGunType = testingGun.getWeaponType();
			Assert::AreEqual(static_cast<int>(gunType), static_cast<int>(testingGunType));
		}

		TEST_METHOD(TestIfNumberStartBulletsFromGunCopyConstructorAreSameAsOtherGunNumberStartBullets)
		{
			Gun gun;
			Gun testingGun(gun);
			int gunNumberStartBullets = gun.getNumberStartBulletsInRefill();
			int testingGunNumberStartBullets = testingGun.getNumberStartBulletsInRefill();
			Assert::AreEqual(gunNumberStartBullets, testingGunNumberStartBullets);
		}

		TEST_METHOD(TestIfNumberCurrentBulletsFromGunCopyConstructorAreSameAsOtherGunNumberCurrentBullets)
		{
			Gun gun;
			Gun testingGun(gun);
			int gunNumberCurrentBullets = gun.getNumberCurrentBulletsInRefill();
			int testingGunNumberCurrentBullets = testingGun.getNumberCurrentBulletsInRefill();
			Assert::AreEqual(gunNumberCurrentBullets, testingGunNumberCurrentBullets);
		}

		TEST_METHOD(TestIfWeightFromGunCopyConstructorIsSameAsOtherGunWeight)
		{
			Gun gun;
			Gun testingGun(gun);
			double gunWeight = gun.getWeight();
			double testingGunWeight = testingGun.getWeight();
			Assert::AreEqual(gunWeight, testingGunWeight);
		}

		TEST_METHOD(TestIfDamageFromGunCopyConstructorIsSameAsOtherGunDamage)
		{
			Gun gun;
			Gun testingGun(gun);
			double gunDamage = gun.getDamage();
			double testingGunDamage = testingGun.getDamage();
			Assert::AreEqual(gunDamage, testingGunDamage);
		}

		TEST_METHOD(TestIfStartDefenseFromGunCopyConstructorIsSameAsOtherGunStartDefense)
		{
			Gun gun;
			Gun testingGun(gun);
			int gunStartDefense = gun.getStartDefense();
			int testingGunStartDefense = testingGun.getStartDefense();
			Assert::AreEqual(gunStartDefense, testingGunStartDefense);
		}

		TEST_METHOD(TestIfCurrentDefenseFromGunCopyConstructorIsSameAsOtherGunCurrentDefense)
		{
			Gun gun;
			Gun testingGun(gun);
			int gunCurrentDefense = gun.getDefense();
			int testingGunCurrentDefense = testingGun.getDefense();
			Assert::AreEqual(gunCurrentDefense, testingGunCurrentDefense);
		}

		TEST_METHOD(TestIfMovementSpeedFromGunCopyConstructorIsSameAsOtherGunMovementSpeed)
		{
			Gun gun;
			Gun testingGun(gun);
			int gunMovementSpeed = gun.getMovementSpeed();
			int testingGunMovementSpeed = testingGun.getMovementSpeed();
			Assert::AreEqual(gunMovementSpeed, testingGunMovementSpeed);
		}

		TEST_METHOD(TestIfRangeFromGunCopyConstructorIsSameAsOtherGunRange)
		{
			Gun gun;
			Gun testingGun(gun);
			double gunRange = gun.getRange();
			double testingGunRange = testingGun.getRange();
			Assert::AreEqual(gunRange, testingGunRange);
		}

		TEST_METHOD(TestIfStatusFromGunDefaultConstructorIsSameAsOtherGunStatus)
		{
			Gun gun;
			Gun testingGun(gun);
			WeaponStatus gunStatus = gun.getStatus();
			WeaponStatus testingGunStatus = testingGun.getStatus();
			Assert::AreEqual(static_cast<int>(gunStatus), static_cast<int>(testingGunStatus));
		}

		//Test Sword Default Constructor -> only one because other functions are the same as other weapons
		TEST_METHOD(TestIfTypeFromSwordDefaultConstructorIsHandgun)
		{
			Sword sword;
			WeaponType swordType = sword.getWeaponType();
			Assert::AreEqual(static_cast<int>(WeaponType::Handgun), static_cast<int>(swordType));
		}

		//Test Sniper
		TEST_METHOD(TestIfWeightOfSniperIs8)
		{
			Sniper sniper;
			double sniperWeight = sniper.getWeight();
			double comparedWeight = 8.0;
			Assert::AreEqual(comparedWeight, sniperWeight);
		}

		TEST_METHOD(TestIfBulletsInSniperAfterOneShotAreWithOneLesser)
		{
			Point2D firstPoint2D(1, 1);
			Point2D secondPoint2D(2, 1);
			Human human("H", firstPoint2D);
			Assassin assassin("A", secondPoint2D);
			Sniper sniper;
			human.takeWeapon(sniper);
			int numberStartBullets = human.getWeapon()->getNumberStartBulletsInRefill();
			human.attack(assassin);
			int numberCurrentBullets = human.getWeapon()->getNumberCurrentBulletsInRefill();
			int difference = numberStartBullets - numberCurrentBullets;
			Assert::AreEqual(1, difference);
		}

		//Test Human
		/*TEST_METHOD(TestIfHumanNameIsHuman)
		{
			Human human;
			std::string humanName = human.getName();
			Assert::AreEqual(1, humanName.compare("Human"));
		}*/
	};
}
