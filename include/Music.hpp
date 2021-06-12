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

class AllMusic {
    public:
        AllMusic();
        ~AllMusic();

        void init();
        void setMusic(std::string path);
        void endMusic();
        void update();
        void playMusic();

        float timePlayed = 0.0f;
        bool pause = false;
    private:
        Music track;
};

#endif