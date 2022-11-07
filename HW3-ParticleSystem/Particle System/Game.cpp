#include "Game.h"

using namespace gm;
using namespace sf;

Game::Game() {
    srand(time(0));
    particleEffect = new SnowEffect();
}

void Game::handleInput(sf::RenderWindow& window) {
    /* check for events from the window
    E.g., is the window being closed? */
    sf::Event event;
    while (window.pollEvent(event))
    {
        // changing tile on brush
        if (event.type == sf::Event::KeyPressed) 
        {
            if (event.key.code == sf::Keyboard::Num1)
            {
                std::cout << "Main Particle Effect Selected" << std::endl;
            }
            else if (event.key.code == sf::Keyboard::Num2)
            {
                std::cout << "Second Particle Effect Selected" << std::endl;
            }
        }
        
        // create new particle effect with mouse click (delete and reallocate)
        if (event.type == sf::Event::MouseButtonPressed) {
            clock.restart();
            particleEffect->CreateParticles(NUM_PARTICLES, sf::Mouse::getPosition(window));
        }

        // close the window during a closed event
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::RenderWindow& window) {
    particleEffect->Update(clock.getElapsedTime());
}

void Game::render(sf::RenderWindow& window) {
    // clear the current frame
    window.clear();

    // render objects
    particleEffect->Render(window);

    // display the window buffer for this frame
    window.display();
}

Game::~Game() {
    std::cout << "Game Deconstructor" << std::endl;
    delete dynamic_cast<SnowEffect*>(particleEffect);
}