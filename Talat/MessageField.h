#pragma once
#include <windows.h>
#include <string>
#include <iostream>

using namespace std;



class MessageField
{
	HANDLE hConsole;
	string message;
	COORD initialCoords;
	COORD writeCoords;
	COORD fieldSize;
	public:
	MessageField();
	MessageField(COORD fieldSize,COORD initialCoords);
	void write(string message);
	//void writeLine<>( message);
	void clear();
	void set_writingCoord(COORD coords);
	~MessageField();

	template<class T>
	void writeLine(T message)
	{
		if (writeCoords.Y-initialCoords.Y>fieldSize.Y )
			clear();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), writeCoords);
		cout << message;
		writeCoords.Y++;
		
	}
};

