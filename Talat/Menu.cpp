#include "pch.h"
#include "Menu.h"
#include <cctype>


Menu::Menu()
{
}


Menu::~Menu()
{
}

char Menu::mainMenu()
{
	showMainMenu();
	return makeChoice(3);
}
char Menu::playersChoiceMenu()
{
	showPlayersChoiceMenu();
	return makeChoice(4);
}

void Menu::showMainMenu()
{
	cout<<"\t\t" << endl << endl << endl;
	cout<<"\t\t" << "TTTTTTTTTTTTTTTTTTTTTTT         AAA               LLLLLLLLLLL                            AAA         TTTTTTTTTTTTTTTTTTTTTTT" << endl;
	cout<<"\t\t" << "T:::::::::::::::::::::T        A:::A              L:::::::::L                           A:::A        T:::::::::::::::::::::T" << endl;
	cout<<"\t\t" << "T:::::::::::::::::::::T       A:::::A             L:::::::::L                          A:::::A       T:::::::::::::::::::::T" << endl;
	cout<<"\t\t" << "T:::::TT:::::::TT:::::T      A:::::::A            LL:::::::LL                         A:::::::A      T:::::TT:::::::TT:::::T" << endl;
	cout<<"\t\t" << "TTTTTT  T:::::T  TTTTTT     A:::::::::A             L:::::L                          A:::::::::A     TTTTTT  T:::::T  TTTTTT" << endl;
	cout<<"\t\t" << "        T:::::T            A:::::A:::::A            L:::::L                         A:::::A:::::A            T:::::T        " << endl;
	cout<<"\t\t" << "        T:::::T           A:::::A A:::::A           L:::::L                        A:::::A A:::::A           T:::::T        " << endl;
	cout<<"\t\t" << "        T:::::T          A:::::A   A:::::A          L:::::L                       A:::::A   A:::::A          T:::::T        " << endl;
	cout<<"\t\t" << "        T:::::T         A:::::A     A:::::A         L:::::L                      A:::::A     A:::::A         T:::::T        " << endl;
	cout<<"\t\t" << "        T:::::T        A:::::AAAAAAAAA:::::A        L:::::L                     A:::::AAAAAAAAA:::::A        T:::::T        " << endl;
	cout<<"\t\t" << "        T:::::T       A:::::::::::::::::::::A       L:::::L                    A:::::::::::::::::::::A       T:::::T        " << endl;
	cout<<"\t\t" << "        T:::::T      A:::::AAAAAAAAAAAAA:::::A      L:::::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A      T:::::T        " << endl;
	cout<<"\t\t" << "      TT:::::::TT   A:::::A             A:::::A   LL:::::::LLLLLLLLL:::::L   A:::::A             A:::::A   TT:::::::TT      " << endl;
	cout<<"\t\t" << "      T:::::::::T  A:::::A               A:::::A  L::::::::::::::::::::::L  A:::::A               A:::::A  T:::::::::T      " << endl;
	cout<<"\t\t" << "      T:::::::::T A:::::A                 A:::::A L::::::::::::::::::::::L A:::::A                 A:::::A T:::::::::T      " << endl;
	cout<<"\t\t" << "      TTTTTTTTTTTAAAAAAA                   AAAAAAALLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAATTTTTTTTTTT      " << endl;
	                                                                                                                                                                                                                                                     
	cout << endl << endl;
				                                              
cout<<"                                             ___     _____                                 "<<endl;
cout<<"                                            |_  |   |   | |___ _ _ _    ___ ___ _____ ___  "<<endl;
cout<<"                                             _| |_ _| | | | -_| | | |  | . | .'|     | -_| "<<endl;
cout<<"                                            |_____|_|_|___|___|_____|  |_  |__,|_|_|_|___| "<<endl;
cout<<"                                                                       |___|               "<<endl;
cout<<"                                                                                           "<<endl;
cout<<"                                             ___   __              _                       "<<endl;
cout<<"                                            |_  | |  |   ___ ___ _| |   ___ ___ _____ ___  "<<endl;
cout<<"                                            |  _|_|  |__| . | .'| . |  | . | .'|     | -_| "<<endl;
cout<<"                                            |___|_|_____|___|__,|___|  |_  |__,|_|_|_|___| "<<endl;
cout<<"                                                                       |___|               "<<endl;
cout<<"                                                                                           "<<endl;
cout<<"                                             ___   _____     _ _                           "<<endl;
cout<<"                                            |_  | |   __|_ _|_| |_                         "<<endl;
cout<<"                                            |_  |_|   __|_'_| |  _|                        "<<endl;
cout<<"                                            |___|_|_____|_,_|_|_|                          "<<endl;
cout<<"                                               "<<endl;
				
}

char Menu::makeChoice(int choices)
{
	char keyPressed[1];
	keyPressed[0] = _getwch();

	while (keyPressed[0] < 0 || keyPressed[0]>255 || !isdigit(keyPressed[0])||(atoi(keyPressed) <=0||atoi(keyPressed)>choices))
		keyPressed[0] = _getwch();
	system("cls");
	return keyPressed[0];
}
char Menu::makeChoiceNoCls(int choices)
{
	char keyPressed[1];
	keyPressed[0] = _getwch();
	while (!isdigit(keyPressed[0]) || (atoi(keyPressed) <= 0 || atoi(keyPressed) > choices))
		keyPressed[0] = _getwch();
	
	return keyPressed[0];
}

void Menu::showPlayersChoiceMenu()
{
	                                                      
cout<<"                                _____                          _                      "<<endl;
cout<<"                               |  |  |_ _ _____ ___ ___    ___| |___ _ _ ___ ___ ___ "<<endl;
cout<<"                               |     | | |     | .'|   |  | . | | .'| | | -_|  _|_ -|"<<endl;
cout<<"                               |__|__|___|_|_|_|__,|_|_|  |  _|_|__,|_  |___|_| |___|"<<endl;
cout<<"                                                          |_|       |___|            "<<endl;
cout<<"                                                                                     "<<endl;
cout<<"                                      ___     ___      _____ _                       "<<endl;
cout<<"                                     |_  |   |_  |    |  _  | |___ _ _ ___ ___       "<<endl;
cout<<"                                      _| |_ _ _| |_   |   __| | .'| | | -_|  _|      "<<endl;
cout<<"                                     |_____|_|_____|  |__|  |_|__,|_  |___|_|        "<<endl;
cout<<"                                                                  |___|              "<<endl;
cout<<"                                                                                     "<<endl;
cout<<"                                      ___   ___    _____ _                           "<<endl;
cout<<"                                     |_  | |_  |  |  _  | |___ _ _ ___ ___ ___       "<<endl;
cout<<"                                     |  _|_|  _|  |   __| | .'| | | -_|  _|_ -|      "<<endl;
cout<<"                                     |___|_|___|  |__|  |_|__,|_  |___|_| |___|      "<<endl;
cout<<"                                                              |___|                  "<<endl;
cout<<"                                                                                     "<<endl;
cout<<"                                      ___   ___    _____ _                           "<<endl;
cout<<"                                     |_  | |_  |  |  _  | |___ _ _ ___ ___ ___       "<<endl;
cout<<"                                     |_  |_|_  |  |   __| | .'| | | -_|  _|_ -|      "<<endl;
cout<<"                                     |___|_|___|  |__|  |_|__,|_  |___|_| |___|      "<<endl;
cout<<"                                                              |___|                  "<<endl;
	                                  
                                                                                    
cout<<"                                              ___   _____         _      "<<endl;                    
cout<<"                                             | | | | __  |___ ___| |_    "<<endl;                    
cout<<"                                             |_  |_| __ -| .'|  _| '_|   "<<endl;                    
cout<<"                                               |_|_|_____|__,|___|_,_|   "<<endl;                    
                                                      
}	 