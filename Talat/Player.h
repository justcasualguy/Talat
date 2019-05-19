#pragma once
#include "Board.h"
#include "Cursor.h"
#include "Board.h"
#include <iostream>
#include "Pawn.h"
#include "TrianglePawn.h"
#include "RectanglePawn.h"
#include "HexagonPawn.h"
#include <cstdlib>
#include <ctime>
#include "MessageField.h"
#include "Controls.h"
#include"Menu.h"
using namespace std;
struct SelectedField
{
	int boardId;
	COORD coords;
	bool operator==(const SelectedField &s) {
		if (boardId == s.boardId&&coords.X == s.coords.X&&coords.Y == s.coords.Y)
			return true;
		return false;
	}
	bool operator!=(const SelectedField &s) {
		if (boardId == s.boardId&&coords.X == s.coords.X&&coords.Y == s.coords.Y)
			return false;
		return true;
	}
};

struct PawnField
{
	int boardId;
	COORD coords;
	bool isTaken = false;
};


enum MoveDirection { down, up };

class Player {
	Board*  usedBoards[2];
	Color playerColor;
	Pawn** pawns;
	Pawn** allPawns[3]; // holds information about all pawns in game neccessary for bugfixing
	short startingRow[2];  //startingRow[i] refers to usedBoards[i]
	int number; //playernumber
	MoveDirection moveDirection[2];//moveDirection[i] reffers to startingRow[i]
	MessageField *messageField;  //for printing messages in game
	int takenPawns; 
	bool AI; // true if players is controlled by computer

public:
	Player();
	~Player();
	Color get_playerColor();
	void set_playerColor(Color player_color);

	

	int makeMove();
	bool makeRandomMove();
	bool isTakingPossible(SelectedField& field);
	SelectedField lookForTaking(SelectedField& pawnField); //checks if any taking move is possible from selected field
	void putPawn(Pawn& pawn, int pawnId);
	void putPawns(); // used in loading previous game
	void putPawnRandom(Pawn& pawn, int pawnId);
	bool isMovePossible(SelectedField& startinPos, SelectedField& destination); //checks if move made is possible
	bool isAnyMovePossible(SelectedField& startingPos); //checks if there is any possible move from field
	bool hasPossibleMove();	//checks if player has any possible move
	void updateTakenPawns();	//updates 
	void movePawn(SelectedField& startinPos, SelectedField& destination);


	Board* get_usedBoards();
	void set_usedBoards(Board &board, int boardId);
	void set_usedBoards(Board* board, int boardId);

	short* get_startingRow();
	void set_startingRow(short startingRow, int boardId);

	Pawn* get_pawn(int pawnId);
	Pawn** get_pawns();
	Board* get_usedBoard(int boardId);

	void set_number(int number);
	int get_number();

	void set_moveDirection(MoveDirection moveDirection, int boardId);
	void set_messageField(MessageField* messageField);

	MessageField* get_messageField();
	MoveDirection get_moveDirection(int boardId);

	int get_points();
	void set_points(int points);

	void set_AI(bool AI);
	bool isAI();

	void set_takenPawns(int taken);
	int get_takenPawns();
	void pawnTaken();

	Pawn*** get_allPawns();
	Pawn** get_pawns(int playerId);
	void set_allPawns(Pawn** pawns, int id);
	


};
