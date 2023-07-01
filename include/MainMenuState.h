#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "State.h"
#include "Button.h"

class MainMenuState : public State
{
public:
	MainMenuState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//Functions
	void renderButtons(sf::RenderTarget* target = nullptr);
	void updateButtons();
	void initFonts();
	void initButtons();
	void initBackground();
	void initVariables();
	void updateInput(const float& dt);
	void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
private:
    std::map<std::string, Button*> buttons;
    sf::RectangleShape background;
    sf::Font font;
    void initKeybinds();
};

#endif // MAINMENUSTATE_H
