#include "enemy.h"

class treasure{
public:
	int type;
	int x;
	int y;
	int pick;
	bool exist;
	enemy* mydragon;
	treasure(int x, int y, int type);
	~treasure();
};
