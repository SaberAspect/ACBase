#include "..\Headers\Hack.h"

Hack::Hack(std::string hName, unsigned int hKey)
{
	this->name = hName;
	this->key = hKey;
}

/**
 * Checking if the current hack is toggled.
 *
 * @return the state of the hack
 */
bool Hack::isToggled()
{
	return this->toggled;
}
/**
 * Toggle the current hack.
 *
 */
void Hack::toggle()
{
	this->toggled = !this->toggled;
}
/**
 * Getting the key of the current hack.
 *
 * @return the key as an unsigned int
 */
unsigned int Hack::getKey()
{
	return this->key;
}
/**
 * Set the key of the hack, might be used later.
 *
 * @param keyCode the key we want to use
 */
void Hack::setKey(unsigned int keyCode)
{
	this->key = keyCode;
}
/**
 * Getting the name of the current hack.
 *
 * @return the name as a string
 */
std::string Hack::getName()
{
	return this->name;
}