#pragma once
#include "Point2D.h"

class Point3D :public Point2D
{
private:
	double z;

	void setZ(const double);
	virtual double getZ() const;

public:
	Point3D();
	Point3D(const double, const double, const double);
	Point3D(const Point3D&);
	Point3D& operator=(const Point3D&);

	virtual Point3D* clone() const;
	
	virtual double getDistanceTo(const Point2D&) const;
	virtual void print() const;
};
