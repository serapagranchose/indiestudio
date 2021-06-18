/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for game class
*/

#ifndef GAME_HPP_
#define GAME_HPP_

extern "C" {
    #include <raylib.h>
}

#define NUM_FRAMES 3
#define NUM_SOUND 11

#include <iostream>
#include <typeinfo>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include <thread>
#include <chrono>

#include "Audio.hpp"
#include "Map.hpp"
#include "Button.hpp"
#include "Block.hpp"
#include "Player.hpp"

class Audio;
class Map;
class Player;
class Button;

class Window{
    public:
        int _ScreenWidth = 1920;
        int _ScreenHeight = 1080;
};

class Game{
    public:
        Game();
        ~Game();

        int getStatus() const;
        void setStatus(const int status);
        Map* getMap() const;
        Audio *getAudio() const;
        std::vector<Player> getPlayers() const;
        Camera getCamera() const;
        int getGenerated() const;
        void setDebug(const bool);
        void setNbPlayer(const int);

        void game_loop();
        void update();
        void input();
        void draw();
        void draw_text();
        void initButton();
        void initPlayer();
        void pushPlayer();
        void popPlayer();

        std::vector<std::string> namePlayer;

    private:
        Window _Window;
        Camera _Camera;
        Audio *_Audio;
        std::vector<Button> _Buttons;
        Map *_Map;
        std::vector<Player> _Players;
        Texture2D _Menu;
        bool _Debug = false;
        int _Status = 0;
        int _MapGenerated = 0;
        int _FramesAnim = 0;
        int _FramesAnimCount = 0;
        double _LastGifTime;
        double _GifFrameRate;
        Image _ImageAnim;
        Font _Font;
        int _FramesCount = 0;
};

std::vector<std::string> str_to_word_array(std::string string);

#endif
