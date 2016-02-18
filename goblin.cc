#include "goblin.h"

goblin::goblin(int x, int y) : enemy(70, 5, 10, "Goblin", x, y) {
	alive=1;
	hostile=1;
}

goblin::~goblin() {}
