#include "Blob.h"

void Blob::updateBoundaries(std::vector<Cell>::iterator it)
{
	//	Update the borders of the blob.  Always keep the border size "one" larger than the actual live cells.
	//	Hence the + 1 and -1 values at the end.  This is to account for new cells popping into life on the "edge"
	//	of the blob

	if (it->getPoint().getx() <= leftEdge)
		leftEdge = it->getPoint().getx() - 1;
	if (it->getPoint().getx() >= rightEdge)
		leftEdge = it->getPoint().getx() + 1;
	if (it->getPoint().gety() <= bottomEdge)
		leftEdge = it->getPoint().gety() - 1;
	if (it->getPoint().getx() >= rightEdge + 1)
		leftEdge = it->getPoint().getx() + 1;
}

Blob::Blob()
{
	cellCount = 0;
	cellsInGame = new std::vector<Cell>;
	leftEdge = INT_MAX;
	rightEdge = INT_MIN;
	topEdge = INT_MIN;
	bottomEdge = INT_MAX;
}

Blob::~Blob()
{
	delete cellsInGame;
	cellsInGame = NULL;
}

void Blob::AddCell(int x, int y)
{
	Point2D point(x,y);
	Cell cell(point);
	cellsInGame->push_back(cell);
}

int Blob::CountNeighbors(Cell *inputCell)
{
	//	Loop through the vector containing the cellsInGame.  These are the "it" cells.  Compare them to the inputCell
	for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
	{
		//	Check two things at each loop...
		//
		//		1.	Is the distance exactly one between "it" and "inputCell"?  This is calculated by using "Taxi Distance" in the Point class
		//		2.	Is the "it" cell alive?  It does not matter if the inputCell is alive.  Only if "it" is alive.

		//	If both are true then "it" is a neighbor of "inputCell" (even if the "inputCell" itself is dead).
		//	Increment the counter for inputCell

		if (it->getPoint().TaxiDistance(inputCell->getPoint()) == 1 && it->getAlive())
		{
			inputCell->setNeighborCount(inputCell->getNeighborCount() + 1);
		}
	}

	return inputCell->getNeighborCount();
}

void Blob::PromptCell()
{
	int x, y;
	std::cout << "Enter the x-coordinate of the cell:\n";
	std::cin >> x;
	std::cout << "Enter the y-coordinate of the cell:\n";
	std::cin >> y;

	AddCell(x, y);
}

void Blob::UpdateBlob()
{
	//	Make sure to reset all vital statistics for each cell and the blob as a whole here...
	//	Such as cellCount, neighborCount, etc.

	cellCount = 0;
	for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
	{
		cellCount++;
		updateBoundaries(it);
		it->setNeighborCount(0);
	}

	//	Add any newly spawned cells to the blob

	//	Remove any newly dying cells from the blob

	//	Draw the blob

	//	Calculate neighbors

	//	Set cells for execution

	//	Set cells for birth
}
