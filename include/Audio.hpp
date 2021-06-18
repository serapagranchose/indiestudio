/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Music class
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include "Game.hpp"

class Game;

class Audio {
    public:
        Audio();
        ~Audio();

        float getVolume() const;
        void setVolume(const float _volume);

        void init(Game *bomberman);
        void setMusic(std::string path);
        void endMusic();
        void update();
        void playMusic();

    private:
        float _TimePlayed = 0.0f; //whut
        bool _Pause = false; //whut
        Music _Track;
        float _Volume = 0.5;
};

#endif
