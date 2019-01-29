#pragma once
#include "Aliases.h"
#include "Board.h"

#include <iostream>

class Game {
private:
	Board _board;
	Field _actualPlayer;

public:
	Game(Field = Field::CIRCLE);

	bool move(Pos);
	void alternatePlayer();

	Field getField(Pos) const;
	Field getActualPlayer() const { return _actualPlayer; };
	Result checkWin() const; 

	void draw(); //Deprecated
};

