#include "Paddle.h"

using namespace sf;
using namespace gm;

Paddle::Paddle(const Vector2f& position, const Vector2f& size) : GameObject(position, size), direction(MovementDirection::None), verticalVelocity(PlayerMovementSpeedPerSecond) {
	body.setPosition(position);
	body.setSize(size);
}

void Paddle::update(sf::RenderWindow& window, float deltaTime) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f relMousePos = sf::Vector2f(mousePos.x - body.getSize().x/2, mousePos.y);

	// Account for when the paddle reaches the bounds of the play area
	if (relMousePos.x < 0) {
		setPosition(sf::Vector2f(0, position.y));
	}
	else if (relMousePos.x + body.getSize().x > window.getSize().x) {
		setPosition(sf::Vector2f(window.getSize().x - body.getSize().x, position.y));
	}
	else {
		GameObject::setPosition(sf::Vector2f(relMousePos.x, position.y));
	}

	body.setPosition(position);
}

void Paddle::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Paddle::move(const Vector2f& velocity) {
	GameObject::move(velocity);
	body.setPosition(position);
}

void Paddle::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Paddle::setMovmentDirection(MovementDirection direction) {
	this->direction = direction;
}

void Paddle::setVerticalVelocity(float val) {
	this->verticalVelocity= val;
}

void Paddle::setFillColor(const Color& color) {
	body.setFillColor(color);
}

const MovementDirection& Paddle::getMovementDirection() const {
	return direction;
}

const Color& Paddle::getFillColor() const {
	return body.getFillColor();
}