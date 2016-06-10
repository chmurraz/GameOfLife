#pragma once

#include "Point2D.h"

class Cell
{
private:
	Point2D point;		//	Template the Point class to use ints (as opposed to floats, or whatever)
	int neighborCount;
	bool alive;

public:
	Cell(Point2D pointval);
	~Cell();
	Point2D getPoint();
	void setCoord(Point2D pval);
	int getNeighborCount();
	void setNeighborCount(int nval);
	bool getAlive();
	void setAlive(bool val);
};

