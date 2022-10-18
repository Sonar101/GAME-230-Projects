// Created by Nathann Latimore

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <string>
#include <iostream>

#include "ParticleEffect.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // initialize the render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Particle Effect");
    
    // set up clock
    sf::Clock clock;

    // create particleEffect pointer
    ParticleEffect* particleEffect = new ParticleEffect();

    // run while window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // create new particle effect with mouse click (delete and reallocate)
            if (event.type == sf::Event::MouseButtonPressed) {
                clock.restart();
                delete particleEffect;
                particleEffect = new ParticleEffect(sf::Mouse::getPosition(window), sf::seconds(.2), sf::seconds(3), 1, 17, 500);
            }
            
            // close the window during a closed event
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // update and render particle effect
        particleEffect->Update(clock.getElapsedTime());
        window.clear();
        particleEffect->Render(window);
        window.display();
    }

    delete particleEffect;
    return 0;
}