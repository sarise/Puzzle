// Puzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include <iostream>
using namespace std;


int main()
{
	Board board = Board();
	cout << board.printable() << endl;

	board.solve();

    return 0;
}

