#include "Cell.h"



Cell::Cell(Point2D pointval)
{
	point = pointval;
}

Cell::~Cell()
{
}

Point2D Cell::getCoord()
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
