#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"
#include "Entity.h"
#include "Player.h"
class GameState : public State
{
public:
	GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);
	virtual ~GameState();

	//Functions
	void initPlayers();
	void initTextures();
	void updateInput(const float& dt);
	void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
private:
    sf::Texture texture;
    Player* player;
    void initKeybinds();
};

#endif // GAMESTATE_H
