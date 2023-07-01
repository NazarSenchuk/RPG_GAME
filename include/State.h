#ifndef STATE_H
#define STATE_H
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include <sstream>
#include <fstream>
#include <stack>
class State
{
    public:
        State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys, std::stack<State*>* states);
        virtual void checkForQuit();
        virtual ~State();
        virtual void endState() =0 ;
        virtual void updateInput(const float& dt) = 0 ;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target = nullptr) =0;
        const bool& getQuit() const;
        virtual void updateMousePositions();
    protected:
        std::stack<State*>* states;
        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;
        std::map<std::string,int> keybinds;
        std::map<std::string,int>* supportedKeys;
        std::map<std::string, sf::Texture> textures;
        sf::RenderWindow* window;
        bool quit;
    private:

};

#endif // STATE_H
