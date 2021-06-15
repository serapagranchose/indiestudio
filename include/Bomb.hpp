/*
** EPITECH PROJECT, 2021
** Bomb.hpp
** File description:
** Bomb.hpp
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Game.hpp"

class Bomb {
    public:
        Bomb(Vector3 position, Vector3 size, Player bomber);
        ~Bomb();
        Vector3 position = {-1.0f, 0.0f, -1.0f};
        Vector3 size = {1.0f, 1.0f, 1.0f};
        Player bomber;
};

#endif /* !BOMB_HPP_ */