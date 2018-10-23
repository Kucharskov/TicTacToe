#pragma once
#include <utility>

//Rodzaje pól na planszy
enum class Field { EMPTY, CIRCLE, CROSS };

//Rodzaje wyników gry
enum class Result { CIRCLE, CROSS, DRAW, NOWIN };

//Pozycja jako para
using Pos = std::pair<int, int>;