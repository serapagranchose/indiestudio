/*
** EPITECH PROJECT, 2021
** Bomb.cpp
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"

Bomb::Bomb(Vector3 position)
{
    this->_Position = position;
    this->_Position.x = round(this->_Position.x);
    this->_Position.z = round(this->_Position.z);
    this->_Timer = std::chrono::steady_clock::now();

}

Bomb::~Bomb()
{
}

Vector3 Bomb::getPosition(void) const
{
    return (this->_Position);
}

bool Bomb::getExploding(void) const
{
    return (this->_Exploding);
}

std::chrono::steady_clock::time_point Bomb::getTimer(void) const
{
    return (this->_Timer);
}

bool Bomb::operator==(const Bomb &bomb)
{
    return (this->_Position.x == bomb.getPosition().x && this->_Position.z == bomb.getPosition().z);
}

void Bomb::update(Game *bomberman)
{
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    double elapsed_time_ns = double(std::chrono::duration_cast <std::chrono::milliseconds> (end - this->_Timer).count());

    if (_Tick > 25)
        this->explode(bomberman);
    if (elapsed_time_ns >= 77) {
        _Tick++;
        this->_Timer = end;
    }
    if (_Tick % 5 == 0 && _Tick != 0) {
        this->_Size.x += 0.01;
        this->_Size.y += 0.01;
        this->_Size.z += 0.01;
    }
}

void Bomb::Draw(void) const
{
    DrawCubeV(this->_Position, this->_Size, this->_Color);
    for (int i = 0; i < this->_Explosions_Positions.size(); i++)
        DrawCubeV(this->_Explosions_Positions[i], this->_Size, RED);
}

int is_there_a_wall(Game *bomberman, Vector3 position)
{

    for (int i = 0; bomberman->getMap()->getBlocks().size() > i; i++) {
        if (round(bomberman->getMap()->getBlocks()[i].getPosition().x) == round(position.x)
        && round(bomberman->getMap()->getBlocks()[i].getPosition().z) == round(position.z)
        && round(bomberman->getMap()->getBlocks()[i].getPosition().y) == round(position.y)) {
            if (bomberman->getMap()->getBlocks()[i].getDestructible() == false)
                return (1);
            else if (bomberman->getMap()->getBlocks()[i].getDestructible() == true) {
                bomberman->_Map->_TxtMap[position.z + 6][position.x + 6] = ' ';
                bomberman->_Map->_Blocks.erase(bomberman->_Map->_Blocks.begin() + i);
            }
        }
    }
    return (0);
}

int is_there_a_player(Game *bomberman, Vector3 position, Bomb bomb)
{
    for (int i = 0; bomberman->getPlayers().size() > i; i++) {
        if ((round(bomberman->getPlayers()[i].getPosition().z) == round(position.z)
        && round(bomberman->getPlayers()[i].getPosition().x) == round(position.x))
        || (round(bomberman->getPlayers()[i].getPosition().z) == round(bomb.getPosition().z)
        && round(bomberman->getPlayers()[i].getPosition().x) == round(bomb.getPosition().x))) {
            bomberman->_Players[i].setAlive(false);
            return (1);
        }
    }
    return (0);
}

void Bomb::explode(Game *bomberman)
{
    Vector3 position = this->_Position;

    if (this->_Exploding == true)
        return;
    this->_Exploding = true;
    this->_Color = RED;
    position.z++;
    for (int i = 0; is_there_a_wall(bomberman, position) == 0 && i < 1; position.z++) {
        this->_Explosions_Positions.push_back(position);
        if (is_there_a_player(bomberman, position, *this) == 1)
            break;
        i++;
    }
    position = this->_Position;
    position.z--;
    for (int i = 0; is_there_a_wall(bomberman, position) == 0 && i < 1; position.z--) {
        this->_Explosions_Positions.push_back(position);
        if (is_there_a_player(bomberman, position, *this) == 1)
            break;
        i++;
    }
    position = this->_Position;
    position.x++;
    for (int i = 0; is_there_a_wall(bomberman, position) == 0 && i < 1; position.x) {
        this->_Explosions_Positions.push_back(position);
        if (is_there_a_player(bomberman, position, *this) == 1)
            break;
        i++;
    }
    position = this->_Position;
    position.x--;
    for (int i = 0; is_there_a_wall(bomberman, position) == 0 && i < 1; position.x--) {
        this->_Explosions_Positions.push_back(position);
        if (is_there_a_player(bomberman, position, *this) == 1)
            break;
        i++;
    }
    this->_Timer = std::chrono::steady_clock::now();
}