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

class Block{
    public:
        Block();
        ~Block();

        void draw(Game *bomberman);

        int place = 1;
        Vector3 position = {0.0f, 0.0f, 0.0f};
        Vector3 size = {1.0f, 1.0f, 1.0f};
        Color color = GREEN;
        int destructible;
};

class Player{
    public:
        Player();
        ~Player();

        void draw(Game *bomberman);

        int place = 1;
        Vector3 position = {0.0f, 0.0f, 0.0f};
        Vector3 size = {1.0f, 4.0f, 1.0f};
        Color color = RED;
        char *name;
        int bomb_nb;
};

class Map{
public:
    std::vector<Block> blocks;
};

class Button{
    public:
        Button();
        ~Button();

        void draw(Game *bomberman);
        void input(Game *bomberman, Vector2 mouse);

        int place = 0;
        float frame_height;
        Texture2D texture;
        Rectangle size;
        Rectangle bounds;
        int status = 0;
        bool action = false;

        Model model;
};

class Window{
    public:
        int screen_width = 1920;
        int screen_height = 1080;
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

        Window window;
        Camera camera;
        std::vector<Button> buttons;
        Map map;
        std::vector<Player> players;
        bool debug = false;
        int status = 0;
};

#endif /* !__INDIESTUDIO_HPP__ */
