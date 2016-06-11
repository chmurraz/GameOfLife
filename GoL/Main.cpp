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
#include <cstdlib>		//	Apparently needed for sytem("pause") lines in Visual Studio.
#include "Blob.h"	
#include <Windows.h>	//	For Sleep
#include "Dice.hpp"
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	Blob myblob;
	Dice mydice(20);
	for (int i = 0; i <= 300; i++)
	{
		myblob.AddLiveCell(mydice.getRoll(), mydice.getRoll());
	}

	for (int i = 0; i <= 40; i++)
	{
		myblob.UpdateBlob();
		Sleep(500);
	}

	return 0;
}