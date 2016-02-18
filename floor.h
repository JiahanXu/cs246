#ifndef __floor_H_
#define __floor_H_
#include <iostream>
#include "treasure.h"
#include "potion.h"
#include "enemy.h"
#include "player.h"
#include "dragon.h"
#include <string>

class merchant;

class floor{
public:
	int numfloor;
	floor();
	void createfloor();
	~floor();
	void hit(player* p, std::string str);
	char** grid;
	enemy** earray;
	//int numenemy;
	potion** parray;
	//int numpotion;
	treasure** tarray;
	char lastpoint;
	//int numtreasure;
	//void movecharacter();
	//void beingnotified(enemy* e);
	//void beingnotified(merchant* m);
	//void beingnotified(potion* p);
	//void beingnotified(treasure* t);
	//void beingnotified(player* p);
	//void printscore(player* p);
	void makemove(player* p, std::string str);
	void checkaround(player* p);
	void setearray(int i);
	void setparray(int i);
	void settarray(int i);
	int setplayer(player* p);
	void setstair(int i);
	//void setmertchanthorde();
	void printfloor(player* p);
};

#endif
