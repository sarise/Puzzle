#pragma once

enum class Side { Up, Down, Left, Right };

class Piece
{
private:
	Side side;
	
public:
	Piece();
	Piece(char i);
	Piece(char i, Side s);
	~Piece();

	char id;
};

