// Created by Nathann Latimore

#include "ParticleEffect.h"

ParticleEffect::ParticleEffect() {
	srand(time(0));
	particleArray = new Particle[NUM_PARTICLES];
	for (int i = 0; i < NUM_PARTICLES; i++) {
		particleArray[i].lifeSpan = sf::seconds(-1);
		particleArray[i].SetPosition(0,0);
		particleArray[i].SetVecolity(0,0);
	}
	prevElapsed = sf::seconds(0);
}

ParticleEffect::ParticleEffect(sf::Vector2i mousePosition, sf::Time minLifeSpan, sf::Time maxLifeSpan, float minSize, float maxSize, float maxVelocity) {
	particleArray = new Particle[NUM_PARTICLES];
	for (int i = 0; i < NUM_PARTICLES; i++) {
		// Randomization calculation
		float lifeSpanCalc = Random::Range(minLifeSpan.asSeconds(), maxLifeSpan.asSeconds());
		float sizeCalc = Random::Range(minSize, maxSize);
		float velocityXCalc = Random::Range(-maxVelocity, maxVelocity);
		float velocityYCalc = Random::Range(-maxVelocity, maxVelocity);
		
		// set random vars of particles
		particleArray[i].lifeSpan = sf::seconds(lifeSpanCalc);
		particleArray[i].SetPosition((float)mousePosition.x, (float)mousePosition.y);
		particleArray[i].SetSize(sizeCalc);
		particleArray[i].SetVecolity(velocityXCalc, velocityYCalc);
	}
	prevElapsed = sf::seconds(0);
}

void ParticleEffect::Update(sf::Time elapsedTime) {
	// determine how much time elapsed in this frame (deltaTime)
	sf::Time deltaTime = elapsedTime - prevElapsed;
	prevElapsed = elapsedTime;
	// update all of the particles in the array
	for (int  i = 0; i < NUM_PARTICLES; i++) {
		particleArray[i].Update(elapsedTime, deltaTime);
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