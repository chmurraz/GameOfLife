#ifndef DICE_H
#define DICE_H
class Dice
{

protected:					//	Had to change this from private to protected to get inheritance to work
	int sides;
public:
	Dice();
	Dice(int user_input);

	void setSides(int user_input);

	int getSides();
	int getRoll();
};

#endif