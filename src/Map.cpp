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

void Map::drawMap()
{
}

void Map::addBlock(Game *bomberman)
{
    int i = 0;
    int l = 0;
    float x = -7.0f;
    float z = -6.0f;

    for (int j = 0; j < map.size(); j++) {
        l++;
        i = 0;
        for (int k = 0; k < map[j].size(); k++) {
            if (map[j][k] == 'H') {
                Block mousse({z + i, 0.0f, x + l},1, BLACK);
                mousse.loadMousse();
                this->blocks.push_back(mousse);
            }
            if (map[j][k] == 'O') {
                Block mur({z + i, 0.0f, x + l}, 0, DARKBLUE);
                mur.loadHolyBlock();
                this->blocks.push_back(mur);
            }
            Block ground({z + i, -1.25f, x + l}, 0, BLUE);
            ground.loadGround();
            this->blocks.push_back(ground);
            i++;
        }
    }
}

// RENDRE PLUS CLEAN PARCE QUE LA MÊME MOI J'AI MAL ALORS QUE C'EST MOI QUI L'AI FAIT

void Map::initStart()
{
    if (map[1][2] == 'H')
        map[1][2] = ' ';
    if (map[2][1] == 'H')
        map[2][1] = ' ';
    if (map[1][10] == 'H')
        map[1][10] = ' ';
    if (map[2][11] == 'H')
        map[2][11] = ' ';
    if (map[10][1] == 'H')
        map[10][1] = ' ';
    if (map[11][2] == 'H')
        map[11][2] = ' ';
    if (map[10][11] == 'H')
        map[10][11] = ' ';
    if (map[11][10] == 'H')
        map[11][10] = ' ';
    if (map[1][1] == 'H')
        map[1][1] = ' ';
    if (map[1][11] == 'H')
        map[1][11] = ' ';
    if (map[11][1] == 'H')
        map[11][1] = ' ';
    if (map[11][11] == 'H')
        map[11][11] = ' ';
}

void Map::randomMap()
{
    std::ifstream file("../graphic/map/map.txt");
    std::string str;
    std::string getMap;
    srand((unsigned) time(0));
    int randomNumber;

    while (std::getline(file, str)) {
        getMap.append(str);
        getMap.append("\n");
    }
    map = str_to_word_array(getMap);
    for (unsigned int i = 0; i < map.size(); i++) {
        for (unsigned int j = 0; j < map[i].size(); j++) {
            randomNumber = (rand() % 100) + 1;
            if (map[i][j] == ' ' && ((randomNumber % 2) == 0 || (randomNumber % 3) == 0))
                map[i][j] = 'H';
        }
    }
    initStart();
}

void Map::saveMap(Game *bomberman)
{
    std::ofstream save;
    int x = 0;
    int z = 0;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '1' || map[i][j] == '2' || map[i][j] == '3' || map[i][j] == '4')
                map[i][j] = ' ';
            for (int k = 0; k < bomberman->getPlayer().size(); k++) {
                if (i == round(bomberman->getPlayer()[k].getPosition().z + 6) && j == round(bomberman->getPlayer()[k].getPosition().x + 6))
                    map[i][j] = std::to_string(k + 1).c_str()[0];
            }
        }               
    }
    save.open("../graphic/map/save.txt", std::ofstream::out | std::ofstream::trunc);
    if (save) {
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++)
                save << map[i][j];
            save << '\n';
        }
    }
    else
        std::cerr << "Error, impossible to open the file" << std::endl;
}

std::vector<Block> Map::getBlock() const
{
    return (this->blocks);
}
