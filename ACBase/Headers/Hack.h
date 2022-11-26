#pragma once
#include <string>

//This is basically a template for what a hack should look like
class Hack
{
	//Basic private variables
private:
	bool toggled = false;
	std::string name;
	unsigned int key;
public:
	Hack(std::string hName, unsigned int hKey);

	//Pure virual function for our hacks to update
	virtual void update() = 0;
	//Check if the hack is toggled
	bool isToggled();
	//Toggling the hack
	void toggle();
	//Getting the key of the hack
	unsigned int getKey();
	//Setting the key of the hack
	void setKey(unsigned int keyCode);
	//Getting the name of the hack
	std::string getName();
};
