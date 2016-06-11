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
	std::vector<Cell> *cellsInGame;
	void BuildDeadCells();
	int liveCellCount;
	Point2D plotmin;
	Point2D plotmax;
public:
	Blob();
	~Blob();
	void AddDeadCell(int x, int y);
	void AddLiveCell(int x, int y);
	void BirthDeath();
	void CountNeighbors();
	void Draw();
	void PromptCell();
	void ResetBlobStats();
	void UpdateBlob();
};

