#ifndef SNOW_EFFECT_H
#define SNOW_EFFECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "ParticleEffect.h"
#include "CircleParticle.h"

class SnowEffect : public ParticleEffect {
public:
	SnowEffect();
	~SnowEffect();
	void CreateParticles(int numParticles, const sf::Vector2i& mousePosition) override;
	void CreateParticle(int index, const sf::Vector2i& mousePosition) override;
private:

};

#endif 