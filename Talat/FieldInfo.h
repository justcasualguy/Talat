#pragma once
#include <windows.h>
#include <string>
#include "Common.h"

using namespace std;

class FieldInfo
{
	COORD coords;
	bool occupied;
	PawnType pawnType;
	Size pawnSize;
	int playerNumber;
	
public:
	FieldInfo();
	FieldInfo(COORD fieldCoords);
	~FieldInfo();
	void set_coords(COORD coords);
	COORD get_coords();
	void set_fieldInfo(bool isOccupied, PawnType pawnType, Size pawnSize, int playerNumber);
	void set_occupied(bool value);
	int get_playerNumber();
	int get_pawnId();
	Size get_pawnSize();
	PawnType get_pawnType();
	bool isOccupied();
};

