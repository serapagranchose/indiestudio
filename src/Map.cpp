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
            if (map[j][k] == '1') {
                bomberman->namePlayer.push_back("One");
                bomberman->coordPlayer.push_back({z + i, 0.0f, x +l});
            }
            if (map[j][k] == '2') {
                bomberman->namePlayer.push_back("Two");
                bomberman->coordPlayer.push_back({z + i, 0.0f, x +l});
            }
            if (map[j][k] == '3') {
                bomberman->namePlayer.push_back("Three");
                bomberman->coordPlayer.push_back({z + i, 0.0f, x +l});
            }
            if (map[j][k] == '4') {
                bomberman->namePlayer.push_back("Four");
                bomberman->coordPlayer.push_back({z + i, 0.0f, x +l});
            }
            Block ground({z + i, -1.25f, x + l}, 0, BLUE);
            ground.loadGround();
            this->blocks.push_back(ground);
            i++;
        }
    }
    bomberman->initPlayer();
}

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

void Map::randomMap(Game *bomberman)
{
    std::ifstream file("assets/map/map.txt");
    std::string str;
    std::string getMap;
    srand((unsigned) time(0));
    int randomNumber;

    if (!file) {
        bomberman->setStatus(0);
        return;
    }
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
            for (int k = 0; k < bomberman->getPlayers().size(); k++) {
                if (i == round(bomberman->getPlayers()[k].getPosition().z + 6) && j == round(bomberman->getPlayers()[k].getPosition().x + 6))
                    map[i][j] = std::to_string(k + 1).c_str()[0];
            }
        }
    }
    save.open("assets/map/save.txt", std::ofstream::out | std::ofstream::trunc);
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

void Map::loadMap(Game *bomberman)
{
    std::ifstream file("assets/map/save.txt");
    std::string str;
    std::string getMap;
    int player = 0;

    while (std::getline(file, str)) {
        getMap.append(str);
        getMap.append("\n");
    }
    if (getMap[0] == '\0') {
        bomberman->setStatus(0);
        return;
    }
    map = str_to_word_array(getMap);
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '1' || map[i][j] == '2' || map[i][j] == '3'|| map[i][j] == '4')
                player++;
        }
    }
    if (player <= 1) {
        bomberman->setStatus(0);
        return;
    }
    initStart();
    addBlock(bomberman);
}

std::vector<Block> Map::getBlock() const
{
    return (this->blocks);
}
