#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H
#include <map>
#include <State.h>
class AnimationComponent
{
    public:
        AnimationComponent(sf::Sprite& sprite , sf::Texture& texture_sheet);
        virtual ~AnimationComponent();
        void play( const std::string key , const float & dt);
        void addAnimation(const std::string key,float animationTimer, int start_x ,int start_y,int end_x ,int end_y,int width , int height) ;
    protected:

    private:

        class Animation
        {
        private:

        public:
            sf::Sprite& sprite;
            sf::Texture& textureSheet;
            float animationTimer;
            float timer ;
            int width;
            int height;
            sf::IntRect startRect;
            sf::IntRect endRect;
            sf::IntRect currentRect;

            Animation(sf::Sprite& sprite,sf::Texture& textureSheet,float animationTimer,int start_x ,int start_y,int end_x , int end_y,int width , int height)
                :   sprite(sprite),textureSheet(textureSheet),animationTimer(animationTimer),width(width),height(height)
            {
                this->timer = 0.f;
                this->startRect = sf::IntRect(start_x * width , start_y * height, width , height);
                this->currentRect = this->startRect;
                this->endRect = sf::IntRect(end_x * width , end_y * height, width , height);
                this->sprite.setTexture(this->textureSheet,true);
                this->sprite.setTextureRect(this->startRect);
            }
            void play(const float& dt ){
                this->timer += 100.f *dt;
                if(this->timer >= this->animationTimer)
                {
                    this->timer = 0.f;
                    if (this->currentRect != this->endRect)
                    {
                        this->currentRect.left+= this->width;
                    }else{
                        this->currentRect.left = this->startRect.left;
                    }
                    this->sprite.setTextureRect(this->currentRect);
                }



            }

            void pause();
            void reset(){
                this->timer = 0.f ;
                this->currentRect = this->startRect;





            }

        };
        std::map<std::string, Animation*> animations;
        sf::Sprite& sprite ;
        sf::Texture& textureSheet;


        void startAnimation(const std::string animation);
        void pauseAnimation(const std::string animation);
        void resetAnimation(const std::string animation);
        void update(const float& dt);

};

#endif // ANIMATIONCOMPONENT_H
