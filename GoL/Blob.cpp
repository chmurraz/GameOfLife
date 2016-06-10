#include "Blob.h"

void Blob::updateBoundaries(std::vector<Cell>::iterator it)
{
	//	Update the borders of the blob.  Always keep the border size "one" larger than the actual live cells.
	//	Hence the + 1 and -1 values at the end.  This is to account for new cells popping into life on the "edge"
	//	of the blob

	if (it->getCoord().getx() <= leftEdge)
		leftEdge = it->getCoord().getx() - 1;
	if (it->getCoord().getx() >= rightEdge)
		leftEdge = it->getCoord().getx() + 1;
	if (it->getCoord().gety() <= bottomEdge)
		leftEdge = it->getCoord().gety() - 1;
	if (it->getCoord().getx() >= rightEdge + 1)
		leftEdge = it->getCoord().getx() + 1;
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
	return 0;
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
	for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
	{
		cellCount++;
		updateBoundaries(it);
	}
}
