#include "stdafx.h"
#include "Board.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

void Board::_randomize_deck()
{
	unsigned int data_size = BoardSize*BoardSize;
	deck.insert(deck.end(), &true_grid[0], &true_grid[data_size]);

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}

void Board::_match(Piece * p)
{
	for (unsigned i = 0; i < BoardSize*BoardSize; i++)
	{
		// Match the piece in an empty grid
		if (grid[i] == nullptr)
		{
			if (true_grid[i].id == p->id)
			{
				//TODO: do permutation of piece by comparing the side direction

				grid[i] = new Piece(p->id);
				break;
			}

		}
	}
}

Board::Board()
{
	true_grid = new Piece[BoardSize*BoardSize];

	char c = 'A';
	for (int i = 0; i < BoardSize*BoardSize; i++)
	{
		true_grid[i] = Piece(c + i);
	}
	
	_randomize_deck();
}

Board::~Board()
{
	delete[] true_grid;
}

string Board::printable()
{
	string result = "";
	for (int i = 0; i < BoardSize; i++)
	{
		for (int j = 0; j < BoardSize; j++)
		{
			if (grid[i*BoardSize + j] != nullptr)
			{
				result += (grid[i*BoardSize + j]->id);
			}
			else
			{
				result += ".";
			}
		}
		result += '\n';
	}

	result += "Deck: ";
	vector<Piece>::iterator it;
	for (it = deck.begin(); it < deck.end(); it++)
	{
		result += (it->id);
	}

	result += '\n\n';

	return result;
}

void Board::solve()
{
	Piece p;
	while (!deck.empty())
	{
		p = deck.back();
		deck.pop_back();

		_match(&p);

		cout << printable() << endl;
	}
}
