/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Music
*/

#include "Music.hpp"

AllMusic::AllMusic()
{
}

AllMusic::~AllMusic()
{
}

void AllMusic::init()
{
    InitAudioDevice();
    std::cout << IsAudioDeviceReady() << std::endl;
    SetMasterVolume(0.5);
}

void AllMusic::setMusic(std::string path)
{
    track = LoadMusicStream(path.c_str());
}

void AllMusic::playMusic()
{
    PlayMusicStream(this->track);
}

void AllMusic::endMusic()
{
    CloseAudioDevice();
    UnloadMusicStream(this->track);
}

void AllMusic::update()
{
    UpdateMusicStream(this->track);
}