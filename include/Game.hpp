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

#include <iostream>
#include <typeinfo>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "Music.hpp"

class Player;
class Button;
class Block;
class AllMusic;

class Window{
    public:
        int screen_width = 1920;
        int screen_height = 1080;
};

class Map{
    public:
        std::vector<Block> blocks;
};

class Game{
    public:
        Game();
        ~Game();

        void game_loop();
        void update();
        void input();
        void draw();
        void random_map();
        void basic_map();
        void draw_text();

        Window window;
        Camera camera;
        AllMusic *audio;
        std::vector<Button> buttons;
        Map map;
        std::vector<Player> players;
        bool debug = false;
        int status = 0;
        int map_generated = 0;
};

#include "Button.hpp"
#include "Block.hpp"
#include "Player.hpp"

#endif
