/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Source for map
*/

#include "Map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

void Map::draw_map()
{
}

void Map::add_block(Game *bomberman)
{    
    int i = 0;
    int L= 0;
    float x = -8.0f;
    float z = -7.0f;

    for (int j = 0; j < map.size(); j++) {
        L++;
        i = 0;
        for (int k = 0; k < map[j].size(); k++) {
            if (map[j][k] == 'H') {
                Block mousse({z + i, 0.0f, x + L},1, BLACK);
                this->blocks.push_back(mousse);
            }
            if (map[j][k] == 'O') {
                Block mur({z + i, 0.0f, x + L},0, DARKBLUE);
                this->blocks.push_back(mur);
            }
            if (map[j][k] == 'P') {
                Player onch;
                bomberman->players.push_back(onch);
            }
            i++;
        }
    }
}

void Map::random_map()
{
    std::ifstream file("../graphic/map/map.txt");
    std::string str;
    std::string getMap;
    srand((unsigned) time(0));
    int infill_pourcent = 75;
    int x_num = 0;
    int h_num = 0;
    int h_need = 75;
    int i = 0;
    int L= 0;
    float x = -6.0f;
    float z = -7.0f;
    int randomNumber;

    while (std::getline(file, str)) {
        getMap.append(str);
        getMap.append("\n");
        for (unsigned int i = 0; i < str.size(); i++) {
            if (str[i] == 'x')
                x_num++;
        }
    }
    map = str_to_word_array(getMap);
    for (unsigned int i = 0; i < map.size(); i++) {
        for (unsigned int j = 0; j < 13; j++) {
            randomNumber = (rand() % 100) + 1;
            if (map[i][j] == 'x' && (randomNumber % 2) == 0) {
                map[i][j] = 'H';
                h_num++;
            }
        }
    }
}