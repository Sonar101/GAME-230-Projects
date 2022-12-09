#include "WeakBlock.h"

using namespace sf;
using namespace gm;

WeakBlock::WeakBlock() : Block(sf::Vector2f(0,0), BLOCKSIZE) {
	
}

void WeakBlock::TakeDamage() {
	isAlive = false; 
}
