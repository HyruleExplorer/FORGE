#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include "SFML/Graphics.hpp"
#include "Level_1.hpp"
#include "Level_2.hpp"

class LevelManager
{
public:
    LevelManager();
    ~LevelManager();
    void run();
    void ignite( Level& level );
    void update( Level& level );

private:
    Level mMenu;
    Level_1 level_1;
    Level_2 level_2;
    sf::Color mAgeColor;
    std::string filename;
    //std::string name;
    //std::map<std::string,Level>::const_iterator result;
};


#endif // LEVEL_MANAGER_HPP
