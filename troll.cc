#include "troll.h"

troll::troll(int x, int y) : enemy(120, 25, 15, "Troll", x, y) {
	alive=1;
	hostile=1;
}

troll::~troll() {}
