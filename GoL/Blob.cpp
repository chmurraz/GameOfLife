#include "Blob.h"

void Blob::UpdateBoundaries()
{
	//	Update the borders of the blob.  Always keep the border size "one" larger than the actual live cells.
	//	Hence the + 1 and -1 values at the end.  This is to account for new cells popping into life on the "edge"
	//	of the blob

	for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
	{
		if (it->getPoint().getx() <= leftEdge)
			leftEdge = it->getPoint().getx() - 1;
		if (it->getPoint().getx() >= rightEdge)
			rightEdge = it->getPoint().getx() + 1;
		if (it->getPoint().gety() <= bottomEdge)
			bottomEdge = it->getPoint().gety() - 1;
		if (it->getPoint().gety() >= topEdge)
			topEdge = it->getPoint().gety() + 1;
	}
}

Blob::Blob()
{
	liveCellCount = 0;
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

void Blob::AddDeadCells()
{
	//	Don't add dead cells if there are no live cells.  Otherwise, there will be (INT_MAX - INT_MIN)^2 dead cells
	if (liveCellCount > 0)
	{
		for (int x = leftEdge; x <= rightEdge; x++)
		{
			for (int y = bottomEdge; y <= topEdge; y++)
			{
				//	Create a new point, called "loopPoint" based off of the (x,y) values in the for loops
				Point2D loopPoint(x, y);
				
				//	Check to see if this new point (loopPoint) matches any of the existing cells.  If yes, set bool to true
				bool liveCellHere = false;
				for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
				{
				
					if (it->getPoint().Equal(loopPoint))
					{
						liveCellHere = true;
					}
				}

				//	If the loopPoint doesn't match one of the liveCells, then create a new cell (and make sure it's dead)
				if (!liveCellHere)
				{
					AddLiveCell(x, y);
					cellsInGame->end()->setAlive(false);		// ->end() is a pointer to the end of the vector, needs to be dereferenced
					
				}
			}
		}
	}
}

void Blob::AddLiveCell(int x, int y)
{
	Point2D point(x,y);
	Cell cell(point);
	cellsInGame->push_back(cell);
	liveCellCount++;
	UpdateBoundaries();
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

	AddLiveCell(x, y);
}

void Blob::ResetBlobStats()
{	
	//	Make sure to reset all vital statistics for each cell and the blob as a whole here...
	//	Such as cellCount, neighborCount, etc.

	liveCellCount = 0;
	for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
	{
		liveCellCount++;
		it->setNeighborCount(0);
	}
}

void Blob::UpdateBlob()
{
	//	Reset vital stats
	ResetBlobStats();

	//	Add any newly spawned cells to the blob

	//	Remove any newly dying cells from the blob

	//	Update the boundaries
	UpdateBoundaries();

	//	Fill the boundaries of the blob with dead cells (making sure to avoid the live cells)
	AddDeadCells();

	//	Draw the blob

	//	Calculate neighbors

	//	Set cells for execution

	//	Set cells for birth
}
