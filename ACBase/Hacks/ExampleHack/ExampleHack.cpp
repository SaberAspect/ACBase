#include "..\..\Headers\ExampleHack.h"
#include <iostream>

ExampleHack::ExampleHack(std::string hName, unsigned int keyCode) : Hack(hName, keyCode)
{
}

/**
 * We update the hack
 * this is basically the main hack loop.
 *
 */
void ExampleHack::update()
{
	std::cout << "This is an example hack" << std::endl;
}