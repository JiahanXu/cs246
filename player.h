#ifndef __player_H_
#define __player_H_
#include <string>
#include "character.h"

class floor;
class enemy;

class player : public character{
protected:
	std::string race;
	int gold;
	int tmpatk;
	int tmpdef;
	bool alive;
public:
	int mhostile;
	int nextfloor;
	std::string action;
	//player();
	//virtual void use(potion*)=0;
	//virtual void use(treasure*)=0;
	//void meet(enemy* e);
	void hit(enemy* e);
	int move(std::string str);
	std::string getrace();
	int getatk();
	int getdef();
	void addtmpatk(int i);
	void addtmpdef(int i);
	void addtmphp(int i);
	void addgold(int i);
	int getgold();
	bool isalive();
	void setalive();
	void cleartmp();
	virtual ~player()=0;
};
#endif
