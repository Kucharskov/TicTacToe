#include "Game.h"

Game::Game(Field f) : _lastPlayer(f) {
}

bool Game::move(Pos p) {
	if (!_board.isLegalPos(p) || !_board.isEmpty(p)) return false;

	_board.set(p, getLastPlayer());
	return true;
}

void Game::alternatePlayer() {
	_lastPlayer = (_lastPlayer == Field::CIRCLE) ? Field::CROSS : Field::CIRCLE;
}

Field Game::getField(Pos p) const {
	return _board.get(p);
}

Result Game::checkWin() const {
	for (int i = 0; i < 3; i++) {
		if (!_board.isEmpty({ 0, i }))
			if (_board.get({ 0, i }) == _board.get({ 1, i }) && _board.get({ 1, i }) == _board.get({ 2, i }))
				return (_board.get({ 0, i }) == Field::CIRCLE) ? Result::CIRCLE : Result::CROSS;
		if (!_board.isEmpty({ i, 0 }))
			if (_board.get({ i, 0 }) == _board.get({ i, 1 }) && _board.get({ i, 1 }) == _board.get({ i, 2 }))
				return (_board.get({ i, 0 }) == Field::CIRCLE) ? Result::CIRCLE : Result::CROSS;
	}

	if (!_board.isEmpty({ 1, 1 })) {
		if (_board.get({ 0, 0 }) == _board.get({ 1, 1 }) && _board.get({ 1,1 }) == _board.get({ 2, 2 }))
			return (_board.get({ 1, 1 }) == Field::CIRCLE) ? Result::CIRCLE : Result::CROSS;

		if (_board.get({ 2, 0 }) == _board.get({ 1, 1 }) && _board.get({ 1,1 }) == _board.get({ 0, 2 }))
			return (_board.get({ 1, 1 }) == Field::CIRCLE) ? Result::CIRCLE : Result::CROSS;
	}

	int empty = 0;
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (_board.isEmpty({ x, y })) empty++;

	return (empty == 0) ? Result::DRAW : Result::NOWIN;
}

void Game::draw() {
	std::cout << " 0|1|2\n";
	for (int y = 0; y < 3; y++) {
		std::cout << y;
		for (int x = 0; x < 3; x++) {
			switch (_board.get({ x, y })) {
			case Field::EMPTY:
				std::cout << " ";
				break;
			case Field::CIRCLE:
				std::cout << "O";
				break;
			case Field::CROSS:
				std::cout << "X";
				break;
			}
			if (x < 2) std::cout << "|";
		}
		std::cout << std::endl;
		if (y < 2) std::cout << " -----" << std::endl;
	}
}
