#include "pch.h"
#include "FieldInfo.h"


FieldInfo::FieldInfo(): coords({0,0}),occupied(false),pawnType(triangle),pawnSize(smaller),playerNumber(0)
{
}

FieldInfo::FieldInfo(COORD fieldCoords): coords({fieldCoords.X,fieldCoords.Y}),occupied(false),pawnType(triangle),pawnSize(smaller), playerNumber(0) {}
FieldInfo::~FieldInfo()
{
}

COORD FieldInfo::get_coords() { return coords; }
void FieldInfo::set_coords(COORD coords)
{
	this->coords = coords;
}

void FieldInfo::set_fieldInfo(bool isOccupied, PawnType pawnType, Size pawnSize, int playerNumber)
{
	occupied = isOccupied;
	this->pawnType = pawnType;
	this->pawnSize = pawnSize;
	this->playerNumber = playerNumber;
}

/*void FieldInfo::set_fieldInfo(Pawn& pawn, int playerNumber)
{
	occupied = true;
	this->pawnType = pawn.get_type();
	this->pawnSize = pawn.get_size();
	this->playerNumber = playerNumber;
}
*/

bool FieldInfo::isOccupied()
{
	if (occupied)
		return true;
	return false;
}
void FieldInfo::set_occupied(bool value)
{
	occupied = value;
}

int FieldInfo::get_playerNumber() { return playerNumber; }



Size FieldInfo::get_pawnSize()
{
	return pawnSize;
}

PawnType FieldInfo::get_pawnType()
{
	return pawnType;
}

/*Pawn* FieldInfo::get_pawn()
{
	return pawn;
}*/

/*void FieldInfo::set_pawn(Pawn* pawn)
{
	this->pawn = pawn;
}*/
