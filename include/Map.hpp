/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** Class for map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <typeinfo>
#include <cstring>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include <random>
#include <ctime>

class Block;
class Game;

class Map {
    public:
        Map();
        ~Map();

        void random_map();
        void draw_map();
        void add_block(Game *bomberman);

        std::vector<Block> getBlock() const;

        std::vector<Block> blocks;
    private:
        std::vector<std::string> map;
};

#include "Block.hpp"

#endif