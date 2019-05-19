#include "pch.h"
#include "Cursor.h"


Cursor::Cursor():cursorColor(BLUE), position({ 0,0 })
{
}

Cursor::Cursor(COORD cursor):position({cursor.X,cursor.Y}){}

Cursor::~Cursor()
{
}

void Cursor::draw(Board &board, COORD boardField)
{
	
	int startingPos = boardField.Y*boardWidth*(fieldHeight - 1) + boardField.X*(fieldWidth - 1);
	for(int i=0;i<fieldHeight;i++)
	{
		for(int j=0;j<fieldWidth;j++)
		{
			
			if (i == 0 || i == fieldHeight - 1) {
				board.get_board()[startingPos + i * boardWidth + j].Attributes = cursorColor;
				board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = boardLook;

			}
			else if (j == 0 || j == fieldWidth - 1) {
				board.get_board()[startingPos + i * boardWidth + j].Attributes = cursorColor;
				board.get_board()[startingPos + i * boardWidth + j].Char.AsciiChar = boardLook;
			}
		}
	}
	
}

void Cursor::draw(Board &board, COORD boardField,Color color)
{
	//boardField.Y*boardWIdth
	Color clor = cursorColor;
	cursorColor = color;
	draw(board, boardField);
	cursorColor = clor;

}

void Cursor::clear(Board &board, COORD boardField)
{
	Color color = cursorColor;
	cursorColor = board.get_boardColor();
	draw(board, boardField);
	cursorColor = color;
}



COORD Cursor::get_position() 
{
	return position;
}

void Cursor::set_position( COORD position)
{
	this->position = position;
}
void Cursor::set_positionY(short y)
{
	this->position.Y = y;
}

void Cursor::set_positionX(short x)
{
	this->position.X = x;
}

void Cursor::changePositionX(short x)
{
	position.X += x;
}
void Cursor::changePositionY(short y)
{
	position.Y += y;
}

void Cursor::set_cursorColor(Color color)
{
	cursorColor = color;
}




