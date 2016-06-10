#pragma once

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
	void setx(int xval);
	void sety(int yval);
};

