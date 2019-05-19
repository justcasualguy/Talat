#include "pch.h"
#include"Board.h"


Board::Board():topLeftCornerPos({ 0,0 })
{
	board = new CHAR_INFO[boardHeight*boardWidth];
	create();
	fieldsInfo = new FieldInfo[fieldsHorizontal*fieldsVertical];

	for(short i = 0;i<fieldsVertical;i++)
	{
		for(short j=0;j<fieldsHorizontal;j++)
		{
			fieldsInfo[fieldsHorizontal*i + j].set_coords({ j,i });
		}
	}
	
	;
}



Board::~Board()
{
	delete[] board; delete[] fieldsInfo;
}

void Board::create(){

	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			board[i * boardWidth + j].Attributes = get_boardColor();
			if (i == 0 || i % (fieldHeight - 1) == 0) {
				board[i * boardWidth + j].Char.UnicodeChar = boardLook;

			}
			else if (j == 0 || j % (fieldWidth - 1) == 0)
			{
				board[i * boardWidth + j].Char.UnicodeChar = boardLook;

			}
			else {
				board[i * boardWidth + j].Char.UnicodeChar = L' ';

			}
		}
	}
}

void Board::draw()
{	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = {boardWidth, boardHeight };
	SMALL_RECT s = { topLeftCornerPos.X,topLeftCornerPos.Y,topLeftCornerPos.X + boardWidth,topLeftCornerPos.Y + boardHeight };

	WriteConsoleOutput(hConsole, board, bufferSize, { 0,0}, &s);
}




bool Board::hasEmptyField(short row)
{
	for (short i = 0; i < fieldsHorizontal; i++)
	{
		if (!fieldsInfo[row*fieldsHorizontal + i].isOccupied())
			return true;
		
	}
	return false;
}

COORD Board::findEmptyField(short row)
{
	for(short i=0;i<fieldsHorizontal;i++)
	{
		if (!fieldsInfo[row*fieldsHorizontal + i].isOccupied())
			return { i,row };
	}
}

COORD Board::findEmptyFieldRight(short row)
{
	for (short i = fieldsHorizontal-1; i >= 0; i--)
	{
		if (!fieldsInfo[row*fieldsHorizontal + i].isOccupied())
			return { i,row };
	}
}

COORD Board::get_topLeftCornerPos()
{
	return topLeftCornerPos;
}

void Board::set_topLeftCornerPos(COORD top_left_corner_position)
{

	topLeftCornerPos = top_left_corner_position;
}

void Board::set_board(CHAR_INFO* board)
{
	this->board = board;
}

CHAR_INFO* Board::get_board()
{
	return board;
}

FieldInfo* Board::get_fieldsInfo()
{
	return fieldsInfo;
}

FieldInfo Board::get_fieldInfo(COORD fieldCoords)
{
	return fieldsInfo[fieldCoords.Y*fieldsHorizontal + fieldCoords.X];
}

void Board::set_fieldInfo(COORD fieldCoords, bool isOccupied, PawnType pawnType, Size pawnSize, int playerNumber)
{
	fieldsInfo[fieldCoords.Y*fieldsHorizontal + fieldCoords.X].set_fieldInfo(isOccupied, pawnType, pawnSize, playerNumber);

}

FieldInfo* Board::get_fieldsInfo(COORD fieldCoords)
{
	return &fieldsInfo[fieldCoords.Y*fieldsHorizontal + fieldCoords.X];
}
