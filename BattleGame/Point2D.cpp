#include <iostream>
#include <cmath>
#include "Point2D.h"

Point2D::Point2D()
{
	setX(0.0);
	setY(0.0);
}

Point2D::Point2D(const double newX, const double newY)
{
	setX(newX);
	setY(newY);
}

Point2D::Point2D(const Point2D& newPoint2D)
{
	setX(newPoint2D.getX());
	setY(newPoint2D.getY());
}

Point2D& Point2D::operator=(const Point2D& newPoint2D)
{
	if (this != &newPoint2D)
	{
		setX(newPoint2D.getX());
		setY(newPoint2D.getY());

		std::cout << "Operator= Base" << std::endl;
	}
	return *this;
}

Point2D* Point2D::clone() const
{
	return new Point2D(*this);
}

void Point2D::setX(const double newX)
{
	this->x = newX;
}

double Point2D::getX() const
{
	return this->x;
}

void Point2D::setY(const double newY)
{
	this->y = newY;
}

double Point2D::getY() const
{
	return this->y;
}

double Point2D::getZ() const
{
	return 0.0;
}

double Point2D::getDistanceTo(const Point2D& otherPoint) const
{
	double differenceX = getX() - otherPoint.getX();
	double differenceY = getY() - otherPoint.getY();
	double distance = sqrt(differenceX * differenceX + differenceY * differenceY);

	return distance;
}

void Point2D::print() const
{
	std::cout << "x: " << getX() << std::endl;
	std::cout << "y: " << getY() << std::endl;
}