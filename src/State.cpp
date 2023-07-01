#include "State.h"

State::State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states)
{
    this->window = window;//ctor
    this->states = states;
    this->quit = false;
    this->supportedKeys = supportedKeys;

}

State::~State()
{
    //dtor
}
void State::endState(){

    this->quit = true;

}
const bool & State::getQuit() const
{
    return this->quit;
}
void State::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
    {

        this->endState();
    }

}
void State::updateMousePositions(){
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}
