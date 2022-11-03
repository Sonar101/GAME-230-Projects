// Created by Nathann Latimore

#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

class Particle {
public:
	sf::Time lifeSpan;
	Particle();
	void SetPosition(float, float);
	void SetVecolity(float, float);
	void SetSize(float);
	void Update(const sf::Time&, const sf::Time&);
	void Render(sf::RenderWindow&);
	~Particle();
private:
	float velocityX;
	float velocityY;
	bool alive;
	sf::CircleShape shape;
};

#endif // !PARTICLE_H
