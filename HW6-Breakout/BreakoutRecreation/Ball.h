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
    const int BallSize = 20;
    // Ball movement speed
    const int MinBallSpeedPerSecond = 400;
    const int MaxBounceAngle = 7 * M_PI / 18; // 70 degrees in radians
    const int speedTickAdd = 150;
    
    class Ball : public GameObject {
    public:
        Ball(const sf::Vector2f& position, const sf::Vector2f& size);
        void update(sf::RenderWindow& window, float deltaTime) override;
        void render(sf::RenderWindow& window, float deltaTime) override;
        void move(const sf::Vector2f& velocity) override;
        void knockBack(const float paddleHeight, const float collisionHeight);
        void setPosition(const sf::Vector2f& position) override;
        void setVelocity(const sf::Vector2f& velocity);
        void setSpeedTick(int val);
        void setLaunched(bool condition);
        void setFillColor(const sf::Color& color);
        const sf::Vector2f& getVelocity() const;
        bool getLaunched() const;
        const int getSpeedTick() const;
        const sf::Color& getFillColor() const;
    protected:
        sf::CircleShape body;
        sf::Vector2f velocity;
        int speedTick;
        bool launched;
	};

}
#endif