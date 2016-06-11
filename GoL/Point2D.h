#pragma once

#include <cmath>			//	For std::abs
#include <algorithm>		//	For std::max
class Point2D
{
private:
	int x;
	int y;
public:
	Point2D();
	Point2D(int xval, int yval);
	int getx();
	int gety();
	void setxy(int xval, int yval);

	bool Equal(Point2D other);
	int NeighborDistance(Point2D other);

	//	Operator overload of "<" to compare points
	bool operator<(const Point2D& other);
	bool operator>(const Point2D& other);
	bool operator<=(const Point2D& other);
	bool operator>=(const Point2D& other);
};

