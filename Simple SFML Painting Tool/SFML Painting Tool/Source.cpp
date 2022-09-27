#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <string>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    
    // create shape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    // run while window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // checking single key press events for modifying brush settings
            if (event.type == sf::Event::KeyPressed)
            {
                // --- changing brush color settings
                if (event.key.code == sf::Keyboard::R)
                {
                    std::cout << "Set color to red" << std::endl;
                    shape.setFillColor(sf::Color::Red);
                }
                else if (event.key.code == sf::Keyboard::G)
                {
                    std::cout << "Set color to green" << std::endl;
                    shape.setFillColor(sf::Color::Green);
                }
                else if (event.key.code == sf::Keyboard::B)
                {
                    std::cout << "Set color to blue" << std::endl;
                    shape.setFillColor(sf::Color::Blue);
                }

                // --- changing brush size settings
                if (event.key.code == sf::Keyboard::Up && shape.getRadius() <= 200.0f)
                {
                    std::cout << "Increasing brush size by 5 pixels" << std::endl;
                    shape.setRadius(shape.getRadius() + 5.0f);
                }
                else if (event.key.code == sf::Keyboard::Down && shape.getRadius() >= 5.0f)
                {
                    std::cout << "Decreasing brush size by 5 pixels" << std::endl;
                    shape.setRadius(shape.getRadius() - 5.0f);
                }
            }
            
            // close the window during a closed event
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // position shape to where the mouse is
        shape.setPosition(sf::Mouse::getPosition(window).x - shape.getRadius(), sf::Mouse::getPosition(window).y - shape.getRadius());
        
        // detect left mouse click to draw shape
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
        {
            window.draw(shape);
        }

        window.display();
    }
    return 0;
}