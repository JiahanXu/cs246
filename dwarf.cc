#include <iostream>
#include "dwarf.h"

using namespace std;

dwarf::dwarf(int x, int y){
	mhostile=0;
	race="Dwarf";
	hp=100;
	atk=20;
	def=30;
	maxhp=100;
	this->x=x;
	this->y=y;
	gold=0;
	tmpatk=0;
	tmpdef=0;
	alive=1;
	nextfloor=0;
	action="";
}
dwarf::~dwarf(){}
