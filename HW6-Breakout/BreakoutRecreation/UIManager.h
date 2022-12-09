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
        void SetLivesText(int val);
        void SetScoreText(int val);
        void SetBackgroundText(const std::string& text);
        void SetBackgroundFontColor(const sf::Color& color);
        void SetUIPosition(const sf::Vector2f& score1Pos, const sf::Vector2f& score2Pos, const sf::Vector2f& messagePos);
    private:
        sf::Font uiFont;
        sf::Text livesText;
        sf::Text scoreText;
        sf::Text backgroundText;
    };

}


#endif