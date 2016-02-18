#include <iostream>
#include "human.h"
using namespace std;

human::human(int x, int y){
	mhostile=0;
	race="human";
	hp=140;
	atk=20;
	def=20;
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
human::~human(){}
