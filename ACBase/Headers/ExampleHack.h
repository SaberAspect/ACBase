#pragma once
#include "Hack.h"

class ExampleHack : public Hack
{
public:
	ExampleHack(std::string hName, unsigned int keyCode);
	//Update our hack
	void update();
};
