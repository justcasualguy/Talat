#pragma once
#include <windows.h>
#include "Common.h"

class BoardProperties
{
protected:
	int fieldsVertical, fieldsHorizontal, fieldWidth, fieldHeight;//ilosc pol wysokosci i szerokosci
	short boardHeight;
	short boardWidth ;
	Color boardColor;
	short gameFieldWidth;
	wchar_t boardLook;
public:
	BoardProperties();
	~BoardProperties();
	
	int get_fieldsVertical();
	void set_fieldsVertical(int fields_vertical);
	
	int get_fieldsHorizontal();
	void set_fieldsHorizontal(int fields_horizontal);
	
	int get_fieldWidth();
	void set_fieldWidth(int field_width);
	
	int get_fieldHeight();
	void set_fieldHeight(int field_height);
	
	short get_boardHeight();
	void set_boardHeight(int height);
	
	short  get_boardWidth();
	void set_boardWidth(int width);
	
	Color  get_boardColor();
	void set_boardColor(Color boardColor);
	
	int get_gameFieldWidth();
	void set_gameFieldWidth(int gameFieldWidth);

	void set_boardLook(wchar_t character);
};

