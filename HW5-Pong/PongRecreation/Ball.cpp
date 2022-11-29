#include "Ball.h"

using namespace sf;
using namespace gm;

Ball::Ball(const Vector2f& position, const Vector2f& size) : GameObject(position, size), direction(BallDirection::Left), totalKnocks(0) {
	body.setPosition(position);
	body.setRadius(size.x / 2);
	velocity = Vector2f(-MinBallSpeedPerSecond, 0);
	std::cout << "rect: " << collider.width << ", " << collider.height << std::endl;
}

void Ball::update(sf::RenderWindow& window, float deltaTime) {
	move(Vector2f(velocity.x * deltaTime, velocity.y * deltaTime));
}

void Ball::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Ball::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
}

void Ball::setVelocity(const sf::Vector2f& velocity) {
	this->velocity = velocity;
}

void Ball::move(const Vector2f& velocity) {
	GameObject::move(velocity);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
}

void Ball::setBallDirection(BallDirection direction) {
	this->direction = direction;
}

BallDirection Ball::getBallDirection() const {
	return direction;
}

void Ball::knockBack(const float paddleHeight, const float paddleY) {
	totalKnocks++;
	
	float relativeColY = paddleY+(paddleHeight/2) - position.y; // (if paddleHeight is 100, will be between -50 and 50)
	float normalizedRelativeColY = relativeColY/(paddleHeight/2);
	float currBounceAngle = MaxBounceAngle * normalizedRelativeColY;
	
	float currSpeed = MinBallSpeedPerSecond + (totalKnocks*knockSpeedAdd);
	std::cout << currSpeed << std::endl;

	if (direction == Left) {
		setVelocity(sf::Vector2f(currSpeed * cos(currBounceAngle), currSpeed * -sin(currBounceAngle)));
		setBallDirection(BallDirection::Right);
	}
	else {
		setVelocity(sf::Vector2f( -(currSpeed * cos(currBounceAngle)), currSpeed * -sin(currBounceAngle)));
		setBallDirection(BallDirection::Left);
	}
	
}

void Ball::setTotalKnocks(int val) {
	totalKnocks = val;
}

const sf::Vector2f& Ball::getVelocity() const {
	return velocity;
}


const Color& Ball::getFillColor() const {
	return body.getFillColor();
}

void Ball::setFillColor(const Color& color) {
	body.setFillColor(color);
}