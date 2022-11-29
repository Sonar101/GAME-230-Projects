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
	if (!scoreSFX.loadFromFile("SFX/score.wav")) {
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
	} else if (type == score) {
		sound.setBuffer(scoreSFX);
	} else {
		sound.setBuffer(gameEndSFX);
	}

	sound.play();
}

SoundManager::~SoundManager() {

}