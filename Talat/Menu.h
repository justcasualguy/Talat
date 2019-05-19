#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
class Menu
{


public:

	void showMainMenu();
	static char makeChoice(int choices);
	static char makeChoiceNoCls(int choices);
	//char makeChoice();
	void showPlayersChoiceMenu();
	Menu();
	~Menu();
	char mainMenu();
	char playersChoiceMenu();
};

