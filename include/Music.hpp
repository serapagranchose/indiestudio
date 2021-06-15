/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Music class
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

extern "C" {
    #include <raylib.h>
}

#include <iostream>

class Game;

class AllMusic {
    public:
        AllMusic();
        ~AllMusic();

        void init(Game *bomberman);
        void setMusic(std::string path);
        void endMusic();
        void update();
        void playMusic();

        float getVolume() const;
        void setVolume(const float _volume);

    private:
        float timePlayed = 0.0f;
        bool pause = false;
        Music track;
        float volume = 5;
};

#include "Game.hpp"

#endif