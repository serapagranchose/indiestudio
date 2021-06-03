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
#include <typeinfo>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <time.h>

class Game;

class Block{
    public:
        Block();
        Block(Vector3 position, bool destructible);
        ~Block();

        void draw(Game *bomberman);

        int place = 1;
        Vector3 position = {-1.0f, 0.0f, -1.0f};
        Vector3 size = {1.0f, 1.0f, 1.0f};

        Color color = GREEN;
        bool destructible = false;
};

class Player{
    public:
        Player();
        Player(char *name, int key_right, int key_up, int key_left, int key_down);
        ~Player();

        void update(Game *bomberman);
        void draw(Game *bomberman);

        int place = 1;
        Vector3 position = {0.0f, 0.0f, 0.0f};
        Vector3 past_position;
        Vector3 next_position = position;
        Vector3 size = {0.99f, 0.99f, 0.99f};
        //bool collision = false;
        int right = KEY_D;
        int up = KEY_W;
        int left = KEY_A;
        int down = KEY_S;

        Color color = RED;
        char const *name = "adrien karpapov";
        Vector2 header = {0.0f, 0.0f};
        int bomb_nb = 0;
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

        void game_loop();
        void update();
        void input();
        void draw();
        void draw_text();

        Window window;
        Camera camera;
        std::vector<Button> buttons;
        Map map;
        std::vector<Player> players;
        bool debug = false;
        int status = 0;
};

#endif /* !__INDIESTUDIO_HPP__ */
