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

void Point2D::setxy(int xval, int yval)
{
	x = xval;
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

int Point2D::NeighborDistance(Point2D other)
{
	int x = std::abs(this->getx() - other.getx());
	int y = std::abs(this->gety() - other.gety());

	return std::max(x,y);
}

bool Point2D::operator<(const Point2D & other)
{
	if (y != other.y)
		return (y < other.y);
	else
		return (x > other.x);
}

bool Point2D::operator>(const Point2D & other)
{
	if (y != other.y)
		return (y > other.y);
	else
		return (x < other.x);
}

bool Point2D::operator<=(const Point2D & other)
{
	return ((y <= other.y) && (x <= other.x));
}

bool Point2D::operator>=(const Point2D & other)
{
	return ((y >= other.y) && (x >= other.x));
}
