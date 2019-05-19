#include "pch.h"
#include "MessageField.h"


MessageField::MessageField() :hConsole(GetStdHandle(STD_OUTPUT_HANDLE)), message(""), initialCoords({ 0,0 }), writeCoords(initialCoords), fieldSize({ 30,10 })
{
	
}

MessageField::MessageField( COORD fieldSize, COORD initialCoords): hConsole(GetStdHandle(STD_OUTPUT_HANDLE)), message(""), initialCoords(initialCoords),writeCoords(initialCoords),fieldSize(fieldSize)
{
	
}



MessageField::~MessageField()
{
}

/*void MessageField::write(string message)
{
	
	cout << message;

}*/

/*void MessageField::writeLine(string message)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), writeCoords);
	cout << message;
	writeCoords.Y++;
}*/

void MessageField::clear()
{
	
	for(short i= 0;i<=fieldSize.Y;i++)
	{
		for(short j=0;j<=fieldSize.X;j++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { initialCoords.X + j,initialCoords.Y + i });
			cout << " ";

		}
		
	}
	writeCoords = { initialCoords.X,initialCoords.Y };
}