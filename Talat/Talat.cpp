// Szablon PO projekt.cpp : Ten plik zawiera funkcję „mb.hain”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Board.h"
#include "Board.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Game.h"
#include "Common.h"
#include "Menu.h"
using namespace std;



int main()
{


	Game game;
	char choice;
	Menu m;
	bool loadingFail = false, gameLoaded = false;;
	bool gameFinished = false;
	string takenPawns;
	string lastRow;
	string points;

	Player *player1 = &game.get_players()[0];
	Player *player2 = &game.get_players()[1];
	Player *player3 = &game.get_players()[2];

	player1->set_playerColor(RED);
	player2->set_playerColor(YELLOW);
	player3->set_playerColor(DARKCYAN);

	srand(time(NULL));


	while (1) {
		if (!loadingFail)
			m.showMainMenu();
		else
		{
			m.showMainMenu();
			game.noSavedGamesMsg();
		}
		choice = m.makeChoice(3);

		if (choice == '1') {
			m.showPlayersChoiceMenu();
			choice = m.makeChoice(4);
			if (choice == '1') {
				player2->set_AI(true);
				player3->set_AI(true);

			}
			if (choice == '2')
			{
				player3->set_AI(true);

			}
			if (choice == '4')
				continue;
			game.drawBoards();
			game.showControls();
			for (int i = 0; i < 9; i++) {
				if (!player1->isAI())
					player1->putPawn(*player1->get_pawn(i), i);
				else
					player1->putPawnRandom(*player1->get_pawn(i), i);
				if (!player2->isAI())
					player2->putPawn(*player2->get_pawn(i), i);
				else
					player2->putPawnRandom(*player2->get_pawn(i), i);
				if (!player3->isAI())
					player3->putPawn(*player3->get_pawn(i), i);
				else
					player3->putPawnRandom(*player3->get_pawn(i), i);
			}

			break;
		}
		if (choice == '2') {
			if (!game.loadGame()) {
				loadingFail = true;
			}
			else {
				gameLoaded = true;
				break;
			}
		}
		else
			return 0;

	}

	if (gameLoaded)
		game.showControls();
	game.drawBoards();


	while (1) {
		if (!
			(player1->hasPossibleMove() && player2->hasPossibleMove() && player3->hasPossibleMove())) {
			gameFinished = true;
			break;
		}
		if (!game.turn())
			break;


	}
	if (gameFinished) {

		takenPawns = "Taken pawns: " + to_string(player1->get_takenPawns());
		lastRow = "Pawns in last row: " + to_string(game.pawnsInLastRow(*player1));
		points = "Points: " + to_string(game.countPoints(*player1));
		game.get_gameMessageField()->writeLine("Player 1 ");
		game.get_gameMessageField()->writeLine(takenPawns);
		game.get_gameMessageField()->writeLine(lastRow);
		game.get_gameMessageField()->writeLine(points);
		game.get_gameMessageField()->writeLine("");

		takenPawns = "Taken pawns: " + to_string(player2->get_takenPawns());
		lastRow = "Pawns in last row: " + to_string(game.pawnsInLastRow(*player2));
		points = "Points: " + to_string(game.countPoints(*player2));
		game.get_gameMessageField()->writeLine("Player 2 ");
		game.get_gameMessageField()->writeLine(takenPawns);
		game.get_gameMessageField()->writeLine(lastRow);
		game.get_gameMessageField()->writeLine(points);
		game.get_gameMessageField()->writeLine("");

		takenPawns = "Taken pawns: " + to_string(player3->get_takenPawns());
		lastRow = "Pawns in last row: " + to_string(game.pawnsInLastRow(*player3));
		points = "Points: " + to_string(game.countPoints(*player3));
		game.get_gameMessageField()->writeLine("Player 3 ");
		game.get_gameMessageField()->writeLine(takenPawns);
		game.get_gameMessageField()->writeLine(lastRow);
		game.get_gameMessageField()->writeLine(points);
		game.get_gameMessageField()->writeLine("");

		if (game.countPoints(*player1) > game.countPoints(*player2) && game.countPoints(*player1) > game.countPoints(*player3))
			game.get_gameMessageField()->writeLine("Player 1 wins! ");
		else if (game.countPoints(*player2) > game.countPoints(*player1) && game.countPoints(*player2) > game.countPoints(*player3))
			game.get_gameMessageField()->writeLine("Player 2 wins! ");
		else
			game.get_gameMessageField()->writeLine("Player 3 wins! ");
	}
	game.generatePlayersInfoFile();
	if (gameFinished)
		getchar();



}


