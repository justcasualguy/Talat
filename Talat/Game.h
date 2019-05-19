#pragma once
#include "Player.h"
#include "Controls.h"
#include "Board.h"
#include "MessageField.h"
#include <conio.h>
#include <fstream>


class Game
{

	Player players[3];
	Player* player1;//
	Player* player2;//  used as alias to players[i]
	Player* player3;//
	Board playersBoards[3]; //board[0],[1] - player1; board[1],[2] - player2; board[0],[3] player3;
	COORD topBoardPos;	//1st topLeftCorner position used to start drawing
	COORD bottomLeftBoardPos;//2nd board topLeftCorner position used to start drawing
	COORD bottomRightBoardPos;//3rd board topLeftCorner position used to start drawing
	COORD gameFieldSize;
	int whichPlayerTurn;
	MessageField* messageField;
	MessageField* controlsField;
public:

	Game();
	~Game();
	int turn();
	void drawBoards();
	Player* get_players();
	Board get_gameField();
	COORD get_gameFieldSize();
	void set_gameFieldSize(COORD game_field_size);
	Board* get_playersBoards();
	void saveGame();
	int loadGame();
	int countPoints(Player& p);
	int pawnsInLastRow(Player& player);
	void generatePlayersInfoFile();
	int get_whichPlayerTurn();
	void set_whichPlayerTurn(int playerNumber);
	void noSavedGamesMsg();
	void showControls();
	void updateBoards();



	MessageField* get_gameMessageField();
	
};

