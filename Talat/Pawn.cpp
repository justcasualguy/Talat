#include "pch.h"
#include "Pawn.h"


Pawn::Pawn() :taken(false), pawnCoords({ 0,0 }), size(smaller), type(hexagon), pawnWidth(6), pawnHeight(4), boardId(0) {}
Pawn::~Pawn() {}

void Pawn::draw(Board& board, COORD boardField, Color pawnColor) {};

PawnType Pawn::get_type()
{
	return type;
}

void Pawn::set_type(PawnType type)
{
	this->type = type;
}

void Pawn::set_size(Size size)
{
	this->size = size;
}


Size Pawn::get_size() { return size; }

COORD Pawn::get_pawnCoords()
{
	return pawnCoords;
}

void Pawn::set_pawnCoords(COORD pawnCoords)
{
	this->pawnCoords = pawnCoords;
}
bool Pawn::isTaken()
{
	return taken;
}
void Pawn::set_taken(bool value)
{
	taken = value;
}

int Pawn::get_boardId()
{
	return boardId;
}

void Pawn::set_boardId(int boardId)
{
	this->boardId = boardId;
}

void Pawn::set_color(Color color)
{
	this->color = color;
}
Color Pawn::get_color()
{
	return color;
}






