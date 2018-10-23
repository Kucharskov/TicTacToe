#include "Board.h"

Board::Board() {
	clear();
}

int Board::getIndex(Pos p) const {
	return p.first + p.second * 3;
}

void Board::clear() {
	for (int i = 0; i < 9; i++)
		_fields[i] = Field::EMPTY;
}

void Board::set(Pos p, Field f) {
	_fields[getIndex(p)] = f;
}

bool Board::isEmpty(Pos p) const {
	return (_fields[getIndex(p)] == Field::EMPTY);
}

bool Board::isLegalPos(Pos p) const {
	if (p.first < 0 || p.first >= 3 || p.second < 0 || p.second >= 3) return false;
	return true;
}

Field Board::get(Pos p) const {
	return _fields[getIndex(p)];
}
