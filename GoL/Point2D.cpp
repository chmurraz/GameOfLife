#include "Point2D.h"


Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(int xval, int yval)
{
	x = xval;
	y = yval;
}

int Point2D::getx()
{
	return x;
}

int Point2D::gety()
{
	return y;
}

void Point2D::setx(int xval)
{
	x = xval;
}

void Point2D::sety(int yval)
{
	y = yval;
}

bool Point2D::Equal(Point2D other)
{
	if (this->getx() == other.getx() && this->gety() == other.gety())
	{
		return true;
	}
	return false;
}

int Point2D::TaxiDistance(Point2D other)
{
	return std::abs(this->getx() - other.getx()) + std::abs(this->gety() - other.gety());
}
