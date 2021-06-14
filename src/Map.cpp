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

void Map::add_block()
{    
    int i = 0;
    int L= 0;
    float x = -6.0f;
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
            i++;
        }
    }
}

void Map::random_map()
{
    std::ifstream file("../graphic/map/map.txt");
    std::string str;
    std::string getMap;
    int infill_pourcent = 75;
    int x_num = 0;
    int h_num = 0;
    int h_need = 0;
    int i = 0;
    int L= 0;
    float x = -6.0f;
    float z = -7.0f;

    while (std::getline(file, str)) {
        getMap.append(str);
        getMap.append("\n");
        for (unsigned int i = 0; i < getMap.size(); i++)
            if (getMap[i] == 'x')
                x_num++;
    }
    h_need = (x_num * h_num) / 100;
    map = str_to_word_array(getMap);
    for (unsigned int i = 0; i < map.size(); i++) {
        for (unsigned int j = 0; j < map[i].size(); j++) {
            if (h_num == h_need)
                break;
        }
    }
    add_block();
}