#include "werewolf.h"

werewolf::werewolf(int x, int y): enemy(120,30,5,"Werewolf", x, y){
	alive=1;
	hostile=1;
}

werewolf::~werewolf(){}
