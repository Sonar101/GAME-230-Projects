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
    sf::CircleShape circleBrush(100.f);
    sf::RectangleShape squareBrush({100,100});
    circleBrush.setFillColor(sf::Color::Green);
    squareBrush.setFillColor(sf::Color::Green);

    bool shapeIsCircle = true;
    
    // run while window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // checking single key press events for modifying brush settings
            if (event.type == sf::Event::KeyPressed)
            {
                // --- changing brush shape settings
                if (event.key.code == sf::Keyboard::S)
                {
                    if (shapeIsCircle)
                    {
                        std::cout << "Brush shape set to Square" << std::endl;
                        shapeIsCircle = false;
                    }
                    else
                    {
                        std::cout << "Brush shape set to Circle" << std::endl;
                        shapeIsCircle = true;
                    }
                }
                
                // --- changing brush color settings
                if (event.key.code == sf::Keyboard::R)
                {
                    std::cout << "Set color to red" << std::endl;
                    circleBrush.setFillColor(sf::Color::Red);
                    squareBrush.setFillColor(sf::Color::Red);
                }
                else if (event.key.code == sf::Keyboard::G)
                {
                    std::cout << "Set color to green" << std::endl;
                    circleBrush.setFillColor(sf::Color::Green);
                    squareBrush.setFillColor(sf::Color::Green);
                }
                else if (event.key.code == sf::Keyboard::B)
                {
                    std::cout << "Set color to blue" << std::endl;
                    circleBrush.setFillColor(sf::Color::Blue);
                    squareBrush.setFillColor(sf::Color::Blue);
                }

                // --- changing brush size settings
                if (event.key.code == sf::Keyboard::Up && circleBrush.getRadius() <= 200.0f)
                {
                    std::cout << "Increasing brush size by 5 pixels" << std::endl;
                    circleBrush.setRadius(circleBrush.getRadius() + 5.0f);
                    
                }
                else if (event.key.code == sf::Keyboard::Down && circleBrush.getRadius() >= 5.0f)
                {
                    std::cout << "Decreasing brush size by 5 pixels" << std::endl;
                    circleBrush.setRadius(circleBrush.getRadius() - 5.0f);
                    squareBrush.setSize({squareBrush.getSize().x - 5.0f, squareBrush.getSize().y - 5.0f });
                }
            }
            
            // close the window during a closed event
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // position shape to where the mouse is
        circleBrush.setPosition(sf::Mouse::getPosition(window).x - circleBrush.getRadius(), sf::Mouse::getPosition(window).y - circleBrush.getRadius());
        squareBrush.setPosition(sf::Mouse::getPosition(window).x - squareBrush.getSize().x / 2, sf::Mouse::getPosition(window).y - squareBrush.getSize().y / 2);
        
        // detect left mouse click to draw shape
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
        {
            if (shapeIsCircle)
            {
                window.draw(circleBrush);
            }
            else
            {
                window.draw(squareBrush);
            }
        }

        window.display();
    }
    return 0;
}