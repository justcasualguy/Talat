#include "pch.h"
#include "Player.h"




Player::Player():playerColor(BLUE),messageField(NULL),takenPawns(0)
{
	//nie dzia³a jak powinno
	pawns = new Pawn*[numberOfPawns];
	
	pawns[0] = new TrianglePawn(smaller);
	pawns[1] = new TrianglePawn(medium);
	pawns[2] = new TrianglePawn(big);

	pawns[3] = new RectanglePawn(smaller);
	pawns[4] = new RectanglePawn(medium);
	pawns[5] = new RectanglePawn(big);

	pawns[6] = new HexagonPawn(smaller);
	pawns[7] = new HexagonPawn(medium);
	pawns[8] = new HexagonPawn(big);

	

	startingRow[0] = 0;
	startingRow[1] = 0;

	allPawns[0] = NULL;
	allPawns[1] = NULL;
	allPawns[2] = NULL;
	/*
	hexagonPawns = new HexagonPawn*[numberOfPawns / 3];
	squarePawns = new RectanglePawn*[numberOfPawns / 3];
	trianglePawns = new TrianglePawn*[numberOfPawns / 3];

	hexagonPawns[0] = new HexagonPawn(smaller);
	*/
}


Player::~Player()
{
	for(int i=0;i<numberOfPawns;i++)
	{
		delete pawns[i];
	}
	delete[] pawns;
	
	//allPawns = NULL;
}





int Player::makeMove()
{
	char keyPressed;
	bool keyRegistered = false; //for fixing _getwch() inconsistency
	bool confirmed = false;     //for back button functionality
	int boardId = 0;
	Cursor cursor({ 0,startingRow[boardId] });
	SelectedField pawnField;
	SelectedField destination={-1,-1};

	string playerTurnMsg = "Player " + to_string(number) + " turn";
	
	messageField->writeLine(playerTurnMsg);
	messageField->writeLine("Choose pawn");
	
	cursor.set_cursorColor(playerColor);
	cursor.draw(*usedBoards[boardId], cursor.get_position());
	usedBoards[boardId]->draw();

	while (1) {
		keyRegistered = false;
		cursor.clear(*usedBoards[boardId], cursor.get_position());
		
		if (confirmed)
			cursor.draw(*usedBoards[pawnField.boardId], pawnField.coords, playerColor);
		keyPressed = _getwch();

		if (keyPressed == CONFIRM) {
			
			if(confirmed==false)
			{
				if (!usedBoards[boardId]->get_fieldInfo(cursor.get_position()).isOccupied()) {
					messageField->writeLine("Choose pawn,please...");
					continue;
				}
				if (usedBoards[boardId]->get_fieldInfo(cursor.get_position()).get_playerNumber() != number) {
					messageField->writeLine("Choose YOUR pawn!");
					continue;
				}
				messageField->writeLine("Choose field to move");
				confirmed = true;
				cursor.draw(*usedBoards[boardId], cursor.get_position());
				usedBoards[boardId]->draw();
				pawnField.boardId = boardId;
				pawnField.coords = cursor.get_position();
				continue;
			}
			destination.boardId = boardId;
			destination.coords = cursor.get_position();
			if (isMovePossible(pawnField, destination)) {
				
				movePawn(pawnField, destination);
				cursor.clear(*usedBoards[boardId], pawnField.coords);
				usedBoards[boardId]->draw();
				return 0;
			}
			messageField->writeLine("Incorrect move");
			continue;
			
		}
	
		if(keyPressed==BACK)
	{
		if (confirmed) {
			cursor.clear(*usedBoards[pawnField.boardId], pawnField.coords);
			cursor.draw(*usedBoards[boardId], cursor.get_position(),playerColor);
			usedBoards[boardId]->draw();
			confirmed = false;
			continue;
		}
		
		
	}
		if (keyPressed == QUIT)
		{
			messageField->writeLine("Do you want to save game? ");
			messageField->writeLine("1.Yes 2.No 3.Keep playing");
			int choice = Menu::makeChoiceNoCls(3);
			if (choice == '1')
				return 1;
			if (choice == '3') {
				messageField->clear();
				messageField->writeLine(playerTurnMsg);
				
			}
			else
				return -1;
		}
	 if (keyPressed == KEY_RIGHT) {			
		 keyRegistered = true;
			 cursor.changePositionX(1);
			 if (cursor.get_position().X > cursor.get_fieldsHorizontal() - 1)
			 {
				 cursor.clear(*usedBoards[boardId], { (short)cursor.get_fieldsHorizontal() - 1 ,cursor.get_position().Y });
				  if (confirmed)
					 cursor.draw(*usedBoards[pawnField.boardId], pawnField.coords, playerColor);
				 usedBoards[boardId]->draw();
				 
			 	if (boardId == 0)
					 boardId = 1;
				 else
					 boardId = 0;

				 cursor.set_positionX(0);

			 
		 }
		}
	 else if (keyPressed == KEY_LEFT) {
		 
		 keyRegistered = true;
			 cursor.changePositionX(-1);
			 if (cursor.get_position().X < 0)
			 {
				 cursor.clear(*usedBoards[boardId], { (short)cursor.get_fieldsHorizontal() - 1 ,cursor.get_position().Y });
				 
			 	if (confirmed)
					 cursor.draw(*usedBoards[pawnField.boardId], pawnField.coords, playerColor);
				usedBoards[boardId]->draw();

				 if (boardId == 0)
					 boardId = 1;

				 else
					 boardId = 0;
				 cursor.set_positionX(cursor.get_fieldsHorizontal() - 1);
			 
		 }
	 }
		else if (keyPressed == KEY_DOWN) {
		 keyRegistered = true;
		 
			 cursor.changePositionY(1);
			 if (cursor.get_position().Y > cursor.get_fieldsVertical() - 1)
				 cursor.set_positionY(0);
		 
		}
		else if (keyPressed == KEY_UP) {
		 keyRegistered = true;
		 
			 cursor.changePositionY(-1);
			 if (cursor.get_position().Y < 0)
				 cursor.set_positionY(cursor.get_fieldsVertical() - 1);
		 
		}
	 if (keyRegistered) {
		 if (confirmed)
			 cursor.draw(*usedBoards[pawnField.boardId], pawnField.coords, playerColor);
		 cursor.draw(*usedBoards[boardId], cursor.get_position());
		 usedBoards[boardId]->draw();
	 }
		}
		
	}


void Player::putPawn(Pawn& pawn,int pawnId)
{
	char keyPressed;
	Cursor cursor;
	int boardId = 0;

	cursor.set_cursorColor(playerColor);

	if (usedBoards[boardId]->hasEmptyField(startingRow[boardId])) {
		cursor.set_position(usedBoards[boardId]->findEmptyField(startingRow[boardId]));
	
	}
	else {
		boardId = 1;
		cursor.set_position(usedBoards[boardId]->findEmptyField(startingRow[boardId]));
	}
	
	
	cursor.draw(*usedBoards[boardId], cursor.get_position());
	pawn.draw(*usedBoards[boardId], cursor.get_position(), playerColor);
	usedBoards[boardId]->draw();

	while (1) {
		cursor.clear(*usedBoards[boardId], cursor.get_position());
		pawn.draw(*usedBoards[boardId], cursor.get_position(), BLACK);
		keyPressed = _getwch();

		switch (keyPressed)
		{
		case KEY_LEFT:
			cursor.changePositionX(-1);
			break;
		case KEY_RIGHT:
			cursor.changePositionX(1);
			break;
		default:
			break;

		}

		if (keyPressed == CONFIRM)
		{
			pawn.draw(*usedBoards[boardId], cursor.get_position(), playerColor);
			usedBoards[boardId]->get_fieldsInfo(cursor.get_position())->set_occupied(true);
			cursor.clear(*usedBoards[boardId], cursor.get_position());
			usedBoards[boardId]->draw();
			usedBoards[boardId]->set_fieldInfo(cursor.get_position(), true, pawn.get_type(), pawn.get_size(), number);
			pawn.set_pawnCoords(cursor.get_position());
			pawn.set_boardId(boardId);
			
			return;
		}
		

 		if ( keyPressed == KEY_LEFT || keyPressed == KEY_RIGHT|| keyPressed == KEY_UP|| keyPressed == KEY_DOWN) {			//neccesssary to fix _getwch() issue
			
			while (1) {
				if (cursor.get_position().X > cursor.get_fieldsHorizontal() - 1)
				{
					cursor.clear(*usedBoards[boardId], { (short)cursor.get_fieldsHorizontal() - 1 ,cursor.get_position().Y });
					usedBoards[boardId]->draw();

					if (boardId == 0)
						boardId = 1;
					else
						boardId = 0;

					cursor.set_position(usedBoards[boardId]->findEmptyField(startingRow[boardId]));
			


				}
				else if (cursor.get_position().X < 0)
				{
					cursor.clear(*usedBoards[boardId], { (short)cursor.get_fieldsHorizontal() - 1 ,cursor.get_position().Y });
					usedBoards[boardId]->draw();

					if (boardId == 0)
						boardId = 1;

					else
						boardId = 0;
					cursor.set_position(usedBoards[boardId]->findEmptyFieldRight(startingRow[boardId]));
					
				}
				if (usedBoards[boardId]->get_fieldInfo(cursor.get_position()).isOccupied())
				{
					if (keyPressed == KEY_LEFT)
						cursor.changePositionX(-1);
					else if (keyPressed == KEY_RIGHT)
						cursor.changePositionX(1);
				}
				else
					break;
			}
			cursor.draw(*usedBoards[boardId], cursor.get_position());
			 pawn.draw(*usedBoards[boardId], cursor.get_position(), playerColor);
			usedBoards[boardId]->draw();
			
		}
		
	}
	
}

void Player::putPawns()
{
	for (int i = 0; i < numberOfPawns; i++) 
		if(!pawns[i]->isTaken())
			pawns[i]->draw(*usedBoards[pawns[i]->get_boardId()], pawns[i]->get_pawnCoords(), playerColor);
	
}

void Player::putPawnRandom(Pawn& pawn, int pawnId)
{
	
	short posX;
	int boardId = 0;
	
	do
	{
		posX = rand() % 5;
		boardId = rand() % 2;
	} while ( usedBoards[boardId]->get_fieldInfo({ posX,startingRow[boardId] }).isOccupied());

	pawn.draw(*usedBoards[boardId], { posX,startingRow[boardId] }, playerColor);
	pawn.set_pawnCoords({ posX, startingRow[boardId] });
	pawn.set_boardId(boardId);
	usedBoards[boardId]->set_fieldInfo({ posX,startingRow[boardId] }, true, pawn.get_type(), pawn.get_size(), number);
	usedBoards[boardId]->draw();

}

bool Player::isMovePossible(SelectedField& startingPos, SelectedField& destination)
{
	FieldInfo start = usedBoards[startingPos.boardId]->get_fieldInfo(startingPos.coords);//info of startingPos field
	FieldInfo dest = usedBoards[destination.boardId]->get_fieldInfo(destination.coords);
	if (startingPos.boardId != destination.boardId)
		return false;
	if (abs(startingPos.coords.X - destination.coords.X) > 1 ||
		abs(startingPos.coords.Y - destination.coords.Y) > 1)
		return false;
	if (destination.coords.X > usedBoards[0]->get_fieldsHorizontal() - 1 || destination.coords.Y > usedBoards[0]->get_fieldsVertical() - 1 ||
		destination.coords.X < 0 || destination.coords.Y < 0)
		return false;

	if ((destination.coords.X == startingPos.coords.X + 1 || destination.coords.X == startingPos.coords.X - 1)&&
		destination.coords.Y == startingPos.coords.Y) //move right
		if (!dest.isOccupied()) // you can move right or left only if theres enemy pawn
			return false;
	if (moveDirection[startingPos.boardId] == up) {
		if (destination.coords.Y > startingPos.coords.Y )
				return false;
		}
	if (moveDirection[startingPos.boardId] == down) {
		if (destination.coords.Y < startingPos.coords.Y )
			return false;
	}

	if (dest.isOccupied()) {
		if (start.get_playerNumber() == dest.get_playerNumber()) //check if it's same player's pawn
			return false;
		if (start.get_pawnType() - dest.get_pawnType() == 1) //pawn type rule
			return true;
		if (start.get_pawnType() == dest.get_pawnType()) { //size rule
			if (start.get_pawnSize() > dest.get_pawnSize())
				return true;
		}
		if (start.get_pawnType() == triangle && start.get_pawnSize() == smaller)//Goliath rule
			if (dest.get_pawnType() == hexagon && dest.get_pawnSize() == big)
				return true;
		return false;
	}

	return true;
	
}

bool Player::isAnyMovePossible(SelectedField &startingPos) 
{	
		
	SelectedField dest[5];
	bool isPossible = false;
	
	dest[0] = { startingPos.boardId, {startingPos.coords.X + 1,startingPos.coords.Y} };
	dest[1] = { startingPos.boardId, {startingPos.coords.X - 1,startingPos.coords.Y} };
	
	if (moveDirection[startingPos.boardId] == up) {
		dest[2] = { startingPos.boardId, {startingPos.coords.X - 1,startingPos.coords.Y - 1} };
		dest[3] = { startingPos.boardId, {startingPos.coords.X ,startingPos.coords.Y - 1} };
		dest[4] = { startingPos.boardId, {startingPos.coords.X + 1,startingPos.coords.Y - 1} };
	}
	else {
		dest[2] = { startingPos.boardId, {startingPos.coords.X - 1,startingPos.coords.Y + 1} };
		dest[3] = { startingPos.boardId, {startingPos.coords.X ,startingPos.coords.Y + 1} };
		dest[4] = { startingPos.boardId, {startingPos.coords.X + 1,startingPos.coords.Y + 1} };
	}
	for (int i = 0; i < 5; i++) {
		if (isMovePossible(startingPos, dest[i])) {
			isPossible = true;
			break;

		}
	}
	return isPossible;
	}

bool Player::hasPossibleMove()
{
	SelectedField field;
	string msg;
	for (int i = 0; i < 2; i++) {
		field.boardId = i;
		for (int j = 0; j < numberOfPawns; j++)
		{
			if (pawns[j]->get_boardId() == field.boardId) {
				if (pawns[j]->isTaken())
					continue;
				field.coords = pawns[j]->get_pawnCoords();
				if (isAnyMovePossible(field))
					return true;
			}
		}
		
	}
	msg = "Player " + to_string(number) + " has no moves left";
	messageField->writeLine(msg);
	messageField->writeLine("");
	
	return false;
}

void Player::updateTakenPawns()
{
	for(int i=0;i<numberOfPawns;i++)
	{
		if (usedBoards[pawns[i]->get_boardId()]->get_fieldInfo(pawns[i]->get_pawnCoords()).get_playerNumber() != number&&
			usedBoards[pawns[i]->get_boardId()]->get_fieldInfo(pawns[i]->get_pawnCoords()).isOccupied())
			pawns[i]->set_taken(true);
	}
}

void Player::movePawn(SelectedField &startingPos,SelectedField &destination)
{
	FieldInfo* start = &usedBoards[startingPos.boardId]->get_fieldInfo(startingPos.coords);//info of startingPos field
	FieldInfo* dest = &usedBoards[destination.boardId]->get_fieldInfo(destination.coords);
	Pawn *p;
	if (start->get_pawnType() == triangle)
		p = new TrianglePawn(start->get_pawnSize());
	else if (start->get_pawnType() == rectangle)
		p = new RectanglePawn(start->get_pawnSize());
	else
		p = new HexagonPawn(start->get_pawnSize());
	if (dest->isOccupied()) {
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < numberOfPawns; i++)
			{
				if (allPawns[j][i]->get_type() == dest->get_pawnType() &&
					allPawns[j][i]->get_size() == dest->get_pawnSize() &&
					allPawns[j][i]->get_pawnCoords().X == dest->get_coords().X &&
					allPawns[j][i]->get_pawnCoords().Y == dest->get_coords().Y&&
					allPawns[j][i]->get_boardId()==destination.boardId) {
					allPawns[j][i]->set_taken(true);
					break;
					}
			}
			
		}
		takenPawns++;
	}
		
		
	
	for (int j = 0; j < numberOfPawns; j++)
	{
		if (pawns[j]->get_boardId() == startingPos.boardId&&pawns[j]->get_pawnCoords().X == startingPos.coords.X&&		//look for selected pawn in player->pawns and change its values
			pawns[j]->get_pawnCoords().Y == startingPos.coords.Y){
			pawns[j]->set_pawnCoords(destination.coords);
			break;
		}
	}
	
	usedBoards[destination.boardId]->set_fieldInfo(destination.coords,true, start->get_pawnType(), start->get_pawnSize(), start->get_playerNumber());
	usedBoards[startingPos.boardId]->set_fieldInfo(startingPos.coords, false, start->get_pawnType(), start->get_pawnSize(), start->get_playerNumber());

	p->draw(*usedBoards[startingPos.boardId], startingPos.coords, BLACK);// clear pawn from previous field
	p->draw(*usedBoards[destination.boardId], destination.coords, playerColor);
	delete p;
}

bool Player::isTakingPossible(SelectedField &destination)
{
	if (usedBoards[destination.boardId]->get_fieldInfo(destination.coords).isOccupied())
		return true;
	return false;
	
}

SelectedField Player::lookForTaking(SelectedField& pawnField)
{
	SelectedField dest[5];
	SelectedField takingField;
	dest[0] = { pawnField.boardId, {pawnField.coords.X + 1,pawnField.coords.Y} };
	dest[1] = { pawnField.boardId, {pawnField.coords.X - 1,pawnField.coords.Y} };

	if (moveDirection[pawnField.boardId] == up) {
		dest[2] = { pawnField.boardId, {pawnField.coords.X - 1,pawnField.coords.Y - 1} };
		dest[3] = { pawnField.boardId, {pawnField.coords.X ,pawnField.coords.Y - 1} };
		dest[4] = { pawnField.boardId, {pawnField.coords.X + 1,pawnField.coords.Y - 1} };
	}
	else {
		dest[2] = { pawnField.boardId, {pawnField.coords.X - 1,pawnField.coords.Y + 1} };
		dest[3] = { pawnField.boardId, {pawnField.coords.X ,pawnField.coords.Y + 1} };
		dest[4] = { pawnField.boardId, {pawnField.coords.X + 1,pawnField.coords.Y + 1} };
	}
	for (int i = 0; i < 5; i++) {
		if (isMovePossible(pawnField, dest[i])) {
			if (isTakingPossible(dest[i])) 
				return dest[i];
			
		}
		
	}
	return pawnField;
}

bool Player::makeRandomMove()
{
	SelectedField start;
	SelectedField dest;
	Cursor cursor;
	int tries = 0;
	int pawn=0;
	SelectedField take;	//used to search for possible taking field
	while (1) {
			
		do
		{
			if (!hasPossibleMove())
				return false;
			do {
				pawn = rand() % 9;
			} while (pawns[pawn]->isTaken());
				
			start.boardId = pawns[pawn]->get_boardId();
			start.coords = pawns[pawn]->get_pawnCoords();
			take = lookForTaking(start);
			if (take != start) {
				dest = take;
				break;
			}


			dest.boardId = start.boardId;
			do {
				dest.coords.X = start.coords.X - 1 + rand() % 3;
			} while (dest.coords.X < 0 || dest.coords.X >= usedBoards[0]->get_fieldsHorizontal());
			do {
				if (moveDirection[start.boardId] == up)
					dest.coords.Y = start.coords.Y - rand() % 2;
				else
					dest.coords.Y = start.coords.Y + rand() % 2;

			} while (dest.coords.Y < 0 || dest.coords.Y >= usedBoards[0]->get_fieldsVertical());
			tries++;
			if (tries > 10) {
				break;
			}

		} while (!isMovePossible(start, dest));
		if (tries > 10) {
			tries = 0;
			continue;
		}
		break;
	}
	movePawn(start, dest);
	
	usedBoards[start.boardId]->draw();
	return true;
}

Color Player::get_playerColor() { return playerColor; }

void Player::set_playerColor(Color player_color)
{
	for (int i = 0; i < numberOfPawns; i++)
	{
		pawns[i]->set_color(playerColor);
	}
	playerColor = player_color;
}

Board* Player::get_usedBoards() { return *usedBoards; }

void Player::set_usedBoards(Board& board, int boardId)
{
	usedBoards[boardId] = &board;
}

void Player::set_usedBoards(Board *board, int boardId)
{
	usedBoards[boardId] = board;
}

short* Player::get_startingRow()
{
	return startingRow;
}

void Player::set_startingRow(short startingRow,int boardId)
{
	this->startingRow[boardId] = startingRow;
}

Pawn* Player::get_pawn(int pawnId)
{
	return pawns[pawnId];
}

Board* Player::get_usedBoard(int boardId)
{
	return usedBoards[boardId];
}

void Player::set_number(int number)
{
	this->number = number;
}

int Player::get_number() { return number; }

MoveDirection Player::get_moveDirection(int boardId)
{
	return moveDirection[boardId];
}

void Player::set_moveDirection(MoveDirection moveDirection,int boardId)
{
	this->moveDirection[boardId] = moveDirection;
}

void Player::set_messageField(MessageField* messageField)
{
	this->messageField = messageField;
}

MessageField* Player::get_messageField() { return messageField; }

bool Player::isAI()
{
	return AI;
}

void Player::set_AI(bool AI)
{
	this->AI = AI;
}



int Player::get_takenPawns()
{
	return takenPawns;
}

void Player::pawnTaken()
{
	takenPawns++;
}

void Player::set_takenPawns(int taken)
{
	takenPawns = taken;
}

Pawn*** Player::get_allPawns()
{
	return allPawns;
}

Pawn** Player::get_pawns(int playerId)
{
	return allPawns[playerId];
}

void Player::set_allPawns(Pawn** pawns, int id)
{
	allPawns[id] = pawns;
}





Pawn** Player::get_pawns()
{
	return pawns;
}