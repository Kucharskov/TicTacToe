#pragma once
#include <stdexcept>
#include "Aliases.h"
#include "Board.h"

#include <iostream>

class Game {
private:
	Board _board;
	Field _lastPlayer;

public:
	Game(Field = Field::CIRCLE);

	bool move(Pos);
	void alternatePlayer();

	Field getField(Pos) const;
	Field getLastPlayer() const { return _lastPlayer; };
	Result checkWin() const; 

	void draw(); //Deprecated
};

