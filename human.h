#ifndef __human_H_
#define __human_H_
#include <iostream>
#include "player.h"

class human:public player{
public:
	human(int x, int y);
	~human();
};

#endif
