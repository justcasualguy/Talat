#pragma once
#include "Pawn.h"
class TrianglePawn:public Pawn
{

public:
	TrianglePawn();
	TrianglePawn(Size size);
	~TrianglePawn();

 void draw(Board& board, COORD boardField, Color pawnColor) ;
};

