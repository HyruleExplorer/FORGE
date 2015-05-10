#ifndef GAME_HPP
#define GAME_HPP

#include "SFML/Graphics.hpp"
#include "LevelManager.hpp"
#include "GameObjectManager.hpp"
#include "Level.hpp"
//#include <map>

class Game
{
public:
    Game();
    void run();

    enum currentLevel{MENU_0,LEV_1,LEV_2};
    enum currentAge{PAST, PRESENT, FUTURE};
    static currentLevel cLevel;
    static currentAge cAge;
    static bool isExiting;
    static bool change;
    //static std::map<std::string,Level> discoveredLevels;
    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;
    static const float mSpeed;
    static sf::RenderWindow mWindow;

private:
    LevelManager LevMan;
    GameObjectManager GameMan;
    const sf::Time TimePerFrame;
};


#endif // GAME_HPP


