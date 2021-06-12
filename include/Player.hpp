/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Player class
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Game.hpp"

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

#endif