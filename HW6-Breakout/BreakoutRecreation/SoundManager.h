#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <algorithm>

namespace gm {

    enum SoundEffect {
        paddleHit,
        wallHit,
        loseLife,
        gameEnd,
        blockBreak,
        blockCrack
    };

    class SoundManager {
    public:
        SoundManager();
        void PlaySFX(SoundEffect type);
        ~SoundManager();
    private:
        sf::SoundBuffer paddleHitSFX;
        sf::SoundBuffer wallHitSFX;
        sf::SoundBuffer loseLifeSFX;
        sf::SoundBuffer gameEndSFX;
        sf::SoundBuffer blockBreakSFX;
        sf::SoundBuffer blockCrackSFX;
        sf::Sound sound;
    };
}


#endif