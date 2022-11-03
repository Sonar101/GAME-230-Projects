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

#include "Game.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // initialize the render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Particle Effect");

    gm::Game game;

    // run while window is open
    while (window.isOpen())
    {
        game.handleInput(window);
        game.update(window);
        game.render(window);
    }

    return 0;
}