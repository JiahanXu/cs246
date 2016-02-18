#include <string>

class potion{
public:
	std::string type;
	int x;
	int y;
	int exist;
	potion(int x, int y, std::string str);
	~potion();
};
