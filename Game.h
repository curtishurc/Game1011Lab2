#pragma once
#include <string>
#include "Achivement.h"
class Game
{
public:
	Game(std::string name, std::string publisher, std::string developer);
	~Game();

	void addAchivement(Achivement* a);
	void listAchivements() const;

	std::string getName() const;

private:
	std::string m_name;
	std::string m_publisher;
	std::string m_developer;

	Achivement* achivements[5];
	int achivementCount;
};

