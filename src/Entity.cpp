#include "Entity.h"
#include <AnimationComponent.h>
Entity::Entity()
{
    initVariables();

}

Entity::~Entity()
{
    delete this->movementComponent;
}
void Entity::setPosition(const float x , const float y ){

    this->sprite.setPosition( x,y);


}
void Entity::createMovementComponent(const float maxVelocity, const float accleration , const float deceleration){
    this->movementComponent = new   MovementComponent(this->sprite,maxVelocity ,accleration,deceleration);

}
void Entity::createAnimationComponent( sf::Texture & texture){
    this->animationComponent = new AnimationComponent(this->sprite , texture);

}
void Entity::initVariables(){


    this->movementComponent = NULL ;

}
void Entity::move(const float& dt ,const float x ,const float y ){
    if (this->movementComponent)
	{
		this->movementComponent->move(x, y, dt); //Sets velocity
	}
}
void Entity::render(sf::RenderTarget* target){

    target->draw(this->sprite);





}
void Entity::setTexture(sf::Texture& texture){

    this->sprite.setTexture(texture) ;
}
void Entity::update(const float & dt){

    if(this->movementComponent)
        this->movementComponent->update(dt);




}
