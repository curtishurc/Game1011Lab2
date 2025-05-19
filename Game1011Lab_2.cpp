// Game1011Lab_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Platform.h"
#include <string>

Platform* platforms[5];
int platformCount = 0;

void createPlatform()
{
    std::string m_name, m_manufacturer;
    std::cout << "Enter platform name: ";
    std::getline(std::cin, m_name);
    std::cout << "Enter manufacturer name: ";
    std::getline(std::cin, m_manufacturer);

    platforms[platformCount++] = new Platform(m_name, m_manufacturer);
}

void addGameToPlatform()
{
    if (platformCount == 0)
    {
        std::cout << "No platforms avalible.\n";
        return;
    }
    for (int i = 0; i < platformCount; i++)
    {
        std::cout << i + 1 << ". " << platforms[i]->getName() << "\n";
    }
    int choice;
    std::cout << "select platform: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice < 1 ||choice > platformCount)
    {
        std::cout << "Invalid Selection.\n";
        return;
    }
    std::string m_name, m_publisher, m_developer;
    std::cout << "Enter game name: ";
    std::getline(std::cin, m_name);
    std::cout << "Enter publisher name: ";
    std::getline(std::cin, m_publisher);
    std::cout << "Enter developer name: ";
    std::getline(std::cin, m_developer);

    Game* game = new Game(m_name, m_publisher, m_developer);
    platforms[choice - 1]->addGame(game);
    std::cout << "Game added.\n";
}
void addAchievementToGame() {
    if (platformCount == 0) {
        std::cout << "No platforms available.\n";
        return;
    }

    for (int i = 0; i < platformCount; ++i)
        std::cout << i + 1 << ". " << platforms[i]->getName() << "\n";

    int pChoice;
    std::cout << "Select platform: ";
    std::cin >> pChoice;
    std::cin.ignore();

    if (pChoice < 1 || pChoice > platformCount) return;

    Platform* platform = platforms[pChoice - 1];

    if (platform->getGameCount() == 0) {
        std::cout << "No games on this platform.\n";
        return;
    }

    platform->listGames();
    int gChoice;
    std::cout << "Select game: ";
    std::cin >> gChoice;
    std::cin.ignore();

    Game* game = platform->getGame(gChoice - 1);
    if (!game) {
        std::cout << "Invalid game selection.\n";
        return;
    }

    std::string title, desc;
    int score;
    std::cout << "Enter achievement title: ";
    std::getline(std::cin, title);
    std::cout << "Enter description: ";
    std::getline(std::cin, desc);
    std::cout << "Enter score value: ";
    std::cin >> score;
    std::cin.ignore();

    game->addAchivement(new Achivement(title, desc, score));
    std::cout << "Achievement added!\n";
}

void viewAll() {
    if (platformCount == 0) {
        std::cout << "No platforms to show.\n";
        return;
    }

    for (int i = 0; i < platformCount; ++i) {
        Platform* p = platforms[i];
        std::cout << "\nPlatform: " << p->getName() << "\n";
        p->listGames();
        for (int j = 0; j < p->getGameCount(); ++j) {
            Game* g = p->getGame(j);
            std::cout << "Achievements for " << g->getName() << ":\n";
            g->listAchivements();
        }
    }
}

int main() {
    int choice;
    do {
        std::cout << "\n--- Achievement Tracker ---\n";
        std::cout << "1. Create Platform\n";
        std::cout << "2. Add Game to Platform\n";
        std::cout << "3. Add Achievement to Game\n";
        std::cout << "4. View All\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: createPlatform(); break;
        case 2: addGameToPlatform(); break;
        case 3: addAchievementToGame(); break;
        case 4: viewAll(); break;
        case 0: std::cout << "Exiting...\n"; break;
        default: std::cout << "Invalid option.\n";
        }
    } while (choice != 0);
    
    for (int i = 0; i < platformCount; ++i) {
        delete platforms[i];
        platforms[i] = nullptr;
    }
    

    return 0;
}

