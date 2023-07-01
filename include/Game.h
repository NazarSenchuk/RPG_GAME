#ifndef GAME_H
#define GAME_H

#include "Game.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "GameState.h"
#include <stack>
class Game
{
    public:
        // CONSTRUCTOR/DESTRUCTOR
        Game();
        virtual ~Game();
        //VARIABLES
        bool fullscreen;
        sf::RenderWindow *window;
        sf::Event sfEvent;
        sf::Clock dtClock;
        float dt;
        std::stack<State*> states;

        //FUNCTIONS

        void initStates();
        void updateDt();
        void  updateSFMLEvents();
        void update();
        void render();
        void run();
        void initVariables();


    protected:
        std::map<std::string,int> supportedKeys;

    private:
        sf::ContextSettings windowSettings ;
        std::vector<sf::VideoMode> videoModes;
        void initKeys();
        void initWindow();

};

#endif // GAME_H
