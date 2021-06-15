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

void AllMusic::init(Game *bomberman)
{
    InitAudioDevice();
    SetMasterVolume(this->volume);
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

float AllMusic::getVolume()
{
    return (this->volume);
}

void AllMusic::setVolume(float _volume)
{
    this->volume = _volume;
}