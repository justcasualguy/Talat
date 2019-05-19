#pragma once
#include "Pawn.h"
class RectanglePawn :public Pawn
{
public:
	RectanglePawn();
	RectanglePawn(Size size);
	~RectanglePawn();
	void draw(Board& board, COORD boardField,Color pawnColor);
};

