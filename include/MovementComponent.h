#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H


#include <State.h>
class MovementComponent
{
    public:
        MovementComponent(sf::Sprite& sprite ,float maxVelocity,float acceleration ,float deceleration);
        virtual ~MovementComponent();
        void update(const float& dt);
        void move(const float dir_x , const float dir_y,const float& dt );
        const sf::Vector2f& getVelocity() const;
    protected:

    private:
        sf::Sprite& sprite;
        float maxVelocity;

        sf::Vector2f velocity;
        float acceleration;
        float deceleration;

};

#endif // MOVEMENTCOMPONENT_H
