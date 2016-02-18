#include "phoenix.h"

phoenix::phoenix(int x, int y) : enemy(50, 35, 20, "Phoenix", x, y) {
	alive=1;
	hostile=1;
}

phoenix::~phoenix() {}
