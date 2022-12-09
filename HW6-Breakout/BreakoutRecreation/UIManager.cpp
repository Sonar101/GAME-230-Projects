#include "UIManager.h"

using namespace sf;
using namespace gm;

UIManager::UIManager() {
	
	if (!uiFont.loadFromFile("Fonts/arial.ttf")) {
		throw("ERROR — Could not load font");
	}
	
	sf::Color darkgreen = sf::Color(0,110,0);
	sf::Color grey = sf::Color(90, 90, 90);

	livesText.setFont(uiFont);
	livesText.setCharacterSize(30);
	livesText.setString("Text");
	livesText.setFillColor(darkgreen);

	scoreText.setFont(uiFont);
	scoreText.setCharacterSize(30);
	scoreText.setString("0");
	scoreText.setFillColor(darkgreen);

	backgroundText.setFont(uiFont);
	backgroundText.setCharacterSize(58);
	backgroundText.setString("Text");
	backgroundText.setFillColor(grey);
}

void UIManager::Render(sf::RenderWindow& window, float deltaTime) const {
	window.draw(livesText);
	window.draw(scoreText);
	window.draw(backgroundText);
}

void UIManager::SetLivesText(int val) {
	livesText.setString("Lives: " + std::to_string(val));
}

void UIManager::SetScoreText(int val) {
	scoreText.setString(std::to_string(val));
	FloatRect bounds = scoreText.getLocalBounds();
	scoreText.setPosition(scoreText.getPosition().x - bounds.width, scoreText.getPosition().y);
}

void UIManager::SetBackgroundText(const std::string& text) {
	backgroundText.setString(text);
}

void UIManager::SetBackgroundFontColor(const sf::Color& color) {
	backgroundText.setFillColor(color);
}

void UIManager::SetUIPosition(const sf::Vector2f& livesPos, const sf::Vector2f& scorePos, const sf::Vector2f& backgroundPos) {
	livesText.setPosition(livesPos);
	scoreText.setPosition(scorePos);
	FloatRect bounds = scoreText.getLocalBounds();
	scoreText.setPosition(scoreText.getPosition().x - bounds.width, scoreText.getPosition().y);
	backgroundText.setPosition(backgroundPos);
}