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
	int liveCellCount;
	void UpdateBoundaries();

	std::vector<Cell> *cellsInGame;
public:
	Blob();
	~Blob();
	void AddLiveCell(int x, int y);
	void AddDeadCells();
	int CountNeighbors(Cell *inputCell);
	void PromptCell();
	void ResetBlobStats();
	void UpdateBlob();
};

