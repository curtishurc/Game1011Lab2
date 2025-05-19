#pragma once
#include <string>
#include "Game.h"

class Platform
{
public:
	Platform(std:: string name, std:: string manufacturer);
	~Platform();
	void addGame(Game* g);
	void listGames() const;
	std::string getName() const;
	Game* getGame(int index) const;
	int getGameCount() const;
	
private:
	std:: string m_name;
	std:: string m_manufacturer;
	Game* games[5];
	int gameCount;
	
};

