#include "Platform.h"
#include <iostream>

Platform::Platform(std::string name, std::string manufacturer)
	:m_name(name)
	, m_manufacturer(manufacturer)
	, gameCount(0)
{
}
Platform::~Platform() 
{
	for (int i = 0; i < gameCount; i++)
	{
		delete games[i];
		games[i] = nullptr;
	}
}
void Platform::addGame(Game* g)
{
	if (gameCount < 5)
	{
		games[gameCount++] = g;
	}
}
void Platform::listGames() const
{
	for (int i = 0; i < gameCount; i++)
	{
		std::cout << i + 1 << ". " << games[i]->getName() << "/n";
	}
}
std::string Platform::getName() const { return m_name; }
Game* Platform::getGame(int index) const { return (index >= 0 && index < gameCount) ? games[index] : nullptr; }
int Platform::getGameCount() const { return gameCount; }

