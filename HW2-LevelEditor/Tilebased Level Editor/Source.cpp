#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <string>
#include <iostream>
#include <fstream>


int main()
{
    const int TILE_SIZE = 70; // pixels
    const int NUM_TILES_IN_X = 10;
    const int NUM_TILES_IN_Y = 10;
    const int NUM_TILE_IMAGES = 21; // 0 index

    int currTileNum = 0;
    
    // initialize the render window
    sf::RenderWindow window(sf::VideoMode(TILE_SIZE * NUM_TILES_IN_X, TILE_SIZE * NUM_TILES_IN_Y), "SFML works!");
    
    // set up a texture and image to enable screenshot saving
    sf::Texture screenshotTexture;
    screenshotTexture.create(window.getSize().x, window.getSize().y);
    sf::Image screenshotImage;

    /* ----------------- Tileset Setup ----------------- */
    
    // make a default, empty texture;
    sf::Texture emptyTexture;
    emptyTexture.create(TILE_SIZE, TILE_SIZE);

    // Load all textures into array
    sf::Texture* textures = new sf::Texture[NUM_TILE_IMAGES];
    for (int i = 0; i < NUM_TILE_IMAGES; i++)
    {
        // --- Load an image file from a file
        sf::Image tileImage;
        if (!tileImage.loadFromFile("./Tileset/Platformer-" + std::to_string(i) + ".png")) return -1;
        std::cout << "Loaded ./Tileset/Platformer-" << std::to_string(i) << ".png" << std::endl;
        // --- Copy image to a texture
        sf::Texture tileTexture;
        if (!tileTexture.loadFromImage(tileImage, sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE))) return -1;
        // --- Add texture to array
        textures[i] = tileTexture;
    }

    // Create array of sprites
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
            levelSprites[column][row].setTexture(emptyTexture);
        }
    }

    // Create array of ints for storing scene state (to enable level saving)
    int levelArray[NUM_TILES_IN_X][NUM_TILES_IN_Y];
    for (int column = 0; column < NUM_TILES_IN_X; column++)
    {
        for (int row = 0; row < NUM_TILES_IN_Y; row++)
        {
            levelArray[column][row] = -1;
        }
    }

    // Create the tile sprite cursor (for indicating mouse pos and the tile that will be drawn)
    sf::Sprite tileSpriteCursor(textures[currTileNum]);
    
    // run while window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            /* ----------------- checking single key press events ----------------- */
            if (event.type == sf::Event::KeyPressed)
            {
                // changing tile on brush
                if (event.key.code == sf::Keyboard::Up)
                {
                    currTileNum++;
                    if (currTileNum >= NUM_TILE_IMAGES)
                    {
                        currTileNum = 0;
                    }
                    tileSpriteCursor.setTexture(textures[currTileNum]);
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    currTileNum--;
                    if (currTileNum < 0)
                    {
                        currTileNum = NUM_TILE_IMAGES - 1;
                    }
                    tileSpriteCursor.setTexture(textures[currTileNum]);
                }

                // --- take a screenshot
                if (event.key.code == sf::Keyboard::Space)
                {
                    std::cout << "Saved Screenshot" << std::endl;
                    // update the texture with the current window
                    screenshotTexture.update(window);
                    // save contents of texture to an image and save it
                    screenshotImage = screenshotTexture.copyToImage();
                    screenshotImage.saveToFile("Homework 2 Screenshot.png");
                }

                // --- save the level
                if (event.key.code == sf::Keyboard::S)
                {
                    // build level string to represent tile positions
                    std::string levelString = "";
                    for (int column = 0; column < NUM_TILES_IN_X; column++)
                    {
                        for (int row = 0; row < NUM_TILES_IN_Y; row++)
                        {
                            levelString = levelString + std::to_string(levelArray[column][row]) + " ";
                        }
                        levelString = levelString + "\n";
                    }

                    // open the level text file and save the level string in it
                    std::ofstream outfile("level.txt");
                    outfile << levelString << std::endl;
                    outfile.close();
                    std::cout << "Saved Level" << std::endl;
                }

                // --- Load the level
                if (event.key.code == sf::Keyboard::L)
                {
                    std::ifstream inputLevelFile;
                    inputLevelFile.open("level.txt", std::ios::out);
                    if (!inputLevelFile.is_open())
                    {
                        // can't open file, so give an error message
                        std::cout << "ERROR - Could not find level.txt file to load" << std::endl;
                    }
                    else
                    {
                        // --- read input
                        
                        std::string currLine;
                        int column = 0;
                        // for every line in the text file...
                        while(getline(inputLevelFile, currLine))
                        {
                            int row = 0;
                            std::string currWord = "";
                            int currCharNum = 0;
                            char currChar = currLine[currCharNum];
                            while (currCharNum < currLine.length()) {
                                // ...loop through the line and build the numbers out of single characters
                                if (currChar == ' ')
                                {
                                    if (stoi(currWord) != -1) 
                                    {
                                        // select the texture associated with the correct number
                                        levelSprites[column][row].setTexture(textures[stoi(currWord)]);
                                    }
                                    else 
                                    {
                                        // -1 should be an empty texture
                                        levelSprites[column][row].setTexture(emptyTexture);
                                    }
                                    // save tile type in the level array (for saving the level later)
                                    levelArray[column][row] = stoi(currWord);
                                    row++;
                                    currWord = "";
                                }
                                else if (currChar != '\n')
                                {
                                    currWord = currWord + currChar;
                                }
                                currCharNum++;
                                currChar = currLine[currCharNum];
                            }
                            column++;
                        }

                        std::cout << "Level Loaded" << std::endl;
                        inputLevelFile.close();
                    }

                }
            }
            
            /* ----------------- close the window during a closed event ----------------- */
            if (event.type == sf::Event::Closed)
            {
                /* close window */
                window.close();
            }
        }

        /* ----------------- Manage mouse input for tile drawing ----------------- */

        // --- get mouse position relative to the window
        int winX = sf::Mouse::getPosition(window).x;
        int winY = sf::Mouse::getPosition(window).y;
        bool isTileSelected = false;

        // --- get *tile* position of the mouse based on window position
        int tileX = (int)winX / (int)TILE_SIZE;
        int tileY = (int)winY / (int)TILE_SIZE;

        // --- if the mouse is within the bounds of the tiles...
        if (tileX >= 0 && tileY >= 0 && tileX < NUM_TILES_IN_X && tileY < NUM_TILES_IN_Y) 
        {
            // position the tileSpriteCursor over this tile
            tileSpriteCursor.setPosition(tileX* TILE_SIZE, tileY* TILE_SIZE);
            isTileSelected = true;
        }
        
        // --- if the left mouse is held down...
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isTileSelected)
        {
            // set the texture of the tile under the mouse
            levelSprites[tileX][tileY].setTexture(textures[currTileNum]);
            // save tile type in the level array (for saving)
            levelArray[tileX][tileY] = currTileNum;
        }

        // --- if the right mouse is held down...
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && isTileSelected)
        {
            // reset the texture of the tile under the mouse
            levelSprites[tileX][tileY].setTexture(emptyTexture);
            // save tile type in the level array (for saving)
            levelArray[tileX][tileY] = -1;
        }
        
        /* ----------------- Rendering ----------------- */
        window.clear();
        
        // draw all of the sprites in the scene
        for (int column = 0; column < NUM_TILES_IN_X; column++)
        {
            for (int row = 0; row < NUM_TILES_IN_Y; row++)
            {
                window.draw(levelSprites[column][row]);
            }
        }

        // draw the tileSpriteCursor if a tile is selected
        if (isTileSelected)
            window.draw(tileSpriteCursor);

        window.display();
    }

    /* ----------------- Delete allocations ----------------- */

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