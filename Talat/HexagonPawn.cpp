#include "pch.h"
#include "HexagonPawn.h"


HexagonPawn::HexagonPawn()
{
	type = hexagon;
	size = smaller;
	pawnWidth = 6;
	pawnHeight = 3;
}

HexagonPawn::HexagonPawn(Size size)
{
	type = hexagon;
	if(size==smaller)
	{
		pawnWidth = 6;
		pawnHeight = 3;
	}
	if (size == medium)
	{
		pawnWidth = 10;
		pawnHeight = 5;
	}
	if (size == big)
	{
		pawnWidth = 12;
		pawnHeight = 5;
	}
	this->size = size;

}

HexagonPawn::~HexagonPawn()
{
}

void HexagonPawn::draw(Board& board, COORD boardField, Color pawnColor)
{
	int boardWidth = board.get_boardWidth();
	int fieldHeight = board.get_fieldHeight();
	int fieldWidth = board.get_fieldWidth();
	int slashes = pawnHeight / 2;

	int startingPos = boardField.Y*boardWidth*(fieldHeight - 1) + boardField.X*(fieldWidth - 1);

	for (int i = 1; i < fieldHeight-1; i++)
	{
		for (int j = 1; j < fieldWidth-1; j++)
		{
			board.get_board()[startingPos + i * boardWidth + j].Attributes = pawnColor;
			if ((i == fieldHeight / 2 - pawnHeight / 2 - 1 || i == fieldHeight / 2 + (pawnHeight / 2 - 1))
				&& (j > fieldWidth / 2 - pawnWidth / 2 +1&& j < fieldWidth / 2 + pawnWidth / 2 - slashes))
				board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L'_';
			else
				board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = L' ';

		}
	}

	for (int i = 0; slashes > 0; slashes--) {


		board.get_board()[startingPos + boardWidth * (fieldHeight / 2 - 1 + slashes) + fieldWidth / 2 + pawnWidth / 2 - slashes].Char.AsciiChar = L'/';//right lower /
		board.get_board()[startingPos + boardWidth * (fieldHeight / 2 - slashes) + fieldWidth / 2 + pawnWidth / 2 - slashes].Char.AsciiChar = L'\\';//right lower '\'

		board.get_board()[startingPos + boardWidth * (fieldHeight / 2 - 1 + slashes) + fieldWidth / 2 - pawnWidth / 2 + 1 - i].Char.AsciiChar = L'\\';//lewft lower '\'
		board.get_board()[startingPos + boardWidth * (fieldHeight / 2 - slashes) + fieldWidth / 2 - pawnWidth / 2 + 1 - i].Char.AsciiChar = L'/'; //left upper /
		i++;


	}
}