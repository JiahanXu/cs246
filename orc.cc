#include <iostream>
#include "orc.h"

using namespace std;

orc::orc(int x, int y){
	mhostile=0;
	race="orc";
	hp=180;
	atk=30;
	def=25;
	maxhp=180;
	this->x=x;
	this->y=y;
	gold=0;
	tmpatk=0;
	tmpdef=0;
	alive=1;
	nextfloor=0;
	action="";
}

orc::~orc(){}
