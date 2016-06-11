#include "Dice.hpp"
#include <cstdlib>
#include <iostream>
//#include <ctime>


Dice::Dice()
{
	sides = 6;
}

Dice::Dice(int user_input)
{
	sides = user_input;
}

void Dice::setSides(int user_input)
{
	sides = user_input;
}

int Dice::getSides()
{
	return sides;
}

int Dice::getRoll()
{
	return rand() % sides + 1;
}
