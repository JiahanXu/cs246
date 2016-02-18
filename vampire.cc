#include "vampire.h"

vampire::vampire(int x, int y):enemy(50,25,25,"Vampire", x, y){
	alive=1;
	hostile=1;
}

vampire::~vampire(){}
