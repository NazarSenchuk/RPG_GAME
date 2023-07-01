#include "Player.h"

Player::Player(float x , float y , sf::Texture& texture)
{
    this->initVariables();
    this->setPosition(x,y);
    this->createMovementComponent(250.f, 10.f,4.f);
    this->createAnimationComponent(texture);
    this->animationComponent->addAnimation("IDLE_LEFT", 10.f,0,0,13,0,192,192);


    //ctor
}

Player::~Player()
{
    //dtor
}
void Player::update(const float & dt ){
    Entity::update(dt);
    this->animationComponent->play("IDLE_LEFT", dt);
}
void Player::initVariables(){
}
