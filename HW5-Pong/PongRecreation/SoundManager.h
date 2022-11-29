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
        score,
        gameEnd
    };

    class SoundManager {
    public:
        SoundManager();
        void PlaySFX(SoundEffect type);
        ~SoundManager();
    private:
        sf::SoundBuffer paddleHitSFX;
        sf::SoundBuffer wallHitSFX;
        sf::SoundBuffer scoreSFX;
        sf::SoundBuffer gameEndSFX;
        sf::Sound sound;
    };
}


#endif