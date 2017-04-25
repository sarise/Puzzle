#include "stdafx.h"
#include "Piece.h"


Piece::Piece()
{
}

Piece::Piece(char i)
{
	id = i;
	side = Side::Up;
}

Piece::Piece(char i, Side s)
{
	id = i;
	side = s;
}

Piece::~Piece()
{
}
