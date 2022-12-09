#include "Ball.h"

using namespace sf;
using namespace gm;

Ball::Ball(const Vector2f& position, const Vector2f& size) : 
GameObject(position, size), 
levelTicks(0),
bounceTicks(0),
launched(false)
{
	body.setPosition(position);
	body.setRadius(size.x / 2);
	velocity = Vector2f(0, MinBallSpeedPerSecond);
}

void Ball::update(sf::RenderWindow& window, float deltaTime) {
	move(Vector2f(velocity.x * deltaTime, velocity.y * deltaTime));
}

void Ball::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Ball::move(const Vector2f& velocity) {
	if (launched) {
		GameObject::move(velocity);
		body.setPosition(position);
	}
}

void Ball::knockBack(const float paddleWidth, const float paddleX) {
	float relativeColX = paddleX + (paddleWidth / 2) - position.x; // (if paddleWidth is 100, will be between -50 and 50)
	float normalizedRelativeColX = -(relativeColX / (paddleWidth / 2));
	float currBounceAngle = (MaxBounceAngle * normalizedRelativeColX) + (M_PI / 2);

	float currSpeed = MinBallSpeedPerSecond + (levelTicks * levelSpeedAdd) + (bounceTicks * bounceSpeedAdd);
	
	setVelocity(sf::Vector2f(-(currSpeed * cos(currBounceAngle)), currSpeed * -sin(currBounceAngle)));
}

void Ball::increaseSpeedTicks(int levelVal, int bounceVal) {
	levelTicks += levelVal;
	bounceTicks += bounceVal;
}

void Ball::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Ball::setVelocity(const sf::Vector2f& velocity) {
	this->velocity = velocity;
}

void Ball::setSpeedTicks(int levelVal, int bounceVal) {
	levelTicks = levelVal;
	bounceTicks = bounceVal;
}

void Ball::setLaunched(bool condition) {
	launched = condition;
}

void Ball::setFillColor(const Color& color) {
	body.setFillColor(color);
}

const sf::Vector2f& Ball::getVelocity() const {
	return velocity;
}

bool Ball::getLaunched() const {
	return launched;
}

const Color& Ball::getFillColor() const {
	return body.getFillColor();
}