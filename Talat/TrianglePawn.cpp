#include "pch.h"
#include "TrianglePawn.h"


TrianglePawn::TrianglePawn()
{
	type = triangle;
	size = smaller;
	pawnWidth = 6;
	pawnHeight = 5;

}

TrianglePawn::TrianglePawn(Size size)
{
	type = triangle;
	if (size == smaller)
	{
		pawnWidth = 6;
		pawnHeight = 3;
	}
	if (size == medium)
	{
		pawnWidth = 8;
		pawnHeight = 4;
	}
	if (size == big)
	{
		pawnWidth = 10;
		pawnHeight = 5;
	}
	this->size = size;

}

TrianglePawn::~TrianglePawn()
{
}

 void TrianglePawn::draw(Board& board, COORD boardField,  Color pawnColor)
{
	 int boardWidth = board.get_boardWidth();
	 int fieldHeight = board.get_fieldHeight();
	 int fieldWidth = board.get_fieldWidth();
	 int startingPos = boardField.Y*boardWidth*(fieldHeight - 1) + boardField.X*(fieldWidth - 1);
	 int base = fieldHeight / 2 - 1 + pawnHeight / 2;
	 bool leftSlash = false, rightSlash = false;
	int k = 0;
	for(int i=1;i<fieldHeight-1;i++)
	{
		for(int j=1;j<fieldWidth-1;j++)
		{
			board.get_board()[startingPos + i * boardWidth + j].Attributes = pawnColor;
			if (i >= base - pawnHeight + 1 && i <= base&&(j == fieldWidth / 2 - k - 1|| j == fieldWidth / 2 + k)) {
				if (j == fieldWidth / 2 - k - 1 && k < pawnHeight) {
					board.get_board()[startingPos + i * boardWidth + j].Attributes = pawnColor;
					board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L'/';
					rightSlash = true;
				}

				else if (j == fieldWidth / 2 + k && k < pawnHeight) {
					board.get_board()[startingPos + i * boardWidth + j].Attributes = pawnColor;
					board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L'\\';
					leftSlash = true;
				}
				
			}
			
			else if (i == base && (j >= fieldWidth / 2 - pawnWidth/2 +1&& j <= fieldWidth / 2 + pawnWidth/2-2))
					board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L'_';
			
		
			else
				board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L' ';

			
		}
		if (leftSlash&&rightSlash)
		{
			k++;
			rightSlash = false;
			leftSlash = false;
		}
	}


};