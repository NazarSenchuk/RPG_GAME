#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>
class Player  :
    public Entity
{
    public:
        Player(float x , float y , sf::Texture& texture);
        virtual ~Player();
        void initComponents();
        void initVariables();
        void update(const float & dt);
    protected:

    private:
};

#endif // PLAYER_H
