#ifndef __character_H_
#define __character_H_

class floor;
class character{
public:
	int x;
	int y;
	int hp;
	int maxhp;
	int atk;
	int def;
	floor* f;
	void setfloor(floor* f);
	int getx();
	int gety();
	void setx(int x);
	void sety(int y);
	//character();
	virtual int getatk()=0;
	virtual int getdef()=0;
	virtual ~character()=0;
};

#endif
