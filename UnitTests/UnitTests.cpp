#include "pch.h"
#include "CppUnitTest.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Human.h"
#include "Assassin.h"
#include "Wizard.h"
#include "Healer.h"
#include "Sniper.h"
#include "Gun.h"
#include "Sword.h"
#include "Stick.h"
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

		TEST_METHOD(TestIfLocationFromHumanDefaultConstructorIsNotSet)
		{
			Human human;
			Assert::AreEqual(false, human.hasLocation());
		}

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

		TEST_METHOD(TestIfWeaponFromHumanDefaultConstructorIsNotSet)
		{
			Human human;
			Assert::AreEqual(false, human.hasWeapon());
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

		TEST_METHOD(TestIfPointFromHumanParameterConstructorIsSet)
		{
			Point3D point3D(1, 2, 3);
			Human human("A", point3D);
			double arrayPoint3DCoordinates[3];
			arrayPoint3DCoordinates[0] = point3D.getX();
			arrayPoint3DCoordinates[1] = point3D.getY();
			arrayPoint3DCoordinates[2] = point3D.getZ();

			double arrayHumanCoordinates[3];
			arrayHumanCoordinates[0] = human.getLocation()->getX();
			arrayHumanCoordinates[1] = human.getLocation()->getY();
			arrayHumanCoordinates[2] = human.getLocation()->getZ();

			int countFaults = 0;

			for (int i = 0; i < 3; i++)
			{
				if (arrayHumanCoordinates[i] != arrayPoint3DCoordinates[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
		}

		TEST_METHOD(TestIfLocationFromHumanParameterConstructorIsSet)
		{
			Point3D point3D(1, 2, 3);
			Human human("A", point3D);
			bool isLocationSet = human.hasLocation();
			Assert::AreEqual(true, isLocationSet);
		}

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

		TEST_METHOD(TestIfWeaponFromHumanParameterConstructorIsNotSet)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Assert::AreEqual(false, human.hasWeapon());
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

		TEST_METHOD(TestIfPointFromHumanCopyConstructorIsSameAsOtherHumanPoint)
		{
			Point3D point3D(1, 2, 3);
			Human human("First Human", point3D);
			Human testingHuman(human);
			double arrayHumanCoordinates[3];
			arrayHumanCoordinates[0] = human.getLocation()->getX();
			arrayHumanCoordinates[1] = human.getLocation()->getY();
			arrayHumanCoordinates[2] = human.getLocation()->getZ();

			double arrayTestingHumanCoordinates[3];
			arrayTestingHumanCoordinates[0] = testingHuman.getLocation()->getX();
			arrayTestingHumanCoordinates[1] = testingHuman.getLocation()->getY();
			arrayTestingHumanCoordinates[2] = testingHuman.getLocation()->getZ();

			int countFaults = 0;

			for (int i = 0; i < 3; i++)
			{
				if (arrayHumanCoordinates[i] != arrayTestingHumanCoordinates[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
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

		TEST_METHOD(TestIfPointFromHumanOverloadingOperatorIsSameAsOtherHumanPoint)
		{
			Point3D point3D(5, 1, 100);
			Human human("First Human", point3D);
			Human testingHuman;
			testingHuman = human;
			double arrayHumanCoordinates[3];
			arrayHumanCoordinates[0] = human.getLocation()->getX();
			arrayHumanCoordinates[1] = human.getLocation()->getY();
			arrayHumanCoordinates[2] = human.getLocation()->getZ();

			double arrayTestingHumanCoordinates[3];
			arrayTestingHumanCoordinates[0] = testingHuman.getLocation()->getX();
			arrayTestingHumanCoordinates[1] = testingHuman.getLocation()->getY();
			arrayTestingHumanCoordinates[2] = testingHuman.getLocation()->getZ();

			int countFaults = 0;

			for (int i = 0; i < 3; i++)
			{
				if (arrayHumanCoordinates[i] != arrayTestingHumanCoordinates[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
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

		//Test Assassin Default Constructor
		TEST_METHOD(TestIfNameFromAssassinDefaultConstructorIsUnknownAssassin)
		{
			Assassin assassin;
			std::string assassinName(assassin.getName());
			std::string unknownAssassinName("Unknown assassin");
			Assert::AreEqual(0, assassinName.compare(unknownAssassinName));
		}

		TEST_METHOD(TestIfLocationFromAssassinDefaultConstructorIsNotSet)
		{
			Assassin assassin;
			Assert::AreEqual(false, assassin.hasLocation());
		}

		TEST_METHOD(TestIfCategoryFromAssassinDefaultConstructorIsAssassins)
		{
			Assassin assassin;
			Category assassinCategory = assassin.getCategory();
			Assert::AreEqual(static_cast<int>(Category::Assassins), static_cast<int>(assassinCategory));
		}

		TEST_METHOD(TestIfStartHealthFromAssassinDefaultConstructorIs1500)
		{
			Assassin assassin;
			int assassinStartHealth = assassin.getStartHealth();
			Assert::AreEqual(1500, assassinStartHealth);
		}

		TEST_METHOD(TestIfHealthFromAssassinDefaultConstructorIs1500)
		{
			Assassin assassin;
			int assassinHealth = assassin.getHealth();
			Assert::AreEqual(1500, assassinHealth);
		}

		TEST_METHOD(TestIfSpellFromAssassinDefaultConstructorIsIgnite)
		{
			Assassin assassin;
			std::string assassinSpell = assassin.getSpell();
			Assert::AreEqual(0, assassinSpell.compare("Ignite"));
		}

		TEST_METHOD(TestIfWeaponFromAssassinDefaultConstructorIsNotSet)
		{
			Assassin assassin;
			Assert::AreEqual(false, assassin.hasWeapon());
		}

		//Test Wizard Default Constructor
		TEST_METHOD(TestIfNameFromWizardDefaultConstructorIsUnknownWizard)
		{
			Wizard wizard;
			std::string wizardName(wizard.getName());
			std::string unknownWizardName("Unknown wizard");
			Assert::AreEqual(0, wizardName.compare(unknownWizardName));
		}

		TEST_METHOD(TestIfLocationFromWizardDefaultConstructorIsNotSet)
		{
			Wizard wizard;
			Assert::AreEqual(false, wizard.hasLocation());
		}

		TEST_METHOD(TestIfCategoryFromWizardDefaultConstructorIsWizards)
		{
			Wizard wizard;
			Category wizardCategory = wizard.getCategory();
			Assert::AreEqual(static_cast<int>(Category::Wizards), static_cast<int>(wizardCategory));
		}

		TEST_METHOD(TestIfStartHealthFromWizardDefaultConstructorIs1800)
		{
			Wizard wizard;
			int wizardStartHealth = wizard.getStartHealth();
			Assert::AreEqual(1800, wizardStartHealth);
		}

		TEST_METHOD(TestIfHealthFromWizardDefaultConstructorIs1800)
		{
			Wizard wizard;
			int wizardHealth = wizard.getHealth();
			Assert::AreEqual(1800, wizardHealth);
		}

		TEST_METHOD(TestIfSpellFromWizardDefaultConstructorIsMagic)
		{
			Wizard wizard;
			std::string wizardSpell = wizard.getSpell();
			Assert::AreEqual(0, wizardSpell.compare("Magic"));
		}

		TEST_METHOD(TestIfWeaponFromWizardDefaultConstructorIsNotSet)
		{
			Wizard wizard;
			Assert::AreEqual(false, wizard.hasWeapon());
		}

		//Test Healer Default Constructor
		TEST_METHOD(TestIfNameFromHealerDefaultConstructorIsUnknownHealer)
		{
			Healer healer;
			std::string healerName(healer.getName());
			std::string unknownHealerName("Unknown healer");
			Assert::AreEqual(0, healerName.compare(unknownHealerName));
		}

		TEST_METHOD(TestIfLocationFromHealerDefaultConstructorIsNotSet)
		{
			Healer healer;
			Assert::AreEqual(false, healer.hasLocation());
		}

		TEST_METHOD(TestIfCategoryFromHealerDefaultConstructorIsHealers)
		{
			Healer healer;
			Category healerCategory = healer.getCategory();
			Assert::AreEqual(static_cast<int>(Category::Healers), static_cast<int>(healerCategory));
		}

		TEST_METHOD(TestIfStartHealthFromHealerDefaultConstructorIs1000)
		{
			Healer healer;
			int healerStartHealth = healer.getStartHealth();
			Assert::AreEqual(1000, healerStartHealth);
		}

		TEST_METHOD(TestIfHealthFromHealerDefaultConstructorIs1000)
		{
			Healer healer;
			int healerHealth = healer.getHealth();
			Assert::AreEqual(1000, healerHealth);
		}

		TEST_METHOD(TestIfSpellFromHealerDefaultConstructorIsHeal)
		{
			Healer healer;
			std::string healerSpell = healer.getSpell();
			Assert::AreEqual(0, healerSpell.compare("Heal"));
		}

		TEST_METHOD(TestIfWeaponFromHealerDefaultConstructorIsNotSet)
		{
			Healer healer;
			Assert::AreEqual(false, healer.hasWeapon());
		}

		//Test Sword Default Constructor
		TEST_METHOD(TestIfNameFromSwordDefaultConstructorIsSword)
		{
			Sword sword;
			std::string swordName = sword.getName();
			Assert::AreEqual(0, swordName.compare("Sword"));
		}

		TEST_METHOD(TestIfTypeFromSwordDefaultConstructorIsHandgun)
		{
			Sword sword;
			WeaponType swordType = sword.getWeaponType();
			Assert::AreEqual(static_cast<int>(WeaponType::Handgun), static_cast<int>(swordType));
		}

		TEST_METHOD(TestIfWeightFromSwordDefaultConstructorIs2500grams)
		{
			Sword sword;
			double swordWeight = sword.getWeight();
			Assert::AreEqual(2.5, swordWeight);
		}

		TEST_METHOD(TestIfDamageFromSwordDefaultConstructorIs50)
		{
			Sword sword;
			int swordDamage = sword.getDamage();
			Assert::AreEqual(50, swordDamage);
		}

		TEST_METHOD(TestIfStartDefenseFromSwordDefaultConstructorIs25)
		{
			Sword sword;
			int swordStartDefense = sword.getStartDefense();
			Assert::AreEqual(25, swordStartDefense);
		}

		TEST_METHOD(TestIfCurrentDefenseFromSwordDefaultConstructorEqualsStartDefense)
		{
			Sword sword;
			int swordStartDefense = sword.getStartDefense();
			int swordCurrentDefense = sword.getDefense();
			Assert::AreEqual(swordStartDefense, swordCurrentDefense);
		}

		TEST_METHOD(TestIfMovementSpeedFromSwordDefaultConstructorIs410)
		{
			Sword sword;
			int swordMovementSpeed = sword.getMovementSpeed();
			Assert::AreEqual(410, swordMovementSpeed);
		}

		TEST_METHOD(TestIfRangeFromSwordDefaultConstructorIs1500metres)
		{
			Sword sword;
			double swordRange = sword.getRange();
			Assert::AreEqual(1.5, swordRange);
		}

		TEST_METHOD(TestIfStatusFromSwordDefaultConstructorIsStrong)
		{
			Sword sword;
			WeaponStatus swordStatus = sword.getStatus();
			Assert::AreEqual(static_cast<int>(WeaponStatus::Strong), static_cast<int>(swordStatus));
		}

		//Test Stick Default Constructor
		TEST_METHOD(TestIfNameFromStickDefaultConstructorIsStick)
		{
			Stick stick;
			std::string stickName = stick.getName();
			Assert::AreEqual(0, stickName.compare("Stick"));
		}

		TEST_METHOD(TestIfTypeFromStickDefaultConstructorIsHandgun)
		{
			Stick stick;
			WeaponType stickType = stick.getWeaponType();
			Assert::AreEqual(static_cast<int>(WeaponType::Handgun), static_cast<int>(stickType));
		}

		TEST_METHOD(TestIfWeightFromStickDefaultConstructorIs1)
		{
			Stick stick;
			double stickWeight = stick.getWeight();
			Assert::AreEqual(1.0, stickWeight);
		}

		TEST_METHOD(TestIfDamageFromStickDefaultConstructorIs30)
		{
			Stick stick;
			int stickDamage = stick.getDamage();
			Assert::AreEqual(30, stickDamage);
		}

		TEST_METHOD(TestIfStartDefenseFromStickDefaultConstructorIs15)
		{
			Stick stick;
			int stickStartDefense = stick.getStartDefense();
			Assert::AreEqual(15, stickStartDefense);
		}

		TEST_METHOD(TestIfCurrentDefenseFromStickDefaultConstructorEqualsStartDefense)
		{
			Stick stick;
			int stickStartDefense = stick.getStartDefense();
			int stickCurrentDefense = stick.getDefense();
			Assert::AreEqual(stickStartDefense, stickCurrentDefense);
		}

		TEST_METHOD(TestIfMovementSpeedFromStickDefaultConstructorIs500)
		{
			Stick stick;
			int stickMovementSpeed = stick.getMovementSpeed();
			Assert::AreEqual(500, stickMovementSpeed);
		}

		TEST_METHOD(TestIfRangeFromStickDefaultConstructorIs1200metres)
		{
			Stick stick;
			double stickRange = stick.getRange();
			Assert::AreEqual(1.2, stickRange);
		}

		TEST_METHOD(TestIfLengthFromStickDefaultConstructorIs1200metres)
		{
			Stick stick;
			double stickLength = stick.getRange();
			Assert::AreEqual(1.2, stickLength);
		}

		TEST_METHOD(TestIfStatusFromStickDefaultConstructorIsStrong)
		{
			Stick stick;
			WeaponStatus stickStatus = stick.getStatus();
			Assert::AreEqual(static_cast<int>(WeaponStatus::Strong), static_cast<int>(stickStatus));
		}

		//Test Sniper Default Constructor
		TEST_METHOD(TestIfNameFromSniperDefaultConstructorIsSniper)
		{
			Sniper sniper;
			std::string sniperName = sniper.getName();
			Assert::AreEqual(0, sniperName.compare("Sniper"));
		}

		TEST_METHOD(TestIfTypeFromSniperDefaultConstructorIsShooter)
		{
			Sniper sniper;
			WeaponType sniperType = sniper.getWeaponType();
			Assert::AreEqual(static_cast<int>(WeaponType::Shooter), static_cast<int>(sniperType));
		}

		TEST_METHOD(TestIfNumberStartBulletsFromSniperDefaultConstructorAre10)
		{
			Sniper sniper;
			int numberStartBullets = sniper.getNumberStartBulletsInRefill();
			Assert::AreEqual(10, numberStartBullets);
		}

		TEST_METHOD(TestIfNumberCurrentBulletsFromSniperDefaultConstructorAreEqualNumberStartBullets)
		{
			Sniper sniper;
			int numberStartBullets = sniper.getNumberStartBulletsInRefill();
			int numberCurrentBullets = sniper.getNumberCurrentBulletsInRefill();
			Assert::AreEqual(numberStartBullets, numberCurrentBullets);
		}

		TEST_METHOD(TestIfWeightFromSniperDefaultConstructorIs8)
		{
			Sniper sniper;
			double sniperWeight = sniper.getWeight();
			Assert::AreEqual(8.0, sniperWeight);
		}

		TEST_METHOD(TestIfDamageFromSniperDefaultConstructorIs100)
		{
			Sniper sniper;
			int sniperDamage = sniper.getDamage();
			Assert::AreEqual(100, sniperDamage);
		}

		TEST_METHOD(TestIfStartDefenseFromSniperDefaultConstructorIs4)
		{
			Sniper sniper;
			int sniperStartDefense = sniper.getStartDefense();
			Assert::AreEqual(4, sniperStartDefense);
		}

		TEST_METHOD(TestIfCurrentDefenseFromSniperDefaultConstructorEqualsStartDefense)
		{
			Sniper sniper;
			int sniperStartDefense = sniper.getStartDefense();
			int sniperCurrentDefense = sniper.getDefense();
			Assert::AreEqual(sniperStartDefense, sniperCurrentDefense);
		}

		TEST_METHOD(TestIfMovementSpeedFromSniperDefaultConstructorIs200)
		{
			Sniper sniper;
			int sniperMovementSpeed = sniper.getMovementSpeed();
			Assert::AreEqual(200, sniperMovementSpeed);
		}

		TEST_METHOD(TestIfRangeFromGunDefaultConstructorIs70)
		{
			Sniper sniper;
			double sniperRange = sniper.getRange();
			Assert::AreEqual(70.0, sniperRange);
		}

		TEST_METHOD(TestIfStatusFromSniperDefaultConstructorIsStrong)
		{
			Sniper sniper;
			WeaponStatus sniperStatus = sniper.getStatus();
			Assert::AreEqual(static_cast<int>(WeaponStatus::Strong), static_cast<int>(sniperStatus));
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

		//Test method moveTo from class Champions
		TEST_METHOD(TestIfChampionCanMoveToPoint2D)
		{
			Point2D point2D(3, 2);
			Assassin assassin;
			assassin.moveTo(point2D);
			double arrayCoordinatesPoint2D[3];
			arrayCoordinatesPoint2D[0] = point2D.getX();
			arrayCoordinatesPoint2D[1] = point2D.getY();
			arrayCoordinatesPoint2D[2] = point2D.getZ();

			double arrayAssassinCoordinates[3];
			arrayAssassinCoordinates[0] = assassin.getLocation()->getX();
			arrayAssassinCoordinates[1] = assassin.getLocation()->getY();
			arrayAssassinCoordinates[2] = assassin.getLocation()->getZ();

			int countFaults = 0;
			for (int i = 0; i < 3; i++)
			{
				if (arrayAssassinCoordinates[i] != arrayCoordinatesPoint2D[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
		}

		TEST_METHOD(TestIfChampionCanMoveToPoint3D)
		{
			Point3D point3D(3, 2, 5);
			Assassin assassin;
			assassin.moveTo(point3D);
			double arrayCoordinatesPoint3D[3];
			arrayCoordinatesPoint3D[0] = point3D.getX();
			arrayCoordinatesPoint3D[1] = point3D.getY();
			arrayCoordinatesPoint3D[2] = point3D.getZ();

			double arrayAssassinCoordinates[3];
			arrayAssassinCoordinates[0] = assassin.getLocation()->getX();
			arrayAssassinCoordinates[1] = assassin.getLocation()->getY();
			arrayAssassinCoordinates[2] = assassin.getLocation()->getZ();

			int countFaults = 0;
			for (int i = 0; i < 3; i++)
			{
				if (arrayAssassinCoordinates[i] != arrayCoordinatesPoint3D[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
		}

		TEST_METHOD(TestIfChampionCanMoveToOtherChampion)
		{
			Point3D point3D(3, 100, 15);
			Assassin assassin("Assassin", point3D);
			Wizard wizard;
			wizard.moveTo(assassin);
			double arrayAssassinCoordinates[3];
			arrayAssassinCoordinates[0] = assassin.getLocation()->getX();
			arrayAssassinCoordinates[1] = assassin.getLocation()->getY();
			arrayAssassinCoordinates[2] = assassin.getLocation()->getZ();

			double arrayWizardCoordinates[3];
			arrayWizardCoordinates[0] = wizard.getLocation()->getX();
			arrayWizardCoordinates[1] = wizard.getLocation()->getY();
			arrayWizardCoordinates[2] = wizard.getLocation()->getZ();

			int countFaults = 0;
			for (int i = 0; i < 3; i++)
			{
				if (arrayAssassinCoordinates[i] != arrayWizardCoordinates[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
		}

		TEST_METHOD(TestIfChampionCanMoveFromPoint3DToPoint2D)
		{
			Point3D point3D(3, 100, 15);
			Point2D point2D(11, 2);
			Assassin assassin("Assassin", point3D);
			double arrayCoordinatesPoint2D[3];
			arrayCoordinatesPoint2D[0] = point2D.getX();
			arrayCoordinatesPoint2D[1] = point2D.getY();
			arrayCoordinatesPoint2D[2] = point2D.getZ();

			assassin.moveTo(point2D);

			double arrayAssassinCoordinatesPoint2D[3];
			arrayAssassinCoordinatesPoint2D[0] = assassin.getLocation()->getX();
			arrayAssassinCoordinatesPoint2D[1] = assassin.getLocation()->getY();
			arrayAssassinCoordinatesPoint2D[2] = assassin.getLocation()->getZ();

			int countFaults = 0;
			for (int i = 0; i < 3; i++)
			{
				if (arrayCoordinatesPoint2D[i] != arrayAssassinCoordinatesPoint2D[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
		}

		TEST_METHOD(TestIfChampionCanMoveFromPoint2DToPoint3D)
		{
			Point3D point3D(3, 100, 15);
			Point2D point2D(11, 2);
			Assassin assassin("Assassin", point2D);

			double arrayCoordinatesPoint3D[3];
			arrayCoordinatesPoint3D[0] = point3D.getX();
			arrayCoordinatesPoint3D[1] = point3D.getY();
			arrayCoordinatesPoint3D[2] = point3D.getZ();

			assassin.moveTo(point3D);

			double arrayAssassinCoordinatesPoint3D[3];
			arrayAssassinCoordinatesPoint3D[0] = assassin.getLocation()->getX();
			arrayAssassinCoordinatesPoint3D[1] = assassin.getLocation()->getY();
			arrayAssassinCoordinatesPoint3D[2] = assassin.getLocation()->getZ();

			int countFaults = 0;
			for (int i = 0; i < 3; i++)
			{
				if (arrayCoordinatesPoint3D[i] != arrayAssassinCoordinatesPoint3D[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
		}

		TEST_METHOD(TestIfChampionCanMoveFromItsPointToOtherChampionPoint)
		{
			Point3D point3D(3, 100, 15);
			Point2D point2D(11, 2);
			Assassin assassin("Assassin", point2D);
			Wizard wizard("Wizard", point3D);

			double arrayWizardCoordinates[3];
			arrayWizardCoordinates[0] = wizard.getLocation()->getX();
			arrayWizardCoordinates[1] = wizard.getLocation()->getY();
			arrayWizardCoordinates[2] = wizard.getLocation()->getZ();

			assassin.moveTo(wizard);

			double arrayAssassinCoordinatesAfterMovingToWizard[3];
			arrayAssassinCoordinatesAfterMovingToWizard[0] = assassin.getLocation()->getX();
			arrayAssassinCoordinatesAfterMovingToWizard[1] = assassin.getLocation()->getY();
			arrayAssassinCoordinatesAfterMovingToWizard[2] = assassin.getLocation()->getZ();

			int countFaults = 0;
			for (int i = 0; i < 3; i++)
			{
				if (arrayAssassinCoordinatesAfterMovingToWizard[i] != arrayWizardCoordinates[i])
				{
					countFaults++;
				}
			}

			Assert::AreEqual(0, countFaults);
		}

		//Test method getDistanceTo from class Champions
		TEST_METHOD(TestIfChampionDistanceFromItsPoint2DToOtherChampionPoint2DIsValid)
		{
			Point2D first(3, 100);
			Point2D second(11, 2);
			double distanceBetweenPoints2D = first.getDistanceTo(second);

			Assassin assassin("Assassin", second);
			Wizard wizard("Wizard", first);
			double distanceBetweenAssassinAndWizard = assassin.getDistanceTo(wizard);

			Assert::AreEqual(distanceBetweenPoints2D, distanceBetweenAssassinAndWizard);
		}

		TEST_METHOD(TestIfChampionDistanceFromItsPoint3DToOtherChampionPoint2DIsValid)
		{
			Point2D point2D(3, 100);
			Point3D point3D(11, 2, 500);
			double distanceBetweenPoints = point2D.getDistanceTo(point3D);

			Assassin assassin("Assassin", point2D);
			Wizard wizard("Wizard", point3D);
			double distanceBetweenWizardAndAssassin = wizard.getDistanceTo(assassin);

			Assert::AreEqual(distanceBetweenPoints, distanceBetweenWizardAndAssassin);
		}

		//Test method getDistanceTo2D from class Champions
		TEST_METHOD(TestIfChampionDistanceFromItsPoint3DToOtherChampionPoint3DInDimension2DIsValid)
		{
			Point2D firstPoint2D(1, -1);
			Point2D secondPoint2D(3, 3);

			double distanceBetweenPoints2D = firstPoint2D.getDistanceTo(secondPoint2D);

			Point3D firstPoint3D(1, -1, 9);
			Point3D secondPoint3D(3, 3, 10);

			Assassin assassin("Assassin", secondPoint3D);
			Wizard wizard("Wizard", firstPoint3D);

			double distanceInDimension2DBetweenAssassinAndWizard = assassin.getDistanceTo2D(wizard);

			Assert::AreEqual(distanceBetweenPoints2D, distanceInDimension2DBetweenAssassinAndWizard);
		}

		//Test method takeWeapon from class Champions
		TEST_METHOD(TestIfChampionWithNoLocationCanTakeWeapon)
		{
			Healer healer;
			Sword sword;
			healer.takeWeapon(sword);
			Assert::AreEqual(true, healer.hasWeapon());
		}

		TEST_METHOD(TestIfTakenWeaponFromChampionWithNoLocationIsCorrectOne)
		{
			Healer healer;
			Sword sword;
			healer.takeWeapon(sword);
			std::string swordName = sword.getName();
			std::string nameOfTakenWeapon = healer.getWeapon()->getName();
			Assert::AreEqual(swordName, nameOfTakenWeapon);
		}

		TEST_METHOD(TestIfChampionWithLocationCanTakeWeapon)
		{
			Point2D point2D(5, -90);
			Healer healer("Fred", point2D);
			Sword sword;
			healer.takeWeapon(sword);
			Assert::AreEqual(true, healer.hasWeapon());
		}

		TEST_METHOD(TestIfTakenWeaponFromChampionWithLocationIsCorrectOne)
		{
			Point2D point2D(5, -90);
			Healer healer("Fred", point2D);
			Sword sword;
			healer.takeWeapon(sword);
			std::string swordName = sword.getName();
			std::string nameOfTakenWeapon = healer.getWeapon()->getName();
			Assert::AreEqual(swordName, nameOfTakenWeapon);
		}

		//Test method throwWeapon from class Champions
		TEST_METHOD(TestIfChampionWithNoLocationCanThrowWeapon)
		{
			Human human;
			Sword sword;
			human.takeWeapon(sword);
			human.throwWeapon();
			Assert::AreEqual(false, human.hasWeapon());
		}

		TEST_METHOD(TestIfChampionWithLocationCanThrowWeapon)
		{
			Point2D point2D(5, -90);
			Human human("Fred", point2D);
			Sword sword;
			human.takeWeapon(sword);
			human.throwWeapon();
			Assert::AreEqual(false, human.hasWeapon());
		}

		//Test giving weapon from one champion to other champion (class Champions)
		TEST_METHOD(TestIfHumanWithWeaponCanGiveWeaponToAssassinAndHumanIsWithoutWeapon)
		{
			Human human;
			Assassin assassin;
			Sword sword;
			human.takeWeapon(sword);
			bool hasHumanWeaponAfterTaking = human.hasWeapon();
			human.giveWeaponTo(assassin);
			bool hasHumanWeaponAfterGiving = human.hasWeapon();

			bool didHumanGaveTheWeapon = false;

			if (hasHumanWeaponAfterTaking != hasHumanWeaponAfterGiving)
			{
				didHumanGaveTheWeapon = true;
			}

			Assert::AreEqual(true, didHumanGaveTheWeapon);
		}

		TEST_METHOD(TestIfHumanWithWeaponCanGiveWeaponToAssassinAndTheWeaponIsTakenFromAssassin)
		{
			Human human;
			Assassin assassin;
			bool hasAssassinWeaponWhenBorn = assassin.hasWeapon();
			Sword sword;
			human.takeWeapon(sword);
			human.giveWeaponTo(assassin);
			bool hasAssassinWeaponNow = assassin.hasWeapon();

			bool didAssassinGetTheWeapon = false;

			if (hasAssassinWeaponWhenBorn != hasAssassinWeaponNow)
			{
				didAssassinGetTheWeapon = true;
			}

			Assert::AreEqual(true, didAssassinGetTheWeapon);
		}

		TEST_METHOD(TestIfGivenWeaponFromHumanToAssassinIsCorrect)
		{
			Human human;
			Assassin assassin;
			Sword sword;
			human.takeWeapon(sword);
			std::string humanWeaponName = human.getWeapon()->getName();
			human.giveWeaponTo(assassin);
			std::string assassinWeaponName = assassin.getWeapon()->getName();

			Assert::AreEqual(0, humanWeaponName.compare(assassinWeaponName));
		}

		//Test method attack from class Champions
		TEST_METHOD(TestIfChampionWithoutLocationCanNotAttackOtherChampionWithoutLocation)
		{
			Human human;
			Assassin assassin;
			int assassinHealthAfterBorn = assassin.getHealth();

			human.attack(assassin);

			int assassinHealthAfterAttack = assassin.getHealth();

			bool isAssassinAttacked = false;
			if (assassinHealthAfterBorn != assassinHealthAfterAttack)
			{
				isAssassinAttacked = true;
			}

			Assert::AreEqual(false, isAssassinAttacked);
		}

		TEST_METHOD(TestIfChampionWithoutLocationCanNotAttackOtherChampionWithLocation)
		{
			Point3D point3D(0, 0, 0);
			Human human;
			Assassin assassin("Fred", point3D);
			int assassinHealthAfterBorn = assassin.getHealth();

			human.attack(assassin);

			int assassinHealthAfterAttack = assassin.getHealth();

			bool isAssassinAttacked = false;
			if (assassinHealthAfterBorn != assassinHealthAfterAttack)
			{
				isAssassinAttacked = true;
			}

			Assert::AreEqual(false, isAssassinAttacked);
		}

		TEST_METHOD(TestIfChampionWithLocationCanNotAttackOtherChampionWithoutLocation)
		{
			Point3D point3D(0, 0, 0);
			Human human;
			Assassin assassin("Fred", point3D);
			int humanHealthAfterBorn = human.getHealth();

			assassin.attack(human);

			int humanHealthAfterAttack = human.getHealth();

			bool isHumanAttacked = false;
			if (humanHealthAfterBorn != humanHealthAfterAttack)
			{
				isHumanAttacked = true;
			}

			Assert::AreEqual(false, isHumanAttacked);
		}

		TEST_METHOD(TestIfChampionWithLocationAndWithoutWeaponCanAttackOtherChampionWithLocationInRange)
		{
			Point3D point3D(-1, 2, 1);
			Point2D point2D(0, 2);
			Human human("Ben", point2D);
			Assassin assassin("Fred", point3D);
			int humanHealthAfterBorn = human.getHealth();

			assassin.attack(human);

			int humanHealthAfterAttack = human.getHealth();

			bool isHumanAttacked = false;
			if (humanHealthAfterBorn != humanHealthAfterAttack)
			{
				isHumanAttacked = true;
			}

			Assert::AreEqual(true, isHumanAttacked);
		}

		TEST_METHOD(TestIfChampionWithLocationAndWithoutWeaponCanNotAttackOtherChampionWithLocationOutOfRange)
		{
			Point3D point3D(100, 2, 1);
			Point2D point2D(0, 2);
			Human human("Ben", point2D);
			Assassin assassin("Fred", point3D);
			int humanHealthAfterBorn = human.getHealth();

			assassin.attack(human);

			int humanHealthAfterAttack = human.getHealth();

			bool isHumanAttacked = false;
			if (humanHealthAfterBorn != humanHealthAfterAttack)
			{
				isHumanAttacked = true;
			}

			Assert::AreEqual(false, isHumanAttacked);
		}

		TEST_METHOD(TestIfChampionWithLocationAndWithoutWeaponCanAttackOtherChampionWithLocationInRangeAndDamageIs15)
		{
			Point3D point3D(-1, 2, 1);
			Point2D point2D(0, 2);
			Human human("Ben", point2D);
			Assassin assassin("Fred", point3D);
			int humanHealthAfterBorn = human.getHealth();

			assassin.attack(human);

			int humanHealthAfterAttack = human.getHealth();

			int damage = humanHealthAfterBorn - humanHealthAfterAttack;

			Assert::AreEqual(15, damage);
		}

		TEST_METHOD(TestIfChampionWithLocationAndWeaponCanBeInRangeWithOtherChampionWithLocationAndWithoutWeapon)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Assassin assassin("Fred", point3D);

			double healerWeaponRange = healer.getWeapon()->getRange();
			double distanceBetweenHealerAndAssassin = healer.getDistanceTo(assassin);

			bool isAssassinInRangeWithHealer = false;

			if (distanceBetweenHealerAndAssassin <= healerWeaponRange)
			{
				isAssassinInRangeWithHealer = true;
			}

			Assert::AreEqual(true, isAssassinInRangeWithHealer);
		}

		TEST_METHOD(TestIfChampionWithLocationAndWeaponCanAttackOtherInRangeChampionWithLocationAndWithoutWeapon)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Assassin assassin("Fred", point3D);

			int assassinHealthAfterBorn = assassin.getHealth();
			
			healer.attack(assassin);

			int assassinHealthAfterAttack = assassin.getHealth();

			bool isAssassinAttacked = false;

			if (assassinHealthAfterBorn != assassinHealthAfterAttack)
			{
				isAssassinAttacked = true;
			}

			Assert::AreEqual(true, isAssassinAttacked);
		}

		TEST_METHOD(TestIfWeaponDamageIsTheRealDamageAfterAttackingChampionWithoutWeapon)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Assassin assassin("Fred", point3D);
			int assassinHealthAfterBorn = assassin.getHealth();

			healer.attack(assassin);

			int assassinHealthAfterAttack = assassin.getHealth();

			int damageFromHealerWeapon = healer.getWeapon()->getDamage();
			int realDamage = assassinHealthAfterBorn - assassinHealthAfterAttack;

			Assert::AreEqual(damageFromHealerWeapon, realDamage);
		}

		TEST_METHOD(TestIfSniperDamageAfter9ShotsIs900)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Human human("Fred", point3D);

			int healerSniperDamage = 0;

			for (int i = 0; i < 9; i++)
			{
				healerSniperDamage += healer.getWeapon()->getDamage();
				healer.attack(human);
			}

			Assert::AreEqual(900, healerSniperDamage);
		}

		TEST_METHOD(TestIfHumanIsNotAliveAfter9ShotsFromSniperWithDamage100)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Human human("Fred", point3D);

			for (int i = 0; i < 9; i++)
			{
				healer.attack(human);
			}

			bool isHumanAlive = human.isAlive();

			Assert::AreEqual(false, isHumanAlive);
		}

		TEST_METHOD(TestIfHealthOfHumanAfter9ShotsFromSniperWithDamage100Is0)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Human human("Fred", point3D);

			for (int i = 0; i < 9; i++)
			{
				healer.attack(human);
			}

			int humanHealthAfterAttack = human.getHealth();

			Assert::AreEqual(0, humanHealthAfterAttack);
		}

		TEST_METHOD(TestIfSniperIsNotShootingAfterKillingEnemy)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Human human("Fred", point3D);

			int countNumberOfBulletsBeforeKillingHuman = 0;

			for (int i = 0; i < 9; i++)
			{
				if (human.isAlive())
				{
					countNumberOfBulletsBeforeKillingHuman++;
				}
				healer.attack(human);
			}

			int currentNumberOfBulletsInWeapon = healer.getWeapon()->getNumberCurrentBulletsInRefill();
			int firedBullets = healer.getWeapon()->getNumberStartBulletsInRefill() - countNumberOfBulletsBeforeKillingHuman;

			Assert::AreEqual(currentNumberOfBulletsInWeapon, firedBullets);
		}

		TEST_METHOD(TestIfChampionWithLocationAndWeaponCanAttackOtherInRangeChampionWithLocationAndWithWeapon)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Assassin assassin("Fred", point3D);
			assassin.takeWeapon(stick);

			int assassinHealthAfterBorn = assassin.getHealth();

			healer.attack(assassin);

			int assassinHealthAfterAttack = assassin.getHealth();

			bool isAssassinAttacked = false;

			if (assassinHealthAfterBorn != assassinHealthAfterAttack)
			{
				isAssassinAttacked = true;
			}

			Assert::AreEqual(true, isAssassinAttacked);
		}

		TEST_METHOD(TestIfWeaponDefenseAfterOneAttackIsWithOneLesser)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Assassin assassin("Fred", point3D);
			assassin.takeWeapon(stick);

			int assassinWeaponDefenseBeforeAttack = assassin.getWeapon()->getDefense();

			healer.attack(assassin);

			int assassinWeaponDefenseAfterAttack = assassin.getWeapon()->getDefense();

			int difference = assassinWeaponDefenseBeforeAttack - assassinWeaponDefenseAfterAttack;

			Assert::AreEqual(1, difference);
		}

		TEST_METHOD(TestIfWeaponAfterAttackIsDamaged)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Sniper sniper;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(sniper);
			Assassin assassin("Fred", point3D);
			assassin.takeWeapon(stick);

			healer.attack(assassin);

			WeaponStatus assassinWeaponStatus = assassin.getWeapon()->getStatus();

			Assert::AreEqual(static_cast<int>(WeaponStatus::Damaged), static_cast<int>(assassinWeaponStatus));
		}

		TEST_METHOD(TestIfStickAfter20TimesAttackIs0)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Gun gun;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(gun);
			Wizard wizard("Fred", point3D);
			wizard.takeWeapon(stick);

			for (int i = 0; i < 20; i++)
			{
				healer.attack(wizard);
			}

			int wizardWeaponDefense = wizard.getWeapon()->getDefense();

			Assert::AreEqual(0, wizardWeaponDefense);
		}

		TEST_METHOD(TestIfStickWithDefense0IsBroken)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Gun gun;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(gun);
			Wizard wizard("Fred", point3D);
			wizard.takeWeapon(stick);

			for (int i = 0; i < 20; i++)
			{
				healer.attack(wizard);
			}

			WeaponStatus wizardWeaponStatus = wizard.getWeapon()->getStatus();

			Assert::AreEqual(static_cast<int>(WeaponStatus::Broken), static_cast<int>(wizardWeaponStatus));
		}

		TEST_METHOD(TestIfEnemyCanBeAttackedIfBulletsInAttackingWeaponAre0)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Gun gun;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(gun);
			Wizard wizard("Fred", point3D);
			wizard.takeWeapon(stick);

			for (int i = 0; i < 20; i++)
			{
				healer.attack(wizard);
			}

			int wizardHealthAfterAttackWithNonZeroBullets = wizard.getHealth();

			for (int i = 0; i < 5; i++)
			{
				healer.attack(wizard);
			}

			int wizardHealthAfterAttackWithZeroBullets = wizard.getHealth();

			bool isWizardAttackedWithZeroBullets = false;

			if (wizardHealthAfterAttackWithNonZeroBullets != wizardHealthAfterAttackWithZeroBullets)
			{
				isWizardAttackedWithZeroBullets = true;
			}

			Assert::AreEqual(false, isWizardAttackedWithZeroBullets);
		}

		TEST_METHOD(TestIfBulletsInEmptyWeaponAreAlways0AfterShootings)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Gun gun;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(gun);
			Wizard wizard("Fred", point3D);
			wizard.takeWeapon(stick);

			//make gun empty
			for (int i = 0; i < 20; i++)
			{
				healer.attack(wizard);
			}

			for (int i = 0; i < 5; i++)
			{
				healer.attack(wizard);
			}

			int numberGunCurrentBullets = healer.getWeapon()->getNumberCurrentBulletsInRefill();

			Assert::AreEqual(0, numberGunCurrentBullets);
		}

		//Test method repairWeapon from class Champions
		TEST_METHOD(TestIfBrokenWeaponCanBeRepaired)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Gun gun;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(gun);
			Wizard wizard("Fred", point3D);
			wizard.takeWeapon(stick);

			for (int i = 0; i < 20; i++)
			{
				healer.attack(wizard);
			}

			wizard.repairWeapon();
			WeaponStatus wizardWeaponStatus = wizard.getWeapon()->getStatus();

			Assert::AreEqual(static_cast<int>(WeaponStatus::Strong), static_cast<int>(wizardWeaponStatus));
		}

		TEST_METHOD(TestIfWeaponDefenseIsStartWeaponDefenseAfterRepairing)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Gun gun;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(gun);
			Wizard wizard("Fred", point3D);
			wizard.takeWeapon(stick);

			int wizardStartWeaponDefense = wizard.getWeapon()->getStartDefense();

			for (int i = 0; i < 20; i++)
			{
				healer.attack(wizard);
			}

			wizard.repairWeapon();
			int wizardNewWeaponDefense = wizard.getWeapon()->getDefense();

			Assert::AreEqual(wizardStartWeaponDefense, wizardNewWeaponDefense);
		}

		//Test method rechargeWeapon from class Champions (valid if weapon's type is Shooter)
		TEST_METHOD(TestIfChampionCanRechargeItsWeapon)
		{
			Point3D point3D(10, 5, 1);
			Point2D point2D(5, 2);
			Gun gun;
			Stick stick;
			Healer healer("Ben", point2D);
			healer.takeWeapon(gun);
			Wizard wizard("Fred", point3D);
			wizard.takeWeapon(stick);

			int numberGunStartBullets = healer.getWeapon()->getNumberStartBulletsInRefill();

			//make gun empty
			for (int i = 0; i < 25; i++)
			{
				healer.attack(wizard);
			}

			healer.rechargeWeapon();

			int numberGunCurrentBullets = healer.getWeapon()->getNumberCurrentBulletsInRefill();

			Assert::AreEqual(numberGunStartBullets, numberGunCurrentBullets);
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

		//Test method heal from class Healer
		TEST_METHOD(TestIfHealerCanIncreseChampionHealthAfterAttack)
		{
			Point3D firstPoint3D(1, 1, 3);
			Point3D secondPoint3D(5, 3, 1);
			Point2D point2D(2, 1);
			Human human("H", point2D);
			Assassin assassin("A", firstPoint3D);
			Healer healer("FirstHealer", secondPoint3D);
			Sniper sniper;
			assassin.takeWeapon(sniper);

			for (int i = 0; i < 3; i++)
			{
				assassin.attack(human);
			}

			int humanHealthBeforeHeal = human.getHealth();

			healer.heal(human);

			int humanHealthAfterHeal = human.getHealth();

			bool isHumanHealed = false;
			if (humanHealthAfterHeal > humanHealthBeforeHeal)
			{
				isHumanHealed = true;
			}

			Assert::AreEqual(true, isHumanHealed);
		}

		TEST_METHOD(TestIfChampionHealthAfter100TimesOfHealingCanBeMaximumStartHealth)
		{
			Point3D firstPoint3D(1, 1, 3);
			Point3D secondPoint3D(5, 3, 1);
			Point2D point2D(2, 1);
			Human human("H", point2D);
			Assassin assassin("A", firstPoint3D);
			Healer healer("FirstHealer", secondPoint3D);
			Sniper sniper;
			assassin.takeWeapon(sniper);

			int humanStartHealth = human.getStartHealth();

			for (int i = 0; i < 3; i++)
			{
				assassin.attack(human);
			}

			for (int i = 0; i < 100; i++)
			{
				healer.heal(human);
			}

			int humanHealthAfterHeal = human.getHealth();

			bool isAgainStartHealth = false;
			if (humanHealthAfterHeal == humanStartHealth)
			{
				isAgainStartHealth = true;
			}

			Assert::AreEqual(true, isAgainStartHealth);
		}

		TEST_METHOD(TestIfHumanIsKilledAfter8ShotsFromSniper)
		{
			Point3D point3D(1, 1, 3);
			Point2D point2D(2, 1);
			Human human("H", point2D);
			Assassin assassin("A", point3D);
			Sniper sniper;
			assassin.takeWeapon(sniper);

			for (int i = 0; i < 8; i++)
			{
				assassin.attack(human);
			}

			Assert::AreEqual(false, human.isAlive());
		}

		TEST_METHOD(TestIfHealerCanNotHealKilledChampion)
		{
			Point3D firstPoint3D(1, 1, 3);
			Point3D secondPoint3D(5, 3, 1);
			Point2D point2D(2, 1);
			Human human("H", point2D);
			Assassin assassin("A", firstPoint3D);
			Healer healer("FirstHealer", secondPoint3D);
			Sniper sniper;
			assassin.takeWeapon(sniper);

			for (int i = 0; i < 8; i++)
			{
				assassin.attack(human);
			}

			bool isHumanAliveBeforeHeal = human.isAlive();

			healer.heal(human);

			bool isHumanLiveAgain = human.isAlive();

			bool canNotHealerIncreseHealthOfKilledChampion = true;
			if (isHumanAliveBeforeHeal && isHumanLiveAgain)
			{
				canNotHealerIncreseHealthOfKilledChampion = false;
			}

			Assert::AreEqual(true, canNotHealerIncreseHealthOfKilledChampion);
		}

		TEST_METHOD(TestIfHealerCanNotHealOtherHealer)
		{
			Point3D firstPoint3D(1, 1, 3);
			Point3D secondPoint3D(5, 3, 1);
			Point2D point2D(2, 1);
			Healer healerForAttack("H", point2D);
			Assassin assassin("A", firstPoint3D);
			Healer healerForHelpOthers("FirstHealer", secondPoint3D);
			Sniper sniper;
			assassin.takeWeapon(sniper);

			for (int i = 0; i < 3; i++)
			{
				assassin.attack(healerForAttack);
			}

			int healerForAttackHealthBeforeHeal = healerForAttack.getHealth();

			healerForHelpOthers.heal(healerForAttack);

			int healerForAttackHealthAfterHeal = healerForAttack.getHealth();

			bool isHealerForAttackNotHealed = true;
			if (healerForAttackHealthBeforeHeal < healerForAttackHealthAfterHeal)
			{
				isHealerForAttackNotHealed = false;
			}

			Assert::AreEqual(true, isHealerForAttackNotHealed);
		}

		TEST_METHOD(TestIfHealerCanHealItself)
		{
			Point3D point3D(1, 1, 3);
			Point2D point2D(2, 1);
			Assassin assassin("A", point3D);
			Healer healer("FirstHealer", point2D);
			Sniper sniper;
			assassin.takeWeapon(sniper);

			for (int i = 0; i < 3; i++)
			{
				assassin.attack(healer);
			}

			int healerHealthBeforeHeal = healer.getHealth();

			healer.heal(healer);

			int healerHealthAfterHeal = healer.getHealth();

			bool isHealed = false;
			if (healerHealthBeforeHeal < healerHealthAfterHeal)
			{
				isHealed = true;
			}

			Assert::AreEqual(true, isHealed);
		}

		//Test method breakWeaponTo from class Wizard
		TEST_METHOD(TestIfWizardCanBreakOtherChampionWeapon)
		{
			Point3D point3D(1, 1, 3);
			Point2D point2D(2, 1);
			Assassin assassin("A", point3D);
			Wizard wizard("Wizard", point2D);
			Sniper sniper;
			assassin.takeWeapon(sniper);

			WeaponStatus assassinWeaponStatusBeforeWizardBreaking = assassin.getWeapon()->getStatus();

			wizard.breakWeaponTo(assassin);

			WeaponStatus assassinWeaponStatusAfterWizardBreaking = assassin.getWeapon()->getStatus();

			bool didWizardBrokeOtherChampionWeapon = false;

			if (assassinWeaponStatusBeforeWizardBreaking == Strong && assassinWeaponStatusAfterWizardBreaking == Broken)
			{
				didWizardBrokeOtherChampionWeapon = true;
			}

			Assert::AreEqual(true, didWizardBrokeOtherChampionWeapon);
		}

		TEST_METHOD(TestIfWizardCanBreakItsWeapon)
		{
			Point3D point3D(1, 1, 3);
			Wizard wizard("Wizard", point3D);
			Sniper sniper;
			wizard.takeWeapon(sniper);

			WeaponStatus wizardWeaponStatusBeforeBreaking = wizard.getWeapon()->getStatus();

			wizard.breakWeaponTo(wizard);

			WeaponStatus wizardWeaponStatusAfterBreaking = wizard.getWeapon()->getStatus();

			bool didWizardBrokeItsWeapon = false;

			if (wizardWeaponStatusBeforeBreaking == Strong && wizardWeaponStatusAfterBreaking == Broken)
			{
				didWizardBrokeItsWeapon = true;
			}

			Assert::AreEqual(false, didWizardBrokeItsWeapon);
		}
	};
}
