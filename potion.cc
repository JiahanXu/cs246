#include "potion.h"
#include <string>

using namespace std;

potion::potion(int x, int y, string str){
	this->x=x;
	this->y=y;
	type=str;
	exist=1;
}

potion::~potion(){}
