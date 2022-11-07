#include "Game.h"

using namespace gm;
using namespace sf;

Game::Game() {
    srand(time(0));
    particleEffect = new SnowEffect();
    particleEffectMode = 0;
    particleEffectFullySwitched = true;
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
                std::cout << "Snow Particle Effect Selected" << std::endl;
                if (particleEffectMode != 0) {
                    particleEffectMode = 0;
                    particleEffectFullySwitched = false;
                }
            }
            else if (event.key.code == sf::Keyboard::Num2)
            {
                std::cout << "Firework Particle Effect Selected" << std::endl;
                if (particleEffectMode != 1) {
                    particleEffectMode = 1;
                    particleEffectFullySwitched = false;
                }
            }
        }
        
        // create new particle effect with mouse click (delete and reallocate)
        if (event.type == sf::Event::MouseButtonPressed) {
            clock.restart();
            
            // if switch has not occured yet
            if (!particleEffectFullySwitched) {
                if (particleEffectMode == 0) {
                    delete dynamic_cast<FireworkEffect*>(particleEffect);
                    particleEffect = new SnowEffect();
                } else {
                    delete dynamic_cast<SnowEffect*>(particleEffect);
                    particleEffect = new FireworkEffect();
                }
                particleEffectFullySwitched = true;
            }
            
            if (particleEffectMode == 0) {
                particleEffect->CreateParticles(600, sf::Mouse::getPosition(window));
            }
            else {
                particleEffect->CreateParticles(100, sf::Mouse::getPosition(window));
            }
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
    if (particleEffectFullySwitched) {
        if (particleEffectMode == 0) {
            delete dynamic_cast<SnowEffect*>(particleEffect);
        }
        else {
            delete dynamic_cast<FireworkEffect*>(particleEffect);
        }
    } else {
        if (particleEffectMode == 1) {
            delete dynamic_cast<SnowEffect*>(particleEffect);
        }
        else {
            delete dynamic_cast<FireworkEffect*>(particleEffect);
        }
    }
    
}