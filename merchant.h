#ifndef __merchant_H_
#define __merchant_H_
#include "enemy.h"

class merchant: public enemy{
public:
	merchant(int x, int y);
	void sethostile();
	bool gethostile();
	~merchant();
};

#endif
