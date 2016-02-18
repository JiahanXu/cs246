#include "treasure.h"
#include <string>

using namespace std;

treasure::treasure(int x, int y, int type){
	mydragon=NULL;
	this->x=x;
	this->y=y;
	this->type=type;
	exist=true;
	pick=1;
}

treasure::~treasure(){}
