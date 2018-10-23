#pragma once
#include <utility>

//Rodzaje p�l na planszy
enum class Field { EMPTY, CIRCLE, CROSS };

//Rodzaje wynik�w gry
enum class Result { CIRCLE, CROSS, DRAW, NOWIN };

//Pozycja jako para
using Pos = std::pair<int, int>;