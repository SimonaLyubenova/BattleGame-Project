#pragma once
#include <iostream>

class Point2D
{
private:
	double x;
	double y;

	void setX(const double newX)
	{
		this->x = newX;
	}

	void setY(const double newY)
	{
		this->y = newY;
	}

public:
	Point2D()
	{
		setX(0.0);
		setY(0.0);
	}

	Point2D(const double newX, const double newY)
	{
		setX(newX);
		setY(newY);
	}

	Point2D(const Point2D& newPoint2D)
	{
		setX(newPoint2D.getX());
		setY(newPoint2D.getY());
	}

	Point2D& operator=(const Point2D& newPoint2D)
	{
		if (this != &newPoint2D)
		{
			setX(newPoint2D.getX());
			setY(newPoint2D.getY());
		}
		return *this;
	}

	double getX() const
	{
		return this->x;
	}

	double getY() const
	{
		return this->y;
	}

	virtual double getZ() const
	{
		return 0.0;
	}

	virtual Point2D* clone() const
	{
		return new Point2D(*this);
	}

	virtual double getDistanceTo(const Point2D& otherPoint) const
	{
		double differenceX = getX() - otherPoint.getX();
		double differenceY = getY() - otherPoint.getY();
		double distance = sqrt(differenceX * differenceX + differenceY * differenceY);

		return distance;
	}

	virtual void print() const
	{
		std::cout << "x: " << getX() << std::endl;
		std::cout << "y: " << getY() << std::endl;
	}
};
