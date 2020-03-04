// Assignment_3_1.cpp

//---------------------------------------------------------------------------------------------------------------------
// Instructions:
// 
// 1) Refactor this code to encapsulate all of the current functionality into a singleton.  Feel free to modify any 
//    of the code or break it up into separate files.  You can also use multiple classes if you want, but there must
//    be at least one singleton.
// 2) Add a computer controlled player that will fire a random shot on their turn.  This should be done using subclass
//    delegation.
// 3) Right now, the ship is always displayed.  Modify the game so that the ship is hidden view.  Each tile should 
//    display '.' for unattacked tiles, 'X' for a hit tile, and 'O' for a missed tile.
// 4) The game should end when the ship is destroyed.
// 5) Make sure you clean up the code.  Refactoring can create messy code if you don't clean it up.  There are also 
//    a number of things subtley wrong with this project.  See how many you can spot and fix.
// 
// Bonus:
//    *: Prevent the enemy AI from attacking the same spot.
// ****: Create a second grid.  The human player attacks the second grid while the computer player attacks the first.
//---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <conio.h>
#include <time.h>
#include "Constants.h"
#include "Player.h"

using namespace std;

//---------------------------------------------------------------------------------------------------------------------
// Global function prototypes
//---------------------------------------------------------------------------------------------------------------------
void CreateGrid();
void SpawnBattleship();
void DrawGrid();
int RandRange(int minValue, int maxValue);

//---------------------------------------------------------------------------------------------------------------------
// Global variables
//---------------------------------------------------------------------------------------------------------------------
char* g_pGrid = nullptr;


//---------------------------------------------------------------------------------------------------------------------
// main() function
//---------------------------------------------------------------------------------------------------------------------
void main()
{
	srand((unsigned int)time(0));

	cout << "Battleship!\n\n";

	Player player;
	CreateGrid();
	SpawnBattleship();

	bool quitting = false;
	while (!quitting)
	{
		DrawGrid();
		quitting = player.Update();
	}

	delete[] g_pGrid;
	cout << "\n\nThanks for playing!\n";
	_getch();
}

//---------------------------------------------------------------------------------------------------------------------
// Creates and initializes the grid.
//---------------------------------------------------------------------------------------------------------------------
void CreateGrid()
{
	// allocate memory for the grid
	g_pGrid = new char[k_gridWidth*k_gridHeight];

	// set the initial tiles
	for (int y = 0; y < k_gridHeight; ++y)
	{
		for (int x = 0; x < k_gridWidth; ++x)
		{
			int index = (y * k_gridWidth) + x;
			g_pGrid[index] = '.';
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------
// Spawns the battleship in a random location and orientation.
//---------------------------------------------------------------------------------------------------------------------
void SpawnBattleship()
{
	int x = RandRange(k_battleshipLength, k_gridWidth - k_battleshipLength);
	int y = RandRange(k_battleshipLength, k_gridHeight - k_battleshipLength);
	bool isHorizontal = (rand() % 100 < 50) ? (true) : (false);
	int delta = (rand() % 100 < 50) ? (-1) : (1);

	for (int i = 0; i < k_battleshipLength; ++i)
	{
		int index = (y * k_gridWidth) + x;
		g_pGrid[index] = 'O';

		if (isHorizontal)
			x += delta;
		else
			y += delta;
	}
}

//---------------------------------------------------------------------------------------------------------------------
// Draws the grid, including all the row/column labels.
//---------------------------------------------------------------------------------------------------------------------
void DrawGrid()
{
	// draw the 10's place of labels for each column
	cout << "   ";
	for (int i = 0; i < k_gridWidth; ++i)
	{
		int tens = i / 10;
		if (tens > 0)
			cout << tens;
		else
			cout << ' ';
	}
	cout << endl;

	// draw the 1's place of labels for each column
	cout << "   ";
	for (int i = 0; i < k_gridWidth; ++i)
	{
		int ones = i % 10;
		cout << ones;
	}
	cout << endl; // << endl;

	// draw the grid
	for (int y = 0; y < k_gridHeight; ++y)
	{
		// draw the label for this row
		if (y >= 10)
			cout << y << ' ';
		else
			cout << ' ' << y << ' ';

		// draw this row
		for (int x = 0; x < k_gridWidth; ++x)
		{
			int index = (y * k_gridWidth) + x;
			cout << g_pGrid[index];
		}

		cout << endl;
	}

	cout << endl;
}

//---------------------------------------------------------------------------------------------------------------------
// Returns a random number between minValue and maxValue.
//---------------------------------------------------------------------------------------------------------------------
int RandRange(int minValue, int maxValue)
{
	int val = (rand() % (maxValue - minValue)) + minValue;
	return val;
}

