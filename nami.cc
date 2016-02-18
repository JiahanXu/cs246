#include "nami.h"
#include <iostream>

nami::nami(int x, int y){
	mhostile=0;
	race="nami";
	hp=150;
	atk=30;
	def=25;
	maxhp=150;
	this->x=x;
	this->y=y;
	gold=0;
	tmpatk=0;
	tmpdef=0;
	alive=1;
	nextfloor=0;
	action="";
}

nami::~nami() {}
