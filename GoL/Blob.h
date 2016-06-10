#pragma once

#include "Cell.h"
#include "Point2D.h"
#include <vector>
#include <algorithm>		//	Needed for the "for_each" in the constructor
#include <climits>			//	Needed for min/max in the constructor
#include <iostream>

class Blob
{
private:
	int leftEdge;
	int rightEdge;
	int topEdge;
	int bottomEdge;
	int cellCount;
	void updateBlobBoundaries();
	void updateBlobCount();

	std::vector<Cell> *cellsInGame;
public:
	Blob();
	Blob(std::vector<Cell> *inputCells);
	~Blob();
	void AddCell(int x, int y);
	void PromptCell();
	void UpdateBlob();
};

