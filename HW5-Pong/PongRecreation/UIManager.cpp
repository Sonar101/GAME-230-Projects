#include "UIManager.h"

using namespace sf;
using namespace gm;

UIManager::UIManager() {
	
	score1 = 0;
	score2 = 0;
	isDisplayingMessage = false;
	
	if (!uiFont.loadFromFile("Fonts/arial.ttf")) {
		throw("ERROR — Could not load font");
	}
	
	scoreText1.setFont(uiFont);
	scoreText1.setCharacterSize(96);
	scoreText1.setString("0");

	scoreText2.setFont(uiFont);
	scoreText2.setCharacterSize(96);
	scoreText2.setString("0");

	messageText.setFont(uiFont);
	messageText.setCharacterSize(48);
	messageText.setString("");
}

void UIManager::Render(sf::RenderWindow& window, float deltaTime) const {
	window.draw(scoreText1);
	window.draw(scoreText2);
	if (isDisplayingMessage) {
		window.draw(messageText);
	}
}

void UIManager::SetScore1(int val) {
	scoreText1.setString(std::to_string(val));
}

void UIManager::SetScore2(int val) {
	scoreText2.setString(std::to_string(val));
}

void UIManager::SetMessageText(const std::string& text) {
	messageText.setString(text);
}

void UIManager::SetIsDisplayingMessage(bool val) {
	isDisplayingMessage = val;
}

void UIManager::SetUIPosition(const sf::Vector2f& score1Pos, const sf::Vector2f& score2Pos, const sf::Vector2f& messagePos) {
	scoreText1.setPosition(score1Pos);
	scoreText2.setPosition(score2Pos);
	messageText.setPosition(messagePos);
}