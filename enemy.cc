#include <iostream>
#include <string>
#include "enemy.h"
#include "floor.h"
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;

enemy::enemy(int hp, int atk, int def, string race, int x, int y){
	this->x=x;
	this->y=y;
	this->hp=hp;
	this->atk=atk;
	this->def=def;
	this->race=race;
	movebit=1;
}

int enemy::gethp(){
	return hp;
}

bool enemy::ishostile(){
	return hostile;
}


string enemy::getrace(){
	return race;
}

void enemy::hit(player* p){
	/*int addvalue=1;
	if(getdef()==0){
		addvalue=0;
	}*/
	int damage=ceil(100*p->getatk()/(100+getdef()));
	this->hp=this->hp-damage;
	if (this->hp<=0){
//cout<<"a"<<endl;
		this->hp=0;
		if(race!="Merchant"){
			p->addgold(1);
		}
		setalive();
		p->action=p->action+getrace()+" has been slained.\n";
		//cout<<getrace()<<" has been slained."<<endl;
	}
	else{
		stringstream ss;
		ss << damage;
		p->action=p->action+p->getrace()+" deals " + ss.str() + " damage to " +getrace()+"\n";
	}
}

int enemy::getatk(){
	return atk;
}

int enemy::getdef(){
	return def;
}
	
bool enemy::isalive(){
	return alive;
}

void enemy::setalive(){
	alive=false;
}

void enemy::move(){
	//cout<<"come in"<<endl;
	int tmpx=getx();
	int tmpy=gety();
	//cout<< tmpx <<" y "<<tmpy<<endl;
	int random=rand()%8;
	if(random==5) setx(getx()+1);
	else if(random==1) setx(getx()-1);
	else if(random==3) sety(gety()+1);
	else if(random==7) sety(gety()-1);
	else if(random==2) {
		sety(gety()+1);
		setx(getx()-1);
	}
	else if(random==0){
		setx(getx()-1);
		sety(gety()-1);
	}
	else if(random==4){
		setx(getx()+1);
		sety(gety()+1);
	}
	else if(random==6){
		sety(gety()-1);
		setx(getx()+1);
	}
	//cout<<"move a"<<endl;
	int myx=getx();
	int myy=gety();
	//cout<< myx <<" y "<< myy<<endl;
	if(f->grid[getx()][gety()]!='.'){
		setx(tmpx);
		sety(tmpy);
	//cout<<"move b1"<<endl;
		move();
	//cout<<"move b2"<<endl;
	}
	else{
	//cout<<"move c"<<endl;
		int curx=getx();
    	int cury=gety();
    	f->grid[tmpx][tmpy]='.';
    	string tmpstr=getrace();
    	char first;
    	if(tmpstr=="Goblin"){
    		first='N';
    	}
    	else if(tmpstr=="Phoenix"){
    		first='X';
    	}
    	else first=tmpstr[0];
    	f->grid[curx][cury]=first;
    }
}

enemy::~enemy(){}
