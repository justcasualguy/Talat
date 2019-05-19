#pragma once
#include "BoardProperties.h"
#include <iostream>
#include "FieldInfo.h"
using namespace std;
class Board :public BoardProperties
{

	CHAR_INFO* board;				//one dimensional array representing board used by WriteConsoleOutput
	COORD topLeftCornerPos;			//position to start drawing in console
	FieldInfo* fieldsInfo;				//stores information about field state

public:
	Board();
	~Board();
	void create();
	void draw();
	COORD get_topLeftCornerPos();
	void set_topLeftCornerPos(COORD top_left_corner_position);
	
	CHAR_INFO* get_board();
	void set_board(CHAR_INFO* board);
	
	COORD* get_fieldsCoords();
	
	FieldInfo* get_fieldsInfo();
	FieldInfo get_fieldInfo(COORD fieldCoords);
	void set_fieldInfo(COORD fieldCoords, bool isOccupied, PawnType pawnType, Size pawnSize, int playerNumber);
	FieldInfo* get_fieldsInfo(COORD fieldCoords);
	
	COORD findEmptyField(short row); //looks for first empty field from left side of row
	COORD findEmptyFieldRight(short row);//looks for first empty field from right side of row};
	
	Board* get_usedBoard(int boardId);
	bool hasEmptyField(short row);
};
