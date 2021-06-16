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

#include "Music.hpp"
#include "Map.hpp"

class Player;
class Button;
class Block;

class Window{
    public:
        int screen_width = 1920;
        int screen_height = 1080;
};

class Game{
    public:
        Game();
        ~Game();

        void game_loop();
        void update();
        void input();
        void draw();
        void draw_text();
        void initButton();
        void initPlayer();

        int getStatus() const;
        void setStatus(const int status);
        Map* getMap() const;
        AllMusic *getMusic() const;
        std::vector<Player> getPlayer() const;
        Camera getCamera() const;
        int getGenerated() const;
        void setDebug(const bool);

    private:
        Window window;
        Camera camera;
        AllMusic *audio;
        std::vector<Button> buttons;
        Map *map;
        std::vector<Player> players;
        Texture2D menu;
        bool debug = false;
        int status = 0;
        int map_generated = 0;
        int framesAnim = 0;
        int framesAnimCount = 0;
        double lastGifTime;
        double gifFrameRate;
        Image imageAnim;
        Font font;
        int framesCount = 0;
};

std::vector<std::string> str_to_word_array(std::string string);

#include "Button.hpp"
#include "Block.hpp"
#include "Player.hpp"

#endif
