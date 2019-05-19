#include "pch.h"
#include "RectanglePawn.h"


RectanglePawn::RectanglePawn()
{
	type = rectangle;
	size = smaller;
	pawnWidth = 6;
	pawnHeight = 5;
}

RectanglePawn::RectanglePawn(Size size)
{
	type = rectangle;
	if (size == smaller)
	{
		pawnWidth = 6;
		pawnHeight = 5;
	}
	if (size == medium)
	{
		pawnWidth = 8;
		pawnHeight = 5;
	}
	if (size == big)
	{
		pawnWidth = 10;
		pawnHeight = 5;
	}
	this->size = size;

}

RectanglePawn::~RectanglePawn()
{
}

 void RectanglePawn::draw(Board& board, COORD boardField,Color pawnColor)
{
	int boardWidth = board.get_boardWidth();
	 int fieldHeight = board.get_fieldHeight();
	 int fieldWidth = board.get_fieldWidth();
	 

	 int startingPos = boardField.Y*boardWidth*(fieldHeight - 1) + boardField.X*(fieldWidth - 1);

	for(int i=1;i<fieldHeight-1;i++)
	{
		for(int j=1;j<fieldWidth-1;j++)
		{
			board.get_board()[startingPos + i * boardWidth + j].Attributes = pawnColor;
			if ((i == fieldHeight / 2 - pawnHeight / 2 - 1 || i == fieldHeight / 2 + (pawnHeight / 2 ))
				&& (j >= fieldWidth / 2 - pawnWidth / 2  && j < fieldWidth / 2 + pawnWidth / 2 -1 ))
				board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L'_';
			else if((j== fieldWidth / 2 - pawnWidth / 2-1||j== fieldWidth / 2 + pawnWidth / 2-1)&&
				i>= fieldHeight / 2 - pawnHeight / 2 && i<=fieldHeight / 2 + (pawnHeight / 2))
				board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L'|';
			else
				board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L' ';
		}
	}

};