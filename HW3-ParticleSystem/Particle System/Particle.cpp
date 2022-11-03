// Created by Nathann Latimore

#include "Particle.h"

const float SHAPE_SIZE = 10;

Particle::Particle() {
	lifeSpan = sf::seconds(2);
	velocityX = 0;
	velocityY = 0;
	alive = true;
	shape = sf::CircleShape(SHAPE_SIZE);
}

void Particle::SetPosition(float x, float y) {
	shape.setPosition(x, y);
}

void Particle::SetVecolity(float x, float y) {
	velocityX = x;
	velocityY = y;
}

void Particle::SetSize(float size) {
	shape.setRadius(size);
}

void Particle::Update(const sf::Time& elapsedTime, const sf::Time& deltaTime) {
	
	if (alive) {
		// add force to alter position (with respect to time)
		shape.setPosition(shape.getPosition().x + velocityX * deltaTime.asSeconds(), shape.getPosition().y + velocityY * deltaTime.asSeconds());

		// check if still alive
		if (lifeSpan <= elapsedTime) {
			alive = false;
		}
	}
}

void Particle::Render(sf::RenderWindow& window) {
	if (alive) {
		window.draw(shape);
	}
}

Particle::~Particle() {

}