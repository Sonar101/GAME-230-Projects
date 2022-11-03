#include "Game.h"

using namespace gm;
using namespace sf;

Game::Game() {
    particleEffect = new ParticleEffect();
}

void Game::handleInput(sf::RenderWindow& window) {
    /* check for events from the window
    E.g., is the window being closed? */
    sf::Event event;
    while (window.pollEvent(event))
    {
        // create new particle effect with mouse click (delete and reallocate)
        if (event.type == sf::Event::MouseButtonPressed) {
            clock.restart();
            delete particleEffect;
            particleEffect = new ParticleEffect(sf::Mouse::getPosition(window), sf::seconds(.1), sf::seconds(2), 1, 17, 500);
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
    delete particleEffect;
}