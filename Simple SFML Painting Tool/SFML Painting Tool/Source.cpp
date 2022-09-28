#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <string>
#include <iostream>

/*
Controls
--------------
Color settings
'r' Key - Changes brush color to red
'g' Key - Changes brush color to green
'b' Key - Changes brush color to blue

Shape settings
'c' Key - Changes brush to circle shape
's' Key - Changes brush to square shape

Size settings
Up Arrow - Increases brush size by 5 pixels
Down Arrow - Decreases brush size by 5 pixels
*/


int main()
{
    const float DEFAULT_BRUSH_SIZE = 50.0f;
    const float MIN_BRUSH_SIZE = 5.0f;
    const float MAX_BRUSH_SIZE = 500.0f;
    
    // initialize the render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    
    // set up a texture and image to enable screenshot saving
    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);
    sf::Image image;
    
    // create shape types for the brush
    sf::CircleShape circleBrush(DEFAULT_BRUSH_SIZE);
    sf::RectangleShape squareBrush({ DEFAULT_BRUSH_SIZE,DEFAULT_BRUSH_SIZE });
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
                    std::cout << "Brush shape set to Square" << std::endl;
                    shapeIsCircle = false;
                }
                else if (event.key.code == sf::Keyboard::C)
                {
                    std::cout << "Brush shape set to Circle" << std::endl;
                    shapeIsCircle = true;
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
                if (event.key.code == sf::Keyboard::Up && circleBrush.getRadius() <  MAX_BRUSH_SIZE)
                {
                    circleBrush.setRadius(circleBrush.getRadius() + 5.0f);
                    squareBrush.setSize({ squareBrush.getSize().x + 5.0f, squareBrush.getSize().y + 5.0f });
                    std::cout << "Increasing brush size: " << circleBrush.getRadius() << std::endl;
                    
                    
                }
                else if (event.key.code == sf::Keyboard::Down && circleBrush.getRadius() > MIN_BRUSH_SIZE)
                {
                    circleBrush.setRadius(circleBrush.getRadius() - 5.0f);
                    squareBrush.setSize({ squareBrush.getSize().x - 5.0f, squareBrush.getSize().y - 5.0f });
                    std::cout << "Decreasing brush size: " << circleBrush.getRadius() << std::endl;
                }

                // --- take a screenshot
                if (event.key.code == sf::Keyboard::U)
                {
                    std::cout << "Saved screenshot" << std::endl;
                    // update the texture with the current window
                    texture.update(window);
                    // save contents of texture to an image and save it
                    image = texture.copyToImage();
                    image.saveToFile("PaintingToolScreenshot.png");
                }
            }
            
            // close the window during a closed event
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // position shapes to where the mouse is
        circleBrush.setPosition(sf::Mouse::getPosition(window).x - circleBrush.getRadius(), sf::Mouse::getPosition(window).y - circleBrush.getRadius());
        squareBrush.setPosition(sf::Mouse::getPosition(window).x - squareBrush.getSize().x / 2, sf::Mouse::getPosition(window).y - squareBrush.getSize().y / 2);
        
        // detect left mouse click to draw shape
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
        {
            // draw either a circle or square depending on player settings
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