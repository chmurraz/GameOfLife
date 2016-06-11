#include "Cell.h"



Cell::Cell(Point2D pointval)
{
	point = pointval;
	neighborCount = 0;
	alive = true;
}

Cell::~Cell()
{
}

Point2D Cell::getPoint()
{
	return point;
}

void Cell::setCoord(Point2D inputPoint)
{
	point = inputPoint;
}

int Cell::getNeighborCount()
{
	return neighborCount;
}

void Cell::setNeighborCount(int nval)
{
	neighborCount = nval;
}

bool Cell::getAlive()
{
	return alive;
}

void Cell::setAlive(bool val)
{
	alive = val;
}

bool Cell::operator<(const Cell & other)
{
	return point < other.point;
}
