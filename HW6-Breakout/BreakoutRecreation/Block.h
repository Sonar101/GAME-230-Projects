#ifndef BLOCK_H
#define BLOCK_H

#include "GameObject.h"
#include "SoundManager.h"
#include <iostream>;

namespace gm {
    
    const sf::Vector2f BLOCKSIZE = sf::Vector2f(80, 30);

    enum BlockType {
        weak,
        strong
    };

    class Block :
        public GameObject
    {
    protected:
        sf::RectangleShape body;
        BlockType blockType;
        bool isAlive;
        int health;
        int pointValue;
    public:
        Block();
        Block(const sf::Vector2f& position, const sf::Vector2f& size);

        void update(sf::RenderWindow& window, float deltaTime) override;
        void render(sf::RenderWindow& window, float deltaTime) override;
        
        void setPosition(const sf::Vector2f& position) override;
        void setUpBlock(const BlockType& type);
        void setFillColor(const sf::Color& color);
        void setIsAlive(bool condition);
        bool getIsAlive() const;

        // returns value of points
        virtual int TakeDamage(SoundManager& sManager);
        
        const sf::Color& getFillColor() const;
    };
}

#endif