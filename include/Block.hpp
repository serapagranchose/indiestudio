/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Block class
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

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

#include "Game.hpp"

class Block{
    public:
        Block();
        Block(Vector3 position, bool destructible, Color couleur);
        ~Block();

        void draw();

        int place = 1;
        Vector3 position = {-1.0f, 0.0f, -1.0f};
        Vector3 size = {1.0f, 1.0f, 1.0f};

        Color color = GREEN;
        bool destructible = false;
};

#endif