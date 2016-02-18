#include <iostream>
#include "elves.h"
#include "potion.h"
//#include "treasure.h"
using namespace std;

elves::elves(int x, int y){
	mhostile=0;
	race="elves";
	hp=140;
	atk=30;
	def=10;
	maxhp=140;
	this->x=x;
	this->y=y;
	gold=0;
	tmpatk=0;
	tmpdef=0;
	alive=1;
	nextfloor=0;
	action="";
}

elves::~elves(){}
