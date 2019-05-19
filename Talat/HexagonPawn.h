#pragma once
#include "Pawn.h"
class HexagonPawn :public Pawn
{
public:
	HexagonPawn();
	HexagonPawn(Size size);
	~HexagonPawn();
	void draw(Board& board, COORD boardField, Color pawnColor);
};

