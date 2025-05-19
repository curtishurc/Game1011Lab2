#pragma once
#include <string>

class Achivement
{
public:
	Achivement(std::string title, std::string description, int scoreValue);//constructor
	//accesors
	std::string getTitle() const;
	std::string getDiscription() const;
	int getScoreValue() const;
	//mutators
	void setTitle(std::string title);
	void setDescription(std:: string description);
	void setScoreValue(int scoreValue);
	
private:
	std::string m_title;
	std::string m_description;
	int m_scoreValue;
};

