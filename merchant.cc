#include "merchant.h"
#include "player.h"
#include "floor.h"
#include <iostream>

using namespace std;

merchant::merchant(int x, int y): enemy(30,70,5,"Merchant", x, y){
	hostile=0;
	alive=1;
}

void merchant::sethostile(){
	hostile=true;
}

bool merchant::gethostile(){
	return hostile;
}

merchant::~merchant(){}
