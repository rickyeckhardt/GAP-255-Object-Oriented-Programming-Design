// Player.cpp
#include "Player.h"
#include "Constants.h"
#include <iostream>

using namespace std;

extern char* g_pGrid;

//---------------------------------------------------------------------------------------------------------------------
// Gets the player's input and processes it.  Returns true if we're quitting the game, false if not.
//---------------------------------------------------------------------------------------------------------------------
bool Player::Update()
{
	cout << "Enter a grid value, or -1 to quit.\n\n";

	int x = -1;
	int y = -1;
	while (x < 0 || x >= k_gridWidth || y < 0 || y >= k_gridHeight)
	{
		// X
		cout << "X: ";
		cin >> x;

		// we're quitting
		if (x == -1)
			return true;  // quit

		// Y
		cout << "Y: ";
		cin >> y;

		// we're quitting
		if (y == -1)
			return true;  // quit
	}

	// calculate the index
	int index = (y * k_gridWidth) + x;

	// check to see if we hit anything
	if (g_pGrid[index] == 'O')
		cout << "Hit!!";
	else
		cout << "Miss!!";

	return false;  // don't quit
}
