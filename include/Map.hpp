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

#include "Game.hpp"

class Block;
class Game;

class Map {
    public:
        Map();
        ~Map();

        std::vector<Block> getBlocks() const;

        void randomMap(Game *bomberman);
        void drawMap();
        void addBlock(Game *bomberman);
        void saveMap(Game *bomberman);
        void initStart();
        void loadMap(Game *bomberman);

        std::vector<Block> _Blocks;
        std::vector<std::string> _TxtMap;
};

#endif
