#include "Achivement.h"
Achivement::Achivement(std::string title, std::string description, int scoreValue)
	:m_title(title)
	, m_description(description)
	, m_scoreValue(scoreValue) {
}
std::string Achivement::getTitle() const { return m_title; }
std::string Achivement::getDiscription() const { return m_description; }
int Achivement::getScoreValue() const { return m_scoreValue; }

void Achivement::setTitle(std::string title) { m_title = title; }
void Achivement::setDescription(std::string description) { m_description; }
void Achivement::setScoreValue(int scoreValue) { m_scoreValue = scoreValue; }