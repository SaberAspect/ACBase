#include <iostream>
#include <Windows.h>
#include "..\Headers\HackManager.h"
//Including our example hack
#include "..\Headers\ExampleHack.h"

//Structure that holds our hack objects
struct Hacks
{
	ExampleHack* exHack = new ExampleHack("ExampleHack", VK_F3);
}hack;
HackManager::HackManager()
{
	//Adding our example hack to the vector of hacksa
	this->addHack(hack.exHack);
}
void HackManager::updateHacks()
{
	//We loop through our vector of hacks
	for (int i = 0; i < hacks.size(); ++i) {
		//We call the key function to check key input
		key();
		//If the current hack is enabled/toggled
		if (hacks.at(i)->isToggled()) {
			//We update the hack and run its code
			hacks.at(i)->update();
		}
	}
}
void HackManager::addHack(Hack* h)
{
	//Adding hacks to the back of the vector
	this->hacks.push_back(h);
}
//Check if the current key that is held down is equal to any of the current hacks keys
//If the key is pressed, we toggle that specific hack on
unsigned int HackManager::key()
{
	unsigned int key = -1;
	//Loop through the array of hacks, and check their keys
	for (int i = 0; i < hacks.size(); ++i)
	{
		//Equaling the current hack key
		//to our key variable
		key = hacks.at(i)->getKey();
		//if the current key is preseed for the curent hack
		if (GetAsyncKeyState(key) & 1)
			//we toggle that hack on/off
			hacks.at(i)->toggle();
	}
	//Return the key of the current hack
	return key;
}
HackManager::~HackManager()
{
	//We delete the hack objects here
	delete hack.exHack;
}