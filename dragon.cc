#include "dragon.h"
using namespace std;

dragon::dragon(int x, int y):enemy(150,20,20,"Dragon",x,y){
	hostile=0;
	alive=1;
}

dragon::~dragon(){}
