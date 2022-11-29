#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "GameObject.h"

// math includes and defines
#define _USE_MATH_DEFINES
#include <math.h>

namespace gm {
    // Ball movement speed
    const int MinBallSpeedPerSecond = 300;
    const int MaxBounceAngle = 7 * M_PI / 18; // 70 degrees in radians
    const int knockSpeedAdd = 50;

    enum BallDirection {
        Left = -1,
        Right = 1
    };
    
    class Ball : public GameObject {
    public:
        Ball(const sf::Vector2f& position, const sf::Vector2f& size);

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;

        virtual void setVelocity(const sf::Vector2f& velocity);

        // Move the box from its current position to a new one with a specified velocity
        virtual void move(const sf::Vector2f& velocity) override;

        virtual void setBallDirection(BallDirection direction);

        virtual void knockBack(const float paddleHeight, const float collisionHeight);

        virtual void setTotalKnocks(int val);

        virtual BallDirection getBallDirection() const;

        virtual const sf::Vector2f& getVelocity() const;

        const sf::Color& getFillColor() const;

        void setFillColor(const sf::Color& color);
    protected:
        sf::CircleShape body;
        BallDirection direction;
        sf::Vector2f velocity;
        int totalKnocks;
	};

}
#endif