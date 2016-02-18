#ifndef __dwarf_H_
#define __dwarf_H_
#include <iostream>
#include "player.h"

class dwarf:public player{
public:
	dwarf(int x, int y);
	~dwarf();
};

#endif
