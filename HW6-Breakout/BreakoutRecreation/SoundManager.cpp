#include "SoundManager.h"

using namespace sf;
using namespace gm;

SoundManager::SoundManager() {
	if (!paddleHitSFX.loadFromFile("SFX/paddleHit.wav")) {
		throw("ERROR — Could not load sound");
	}
	if (!wallHitSFX.loadFromFile("SFX/wallHit.wav")) {
		throw("ERROR — Could not load sound");
	}
	if (!loseLifeSFX.loadFromFile("SFX/loseLife.wav")) {
		throw("ERROR — Could not load sound");
	}
	if (!gameOverSFX.loadFromFile("SFX/gameOver.wav")) {
		throw("ERROR — Could not load sound");
	}
	if (!blockBreakSFX.loadFromFile("SFX/blockBreak.wav")) {
		throw("ERROR — Could not load sound");
	}
	if (!blockCrackSFX.loadFromFile("SFX/blockCrack.wav")) {
		throw("ERROR — Could not load sound");
	}
	if (!levelCompleteSFX.loadFromFile("SFX/levelComplete.wav")) {
		throw("ERROR — Could not load sound");
	}
}

void SoundManager::PlaySFX(SoundEffect type) {
	if (type == paddleHit) {
		sound.setBuffer(paddleHitSFX);
	} else if (type == wallHit) {
		sound.setBuffer(wallHitSFX);
	} else if (type == loseLife) {
		sound.setBuffer(loseLifeSFX);
	} else if (type == gameOver) {
		sound.setBuffer(gameOverSFX);
	} else if (type == blockBreak) {
		sound.setBuffer(blockBreakSFX);
	} else if (type == blockCrack) {
		sound.setBuffer(blockCrackSFX);
	} else {
		sound.setBuffer(levelCompleteSFX);
	}

	sound.play();
}

SoundManager::~SoundManager() {

}