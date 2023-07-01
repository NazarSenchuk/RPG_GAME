#include "Game.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "GameState.h"
#include "MainMenuState.h"
Game::Game()
{


    //CONSTRUCT
    this->initWindow();

    this->initKeys();
    this->initStates();


}

Game::~Game()
{
    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();


    }
    //DESTRUCT
}
//INIT WINDOW
void Game::initWindow(){
    std::ifstream ifs("Config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();
    std::string title = "None";

    sf::VideoMode window_bounds=  sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;
    if (ifs.is_open())
    {
        std::getline(ifs,title);
        ifs>>window_bounds.width >> window_bounds.height;
        ifs >> fullscreen ;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }
    ifs.close();
    this->fullscreen = fullscreen;
    this->windowSettings.antialiasingLevel = antialiasing_level;
    if(this->fullscreen){
        this->window = new sf::RenderWindow(window_bounds ,title,sf::Style::Fullscreen , this->windowSettings);
    }else {
        this->window = new sf::RenderWindow(window_bounds ,title,sf::Style::Titlebar | sf::Style::Close , this->windowSettings);
    }
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}
void Game::initStates()
{
        this->states.push(new MainMenuState(this->window , &this->supportedKeys , &this->states));



}
void Game::initKeys(){
    std::ifstream ifs("Config/supported_keys.ini");
    if(ifs.is_open())
    {
        std::string key  = "";
        int key_value =0 ;


        while( ifs >> key >> key_value){



            this->supportedKeys[key] = key_value;


        }
    }
    ifs.close();
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;



}
void Game::initVariables(){
    this->window = NULL;
    this->fullscreen  = false;
    this->dt = 0.f;


}
void Game::updateDt(){
    this->dt = this->dtClock.restart().asSeconds();
    system("cls");

    std::cout << this->dt << "\n";

}
// UPDATE SFML EVENT(KEYBOARD,OTHER)
void Game::updateSFMLEvents(){
     while (this->window->pollEvent(this->sfEvent))
        {
            if (this->sfEvent.type == sf::Event::Closed)
                this->window->close();
        }


}
//UPDATE EVENTS

void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else
	{

		this->window->close();
	}
}


//RENDER WINDOW AND OBJECT ON WINDOW
void Game::render(){

    this->window->clear();

    if (!this->states.empty())
        this->states.top()->render();

    this->window->display();

}
//ALL RUN
void Game::run(){
    while (window->isOpen())
    {

        std::cout<<"hello"<<std::endl;
        this->updateDt();
        this->update();



        this->render();
    }

}
