#pragma once
#include <vector>
#include "Hack.h"
class HackManager
{
private:
	std::vector<Hack*>hacks;
public:
	//We will initilize our hacks upon the creation of the manager
	HackManager();
	//Delete the hacks with this
	~HackManager();

	//We update the hacks if they are toggled
	void updateHacks();
	//This is how we add hacks to the vector list
	void addHack(Hack* h);

private:
	//This is how we get key input based on the hacks
	unsigned int key();
};
