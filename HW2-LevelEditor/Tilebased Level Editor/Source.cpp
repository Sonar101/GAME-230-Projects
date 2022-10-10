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
    const int TILE_SIZE = 70; // pixels
    const int NUM_TILES_IN_X = 10;
    const int NUM_TILES_IN_Y = 10;
    const int NUM_TILE_IMAGES = 21; // 0 index
    
    // initialize the render window
    sf::RenderWindow window(sf::VideoMode(TILE_SIZE * NUM_TILES_IN_X, TILE_SIZE * NUM_TILES_IN_Y), "SFML works!");
    
    // set up a texture and image to enable screenshot saving
    sf::Texture screenshotTexture;
    screenshotTexture.create(window.getSize().x, window.getSize().y);
    sf::Image screenshotImage;

    /* ----------------- Tileset Setup ----------------- */
    
    // Load all textures into array
    sf::Texture* textures = new sf::Texture[NUM_TILE_IMAGES];
    for (int i = 0; i < NUM_TILE_IMAGES; i++)
    {
        // --- Load an image file from a file
        sf::Image tileImage;
        if (!tileImage.loadFromFile("./Tileset/Platformer-" + std::to_string(i) + ".png")) return -1;
        // --- Copy image to a texture
        sf::Texture tileTexture;
        if (!tileTexture.loadFromImage(tileImage, sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE))) return -1;
        // --- Add texture to array
        textures[i] = tileTexture;
    }

    // --- Create array of sprites
    sf::Sprite** levelSprites = new sf::Sprite*[NUM_TILES_IN_X];
    for (int i = 0; i < NUM_TILES_IN_X; i++) 
    {
        // allocating the outer array (columns)
        levelSprites[i] = new sf::Sprite[NUM_TILES_IN_Y];
    }
    for (int column = 0; column < NUM_TILES_IN_X; column++)
    {
        for (int row = 0; row < NUM_TILES_IN_Y; row++)
        {
            // allocating the inner array (rows)
            levelSprites[column][row].setPosition(column * TILE_SIZE, row * TILE_SIZE);
            levelSprites[column][row].setTexture(textures[row % NUM_TILE_IMAGES]);
        }
    }
    
    // run while window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            /* checking single key press events */
            if (event.type == sf::Event::KeyPressed)
            {
                // changing tile on brush
                if (event.key.code == sf::Keyboard::Up)
                {
                    std::cout << "Swapping tile" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    std::cout << "Swapping tile" << std::endl;
                }

                // --- take a screenshot
                if (event.key.code == sf::Keyboard::Space)
                {
                    std::cout << "Saved screenshot" << std::endl;
                    // update the texture with the current window
                    screenshotTexture.update(window);
                    // save contents of texture to an image and save it
                    screenshotImage = screenshotTexture.copyToImage();
                    screenshotImage.saveToFile("PaintingToolScreenshot.png");
                }
            }
            
            // close the window during a closed event
            if (event.type == sf::Event::Closed)
            {
                /* close window */
                window.close();
            }
        }

        // Render
        window.clear();

        for (int column = 0; column < NUM_TILES_IN_X; column++)
        {
            for (int row = 0; row < NUM_TILES_IN_Y; row++)
            {
                window.draw(levelSprites[column][row]);
            }
        }

        window.display();
    }

    /* Delete allocations */
    
    // delete texture array
    delete[] textures;
    
    // delete sprite 2D array
    for (int i = 0; i < NUM_TILES_IN_X; i++)
    {
        delete[] levelSprites[i];
    }
    delete[] levelSprites;

    return 0;
}