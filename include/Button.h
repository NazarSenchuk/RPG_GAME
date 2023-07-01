#ifndef BUTTON_H
#define BUTTON_H
#include "State.h"
enum button_states{BTN_IDLE = 0 , BTN_HOVER , BTN_ACTIVE};
class Button
{
    public:
        Button(float x, float y , float width, float height ,sf:: Font* font ,std::string text , sf::Color idleColor , sf::Color hoverColor,sf::Color activeColor    );
        virtual ~Button();
        void render(sf::RenderTarget* target);
        void update( const sf::Vector2f mousePos);
        const bool isPressed() const;
    protected:

    private:
        short unsigned buttonState;
        bool pressed;
        bool hover ;

        sf::RectangleShape shape ;
        sf::Font* font ;
        sf::Text text;
        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;




};

#endif // BUTTON_H
