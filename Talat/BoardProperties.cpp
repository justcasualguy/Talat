#include "pch.h"
#include "BoardProperties.h"


BoardProperties::BoardProperties()
	:fieldsVertical(5), fieldsHorizontal(5),
	fieldWidth(14), fieldHeight(8), boardColor(WHITE), boardLook(L'x')
{
	boardHeight = fieldsVertical * fieldHeight + 1 - fieldsVertical;
	boardWidth = fieldsHorizontal * fieldWidth + 1 - fieldsHorizontal;
	gameFieldWidth= 2 * boardWidth + fieldWidth - 1;
}	


BoardProperties::~BoardProperties()
{
}

int BoardProperties::get_fieldsVertical() 
{
	return fieldsVertical;
}

void BoardProperties::set_fieldsVertical(int fields_vertical)
{
	fieldsVertical = fields_vertical;
}

int BoardProperties::get_fieldsHorizontal() 
{
	return fieldsHorizontal;
}

void BoardProperties::set_fieldsHorizontal(int fields_horizontal)
{
	fieldsHorizontal = fields_horizontal;
}

int BoardProperties::get_fieldWidth() 
{
	return fieldWidth;
}

void BoardProperties::set_fieldWidth(int field_width)
{
	fieldWidth = field_width;
}

int BoardProperties::get_fieldHeight() 
{
	return fieldHeight;
}

void BoardProperties::set_fieldHeight(int field_height)
{
	fieldHeight = field_height;
}

short BoardProperties::get_boardHeight()
{
	return boardHeight;
}

void BoardProperties::set_boardHeight(int height)
{
	this->boardHeight = height;
}

short BoardProperties::get_boardWidth()
{
	return boardWidth;
}

void BoardProperties::set_boardWidth(int width)
{
	this->boardWidth = width;
}
Color BoardProperties::get_boardColor()
{
	return boardColor;
}

void BoardProperties::set_boardColor(Color boardColor)
{
	this->boardColor = boardColor;
}

int BoardProperties::get_gameFieldWidth() { return gameFieldWidth; }

void BoardProperties::set_gameFieldWidth(int gameFieldWidth) { this->gameFieldWidth = gameFieldWidth; }

void BoardProperties::set_boardLook(wchar_t character)
{
	boardLook = character;
}