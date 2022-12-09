#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <algorithm>

#include "Paddle.h"
#include "Ball.h"

const float maxTrackDistanceY = 10;

namespace gm {
    class AIController {
    public:
        AIController();
        void Sense(const gm::Ball& ball);
        void Update(gm::Paddle& enemyPaddle, float paddleHeight);
        ~AIController();
    private:
        sf::Vector2f sensedBallPos;
    };
}


#endif