// Created by Nathann Latimore

#include "Particle.h"

const float SHAPE_SIZE = 10;

Particle::Particle() {
	lifespan = sf::seconds(0);
	lifespanRemaining = lifespan;
	position = sf::Vector2f(0,0);
	velocity = sf::Vector2f(0,0);
	isAlive = true;
}

void Particle::Update(const sf::Time& deltaTime) {
	
	// manage lifespan
	lifespanRemaining -= deltaTime;

	// check if still alive based on lifespan
	if (lifespanRemaining > sf::seconds(0)) {
		isAlive = true;
	} else {
		isAlive = false;
	}

	if (isAlive) {
		// add force to alter position (with respect to time)
		if (deltaTime.asSeconds() >= 0) {
			position = sf::Vector2f(position.x + velocity.x * deltaTime.asSeconds(), position.y + velocity.y * deltaTime.asSeconds());
		}
		
	}
}

Particle::~Particle() {
	
}

// --- Getters
const sf::Vector2f& Particle::GetPosition() {
	return position;
}

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
	position = vector;
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