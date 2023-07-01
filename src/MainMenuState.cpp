#include "MainMenuState.h"
#include "GameState.h"
MainMenuState::MainMenuState(sf::RenderWindow* window , std::map<std::string,int>* supportedKeys,std::stack<State*>* states)
    : State(window, supportedKeys,states)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();


}
void MainMenuState::initButtons(){
    this->buttons["GAME_STATE"] = new Button(300,480,150,50 , &this->font,"New Game",sf::Color(70,70,200),sf::Color(150,150,150,200) , sf::Color(0,20,20,200 ));
    this->buttons["SETTINGS"] = new Button(300,580,150,50 , &this->font,"Settings",sf::Color(70,70,200),sf::Color(150,150,150,200) , sf::Color(0,20,20,200 ));
    this->buttons["EXIT"] = new Button(300,680,150,50 , &this->font,"Exit",sf::Color(70,70,200),sf::Color(150,150,150,200) , sf::Color(0,20,20,200 ));

}
MainMenuState::~MainMenuState()
{
    auto it =this->buttons.begin();
    for(it = this->buttons.begin(); it!= this->buttons.end(); ++it);
    {
        delete it->second;
    }
}
void MainMenuState::initKeybinds(){
    std::ifstream ifs("Config/mainmenustate_keybinds.ini");
    if(ifs.is_open()){
        std::string key1 ;
        std:: string key2 ;
        while(ifs >> key1 >> key2 ){
            this->keybinds[key1] = this->supportedKeys->at(key2);



        }


    }
    ifs.close();

}
void MainMenuState::initBackground(){
    this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));

    sf::Texture bg ;
    if( !bg.loadFromFile("Resources/Images/Background/background.jpg")){


    }
    this->background.setTexture(&bg);

}
void MainMenuState::initVariables(){
}
void MainMenuState::updateInput(const float & dt){
    this->checkForQuit();



}
void MainMenuState::update(const float& dt){
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButtons();


}
void MainMenuState::render(sf::RenderTarget* target){
    if(!target)
    {
        target = this->window;
    }
    target->draw(this->background);

    this->renderButtons(this->window);
}
void MainMenuState::endState(){



}
void MainMenuState::initFonts(){



}
void MainMenuState::updateButtons()
{
    if(this->font.loadFromFile("font/avenir_ff/AvenirLTStd-Black.otf")){
        for (auto &it : this->buttons)
        {
            it.second->update(this->mousePosView);
        }

    if(this->buttons["EXIT"]->isPressed())
    {

        this->endState();

    }
    if(this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->supportedKeys , this->states));
    }




}
}
void MainMenuState::renderButtons(sf::RenderTarget * target){
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }


}
