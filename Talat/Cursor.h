#pragma once
#include <windows.h>
#include "BoardProperties.h"
#include "Board.h"
#include "Common.h"

class Cursor : public BoardProperties
{
	COORD position;	//represents top left corner of selected field
	Color cursorColor;
	
public:
	Cursor();
	Cursor(COORD cursor);
	~Cursor();

	void draw(Board& board, COORD cursorPosition);
	void draw(Board& board, COORD boardField, Color color);
	void draw(Board& board);
	void clear(Board& board, COORD boardField);
	
	COORD get_position() ;
	void set_position( COORD position);
	void set_positionY(short y);
	void set_positionX(short x);
	void changePositionX(short x);
	void changePositionY(short y);
	void set_cursorColor(Color color);
};


