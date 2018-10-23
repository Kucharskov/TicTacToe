#pragma once
#include "Aliases.h"
#include <array>

class Board {
private:
	std::array<Field, 9> _fields;
	int getIndex(Pos) const;

public:
	Board();

	void clear();
	void set(Pos, Field);

	bool isEmpty(Pos) const;
	bool isLegalPos(Pos) const;
	Field get(Pos) const;
};

