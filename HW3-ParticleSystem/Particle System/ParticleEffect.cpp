// Created by Nathann Latimore

#include "ParticleEffect.h"

ParticleEffect::ParticleEffect() {
	srand(time(0));
	particleArray = new Particle[NUM_PARTICLES];
	for (int i = 0; i < NUM_PARTICLES; i++) {
		particleArray[i].SetLifespan(sf::seconds(-1));
		particleArray[i].SetLifespanRemaining(sf::seconds(-1));
		particleArray[i].SetPosition(sf::Vector2f(0,0));
		particleArray[i].SetVecolity(sf::Vector2f(0, 0));
	}
	prevElapsed = sf::seconds(0);
}

ParticleEffect::ParticleEffect(const sf::Vector2i& mousePosition, const sf::Time& minLifeSpan, const sf::Time& maxLifeSpan, float minSize, float maxSize, float maxVelocity) {
	particleArray = new Particle[NUM_PARTICLES];
	for (int i = 0; i < NUM_PARTICLES; i++) {
		// Randomization calculation
		float lifeSpanCalc = Random::Range(minLifeSpan.asSeconds(), maxLifeSpan.asSeconds());
		float sizeCalc = Random::Range(minSize, maxSize);
		float velocityXCalc = Random::Range(-maxVelocity, maxVelocity);
		float velocityYCalc = Random::Range(-maxVelocity, maxVelocity);
		
		// set random vars of particles
		particleArray[i].SetLifespan(sf::seconds(lifeSpanCalc));
		particleArray[i].SetLifespanRemaining(sf::seconds(lifeSpanCalc));
		particleArray[i].SetPosition(sf::Vector2f((float)mousePosition.x, (float)mousePosition.y));
		particleArray[i].SetSize(sizeCalc);
		particleArray[i].SetVecolity(sf::Vector2f(velocityXCalc, velocityYCalc));
	}
	prevElapsed = sf::seconds(0);
}

void ParticleEffect::Update(const sf::Time& elapsedTime) {
	// determine how much time elapsed in this frame (deltaTime)
	sf::Time deltaTime = elapsedTime - prevElapsed;
	prevElapsed = elapsedTime;
	// update all of the particles in the array
	for (int  i = 0; i < NUM_PARTICLES; i++) {
		particleArray[i].Update(deltaTime);
	}
}

void ParticleEffect::Render(sf::RenderWindow& window) {
	for (int i = 0; i < NUM_PARTICLES; i++) {
		particleArray[i].Render(window);
	}
}

ParticleEffect::~ParticleEffect() {
	delete[] particleArray;
}