#ifndef __enemy_H_
#define __enemy_H_
#include "character.h"
#include <string>

class player;

class enemy: public character{
protected:
	bool alive;
	std::string race;
public:
	bool hostile;
	int movebit;
	enemy(int hp, int atk, int def, std::string race, int x, int y);
	bool isalive();
	bool ishostile();
	std::string getrace();
	void hit(player*);
	int getatk();
	int getdef();
	void setalive();
	void move();
	int gethp();
	virtual ~enemy()=0;
};

#endif
