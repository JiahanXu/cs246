#include <iostream>
#include "character.h"
#include "floor.h"
using namespace std;

void character::setfloor(floor* f){
	this->f=f;
}

int character::getx(){
	return this->x;
}

int character::gety(){
	return this->y;
}

void character::setx(int x){
	this->x=x;
}

void character::sety(int y){
	this->y=y;
}

//character::character(){}

character::~character(){}
