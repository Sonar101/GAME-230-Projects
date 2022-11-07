#ifndef COLOR_PARTICLE_H
#define COLOR_PARTICLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "ShapeParticle.h"

class ColorParticle : public ShapeParticle {
public:
	ColorParticle();
	~ColorParticle();
	void Update(const sf::Time& deltaTime) override;
	void Render(sf::RenderWindow& window) override;

	// --- Setters
	void SetRect(float value);
	void SetColor(const sf::Color& colorValue);
private:
	sf::Color color;
};

#endif 