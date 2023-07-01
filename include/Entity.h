#ifndef ENTITY_H
#define ENTITY_H
#include "State.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"
class Entity
{
    public:

        Entity();
        virtual void initVariables();
        virtual ~Entity();
        virtual void setPosition(const float x , const float y );
        virtual void render(sf::RenderTarget* target);
        virtual void update(const float& dt);
        virtual void move(const float& dt,const float x,const float y);
        void setTexture(sf::Texture& texture);
        void createMovementComponent( const float maxVelocity , const float acceleration , const float deceleration ) ;
        void createAnimationComponent(sf::Texture & texture) ;
    protected:
        AnimationComponent* animationComponent;
        sf::Sprite sprite;
        MovementComponent* movementComponent;


    private:

};

#endif // ENTITY_H
