#pragma once

class Point2D
{
private:
	double x;
	double y;

	void setX(const double);
	double getX() const;
	void setY(const double);
	double getY() const;

protected:
	virtual double getZ() const;

public:
	Point2D();
	Point2D(const double, const double);
	Point2D(const Point2D&);
	Point2D& operator=(const Point2D&);

	virtual Point2D* clone() const;

	virtual double getDistanceTo(const Point2D&) const;
	virtual void print() const;
};
