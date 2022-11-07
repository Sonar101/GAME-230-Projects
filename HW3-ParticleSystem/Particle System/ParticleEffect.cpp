// Created by Nathann Latimore

#include "ParticleEffect.h"

ParticleEffect::ParticleEffect() {
	prevElapsed = sf::seconds(0);
}

void ParticleEffect::CreateParticles(int numParticles,const sf::Vector2i& mousePosition) {
	prevElapsed = sf::seconds(0);
	
	// delete the previously initialized
	for (int i = 0; i < arraySize; i++) {
		delete particleArray[i];
	}
	delete[] particleArray;

	// allocate new array
	arraySize = numParticles;
	particleArray = new Particle*[arraySize];
	
	// add each element in the array
	for (int i = 0; i < arraySize; i++) {
		CreateParticle(i, mousePosition);
	}
}

void ParticleEffect::Update(const sf::Time& elapsedTime) {
	// determine how much time elapsed in this frame (deltaTime)
	sf::Time deltaTime = elapsedTime - prevElapsed;
	prevElapsed = elapsedTime;
	// update all of the particles in the array
	for (int  i = 0; i < arraySize; i++) {
		particleArray[i]->Update(deltaTime);
	}
}

void ParticleEffect::Render(sf::RenderWindow& window) {
	for (int i = 0; i < arraySize; i++) {
		particleArray[i]->Render(window);
	}
}

ParticleEffect::~ParticleEffect() {
	
}