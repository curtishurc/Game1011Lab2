#include "Game.h"
#include <iostream>

Game::Game(std::string name, std::string publisher, std::string developer)
	:m_name(name)
	, m_publisher(publisher)
	, m_developer(developer)
	, achivementCount(0) {
}
Game::~Game()
{
	for (int i = 0; i < achivementCount; i++)
	{
		delete achivements[i];
		achivements[i] = nullptr;
	}
}
void Game::addAchivement(Achivement* a)
{
	if (achivementCount < 5)
	{
		achivements[achivementCount++] = a;
	}
}
void Game::listAchivements() const
{
	for (int i = 0; i < achivementCount; i++)
	{
		std::cout << "- " << achivements[i]->getTitle()
			<< achivements[i]-> getDiscription()
			<< " (" << achivements[i]->getScoreValue() << " )\n";
			
	}
}
std::string Game::getName() const { return m_name; }