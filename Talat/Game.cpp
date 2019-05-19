#include "pch.h"
#include "Game.h"




Game::Game():whichPlayerTurn(0)
{

	SMALL_RECT s = { 0,0,200,200 };
	SetConsoleTitleA("Talat");
	int opposite = playersBoards[0].get_fieldsHorizontal() - 1; // last row of board 
	short boardWidth = playersBoards[0].get_boardWidth();
	short fieldWidth = playersBoards[0].get_fieldWidth();
	short boardHeight = playersBoards[0].get_boardHeight();
	short fieldHeight = playersBoards[0].get_fieldHeight();
	
	topBoardPos = { boardWidth - fieldWidth * 2,0 };
	bottomLeftBoardPos = { 0,boardHeight + fieldHeight - 1 };
	bottomRightBoardPos = { boardWidth + fieldWidth - 1 ,boardHeight + fieldHeight - 1 };


	players[0].set_usedBoards(&playersBoards[1], 0);
	players[0].set_startingRow(opposite, 0);
	players[0].set_moveDirection(up, 0);

	players[0].set_usedBoards(&playersBoards[2], 1);
	players[0].set_startingRow(opposite, 1);
	players[0].set_moveDirection(up, 1);

	players[1].set_usedBoards(&playersBoards[0], 0);
	players[1].set_startingRow(0, 0);
	players[1].set_moveDirection(down, 0);

	players[1].set_usedBoards(&playersBoards[1], 1);
	players[1].set_startingRow(0, 1);
	players[1].set_moveDirection(down, 1);



	players[2].set_usedBoards(&playersBoards[0], 0);
	players[2].set_startingRow(opposite, 0);
	players[2].set_moveDirection(up, 0);

	players[2].set_usedBoards(&playersBoards[2], 1);
	players[2].set_startingRow(0, 1);
	players[2].set_moveDirection(up, 0);

	players[0].set_allPawns(players[0].get_pawns(),0);
	players[0].set_allPawns(players[1].get_pawns(),1);
	players[0].set_allPawns(players[2].get_pawns(),2);
	players[1].set_allPawns(players[0].get_pawns(), 0);
	players[1].set_allPawns(players[1].get_pawns(), 1);
	players[1].set_allPawns(players[2].get_pawns(), 2); 
	players[2].set_allPawns(players[1].get_pawns(), 0);
	players[2].set_allPawns(players[2].get_pawns(), 1);
	players[2].set_allPawns(players[2].get_pawns(), 2);
	
	
	players[0].set_number(1);
	players[1].set_number(2);
	players[2].set_number(3);


	player1 = &players[0];
	player2 = &players[1];
	player3 = &players[2];

	messageField = new MessageField({ 30,20 }, { topBoardPos.X + boardWidth + 5,topBoardPos.Y + boardHeight / 2 });
	players[0].set_messageField(messageField);
	players[1].set_messageField(messageField);
	players[2].set_messageField(messageField);

	controlsField = new MessageField({ 20,20 }, {  5,topBoardPos.Y + boardHeight / 2 });




}

Game::~Game()
{
	delete messageField;
	delete controlsField;
}



void Game::drawBoards()
{
	playersBoards[0].set_topLeftCornerPos(topBoardPos);
	playersBoards[0].draw();

	playersBoards[1].set_topLeftCornerPos(bottomLeftBoardPos);
	playersBoards[1].draw();

	playersBoards[2].set_topLeftCornerPos(bottomRightBoardPos);
	playersBoards[2].draw();

}

int Game::turn()
{
	int i;
	updateBoards();
	drawBoards();
	players[whichPlayerTurn].updateTakenPawns();
	if (players[whichPlayerTurn].isAI())
		players[whichPlayerTurn].makeRandomMove();
	else {
		i = players[whichPlayerTurn].makeMove();
		if (i == 1) {
			saveGame();
			return 0;
		}
		if(i==-1) return 0;
	}
	whichPlayerTurn++;
	if (whichPlayerTurn > 2)
		whichPlayerTurn = 0;
	messageField->clear();
	return 1;

}

void Game::updateBoards()
{
	for (int i = 0; i < 3; i++)
	{
		playersBoards[i].create();

	}
	for (int i = 0; i < 3; i++)
	{
		players[i].putPawns();
	}

}

void Game::saveGame()
{
	
	fstream save;

	save.open("save.txt", ios::trunc | ios::out);
	if (!save.good())
		return;
	for (int j = 0; j < 3; j++) {

		
		for (int i = 0; i < 9; i++)
		{
			save << players[j].get_pawn(i)->get_boardId()<<" ";
			save << players[j].get_pawn(i)->get_pawnCoords().X<<" ";
			save << players[j].get_pawn(i)->get_pawnCoords().Y << " ";
			save << players[j].get_pawn(i)->get_type() << " ";
			save << players[j].get_pawn(i)->get_size() << " ";
			save << players[j].get_pawn(i)->isTaken();
			save << endl;
			
		}
		save << players[j].get_takenPawns();
		save << endl << endl;
	}
	save << players[0].isAI() << " " << players[1].isAI() << " " << players[2].isAI() << " ";
	save << whichPlayerTurn;
	save.close();
}

int Game::loadGame()
{
	fstream saveFile;
	bool taken;
	COORD coords;
	int type;
	int size;
	int takenPawns;
	int boardId;
	bool isAi;
	saveFile.open("save.txt", ios::in);
	if (!saveFile.good())
		return 0;
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k< numberOfPawns; k++) {
			saveFile >> boardId;
			saveFile >> coords.X;
			saveFile >> coords.Y;
			saveFile >> type;
			saveFile >> size;
			saveFile >> taken;

			players[i].get_pawn(k)->set_boardId(boardId);
			players[i].get_pawn(k)->set_pawnCoords(coords);
			players[i].get_pawn(k)->set_type(static_cast<PawnType>(type));
			players[i].get_pawn(k)->set_size(static_cast<Size>(size));
			players[i].get_pawn(k)->set_taken(taken);
			players[i].get_usedBoard(boardId)->set_fieldInfo(coords, !taken, static_cast<PawnType>(type), static_cast<Size>(size), i + 1);
		}
		saveFile >> takenPawns;
		players[i].set_takenPawns(taken);
	}
	saveFile >> isAi;
	players[0].set_AI(isAi);
	saveFile >> isAi;
	players[1].set_AI(isAi);
	saveFile >> isAi;
	players[2
	
	].set_AI(isAi);
	saveFile >> whichPlayerTurn;
	players[0].putPawns();
	players[1].putPawns();
	players[2].putPawns();
	saveFile.close();
	return 1;
}

int Game::countPoints(Player& player)
{
	int points = player.get_takenPawns()*pointsForTaking;
	points += pawnsInLastRow(player)*pointsForLastRow;

	return points;
}

int Game::pawnsInLastRow(Player &player)
{
	short lastRow;
	int fieldsVertical = player.get_usedBoard(0)->get_fieldsVertical() - 1;
	int count = 0;
	for (int j = 0; j < 2; j++) {
		if (player.get_moveDirection(j) == up)
			lastRow = 0;
		else
			lastRow = fieldsVertical;
		for (int i = 0; i < numberOfPawns; i++)
		{
			if (player.get_pawn(i)->get_boardId() == j)
				if (player.get_pawn(i)->get_pawnCoords().Y == lastRow && !player.get_pawn(i)->isTaken())
					count++;

		}
	}
	return count;
}

void Game::generatePlayersInfoFile()
{
	fstream plik;

	plik.open("recent game info.txt", ios::trunc | ios::out);
	if (!plik.good())
		return;
	for (int j = 0; j < 3; j++) {
		string type;
		string size;
		plik << "P" << j << " " << endl << "pId " << "   x y    type           size       taken" << endl;
		for (int i = 0; i < 9; i++)
		{
			switch (players[j].get_pawn(i)->get_type())
			{
			case hexagon:
				type = "hexagon";
				break;
			case triangle:
				type = "triangle";
				break;
			case rectangle:
				type = "rectangle";
				break;
			default:
				break;
			}

			switch (players[j].get_pawn(i)->get_size())
			{
			case smaller:
				size = "small";
				break;
			case medium:
				size = "medium";
				break;
			case big:
				size = "big";
				break;
			}
			plik << i + 1 << "      " << players[j].get_pawn(i)->get_pawnCoords().X << " " << players[j].get_pawn(i)->get_pawnCoords().Y << "    " << type << "       " << size << "       ";
			if (players[j].get_pawn(i)->isTaken())
				plik << "true";
			else
				plik << "false";

			plik << endl;
		}
		plik << endl << "taken pawns: " << players[j].get_takenPawns() << ", pawns in last row: " << pawnsInLastRow(players[j]) << endl;
	}
	plik.close();
}

COORD Game::get_gameFieldSize() { return gameFieldSize; }
void Game::set_gameFieldSize(COORD game_field_size) { gameFieldSize = game_field_size; }

Player* Game::get_players() { return players; }

Board* Game::get_playersBoards() { return playersBoards; }

MessageField* Game::get_gameMessageField()
{
	return messageField;
}

int Game::get_whichPlayerTurn()
{
	return whichPlayerTurn;
}
void Game::set_whichPlayerTurn(int playerNumber)
{
	this->whichPlayerTurn = playerNumber;
}

void Game::noSavedGamesMsg()
{

cout<<"                                _____                          _                           "<<endl;
cout<<"                               |   | |___    ___ ___ _ _ ___ _| |   ___ ___ _____ ___ ___  "<<endl;
cout<<"                               | | | | . |  |_ -| .'| | | -_| . |  | . | .'|     | -_|_ -| "<<endl;
cout<<"                               |_|___|___|  |___|__,|\\_/|___|___|  |_  |__,|_|_|_|___|___| "<<endl;
cout<<"                                                                   |___|                    "<<endl;
}

void Game::showControls()
{
	controlsField->writeLine("Controls:");
	controlsField->writeLine("Move cursor - Arrow keys,");
	controlsField->writeLine("Put pawn - Enter");
	controlsField->writeLine("Select field - Enter");
	controlsField->writeLine("Move pawn - Enter ");
	controlsField->writeLine("Cancel selection - B");
	controlsField->writeLine("Quit - Esc ");
	controlsField->writeLine("(works after pawns are put)");


}