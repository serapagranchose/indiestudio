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
#include <vector>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fstream>

class Block;

class Map {
    public:
        Map();
        ~Map();

        void random_map();
        void draw_map();
        void add_block();

        std::vector<std::string> map;
        std::vector<Block> blocks;
};

#include "Block.hpp"

#endif