/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Music
*/

#include "Audio.hpp"

Audio::Audio()
{
}

Audio::~Audio()
{
}

void Audio::init(Game *bomberman)
{
    InitAudioDevice();
    SetMasterVolume(this->_Volume);
}

void Audio::setMusic(std::string path)
{
    this->_Track = LoadMusicStream(path.c_str());
}

void Audio::playMusic()
{
    PlayMusicStream(this->_Track);
}

void Audio::endMusic()
{
    CloseAudioDevice();
    UnloadMusicStream(this->_Track);
}

void Audio::update()
{
    UpdateMusicStream(this->_Track);
}

float Audio::getVolume() const
{
    return (this->_Volume);
}

void Audio::setVolume(const float volume)
{
    this->_Volume = volume;
}
