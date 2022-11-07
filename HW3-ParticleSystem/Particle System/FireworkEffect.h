#ifndef FIREWORK_EFFECT_H
#define FIREWORK_EFFECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "ParticleEffect.h"
#include "ColorParticle.h"

class FireworkEffect : public ParticleEffect {
public:
	FireworkEffect();
	~FireworkEffect();
	void CreateParticles(int numParticles, const sf::Vector2i& mousePosition) override;
	void CreateParticle(int index, const sf::Vector2i& mousePosition) override;
private:

};

#endif 
