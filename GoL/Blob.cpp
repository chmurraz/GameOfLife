#include "Blob.h"

Blob::Blob()
{
	liveCellCount = 0;
	cellsInGame = new std::vector<Cell>;
	plotmin.setxy(0,0);
	plotmax.setxy(50,20);
}

Blob::~Blob()
{
	delete cellsInGame;
	cellsInGame = NULL;
}

void Blob::AddDeadCell(int x, int y)
{
}


void Blob::BuildDeadCells()
{
	//	Don't add dead cells if there are no live cells.
	if (liveCellCount > 0)
	{
		//	Create a new vector to add the deadCells to, then copy it over at the end.  This is to keep the iterators separate
		std::vector<Cell> *cellsInGameCopy = new std::vector<Cell>;
		for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
		{
			Point2D newPoint = it->getPoint();
			Cell newCell(newPoint);
			cellsInGameCopy->push_back(newCell);
		}

		//	At this point, cellsInGameCopy should have an identical set of cells (but not pointed to the same addresses)
		//	For each live cell in the cellsInGameCopy vector, search all adjacent points and (if no live cells are present at
		//	each point) create a dead one in the ORIGINAL cellsInGame vector.

		for (std::vector<Cell>::iterator it = cellsInGameCopy->begin(); it != cellsInGameCopy->end(); ++it)
		{
			Point2D centerPoint = it->getPoint();
			for (int x = centerPoint.getx() - 1; x <= centerPoint.getx() + 1; x++)
			{
				for (int y = centerPoint.gety() - 1; y <= centerPoint.gety() + 1; y++)
				{
					//	Search the list of cells.  Check for a matching (x,y) ... doesn't matter if it's alive or dead
					bool cellHere = false;
					Point2D checkMatchPoint(x, y);
					for (std::vector<Cell>::iterator it2 = cellsInGame->begin(); it2 != cellsInGame->end(); ++it2)
					{
						if (it2->getPoint().Equal(checkMatchPoint))
							cellHere = true;
					}
					if (!cellHere)
					{
						//	Create a new cell at this (x,y) location
						//	push_back onto the vector of cellsInGame
						//	make sure this cell is dead

						Cell newCell(checkMatchPoint);
						cellsInGame->push_back(newCell);
						cellsInGame->back().setAlive(false);
					}
				}
			}
		}

		delete cellsInGameCopy;
		cellsInGameCopy = NULL;
	}
}

void Blob::AddLiveCell(int x, int y)
{
	Point2D point(x,y);
	Cell cell(point);
	cellsInGame->push_back(cell);
	liveCellCount++;
}

void Blob::BirthDeath()
{
	for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
	{
		if (it->getNeighborCount() <2 || it->getNeighborCount() > 3)
			it->setAlive(false);
		if (!it->getAlive() && it->getNeighborCount() == 3)
			it->setAlive(true);
	}
}

void Blob::CountNeighbors()
{
	for (std::vector<Cell>::iterator inputCell = cellsInGame->begin(); inputCell !=cellsInGame->end(); ++inputCell)
	{
		//	Loop through the vector containing the cellsInGame.  These are the "it" cells.  Compare them to the inputCell
		for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
		{
			//	Check two things at each loop...
			//
			//		1.	Is the distance exactly one between "it" and "inputCell"?  This is calculated by using "NeighborDistance" in the Point class
			//		2.	Is the "it" cell alive?  It does not matter if the inputCell is alive.  Only if "it" is alive.

			//	If both are true then "it" is a neighbor of "inputCell" (even if the "inputCell" itself is dead).
			//	Increment the counter for inputCell

			if (it->getPoint().NeighborDistance(inputCell->getPoint()) == 1 && it->getAlive())
			{
				inputCell->setNeighborCount(inputCell->getNeighborCount() + 1);
			}
		}
	}
}

void Blob::Draw()
{
	if (liveCellCount > 0)
	{
		//	"Sort" the vector of cells, according to the "Bottom to Top" and "Left to Right" scheme in the Pointclass
		std::sort(cellsInGame->begin(), cellsInGame->end());

		//	Extract the live cells to draw... but only if they are in bounds
		std::vector<Cell> *drawable = new std::vector<Cell>;
		for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
		{

			if (it->getAlive() && it->getPoint() >= plotmin && it->getPoint() <= plotmax)
			{
				Point2D newPoint = it->getPoint();
				Cell newCell(newPoint);
				drawable->push_back(newCell);
			}
		}

		unsigned count = 0;
		int count2 = 1;
		system("cls");
		for (int y = plotmin.gety(); y <= plotmax.gety(); y++)
		{

			for (int x = plotmin.getx(); x <= plotmax.getx(); x++)
			{
				Point2D testPoint(x, y);

				if (drawable->at(count).getPoint().Equal(testPoint) && count < drawable->size())
				{
					count++;
					std::cout << "A";
					if (count == drawable->size())
						count--;
				}
				else
					std::cout << " ";
				if (count2 % plotmax.getx() == 0)
					std::cout << "\n";
				count2++;
			}
		}

		delete drawable;
		drawable = NULL;
	}
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
	std::vector<Cell> *copy = new std::vector<Cell>;
	for (std::vector<Cell>::iterator it = cellsInGame->begin(); it != cellsInGame->end(); ++it)
	{
		if (it->getAlive())
		{
			liveCellCount++;
			Point2D newPoint = it->getPoint();
			Cell newCell(newPoint);
			copy->push_back(newCell);
		}
		it->setNeighborCount(0);
	}
	delete cellsInGame;
	cellsInGame = copy;
}

void Blob::UpdateBlob()
{
	//	Reset vital stats
	ResetBlobStats();

	//	Fill the boundaries of the blob with dead cells (making sure to avoid the live cells)
	BuildDeadCells();

	//	Draw the blob
	Draw();

	//	Calculate neighbors
	CountNeighbors();

	//	Add any newly spawned cells and remove dying cells from the blob
	BirthDeath();
}
