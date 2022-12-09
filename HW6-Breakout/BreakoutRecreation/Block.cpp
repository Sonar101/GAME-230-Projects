#include "Block.h"

using namespace sf;
using namespace gm;

Block::Block() : GameObject(sf::Vector2f(0, 0), BLOCKSIZE), isAlive(true), blockType(weak), health(1), pointValue(1) {
	body.setPosition(position);
	body.setSize(BLOCKSIZE);
}

Block::Block(const Vector2f& position, const Vector2f& size) : GameObject(position, size), isAlive(true), blockType(weak), health(1), pointValue(1) {
	body.setPosition(position);
	body.setSize(size);
}

void Block::update(sf::RenderWindow& window, float deltaTime) {
	
}

void Block::render(sf::RenderWindow& window, float deltaTime) {
	if (isAlive) {
		window.draw(body);
	}
}

void Block::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Block::setFillColor(const Color& color) {
	body.setFillColor(color);
}

void Block::setIsAlive(bool condition) {
	isAlive = condition;
}

void Block::setUpBlock(const BlockType& type) {
	blockType = type;
	
	if (blockType == weak) {
		health = 1;
		pointValue = 100;
		setFillColor(sf::Color(0, 255, 42));
	} else {
		health = 2;
		pointValue = 200;
		setFillColor(sf::Color(181,0,0));
	}
}

bool Block::getIsAlive() const {
	return isAlive;
}

int Block::TakeDamage() {
	health--;

	if (blockType == strong) {
		// change color
		setFillColor(sf::Color(245, 142, 142));
	}

	if (health <= 0) {
		isAlive = false;
		return pointValue;
	} else {
		return 0;
	}
}

const Color& Block::getFillColor() const {
	return body.getFillColor();
}