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
#include <cstring>
#include <vector>
#include <time.h>

class Game;

class Window{
    public:
        int status = 0;
        int screen_width = 1920;
        int screen_height = 1080;
};

class Block{
    public:
        Block();
        ~Block();

        void draw(Game *bomberman);

        Vector3 position = {0.0f, 0.0f, 0.0f};
        Vector3 size = {1.0f, 1.0f, 1.0f};
        int place = 1;
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
        Player();
        ~Player();

        void draw(Game *bomberman);

        Vector3 position = {0.0f, 0.0f, 0.0f};
        Vector3 size = {1.0f, 4.0f, 1.0f};
        int place = 1;
        int bomb_nb;
        Color color = RED;

        Model model;
};

class Button{
    public:
        Button();
        ~Button();

        void draw(Game *bomberman);
        void input(Game *bomberman, Vector2 mouse);

        int status = 0;
        int place = 0;
        bool action = false;
        float frame_height;
        Texture2D texture;
        Rectangle size;
        Rectangle bounds;

        Model model;
};

class Game{
    public:
        Game();
        ~Game();

        void input();
        void input_debug();
        void draw();
        void draw_debug();
        void game_loop();

        int status = 0;
        bool debug = false;
        Window window;
        Camera camera;
        Map map;
        std::vector<Player> players;
        std::vector<Button> buttons;
};


int input(Game *bomberman);

void draw(Game *bomberman);

#endif /* !__TEKSPICE_HPP__ */
