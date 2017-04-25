#pragma once
#include <vector>
#include <string>
#include "Piece.h"
using namespace std;

class Board
{
#define BoardSize 5
private:
	vector<Piece> deck;
	Piece * true_grid;
	Piece * grid[BoardSize*BoardSize] = { nullptr };
	int size;

	void _randomize_deck();
	void _match(Piece *p);
	
public:
	Board();
	Board(int s);
	~Board();

	string printable();
	void solve();

};

