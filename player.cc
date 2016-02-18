#include <iostream>
#include <string>
#include "player.h"
#include "enemy.h"
//#include "treasure.h"
#include "floor.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
//#include "potion.h"
//#include "treasure.h"

using namespace std;

//player::player(){}
/*void player::meet(enemy* e){
	e->hit(this);
}*/
void player::hit(enemy* e){
	int damage=ceil(100*e->getatk()/(100+getdef()));
	this->hp=this->hp-damage;
	if (this->hp<=0){
		this->hp=0;
		setalive();
		action=action+"You are died!\n";
		//cout<<"You are died!"<<endl;
	}
	else{
		stringstream ss;
		ss << damage;
		//cout<<e->getrace()<<" deals "<<damage<<" to "<< getrace()<<endl;
		action=action+e->getrace()+" deals "+ ss.str() +" to "+getrace()+"\n";
	}
}

string player::getrace(){
	return race;
}

int player::getatk(){
	if (atk+tmpatk<0){
		return 0;
	}else {
		return atk+tmpatk;
	}
}

int player::getdef(){
	if (def+tmpdef<0){
		return 0;
	}else {
		return def+tmpdef;
	}
}

void player::addtmpatk(int a){
	if(race=="elves" && a<0){
		tmpatk=tmpatk-a;
	}
	else{
		tmpatk=tmpatk+a;
	}
}

void player::addtmpdef(int a){
	if(race=="elves" && a<0){
		tmpdef=tmpdef-a;
	}
	else{
		tmpdef=tmpdef+a;
	}
}

void player::addtmphp(int a){
	if(race=="elves" && a<0){
		hp=hp-a;
	}else if (race=="nami"){
		if (a < 0){
			hp=hp-(a*2);
		}else {
			hp=hp+(a*2);
		}
	}
	else {
		hp=hp+a;
	}
	if(hp>maxhp){
		hp=maxhp;
	}
	else if(hp<=0){
		setalive();
	}
}
void player::addgold(int a){
	gold=gold+a;
}

int player::getgold(){
	if(race=="orc"){
		return gold/2;
	}
	else if(race=="dwarf"){
		return gold*2;
	}
	else{
		return gold;
	}
}

bool player::isalive(){
	return alive;
}

void player::setalive(){
	alive=false;
}

void player::cleartmp(){
	tmpdef=0;
	tmpatk=0;
}


int player::move(string str){
	int tmpx=getx();
	int tmpy=gety();
	if(str=="so") setx(getx()+1);
	else if(str=="no") setx(getx()-1);
	else if(str=="ea") sety(gety()+1);
	else if(str=="we") sety(gety()-1);
	else if(str=="ne") {
		sety(gety()+1);
		setx(getx()-1);
	}
	else if(str=="nw"){
		setx(getx()-1);
		sety(gety()-1);
	}
	else if(str=="se"){
		setx(getx()+1);
		sety(gety()+1);
	}
	else if(str=="sw"){
		sety(gety()-1);
		setx(getx()+1);
	}
	if(!(f->grid[getx()][gety()]=='+' || f->grid[getx()][gety()]=='#' || f->grid[getx()][gety()]=='.' ||
		f->grid[getx()][gety()]=='G' || f->grid[getx()][gety()]=='P' || f->grid[getx()][gety()]=='\\')){
		//cout<<"here "<< f->grid[getx()][gety()]<<endl;
		setx(tmpx);
		sety(tmpy);
		return -1;
	}
	else if(f->grid[getx()][gety()]=='G'){
		int flag=0;
		for(int i=0; i<10; i++){
			if(f->tarray[i]->x==getx() && f->tarray[i]->y==gety()){
				flag=1;
				if(f->tarray[i]->pick==0){
					setx(tmpx);
					sety(tmpy);
					return -1;
				}
				else{
					if(f->tarray[i]->type==1){
						addgold(1);
						action=action+"You picked up a normal horde.";
					}
					else if(f->tarray[i]->type==2){
						addgold(2);
						action=action+"You picked up a small horde.";
					}
					else if (f->tarray[i]->type==3){
						addgold(6);
						action=action+"You picked up a dragon hoard.";
					}
					f->tarray[i]->exist=0;
					f->grid[getx()][gety()]='.';
					break;
				}
			}
		}
		if(flag==0){
			f->grid[getx()][gety()]='.';
			addgold(4);
			action=action+"You picked up a merchant hoard.";
		}
	}
	else if(f->grid[getx()][gety()]=='P'){
//cout<<"in"<<endl;
		for(int i=0; i<10; i++){
//cout<<getx()<< "  "<<gety()<<endl;
//cout<<f->parray[i]->x<<"  "<<f->parray[i]->y<<endl;
			if(f->parray[i]->x==getx() && f->parray[i]->y==gety() &&
				f->parray[i]->exist==1){
				if(f->parray[i]->type=="RH"){
					addtmphp(10);
					action=action+"You used RH.\n";
				}
				else if(f->parray[i]->type=="BA"){
					addtmpatk(5);
					action=action+"You used BA.\n";
				}
				else if(f->parray[i]->type=="BD"){
					addtmpdef(5);
					action=action+"You used BD.\n";
				}
				else if(f->parray[i]->type=="PH"){
					addtmphp(-10);
					action=action+"You used PH.\n";
				}
				else if(f->parray[i]->type=="WA"){
					addtmpatk(-5);
					action=action+"You used WA.\n";
				}
				else if(f->parray[i]->type=="WD"){
					addtmpdef(-5);
					action=action+"You used WD.\n";
				}
				f->parray[i]->exist=false;
				f->grid[getx()][gety()]='.';
				break;
			}
		}
	}
	else if(f->grid[getx()][gety()]=='\\'){
		cleartmp();
		nextfloor=1;
	}
	int curx=getx();
    int cury=gety();
 //cout<<f->lastpoint<<endl;
    //cout<< f->grid[curx][cury]<<endl;
    f->grid[tmpx][tmpy]=f->lastpoint;
    f->lastpoint=f->grid[curx][cury];
    f->grid[curx][cury]='@';
	return 1;
}

player::~player(){}
