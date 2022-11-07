#include "ColorParticle.h"

ColorParticle::ColorParticle() {
	// unsure if need to call base class constructor
	shape = new sf::RectangleShape();
}

ColorParticle::~ColorParticle() {
	delete shape;
}

void ColorParticle::Update(const sf::Time& deltaTime) {
	ShapeParticle::Update(deltaTime);
	float opacityVal = GetLifespanRemaining().asSeconds() / GetLifespan().asSeconds();
	if (opacityVal >= 0) {
		shape->setFillColor(sf::Color(color.r, color.g, color.b, 255 * opacityVal));
	}
	else {
		shape->setFillColor(sf::Color(255, 255, 255, 0));
	}
}

void ColorParticle::Render(sf::RenderWindow& window) {
	if (isAlive) {
		window.draw(*shape);
	}
}

void ColorParticle::SetRect(float value) {
	dynamic_cast<sf::RectangleShape*>(shape)->setSize(sf::Vector2f(value, value));
}

void ColorParticle::SetColor(const sf::Color& colorVal) {
	color = colorVal;
}