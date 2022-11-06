// Created by Nathann Latimore

#include "Particle.h"

const float SHAPE_SIZE = 10;

Particle::Particle() {
	lifespan = sf::seconds(0);
	lifespanRemaining = lifespan;
	velocity = sf::Vector2f(0,0);
	isAlive = true;
	shape = sf::CircleShape(SHAPE_SIZE);
}

void Particle::Update(const sf::Time& deltaTime) {
	
	if (isAlive) {
		// add force to alter position (with respect to time)
		shape.setPosition(shape.getPosition().x + velocity.x * deltaTime.asSeconds(), shape.getPosition().y + velocity.y * deltaTime.asSeconds());

		// manage lifespawn
		lifespanRemaining -= deltaTime;

		// check if still alive
		if (lifespanRemaining <= sf::seconds(0)) {
			isAlive = false;
		}
	}
}

void Particle::Render(sf::RenderWindow& window) {
	if (isAlive) {
		window.draw(shape);
	}
}

Particle::~Particle() {

}

// --- Getters
const sf::Vector2f& Particle::GetVelocity() {
	return velocity;
}

const sf::Time& Particle::GetLifespan() {
	return lifespan;
}

const sf::Time& Particle::GetLifespanRemaining() {
	return lifespanRemaining;
}

bool Particle::GetIsAlive() {
	return isAlive;
}

// --- Setters
void Particle::SetPosition(const sf::Vector2f& vector) {
	shape.setPosition(vector);
}

void Particle::SetVecolity(const sf::Vector2f& vector) {
	velocity.x = vector.x;
	velocity.y = vector.y;
}

void Particle::SetLifespan(const sf::Time& time) {
	lifespan = time;
}

void Particle::SetLifespanRemaining(const sf::Time& time) {
	lifespanRemaining = time;
}

void Particle::SetIsAlive(bool condition) {
	isAlive = condition;
}

void Particle::SetSize(float size) {
	shape.setRadius(size);
}