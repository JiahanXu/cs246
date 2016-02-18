#ifndef __orc_H_
#define __orc_H_
#include <iostream>
#include "player.h"

class orc:public player{
public:
	orc(int x, int y);
	~orc();
};

#endif
