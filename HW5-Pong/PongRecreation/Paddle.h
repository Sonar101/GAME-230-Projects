#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

namespace gm {
    // Box movement speed
    const int PlayerMovementSpeedPerSecond = 400;

    enum MovementDirection {
        None = 0,
        Up = -1,
        Down = 1
    };

    class Paddle :
        public GameObject
    {
    protected:
        sf::RectangleShape body;
        MovementDirection direction;
        float verticalVelocity;
    public:
        Paddle(const sf::Vector2f& position, const sf::Vector2f& size);

        void update(sf::RenderWindow& window, float deltaTime) override;
        void render(sf::RenderWindow& window, float deltaTime) override;
        void move(const sf::Vector2f& velocity) override;
        void setPosition(const sf::Vector2f& position) override;
        void setMovmentDirection(MovementDirection direction);
        void setVerticalVelocity(float val);
        void setFillColor(const sf::Color& color);
        const MovementDirection& getMovementDirection() const;
        const sf::Color& getFillColor() const;
    };
}

#endif