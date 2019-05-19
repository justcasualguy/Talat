#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
class Menu
{


public:
	Menu();
	~Menu();
	void showMainMenu();
	static char makeChoice(int choices);
	static char makeChoiceNoCls(int choices);
	void showPlayersChoiceMenu();
	char mainMenu();
	char playersChoiceMenu();
};

