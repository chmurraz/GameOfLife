/***********************************************************************
** Program Filename: Main.cpp
** Author:  Chris Murray
** Date: 6/10/2016
** Description: Executes Conway's game of life based on user input
** Input: The user will choose a starting pattern, the location and
**		   the number of generations to run the game.
** Output: Prints the locations of all living cells at each generation
**************************************************************************/

#include <iostream>
#include <cstdlib>		// Apparently needed for sytem("pause") lines in Visual Studio.
#include "Blob.h"

using namespace std;

int main()
{
	Blob myblob;
	myblob.AddLiveCell(5,1);
	//myblob.AddLiveCell(5,2);
	//myblob.AddLiveCell(5, 3);
	//myblob.AddLiveCell(-2, 0);
	//myblob.AddLiveCell(-2, 1);
	//myblob.AddLiveCell(-2, 2);
	//myblob.AddLiveCell(-3, 2);

	for (int i = 0; i <= 10;i++)
		myblob.UpdateBlob();
	return 0;
}