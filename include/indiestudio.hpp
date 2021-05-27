/*
** EPITECH PROJECT, 2021
** tekspice.hpp
** File description:
** header file with all the includes
*/

#ifndef __INDIESTUDIO_HPP__
#define __INDIESTUDIO_HPP__

extern "C" {
    #include <raylib.h>
}

#include <iostream>
#include <vector>
#include <time.h>

class Window{
    public:
        int status = 0;
        int screen_width = 1920;
        int screen_height = 1080;
};

class Block{
    public:
        Vector3 position = {0.0f, 0.0f, 0.0f};
        Vector3 size = {1.0f, 1.0f, 1.0f};
        Color color = GREEN;
        int destructible;
};

class Map{
    public:
        Vector3 position;

        Texture2D flat_map;
        Model model;
        std::vector<Block> blocks;
};

class Player{
    public:
        Vector3 position = {0.0f, 0.0f, 0.0f};
        Vector3 size = {1.0f, 4.0f, 1.0f};
        int bomb_nb;
        Color color = RED;

        Model model;
};

class Button{
    public:
        int status = 0;
        bool action = false;
        float frame_height;
        Texture2D texture;
        Rectangle size;
        Rectangle bounds;

        Model model;
};

class Game{
    public:
        int status = 0;
        Window window;
        Camera camera;
        Map map;
        std::vector<Player> players;
        std::vector<Button> buttons;
};

int setup(Game *bomberman);
int game_loop(Game *bomberman);
int setdown(Game *bomberman);

int game_input(Game *bomberman);

int draw(Game *bomberman);
int draw2d(Game *bomberman);
int draw3d(Game *bomberman);

#endif /* !__TEKSPICE_HPP__ */
