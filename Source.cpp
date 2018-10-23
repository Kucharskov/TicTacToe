#include <iostream>
#include "Game.h"

Game g;

int main() {
	bool err(false);
	do {
		system("CLS");
		g.draw();

		if (err) std::cout << std::endl << "Pozycja juz zajeta!";

		int pos;
		std::cout << std::endl << "Podaj pozycje: ";
		std::cin >> pos;
		if (g.move({ pos / 10, pos % 10 })) {
			g.alternatePlayer();
			err = false;
		}
		else err = true;

		system("PAUSE");
	} while (g.checkWin() == Result::NOWIN);

	system("CLS");
	g.draw();
	switch (g.checkWin())
	{
	case Result::CIRCLE:
		std::cout << "Wygraly Kolka!\n";
		break;
	case Result::CROSS:
		std::cout << "Wygraly Krzyzyki!\n";
		break;
	case Result::DRAW:
		std::cout << "Remis!\n";
		break;
	}
	system("PAUSE");

	return 0;
}