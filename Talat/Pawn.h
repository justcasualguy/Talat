#pragma once
#include "pch.h"

#include <iostream>
#include "Board.h"
#include "Common.h"

//using namespace std;



class Pawn
{
protected:
	Size size;
	PawnType type;
	int pawnHeight;
	int pawnWidth;
	COORD pawnCoords;
	bool taken;
	int boardId;
	Color color;
public:
	Pawn();
	~Pawn();
	virtual void draw(Board& board, COORD boardField, Color pawnColor);

	PawnType get_type();
	void set_type(PawnType type);
	
	Size get_size();
	void set_size(Size size);

	Color get_color();
	void set_color(Color color);


	COORD get_pawnCoords();
	void set_pawnCoords(COORD pawnCoords);

	bool isTaken();
	void set_taken(bool value);

	void set_boardId(int boardId);
	int get_boardId();

};
