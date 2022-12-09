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
	if (!gameEndSFX.loadFromFile("SFX/gameEnd.wav")) {
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
	} else if (type == gameEnd) {
		sound.setBuffer(gameEndSFX);
	} else if (type == blockBreak) {
		sound.setBuffer(blockBreakSFX);
	} else {
		sound.setBuffer(blockCrackSFX);
	}

	sound.play();
}

SoundManager::~SoundManager() {

}