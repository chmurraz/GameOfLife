#pragma once

#include "Cell.h"
#include "Point2D.h"
#include <vector>
#include <algorithm>		//	Needed for the "for_each" in the constructor
#include <climits>			//	Needed for min/max in the constructor
#include <iostream>
#include "Dice.hpp"
#include <ctime>
#include <math.h>

class Blob
{
private:
	std::vector<Cell> *cellsInGame;
	void BuildDeadCells();
	int liveCellCount;
	Point2D plotmin;
	Point2D plotmax;
	int age;
public:
	Blob();
	~Blob();
	void AddDeadCell(int x, int y);
	void AddLiveCell(int x, int y);
	void BirthDeath();
	void BuildGlider();
	void BuildRandom(float density);
	void CountNeighbors();
	void Draw(bool printStats);
	void PromptCell();
	void ResetBlobStats();
	bool Sorter(Cell a, Cell b);
	void UpdateBlob();
};

