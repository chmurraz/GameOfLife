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
#include <Windows.h>	//	For Sleep in Main and OutputDebugString in Blob
#include <string>

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
	void AddLiveCell(Point2D point);
	void BirthDeath();
	void BuildGlider();
	void BuildRandom(float density);
	void CountNeighbors();
	void Draw(bool printStats);
	bool IsCellHere(Point2D point);
	void ResetBlobStats();
	void UpdateBlob();
};

