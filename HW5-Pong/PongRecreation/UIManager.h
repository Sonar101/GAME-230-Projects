#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

namespace gm {
    class UIManager {
    public:
        UIManager();
        void Render(sf::RenderWindow& window, float deltaTime) const;
        void SetScore1(int val);
        void SetScore2(int val);
        void SetMessageText(const std::string& text);
        void SetIsDisplayingMessage(bool val);
        void SetUIPosition(const sf::Vector2f& score1Pos, const sf::Vector2f& score2Pos, const sf::Vector2f& messagePos);
    private:
        bool isDisplayingMessage;
        sf::Font uiFont;
        int score1;
        int score2;
        sf::Text scoreText1;
        sf::Text scoreText2;
        sf::Text messageText;
    };

}


#endif