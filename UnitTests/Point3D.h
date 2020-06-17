#pragma once
#include "Point2D.h"

class Point3D :public Point2D
{
private:
	double z;

	void setZ(const double newZ)
	{
		this->z = newZ;
	}

public:
	Point3D() :Point2D()
	{
		setZ(0.0);
	}

	Point3D(const double newX, const double newY, const double newZ) :Point2D(newX, newY)
	{
		setZ(newZ);
	}

	Point3D(const Point3D& newPoint3D) :Point2D(newPoint3D)
	{
		setZ(newPoint3D.getZ());
	}	

	Point3D& operator=(const Point3D& newPoint3D)
	{
		if (this != &newPoint3D)
		{
			Point2D::operator=(newPoint3D);
			setZ(newPoint3D.getZ());
		}
		return *this;
	}

	virtual double getZ() const
	{
		return this->z;
	}

	virtual Point3D* clone() const
	{
		return new Point3D(*this);
	}
	
	virtual double getDistanceTo(const Point2D& otherPoint) const
	{
		//check if otherPoint is Point2D or Point3D
		try
		{
			auto castedPoint3D = dynamic_cast<const Point3D&>(otherPoint); //try to cast to Point3D
			double distanceIn2D = Point2D::getDistanceTo(otherPoint); //here are used only x and y coordinates
			double differenceZ = getZ() - castedPoint3D.getZ();

			double distance = sqrt(distanceIn2D * distanceIn2D + differenceZ * differenceZ);

			return distance;
		}
		catch (...)
		{
			return Point2D::getDistanceTo(otherPoint); //if argument is Point2D (if cast failed)
		}
	}
	virtual void print() const
	{
		Point2D::print();
		std::cout << "z: " << getZ() << std::endl;;
	}
};
