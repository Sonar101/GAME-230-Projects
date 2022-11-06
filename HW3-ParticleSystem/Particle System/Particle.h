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
	Particle();
	~Particle();
	void Update(const sf::Time& deltaTime);
	void Render(sf::RenderWindow& window);
	
	// -- Getters
	const sf::Vector2f& GetVelocity();
	const sf::Time& GetLifespan();
	const sf::Time& GetLifespanRemaining();
	bool GetIsAlive();
	
	// --- Setters
	void SetPosition(const sf::Vector2f& vector);
	void SetVecolity(const sf::Vector2f& vector);
	void SetLifespan(const sf::Time& time);
	void SetLifespanRemaining(const sf::Time& time);
	void SetIsAlive(bool condition);
	void SetSize(float);
private:
	sf::Vector2f velocity;
	sf::Time lifespan;
	sf::Time lifespanRemaining;
	bool isAlive;
	sf::CircleShape shape;
};

#endif // !PARTICLE_H
