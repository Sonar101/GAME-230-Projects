#include "Paddle.h"

using namespace sf;
using namespace gm;

Paddle::Paddle(const Vector2f& position, const Vector2f& size) : GameObject(position, size), direction(MovementDirection::None), verticalVelocity(PlayerMovementSpeedPerSecond) {
	body.setPosition(position);
	body.setSize(size);
}

void Paddle::update(sf::RenderWindow& window, float deltaTime) {
	move(Vector2f(0, verticalVelocity * direction * deltaTime));
	// Account for when the paddle reaches the bounds of the play area
	if (getPosition().y < 0) {
		setPosition(sf::Vector2f(position.x, 0));
		body.setPosition(position);
	}
	else if (getPosition().y > window.getSize().y - body.getSize().y) {
		setPosition(sf::Vector2f(position.x, window.getSize().y - body.getSize().y));
		body.setPosition(position);
	}
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